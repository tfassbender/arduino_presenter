#include <RCSwitch.h>

RCSwitch rcSwitch = RCSwitch();

// set pin numbers for the five buttons:
const int leftButton = 4;
const int rightButton = 3;
const int f5Button = 2;

const int LEFT_BUTTON_SEND_CODE = 4742;
const int RIGHT_BUTTON_SEND_CODE = 4743;
const int F5_BUTTON_SEND_CODE = 4744;
const int SEND_BITS = 16;

void setup() {
  // initialize the buttons' inputs:
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(f5Button, INPUT);

  // Sendemodul an dem digitalen PIN 10 angeschlossen.
  rcSwitch.enableTransmit(10);
}

void loop() {
  if (digitalRead(leftButton) == HIGH) {
    rcSwitch.send(LEFT_BUTTON_SEND_CODE, SEND_BITS);
  }
  if (digitalRead(rightButton) == HIGH) {
    rcSwitch.send(RIGHT_BUTTON_SEND_CODE, SEND_BITS);
  }
  if (digitalRead(f5Button) == HIGH) {
    rcSwitch.send(F5_BUTTON_SEND_CODE, SEND_BITS);
  }

  //rcSwitch.send(42, 16);

  delay(250);
}
