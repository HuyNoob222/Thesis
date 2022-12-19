#define BLYNK_TEMPLATE_ID "TMPLhAczuFLC"
#define BLYNK_DEVICE_NAME "8RELAY"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
#include "BlynkEdgent.h"
const int bt1 = 23;
const int bt2 = 3;//Rx
const int bt3 = 19;
const int bt4 = 18;
const int bt5 = 5;
const int bt6 = 17;//Tx2
const int bt7 = 16;//Rx2
const int bt8 = 4;
const int btSetup = 15;
const int out1 = 32;
const int out2 = 33;
const int out3 = 25;
const int out4 = 26;
const int out5 = 27;
const int out6 = 14;
const int out7 = 12;
const int out8 = 13;
const int ledSignal = 2;
boolean bt1State = HIGH;
boolean bt2State = HIGH;
boolean bt3State = HIGH;
boolean bt4State = HIGH;
boolean bt5State = HIGH;
boolean bt6State = HIGH;
boolean bt7State = HIGH;
boolean bt8State = HIGH;
WidgetLED ledConnect(V0);
unsigned long timesBlinkLed=millis();

void setup(){
  Serial.begin(115200);
  delay(100);
  pinMode(bt1,INPUT_PULLUP);
  pinMode(bt2,INPUT_PULLUP);
  pinMode(bt3,INPUT_PULLUP);
  pinMode(bt4,INPUT_PULLUP);
  pinMode(bt5,INPUT_PULLUP);
  pinMode(bt6,INPUT_PULLUP);
  pinMode(bt7,INPUT_PULLUP);
  pinMode(bt8,INPUT_PULLUP);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  pinMode(out5,OUTPUT);
  pinMode(out6,OUTPUT);
  pinMode(out7,OUTPUT);
  pinMode(out8,OUTPUT);
  BlynkEdgent.begin();
}

void loop(){
  BlynkEdgent.run();
  if(millis()-timesBlinkLed>1000){
    if(ledConnect.getValue()){
      ledConnect.off();
    }else{
      ledConnect.on();
    }
    unsigned long value = millis() / 1000;
    Blynk.virtualWrite(V9, String(value));
    timesBlinkLed=millis();
  }
  checkButton();
}
void checkButton(){
  if(digitalRead(bt1)==LOW){
    if(bt1State==HIGH){
      digitalWrite(out1,!digitalRead(out1));
      Blynk.virtualWrite(V1,digitalRead(out1));
      delay(200);
      bt1State=LOW;
    }
  }else{
    bt1State=HIGH;
  }
  if(digitalRead(bt2)==LOW){
    if(bt2State==HIGH){
      digitalWrite(out2,!digitalRead(out2));
      Blynk.virtualWrite(V2,digitalRead(out2));
      delay(200);
      bt2State=LOW;
    }
  }else{
    bt2State=HIGH;
  }
  if(digitalRead(bt3)==LOW){
    if(bt3State==HIGH){
      digitalWrite(out3,!digitalRead(out3));
      Blynk.virtualWrite(V3,digitalRead(out3));
      delay(200);
      bt3State=LOW;
    }
  }else{
    bt3State=HIGH;
  }
  if(digitalRead(bt4)==LOW){
    if(bt4State==HIGH){
      digitalWrite(out4,!digitalRead(out4));
      Blynk.virtualWrite(V4,digitalRead(out4));
      delay(200);
      bt4State=LOW;
    }
  }else{
    bt4State=HIGH;
  }
  if(digitalRead(bt5)==LOW){
    if(bt5State==HIGH){
      digitalWrite(out5,!digitalRead(out5));
      Blynk.virtualWrite(V5,digitalRead(out5));
      delay(200);
      bt5State=LOW;
    }
  }else{
    bt5State=HIGH;
  }
  if(digitalRead(bt6)==LOW){
    if(bt6State==HIGH){
      digitalWrite(out6,!digitalRead(out6));
      Blynk.virtualWrite(V6,digitalRead(out6));
      delay(200);
      bt6State=LOW;
    }
  }else{
    bt6State=HIGH;
  }
  if(digitalRead(bt7)==LOW){
    if(bt7State==HIGH){
      digitalWrite(out7,!digitalRead(out7));
      Blynk.virtualWrite(V7,digitalRead(out7));
      delay(200);
      bt7State=LOW;
    }
  }else{
    bt7State=HIGH;
  }
  if(digitalRead(bt8)==LOW){
    if(bt8State==HIGH){
      digitalWrite(out8,!digitalRead(out8));
      Blynk.virtualWrite(V8,digitalRead(out8));
      delay(200);
      bt8State=LOW;
    }
  }else{
    bt8State=HIGH;
  }
}
BLYNK_CONNECTED() {
  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll();
  //Blynk.syncVirtual(V0, V2);
}
BLYNK_WRITE(V1){
  int p = param.asInt();
  digitalWrite(out1,p);
}
BLYNK_WRITE(V2){
  int p = param.asInt();
  digitalWrite(out2,p);
}
BLYNK_WRITE(V3){
  int p = param.asInt();
  digitalWrite(out3,p);
}
BLYNK_WRITE(V4){
  int p = param.asInt();
  digitalWrite(out4,p);
}
BLYNK_WRITE(V5){
  int p = param.asInt();
  digitalWrite(out5,p);
}
BLYNK_WRITE(V6){
  int p = param.asInt();
  digitalWrite(out6,p);
}
BLYNK_WRITE(V7){
  int p = param.asInt();
  digitalWrite(out7,p);
}
BLYNK_WRITE(V8){
  int p = param.asInt();
  digitalWrite(out8,p);
}
