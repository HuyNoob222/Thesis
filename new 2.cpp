/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLylU-N9D4"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "2gEQdFIe3_ohfdyFpu0cgftl5m5DR_Jo"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

//2->9 = GPIO1 -> GPIO8
//27 26 29 30 = GPIO 9 10 18 19

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
/////// 12 LOOP 

BLYNK_WRITE(V1) //GPIO1
{
  // Update state
  digitalWrite(2,param.asInt());
}
BLYNK_WRITE(V2) //GPIO2
{
  // Update state
  digitalWrite(3, param.asInt());
}
BLYNK_WRITE(V3) //GPIO3
{
  // Update state
  digitalWrite(4, param.asInt());
}
BLYNK_WRITE(V4) //GPIO4
{
  // Update state
  digitalWrite(5, param.asInt());
}
BLYNK_WRITE(V5) //GPIO5
{
  // Update state
  digitalWrite(6, param.asInt());
}
BLYNK_WRITE(V6) //GPIO6
{
  // Update state
  digitalWrite(7, param.asInt());
}
BLYNK_WRITE(V7) //GPIO7
{
  // Update state
  digitalWrite(8, param.asInt());
}
BLYNK_WRITE(V8) //GPIO8
{
  // Update state
  digitalWrite(9, param.asInt());
}
BLYNK_WRITE(V9) //GPIO9
{
  // Update state
  digitalWrite(27, param.asInt());
}
BLYNK_WRITE(V10) //GPIO10
{
  // Update state
  digitalWrite(26, param.asInt());
}
BLYNK_WRITE(V11) //GPIO11
{
  // Update state
  digitalWrite(29, param.asInt());
}
BLYNK_WRITE(V12) //GPIO12
{ 
  // Update state
  digitalWrite(30, param.asInt());
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V13, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
