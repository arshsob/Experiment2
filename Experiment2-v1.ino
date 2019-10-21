#include <animationTools.h>

int th1 = 1200;
int th2 = 3000;

int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;
int ledPin4 = 12;
int ledPin5 = 3;


int pinSensor1 = 2;
int pinSensor2 = 3;
int pinSensor3 = 5;

int ledBrightness1;
int ledBrightness2;
int ledBrightness3;
int ledBrightness4;

int ledblinkRate1;
int ledblinkRate2;
int ledblinkRate3;
int ledblinkRate4;

boolean ledState1 = false;
boolean ledState2 = false;
boolean ledState3 = false;
boolean ledState4 = false;

long lastTimeYouBlinked1;
long lastTimeYouBlinked2;
long lastTimeYouBlinked3;
long lastTimeYouBlinked4;

int d1;
int d2;
int d3;

//Idle Mode
float idleFadeSpeed = 0.06;

//Crazy Mode
int crazyBlinkRate1 = 50;
int crazyBlinkRate2 = 71;
int crazyBlinkRate3 = 52;
int crazyBlinkRate4 = 73;

float crazyFadeSpeed = 0.8;







void setup() {

//LEDs
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);


//Sensors
pinMode(pinSensor1, INPUT);

Serial.begin(9600);

}








void loop() {

d1 = pulseIn(pinSensor1, HIGH);

Serial.println(d1);

analogWrite(ledPin5, 255);




//Idle Mode
if (d1 > th2){
  Idle();
  }

//Working Mode
if (d1 > th1 && d1 < th2){
  if (d1 > th1 && d1 <= th1+((th2-th1)/3)){
    Working(50);
  }

  if (d1 > th1+((th2-th1)/3) && d1 <= th1+2*((th2-th1)/3)){
    Working(100);
  }

  if (d1 > th1 + 2 * ((th2 - th1) / 3) && d1 < th2){
    Working(200);
  }
}  

//Crazy Mode
if (d1 < th1){
  Crazy();
  }

}








void Idle() {
ledBrightness1 = oscillate(0, 50, 0, idleFadeSpeed, millis());
ledBrightness2 = oscillate(100, 0, 0, idleFadeSpeed, millis());
ledBrightness3 = oscillate(0, 100, 70, idleFadeSpeed, millis());
ledBrightness4 = oscillate(120, 20, 60, idleFadeSpeed, millis());
analogWrite(ledPin1, ledBrightness1);
analogWrite(ledPin2, ledBrightness2);
analogWrite(ledPin3, ledBrightness3);
analogWrite(ledPin4, ledBrightness4);
}







void Crazy(){
ledBrightness1 = oscillate(0, 255, 0, crazyFadeSpeed, millis());
ledBrightness2 = oscillate(255, 0, 0, crazyFadeSpeed, millis());
ledBrightness3 = oscillate(0, 255, 70, crazyFadeSpeed, millis());
ledBrightness4 = oscillate(255, 0, 60, crazyFadeSpeed, millis());
analogWrite(ledPin1, ledBrightness1);
analogWrite(ledPin2, ledBrightness2);
analogWrite(ledPin3, ledBrightness3);
analogWrite(ledPin4, ledBrightness4);
}







void Working(int beat) {
ledblinkRate1 = beat;
ledblinkRate2 = beat;
ledblinkRate3 = beat;
ledblinkRate4 = beat;

ledBrightness1 = map(d1, th1, th2, 255, 0);
ledBrightness2 = map(d1, th1, th2, 255, 0);
ledBrightness3 = map(d1, th1, th2, 255, 0);
ledBrightness4 = map(d1, th1, th2, 255, 0);



///////////////////BLINK WITH DISTANCE
  
if(millis()-lastTimeYouBlinked1>=ledblinkRate1) {
  ledState1 = !ledState1;
    if(ledState1){
      analogWrite(ledPin1,0);
    }
    else {
      analogWrite(ledPin1,ledBrightness1);
    }
  lastTimeYouBlinked1 = millis();
}

if(millis()-lastTimeYouBlinked2>=ledblinkRate2) {
  ledState2 = !ledState2;
    if(ledState2){
      analogWrite(ledPin2,ledBrightness2);
    }
    else {
      analogWrite(ledPin2,0);
    }
  lastTimeYouBlinked2 = millis();
}

if(millis()-lastTimeYouBlinked3>=ledblinkRate3) {
  ledState3 = !ledState3;
    if(ledState3){
      analogWrite(ledPin3,ledBrightness3);
    }
    else {
      analogWrite(ledPin3,0);
    }
  lastTimeYouBlinked3 = millis();
}

if(millis()-lastTimeYouBlinked4>=ledblinkRate4) {
  ledState4 = !ledState4;
    if(ledState4){
      analogWrite(ledPin4,ledBrightness4);
    }
    else {
      analogWrite(ledPin4,0);
    }
  lastTimeYouBlinked4 = millis();
}
}




/*
void NilamSensor2(){
int distanceValue2;
int prevDistanceValue2;
int distanceChange2;
int velocity2;
int noiseThreshhold2 = 50;

d2 = pulseIn(pinSensor2, HIGH);
distanceChange2 = prevDistanceValue2 - d2;
velocity2 = abs(distanceChange2);

if(velocity2 > noiseThreshhold2){
 if (distanceChange2 < 0){
   ledBrightness1 = ledBrightness1 + 50;
   ledBrightness2 = ledBrightness2 - 50;
   ledBrightness3 = ledBrightness3 + 50;
   ledBrightness4 = ledBrightness4 - 50;
 } else {
   ledBrightness1 = ledBrightness1 - 50;
   ledBrightness2 = ledBrightness2 + 50;
   ledBrightness3 = ledBrightness3 - 50;
   ledBrightness4 = ledBrightness4 + 50;
 }
 }
prevDistanceValue2 = distanceValue2;
}
*/
