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
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(2, value);
}
BLYNK_WRITE(V2) //GPIO2
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(3, value);
}
BLYNK_WRITE(V3) //GPIO3
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(4, value);
}
BLYNK_WRITE(V4) //GPIO4
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(5, value);
}
BLYNK_WRITE(V5) //GPIO5
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(6, value);
}
BLYNK_WRITE(V6) //GPIO6
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(7, value);
}
BLYNK_WRITE(V7) //GPIO7
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(8, value);
}
BLYNK_WRITE(V8) //GPIO8
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(9, value);
}
BLYNK_WRITE(V9) //GPIO9
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(27, value);
}
BLYNK_WRITE(V10) //GPIO10
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(26, value);
}
BLYNK_WRITE(V11) //GPIO11
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(29, value);
}
BLYNK_WRITE(V12) //GPIO12
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  
  // Update state
  digitalWrite(30, value);
}
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V14, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V14, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V14, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
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
