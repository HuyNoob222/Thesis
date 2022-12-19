#include <SPI.h>
#include <Ethernet.h>
int LED_PIN[] = {2,3,4,5,6,7,8,9,27,26,29,30};
//2->9 = GPIO 1 -> GPIO8
//27 26 29 30 = GPIO 9 10 18 19
#define SERVER_PORT 4080
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
//byte mac[] = {0x84, 0xF7, 0x03, 0xA5, 0x1D, 0x19};
EthernetServer TCPserver(SERVER_PORT);
int count_pin=12;
void setup() {
  Serial.begin(115200);
  for(int i =0;i<count_pin;i++)
  {
  pinMode(LED_PIN[i], OUTPUT);
  }
  Serial.println("ESP32 #2: TCP SERVER + AN LED");
  // Initialize Ethernet Shield:
  if (Ethernet.begin(mac) == 0){
    Serial.println("ESP32 #2: Failed to configure Ethernet using DHCP");
    while(true) {
      delay(1); // do nothing
    }
  } 
  else {
    // Print your local IP address:
    Serial.print("ESP32 #2: TCP Server IP address: ");
    Serial.println(Ethernet.localIP());
    Serial.println("ESP32 #2: -> Please update the serverAddress in ESP32 #1 code");
  }

  // Listening for a TCP client (from ESP32 #1)
  TCPserver.begin();
}

void loop() {
  // Wait for a TCP client from ESP32 #1:
  EthernetClient client = TCPserver.available();

  if (client) {
    // Read the command from the TCP client:
    char command = client.read();
    Serial.print("ESP32 #2: - Received command: ");
    Serial.println(command);
/*
  //PIN1
    if (command == '10')
    digitalWrite(LED_PIN[1], LOW);
    else if (command == '11')
    digitalWrite(LED_PIN[1], HIGH); 
  //PIN2
  else if (command == '20')
    digitalWrite(LED_PIN[2],LOW);
  else if (command == '21')
    digitalWrite(LED_PIN[2],HIGH);
  //PIN3
  else if (command == '30')
    digitalWrite(LED_PIN[3],LOW);
  else if (command == '31')
    digitalWrite(LED_PIN[3],HIGH);
  //PIN4
  else if (command == '40')
    digitalWrite(LED_PIN[4],LOW);
  else if (command == '41')
    digitalWrite(LED_PIN[4],HIGH);
  //PIN5
  else if (command == '50')
    digitalWrite(LED_PIN[5],LOW);
  else if (command == '51')
    digitalWrite(LED_PIN[5],HIGH);
  //PIN6
  else if (command == '60')
    digitalWrite(LED_PIN[6],LOW);
  else if (command == '61')
    digitalWrite(LED_PIN[6],HIGH);
  //PIN7
  else if (command == '70')
    digitalWrite(LED_PIN[7],LOW);
  else if (command == '71')
    digitalWrite(LED_PIN[7],HIGH);
  //PIN8
  else if (command == '80')
    digitalWrite(LED_PIN[8],LOW);
  else if (command == '81')
    digitalWrite(LED_PIN[8],HIGH);
  //PIN9
  else if (command == '90')
    digitalWrite(LED_PIN[9],LOW);
  else if (command == '91')
    digitalWrite(LED_PIN[9],HIGH);
  //PIN10
  else if (command == '100')
    digitalWrite(LED_PIN[10],LOW);
  else if (command == '101')
    digitalWrite(LED_PIN[10],HIGH);
  //PIN11
  else if (command == '110')
    digitalWrite(LED_PIN[11],LOW);
  else if (command == '111')
    digitalWrite(LED_PIN[11],HIGH);
  //PIN12
  else if (command == '120')
    digitalWrite(LED_PIN[12],LOW);
  else if (command == '121')
    digitalWrite(LED_PIN[12],HIGH);
 */   
  //Convertto32INT => interger => temp1 = PIN[temp1], temp2 = STT PIN;
  int recievenumber = command - '0';
  int temp = recievenumber/10; int temp1 = recievenumber%10;
  if (temp1 == 1)
  {
    digitalWrite(LED_PIN[temp],HIGH);
  }
  else
  {
    digitalWrite(LED_PIN[temp],LOW);
  }
    Ethernet.maintain();
  }
}
