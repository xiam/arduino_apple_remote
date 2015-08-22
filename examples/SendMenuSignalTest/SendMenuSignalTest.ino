#include <AppleRemote.h>

// PWM~ PIN (an IR LED)
#define PIN_IR_OUTPUT 3

AppleRemote *appleRemote;

void setup() {
  // We can pass either APPLE_REMOTE_MODEL_A or APPLE_REMOTE_MODEL_B to define
  // the Apple Remote model we want to use.
  appleRemote = new AppleRemote(PIN_IR_OUTPUT, APPLE_REMOTE_MODEL_A);
}

void loop() {
  // Sends the IR signal that corresponds to the menu button in the Apple
  // Remote.
  appleRemote->Menu();
  delay(10000);
}
