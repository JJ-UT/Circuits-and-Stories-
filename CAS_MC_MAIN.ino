////////// Variables //////////

const int ledPin = 9;

/// Buttons///////////

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 12;



int prevButtonState1 = 0;
int buttonState1 = 0;

int prevButtonState2 = 0;
int buttonState2 = 0;

int prevButtonState3 = 0;
int buttonState3 = 0;

int prevButtonState4 = 0;
int buttonState4 = 0;

int prevButtonState5 = 0;
int buttonState5 = 0;

////// BOOLEANS/////////////
///////////////////////////

bool isOn = false;
bool isOn2 = false;
bool isOn3 = false;
bool isOn4 = false;
bool isOn5 = false;

//Event booleans////////////////////////
//////////////////////////////////////
bool event1 = false;
bool event2 = false;
bool event3 = false;
bool event4 = false;
bool event5 = false;

//SERVOS////////////////////////////////
///////////////////////////////////////

#include <Servo.h>

int servDelay = 5;
Servo servoE1;
Servo servoE2;
Servo servoE3;
Servo servoE4;
Servo servoE5;

int pos;
int pos2;



//# variables
int angle;
const int min = 0;
const int max = 180;
int inc = 0.025;



void setup() {


  pinMode(ledPin, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);


  Serial.begin(9600);

  servoE1.attach(6);   /// SERVO PIN
  servoE2.attach(7);   /// SERVO PIN
  servoE3.attach(8);   /// SERVO PIN
  servoE4.attach(11);   /// SERVO PIN
  servoE5.attach(13);  /// SERVO PIN
}


void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);
  buttonState5 = digitalRead(button5);




  //Serial.println(angle);


  ///// EVENT 1//////////////////////////
  //////////////////////////////////////

  // If u want to edit any code and test buttons, place them in the respective "ON" location for each button.//

  //ON
  if (buttonState1 != prevButtonState1) {
    if (buttonState1 == HIGH) {
      Serial.println("button 1 on");
      isOn = !isOn;
    }
  }

  if (isOn == true) {
    event2 = true;


    for (pos = 0; pos <= 36.5; pos = pos + 1.5) {
      servoE1.write(pos);


    }

    for (pos = 36.5; pos >= 0; pos = pos - 1.5) {
      servoE1.write(pos);

    }

  } else {
    //OFF
    servoE1.write(0);
    //Serial.println("button 1OFF");



  }


  /////////////////////////////
  ///////// Event 2////////////
 //if (event2 == true) {
    if (buttonState2 != prevButtonState2) {
      if (buttonState2 == HIGH) {
        Serial.println("button 2 on ");
        isOn2 = !isOn2;
      }
      if (isOn2 == true) {
      //event3 = true;
        
        servoE2.write(90);

          

      



    } else {
      //OFF
       servoE2.write(0);
          Serial.println("button 2 off ");


    }
   }
  // }

  //// Event 3//////////////////
  //////////////////////////////

  //if (event3 == true) {
    if (buttonState3 != prevButtonState3) {
      if (buttonState3 == HIGH) {
        Serial.println("Button 3 on");
        isOn3 = !isOn3;
      }
       if (isOn3 == true) {  //ON
      //event4 = true;
      
                servoE3.write(90);







    } else {
      //OFF
             servoE3.write(0);

      Serial.println("Button 3 OFF");
    }
  }
//}

  /////////////// Event 4///////////////////////
  //////////////////////////////////////////////

  //if (event4 == true) {
    if (buttonState4 != prevButtonState4) {
      if (buttonState4 == HIGH) {
        Serial.println("Button 4 on");
        isOn4 = !isOn4;
      }
       if (isOn4 == true) {  //ON
      event5 = true;

        servoE4.write(60);

      





    } else {
      //OFF
        Serial.println("Button 4 OFF");
        servoE4.write(0);


    }
    }
//}

  ////////////// EVENT 5////////////////////
  //////////////////////////////////////////
  //if (event5 == true) {
    if (buttonState5 != prevButtonState5) {
      if (buttonState5 == HIGH) {
        Serial.println("Button 5 on");
        isOn5 = !isOn5;
      }
    }

    if (isOn5 == true) {  //ON
              servoE5.write(30);




    } else {
       //OFF

        Serial.println("Button 5  OFF");



              servoE5.write(0);


    }
  //}




  prevButtonState1 = buttonState1;
  prevButtonState2 = buttonState2;
  prevButtonState3 = buttonState3;
  prevButtonState4 = buttonState4;
  prevButtonState5 = buttonState5;
}
