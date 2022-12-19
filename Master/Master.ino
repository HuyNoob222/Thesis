#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

//Libs for esp master wifi
#include <esp_now.h>
#include <WiFi.h>

//Channel used in the connection
#define CHANNEL 1

//Gpios that goinf to read (digitalRead)
//2->9 = GPIO 1 -> GPIO8
//27 26 29 30 = GPIO 9 10 18 19
int temp,status_temp;
uint8_t gpio[] = {temp,status_temp};
int gpioCount = sizeof(gpio)/sizeof(uint8_t);
//Slave MAC addreddes that will receive data from Master
uint8_t macSlaves[] = {0x84,0xF7,0x03,0xA5,0x1D,0x19};

void setup() {
  Serial.begin(115200);
  //Calculation of gpio array size
  //Serial.println(gpioCount);

  //Puts ESP in STATION MODE
  WiFi.mode(WIFI_STA);

  //Shows on the Serial Monitor the STATION MODE MAC Adress of this ESP
  Serial.print("Mac Address in Station: ");
  Serial.println(WiFi.macAddress());

  //Calls the function that will initialize the ESP-NOW protocol
  InitESPNow();
  //For each GPIO
  Serial.println("Get IO ? ");
  temp = Serial.parseInt();
  delay(100);
  Serial.print("Set status IO? ");
  status_temp = Serial.parseInt();  
  delay(200);
    //put it in read mode
  pinMode(gpio[temp],INPUT);
  senddata();
}
void InitESPNow(){
  //If initalization was success
  if(esp_now_init() == ESP_OK){
    Serial.println("ESPNow Init Success");
  }
  //If there was am error
  else {
    Serial.println("ESPNow Init Failed");
    ESP.restart();
  }
}
//Function will read the gpios and send
//read values to the others ESPs
void senddata(){
  //Array that will store the read values
  uint8_t values[gpioCount];
  Serial.println(temp);
  Serial.println(status_temp);
  for(int i=0; i<gpioCount;i++){
      values[i] = digitalRead(gpio[i]);
  //  Serial.print("Pin:");
  //  Serial.print(gpio[i]);
  //  Serial.println(values[i]);
  }
  uint8_t broadcast[] = {0xFF, 0xFF,0xFF,0xFF,0xFF,0xFF};
  esp_err_t result = esp_now_send(broadcast, (uint8_t*) &values, sizeof(values));
  Serial.print("Send Status: ");
//If it was successful
  if (result == ESP_OK) {
    Serial.println("Success");
  }
//if it failed
    else if (result == ESP_ERR_ESPNOW_NOT_INIT) {
    // How did we get so far!!
    Serial.println("ESPNOW not Init.");
  } else if (result == ESP_ERR_ESPNOW_ARG) {
    Serial.println("Invalid Argument");
  } else if (result == ESP_ERR_ESPNOW_INTERNAL) {
    Serial.println("Internal Error");
  } else if (result == ESP_ERR_ESPNOW_NO_MEM) {
    Serial.println("ESP_ERR_ESPNOW_NO_MEM");
  } else if (result == ESP_ERR_ESPNOW_NOT_FOUND) {
    Serial.println("Peer not found.");
  } else {
    Serial.println("Not sure what happened");
  }
}

//Callback function that gives us feedback about the sent data
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  //Copies the receiver Mac Address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  //Prints it on Serial Monitor
  Serial.print("Sent to: "); 
  Serial.println(macStr);
  //Prints if it was successful or not
  Serial.print("Status: "); 
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
  //Sends again
  senddata();
}
//don't do anything on the loop
//Every time receive feedback about the last sent data,
//=> calling the send function again,
//therefore the data is always being sent
void loop(){
}
