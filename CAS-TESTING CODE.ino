const int ledPin = 9;

int pos;

const int buttonPin = 2;

int prevButtonState = 0;
int buttonState = 0;

bool isOn = false;

//Event booleans
bool event1 = false;
bool event2 = false;
bool event3 = false;
bool event4 = false;
bool event5 = false;

//SERVOS

#include <Servo.h>

int servDelay = 5;
Servo tServo;

//# variables
int angle;
const int min = 0;
const int max = 180;
int inc = 0.025;



void setup() {

  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  tServo.attach(9); /// SERVO PIN
 
}

//EVENT 1
void loop() {
buttonState = digitalRead(buttonPin);
Serial.println(angle);

  //ON
  if (buttonState != prevButtonState) {
    if (buttonState == HIGH) {
      Serial.println("ON");
      isOn = !isOn;
    

    }
  }

  if (isOn == true) {
    event1 = true;
    

    for ( pos = 0; pos<=120; pos = pos + 1.5) {
         tServo.write(pos); 
         delay(servDelay);
    }

    for ( pos = 120; pos>=0; pos = pos - 1.5) {
        tServo.write(pos); 
        delay(servDelay);

    }

  } else {
    //OFF
    tServo.write(0);
    Serial.println("OFF");


  }

  prevButtonState = buttonState;
}


