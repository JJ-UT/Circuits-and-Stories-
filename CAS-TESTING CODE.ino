const int ledPin = 9;

const int buttonPin = 2;

int prevButtonState = 0;
int buttonState = 0;

bool isOn = false;


//SERVOS

#include <Servo.h>

Servo tServo;



void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  tServo.attach(9);
 
}

void loop() {

  //ON
  if (buttonState != prevButtonState) {
    if (buttonState == HIGH) {
      Serial.println("PRESSED");
      isOn = !isOn;
    }
  }

  if (isOn == true) {
    tServo.write(180); // DO NOT GO PAST 180

    

  } else {
    //OFF
    tServo.write(0);
  }

  prevButtonState = buttonState;
}



