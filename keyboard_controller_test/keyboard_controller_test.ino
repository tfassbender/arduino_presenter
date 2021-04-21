#include "Keyboard.h"

// set pin numbers for the five buttons:
const int leftButton = 2;
const int rightButton = 3;
const int f5Button = 4;

void setup() { // initialize the buttons' inputs:
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(f5Button, INPUT);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // use the pushbuttons to control the keyboard:
  if (digitalRead(leftButton) == HIGH) {
    Keyboard.write(KEY_LEFT_ARROW);
  }
  if (digitalRead(rightButton) == HIGH) {
    Keyboard.write(KEY_RIGHT_ARROW);
  }
  if (digitalRead(f5Button) == HIGH) {
    Keyboard.write(KEY_F5);
  }
  
  delay(250);
}
