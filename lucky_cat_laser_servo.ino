
/* 
 Cat Mid-Term
 Physical Computing
 8 November 2012
 
 Anke Stohlmann, Deborah Koo, Rachelle Milne, Stephen Faletti
 
 */

#include <Servo.h> //import servo library

const int numCats = 4;
const int btnCount = 4;

int buttonVal = 0;
int buttonState = 0;
int prevState = 0;

unsigned long resetCounter = 0;
const int resetTime = 2000; //reset to front, in milliseconds

unsigned long debounceTimer = 0;
const int debounceDelay = 50;

Servo servoCat[numCats];

int catTurnVal0[] = {
  90, 90, 90, 90};
int catTurnVal1[] = {
  90, 100, 120, 140};
int catTurnVal2[] = {
  80, 90, 110, 130};
int catTurnVal3[] = {
  60, 80, 90, 110};
int catTurnVal4[] = {
  30, 60, 80, 90};

const int buttonPins[] = {
  2,3,4,5
};
const int servoPin[] = {
  8, 9, 10, 11
};

void setup() {
  for (int i=0; i<btnCount; i++) {  
    pinMode(buttonPins[i], INPUT_PULLUP); //set button pins as INPUT w/ internal pullup resistor
  }

  for (int i = 0; i < numCats; i++) { //setup servo pins
    servoCat[i].attach(servoPin[i]); 
    servoCat[i].write(90);
  }

  Serial.begin(9600);
}

void loop() {
  for (int i=0; i<btnCount; i++) { 
    if (digitalRead(buttonPins[i]) == LOW){
      buttonVal=i+1; //get reading from one of 4 pins. 0=no button.
      break; //if a button is pressed get on with life
    }
    else { //if no buttons are pressed
      buttonVal = 0;
    }
  }
  Serial.print("buttonVal: ");
  Serial.println(buttonVal);

  if(buttonState != buttonVal){ 
    buttonState = buttonVal; //set the buttonState to the current pressed button. Ignore if this button is already pressed
    Serial.print("buttonState: ");
    Serial.println(buttonState);
    if (buttonState > 0){
      resetCounter = millis(); //set reset counter in case no button is pressed after this
      if (buttonState != prevState){ // if the cats are already not looking at that button, or it's not held down
        turnCats(buttonState); //run the turn function
        Serial.println("buttonpressed");
        prevState = buttonState; //upate the current position
      }
    }
  }
  /*when no button has been pressed for the reset delay time
   also make sure that this does not run continuously while no button is pressed*/
  if (buttonState == 0 && (millis() - resetCounter) >= resetTime && prevState > 0){
    turnCats(0); //cats face front
    Serial.println("forward");
    prevState = 0; //update the current position
  }
}

void turnCats(int faceVal){
  switch(faceVal){
    case(0):
    servoSettings(catTurnVal0);
    break;
    case (1):
    servoSettings(catTurnVal1);
    break;
    case(2):
    servoSettings(catTurnVal2);
    break; 
    case(3):
    servoSettings(catTurnVal3);
    break;
    case(4):
    servoSettings(catTurnVal4);
    break;
  }
  //TODO implement light function at end of turn. Need LED string
}

void servoSettings(int servoPos[]){
  for (int i=0; i<4; i++){
    servoCat[i].write(servoPos[i]);
  }
}






























