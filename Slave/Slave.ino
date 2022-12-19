//Libs for esp e wifi
#include <esp_now.h>
#include <WiFi.h>

//Gpios write the values received from the Master
uint8_t gpio[] = {int temp};

//setup function calculate the gpio count and put in this variable
//on setup function

int gpioCount;
void setup() {
  Serial.begin(115200);
  
  //Calculation of gpio array size:
  //sizeof(gpios) returns how many bytes "gpios" array points to.
  //Elements in this array are of type uint8_t.
  //sizeof(uint8_t) return how many bytes uint8_t type has.
  //Therefore if we want to know how many gpios there are,
  //we divide the total byte count of the array by how many bytes
  //each element has.
  //Puts ESP in STATION MODE
  WiFi.mode(WIFI_STA);

  //Shows on the Serial Monitor the STATION MODE Mac Address of this ESP
  Serial.print("Mac Address in Station: "); 
  Serial.println(WiFi.macAddress());

  //Calls the function that will initialize the ESP-NOW protocol
  InitESPNow();

  //Registers the callback function that will be excuted when
    //this Slave receives data from the Master
    //The function in this case is called OnDataRecv
    esp_now_register_recv_cb(OnDataRecv);
    //For each gpio on gpio array
      //Put it in read mode
      Serial.print("Set IO: ");
      Serial.print(temp);
      pinMode(gpio[temp],OUTPUT);
}
void InitESPNow(){
  //Init sucess
  if(esp_now_init() == ESP_OK){
    Serial.println("ESPNow Init Success");
  }
  //Init error
  else{
    Serial.println("ESPNow Init Fail");
    ESP.restart();
  }
}
//Function that serves as a callback to let us know 
//when something has arrived from the Master 
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) { 
  char macStr[18]; 
  //Copy the source Mac Address to a string 
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x", 
           mac_addr[0], mac_addr[1], mac_addr [2], mac_addr[3], mac_addr[4], mac_addr[5]); 
  //We show the Mac Address that was the origin of the message 
  Serial.print("Received from: "); 
  Serial.println(macStr); 
  Serial.println(""); 

  //For each pin 
 // for(int i=0; i<gpioCount; i++){ 
    //We put the value received from the Master in the output of the respective pin
 //   digitalWrite(gpio[i], data[i]); 
  digitalWrite(gpio[temp],data);
  } 
}
void loop(){
}
    
