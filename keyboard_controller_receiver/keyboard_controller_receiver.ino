#include "Keyboard.h"
#include <RCSwitch.h>

RCSwitch rcSwitch = RCSwitch();

const int LEFT_BUTTON_SEND_CODE = 4742;
const int RIGHT_BUTTON_SEND_CODE = 4743;
const int F5_BUTTON_SEND_CODE = 4744;
const int SEND_BITS = 16;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();

  // Empfängermodul ist am digitalen PIN 3 angeschlossen (PIN 3 am Pro Micro, PIN 2 am Nano)
  // dies ist der Interrupt-Pin "0".
  rcSwitch.enableReceive(0);
}
 
void loop() {
  if (rcSwitch.available()){
    //Ausgabe des gelesenen Wertes
    int received = rcSwitch.getReceivedValue();
    int bitLength = rcSwitch.getReceivedBitlength();

    Serial.write("Received: ");
    Serial.write(received);
    Serial.write(" Bit-Length: ");
    Serial.write(bitLength);
    Serial.write("\n");
    
    if (bitLength == SEND_BITS) {
      if (received == LEFT_BUTTON_SEND_CODE) {
        Keyboard.write(KEY_LEFT_ARROW);
      }
      if (received == RIGHT_BUTTON_SEND_CODE) {
        Keyboard.write(KEY_RIGHT_ARROW);
      }
      if (received == F5_BUTTON_SEND_CODE) {
        Keyboard.write(KEY_F5);
      }
    }
    
    delay(250);//verhindert wiederhohltes weiterschalten
    
    //Zurücksetzen des Empfängers.
    rcSwitch.resetAvailable();
  }
}
