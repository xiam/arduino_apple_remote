// Copyright (c) 2014-2015 José Carlos Nieto, https://menteslibres.net/xiam
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <IRDump.h>
#include <AppleRemote.h>

#define SIGNAL_MAX_LENGTH 70

#define PIN_IR_INPUT      2
#define PIN_IR_OUTPUT     3

unsigned int signal[SIGNAL_MAX_LENGTH];

IRDump *irdumper;
AppleRemote *appleRemote;

void setup() {
  Serial.begin(115200);
  Serial.println("Apple Remote for Arduino.");

  appleRemote = new AppleRemote(PIN_IR_OUTPUT, APPLE_REMOTE_MODEL_A);
  irdumper = new IRDump();
}

void example_receive_signals() {
  unsigned int *s = signal;

  bool captured;
  int code;

  captured = irdumper->Capture(PIN_IR_INPUT, s, SIGNAL_MAX_LENGTH, 9500);

  if (captured) {

    code = appleRemote->Match(s);

    switch (code) {
      case APPLE_REMOTE_MENU:
        Serial.println("[menu]");
        break;
      case APPLE_REMOTE_RIGHT:
        Serial.println("[right]");
        break;
      case APPLE_REMOTE_LEFT:
        Serial.println("[left]");
        break;
      case APPLE_REMOTE_UP:
        Serial.println("[up]");
        break;
      case APPLE_REMOTE_DOWN:
        Serial.println("[down]");
        break;
      case APPLE_REMOTE_PLAY:
        Serial.println("[play]");
        break;
      case APPLE_REMOTE_CENTER:
        Serial.println("[center]");
        break;
      case APPLE_REMOTE_REPEAT:
        Serial.println("[repeat]");
        break;
      default:
        Serial.println("[?]");
    }
  }
}

void example_emit_signals() {

  // Getting to the main menu.
  Serial.println("Sending signal: menu.");
  appleRemote->Menu();
  delay(100);

  // Sending repeat code to scalate to the main menu.
  Serial.println("Sending signal: repeat.");
  appleRemote->Repeat();
  delay(100);
  appleRemote->Repeat();
  delay(100);
  appleRemote->Repeat();

  delay(2000);

  // Entering "movies"

  Serial.println("Sending signal: center.");
  appleRemote->Center();
  delay(2000);

  // Top-paid first movie.
  Serial.println("Sending signal: down.");
  appleRemote->Down();
  delay(2000);

  // Selecting movie.
  Serial.println("Sending signal: center.");
  appleRemote->Center();
  delay(2000);

  // Lanching preview.
  Serial.println("Sending signal: play.");
  appleRemote->Play();
  delay(10000);

  // Pausing preview.
  Serial.println("Sending signal: play.");
  appleRemote->Play();
  delay(2000);

  // Resuming preview.
  Serial.println("Sending signal: play.");
  appleRemote->Play();
  delay(5000);

  // Ok, going up again.
  Serial.println("Sending signal: menu.");
  appleRemote->Menu();
  delay(2000);

  // Moving right, rent ot buy it?
  Serial.println("Sending signal: right.");
  appleRemote->Right();
  delay(2000);

  // Nope, just playing.
  Serial.println("Sending signal: left.");
  appleRemote->Left();
  delay(2000);

  Serial.println("Sending signal: down.");
  appleRemote->Down();
  delay(2000);

  Serial.println("Sending signal: up.");
  appleRemote->Up();
  delay(2000);

  Serial.println("Sending signal: play.");
  appleRemote->Play();
  delay(10000);

  Serial.println("Waiting a minute.");

  delay(10000);
}

void loop() {
  // This example receives and decodes Apple Remote signals.
  example_receive_signals();

  // This example emits Apple Remote codes to an AppleTV receiver.
  // example_emit_signals();
}
