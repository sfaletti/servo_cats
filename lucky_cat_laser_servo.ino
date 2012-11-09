
/* 
 Cat Mid-Term
 Physical Computing
 8 November 2012
 
 Anke Stohlmann, Deborah Koo, Rachelle Milne, Stephen Faletti
 
 */

#include <Servo.h> //import servo library
#include <Bounce.h> //import debounce library

const int numCats = 4;
Servo servoCat[numCats];

int pinCount = 4;
const int buttonPins[] = {
  6, 5, 4, 3
};
int pressedButton = 0;

const int servoPin[] = {
  8, 9, 10, 11
};

int front = 90;
int left = 45;
int right = 135;
int tweak = 10;

void setup() {

  for (int a = 0; a < pinCount; a++) {  
    pinMode(buttonPins[a], INPUT);
  }

  for (int f = 0; f < numCats; f++) {
    servoCat[f].attach(servoPin[f]); 
    servoCat[f].write(90);
  }
}

void loop() {

  for (int i = 0; i < numCats; i++) {
    if (digitalRead(buttonPins[i])) {
      
    }
  }
  
  
  
  
  for (int i=0; i<numCats; i++) {
    turnCatFront(i);
  }

  if (digitalRead(buttonPins[0])) {

    for (int i=0; i<numCats; i++) {
      turnCatLeft(i);
    }
  }

  if (digitalRead(buttonPins[1])) {

    turnCatRight(0);
    for (int i=1; i<(numCats-1); i++) {
      turnCatLeft(i);
    }
  }

  if (digitalRead(buttonPins[2])) {

    for (int i=0; i<(numCats-1); i++) {
      turnCatRight(i);
    }
    turnCatLeft(3);
  }

  if (digitalRead(buttonPins[3])) {

    for (int i=0; i<numCats; i++) {
      turnCatRight(i);
    }
  }

}

void turnCatLeft(int _x) {
  if (servoCat[_x].read() != left) {
    servoCat[_x].write(left);
  } 
  else if (servoCat[_x].read() == left) {
    servoCat[_x].write(left+tweak);
    servoCat[_x].write(left);
  }
}

void turnCatRight(int _x) {
  if (servoCat[_x].read() != right) {
    servoCat[_x].write(right);
  } 
  else if (servoCat[_x].read() == right) {
    servoCat[_x].write(right+tweak);
    servoCat[_x].write(right);
  }
}

void turnCatFront(int _x) {
  if (servoCat[_x].read() != front) {
    servoCat[_x].write(front);
  } 
  else if (servoCat[_x].read() == front) {
    servoCat[_x].write(front+tweak);
    servoCat[_x].write(front);
  }
}









