#include <animationTools.h>


int D1 = 2200;
int D2 = 8000;                //interactive zone Distance
int d;                       //distance read from sensor
int prevd;
int dchange;
int absolchange;

long changetime;
long prevchangetime;
boolean suddenchange = false;

int chth = 15000;                    //sudden change threshold
int ichth = 100;                   //interactive change threshold

int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;
int ledPin4 = 12;
int ledPin5 = 3;

int SensorPin = 2;

int ledBrightness1 = 0;
int ledBrightness2 = 0;
int ledBrightness3 = 0;
int ledBrightness4 = 0;
int ledBrightness5 = 0;

long lastTimeYouBlinked1;
long lastTimeYouBlinked2;
long lastTimeYouBlinked3;
long lastTimeYouBlinked4;
long lastTimeYouBlinked5;

int ledblinkRate1;
int ledblinkRate2;
int ledblinkRate3;
int ledblinkRate4;
int ledblinkRate5;

boolean ledState1 = false;
boolean ledState2 = false;
boolean ledState3 = false;
boolean ledState4 = false;
boolean ledState5 = false;

float crazyFadeSpeed = 0.8;





void setup() {

//LEDs
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);

//Sensors
pinMode(SensorPin, INPUT);

Serial.begin(9600);

}








void loop() {

d = pulseIn(SensorPin, HIGH);

dchange = prevd - d;
absolchange = abs(dchange);

Serial.println(d);


////////////////////////////////////////////////////////////////////////pass
if (absolchange > chth){
  changetime = millis(); 
  suddenchange = true;
  }

if(suddenchange = true){
  pass();
  }

prevd = d;                         
prevchangetime = changetime;


//////////////////////////////////////////////////////////////////////uncomfortable interact
if (d > D1 && d < D2){
  if (d > D1 && d <= D1+((D2-D1)/3)){
    interact(50);
  }

  if (d > D1+((D2-D1)/3) && d <= D1+2*((D2-D1)/3)){
    interact(100);
  }

  if (d > D1 + 2 * ((D2 - D1) / 3) && d < D2){
    interact(200);
  }
}

if (d < D1){
  Crazy();
  }

}








void pass(){

int fadetime = 200;
int timepast = millis() - changetime;
int wavedelay = 100;


//led1
if(timepast < fadetime){
  ledBrightness1 = map(timepast, 0, fadetime, 0, 255);
  analogWrite(ledPin1, ledBrightness1);
  }
if(timepast > fadetime){
  ledBrightness1 = map(timepast, fadetime, fadetime*2, 255, 0);
  analogWrite(ledPin1, ledBrightness1);
  }
if(timepast > fadetime*2){
  analogWrite(ledPin1, 0);
  }


//led2
if(timepast < fadetime + wavedelay){
  ledBrightness2 = map(timepast, wavedelay, fadetime + wavedelay, 0, 255);
  analogWrite(ledPin2, ledBrightness2);
  }
if(timepast > fadetime + wavedelay){
  ledBrightness2 = map(timepast, fadetime + wavedelay, 2*fadetime+wavedelay, 255, 0);
  analogWrite(ledPin2, ledBrightness2);
  }
if(timepast > fadetime*2 + wavedelay){
  analogWrite(ledPin2, 0);
  }



//led3
if(timepast < fadetime + 2*wavedelay){
  ledBrightness3 = map(timepast, 2*wavedelay, fadetime + 2*wavedelay, 0, 255);
  analogWrite(ledPin3, ledBrightness3);
  }
if(timepast > fadetime + 2*wavedelay){
  ledBrightness3 = map(timepast, fadetime + 2*wavedelay, 2*fadetime+2*wavedelay, 255, 0);
  analogWrite(ledPin3, ledBrightness3);
  }
if(timepast > (fadetime*2 + 2*wavedelay)){
  analogWrite(ledPin3, 0);
  }


//led4
if(timepast < fadetime + 3*wavedelay){
  ledBrightness4 = map(timepast, 3*wavedelay, fadetime + 3*wavedelay, 0, 255);
  analogWrite(ledPin4, ledBrightness4);
  }
if(timepast > fadetime + 3*wavedelay){
  ledBrightness4 = map(timepast, fadetime + 3*wavedelay, 2*fadetime+3*wavedelay, 255, 0);
  analogWrite(ledPin4, ledBrightness4);
  }
if(timepast > (fadetime*2 + 3*wavedelay)){
  analogWrite(ledPin4, 0);
  }


//led5
if(timepast < fadetime + 4*wavedelay){
  ledBrightness5 = map(timepast, 4*wavedelay, fadetime + 4*wavedelay, 0, 255);
  analogWrite(ledPin5, ledBrightness5);
  }
if(timepast > fadetime + 4*wavedelay){
  ledBrightness5 = map(timepast, fadetime + 4*wavedelay, 2*fadetime+4*wavedelay, 255, 0);
  analogWrite(ledPin5, ledBrightness5);
  }
if(timepast > (fadetime*2 + 4*wavedelay)){
  analogWrite(ledPin5, 0);
  }


}














void interact(int beat) {
ledblinkRate1 = beat;
ledblinkRate2 = beat;
ledblinkRate3 = beat;
ledblinkRate4 = beat;
ledblinkRate5 = beat;

ledBrightness1 = map(d, D1, D2, 255, 0);
ledBrightness2 = map(d, D1, D2, 255, 0);
ledBrightness3 = map(d, D1, D2, 255, 0);
ledBrightness4 = map(d, D1, D2, 255, 0);
ledBrightness5 = map(d, D1, D2, 255, 0);



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

if(millis()-lastTimeYouBlinked5>=ledblinkRate5) {
  ledState5 = !ledState5;
    if(ledState5){
      analogWrite(ledPin5,ledBrightness5);
    }
    else {
      analogWrite(ledPin5,0);
    }
  lastTimeYouBlinked5 = millis();
}
}







void Crazy(){
ledBrightness1 = oscillate(0, 255, 0, crazyFadeSpeed, millis());
ledBrightness2 = oscillate(255, 0, 0, crazyFadeSpeed, millis());
ledBrightness3 = oscillate(0, 255, 70, crazyFadeSpeed, millis());
ledBrightness4 = oscillate(255, 0, 60, crazyFadeSpeed, millis());
ledBrightness5 = oscillate(255, 0, 60, crazyFadeSpeed, millis());
analogWrite(ledPin1, ledBrightness1);
analogWrite(ledPin2, ledBrightness2);
analogWrite(ledPin3, ledBrightness3);
analogWrite(ledPin4, ledBrightness4);
analogWrite(ledPin4, ledBrightness5);
}
