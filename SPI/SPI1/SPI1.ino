#include <SPI.h>
#include <Ethernet.h>

int PIN[] = {2,3,4,5,6,7,8,9,27,26,29,30};
//2->9 = GPIO 1 -> GPIO8
//27 26 29 30 = GPIO 9 10 18 19
#define SERVER_PORT  4080

//byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x03};
byte mac[] = {0x84, 0xF7, 0x03, 0xA5, 0x1D, 0x19};
IPAddress serverAddress(0, 0, 0, 0);
EthernetClient TCPclient;
int count_pin = 12;
void setup() {
  Serial.begin(115200);
 // button.setDebounceTime(50); // set debounce time to 50 milliseconds

  for (int i =0;i<count_pin;i++) // set number of pin like as input
  {
  pinMode(PIN[i],INPUT);
  }

  Serial.println("ESP32 #1: TCP CLIENT + A BUTTON/SWITCH");

  // Initialize Ethernet Shield:
  if (Ethernet.begin(mac) == 0)
    Serial.println("ESP32 #1: Failed to configure Ethernet using DHCP");

  // connect to TCP server (ESP32 #2 )
  if (TCPclient.connect(serverAddress, SERVER_PORT))
    Serial.println("ESP32 #1: Connected to TCP server");
  else
    Serial.println("ESP32 #1: Failed to connect to TCP server");
}

void loop() {

  digitalWrite(PIN[1],0);
  digitalWrite(PIN[2],1);
  digitalWrite(PIN[3],0);
  digitalWrite(PIN[4],1);
  digitalWrite(PIN[5],0);
  digitalWrite(PIN[6],1);
  digitalWrite(PIN[7],0);
  digitalWrite(PIN[8],1);
  digitalWrite(PIN[9],0);
  digitalWrite(PIN[10],1);
  digitalWrite(PIN[11],0);
  digitalWrite(PIN[12],1);
  
  if (!TCPclient.connected()) {
    Serial.println("ESP32 #1: Connection is disconnected");
    TCPclient.stop();

    // reconnect to TCP server (ESP32 #2)
    if (TCPclient.connect(serverAddress, SERVER_PORT))
      Serial.println("ESP32 #1: Reconnected to TCP server");
    else
      Serial.println("ESP32 #1: Failed to reconnect to TCP server");
  }
//////////////////////////*
 /* if (button.isPressed()) {
    TCPclient.write('1');
    TCPclient.flush();
    Serial.println("ESP32 #1: - The button is pressed,  sent command: 1");
  }

  if (button.isReleased()) {
    TCPclient.write('0');
    TCPclient.flush();
    Serial.println("ESP32 #1: - The button is released, sent command: 0");
  }
*/////////////////////////
  for(int i = 0; i< count_pin;i++)
  {
    digitalRead(PIN[i]);
    if (PIN[i] == 1)
    {
      int temp = i*10+1;
      TCPclient.write(temp);
      TCPclient.flush();
    }
    else 
    {
      int temp = i*10+0;
      TCPclient.write(temp);
      TCPclient.flush();
    }
  }
}
