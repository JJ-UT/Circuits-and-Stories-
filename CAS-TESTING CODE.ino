const int ledPin = 9;

const int buttonPin = 2;

int prevButtonState = 0;
int buttonState = 0;

bool isOn = false;

//Crazy? I was crazy once. They locked me in a room. A rubber room! 
//A rubber room with rats,and rats make me crazy. 
//Crazy? I was crazy once. They locked me in a ro- 

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
 
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

    

  } else {
    //OFF

  }

  prevButtonState = buttonState;
}



