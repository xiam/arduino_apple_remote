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

/*
 * See:
 *  https://github.com/makerworkshop/arduino_irdump
 *  http://techdocs.altium.com/display/ADRR/NEC+Infrared+Transmission+Protocol
 *  http://en.wikipedia.org/wiki/Apple_Remote
* */

#include <AppleRemote.h>

unsigned int apple_remote_signal_wrapper[APPLE_REMOTE_SIGNAL_SIZE] = {
  APPLE_REMOTE_LEADER,  // 2
  APPLE_CUSTOM_CODE,    // 32

  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,           // 16

  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,           // 16

  APPLE_REMOTE_STOP     // 2
};

unsigned int apple_remote_signal_repeat[APPLE_REMOTE_SIGNAL_REPEAT_SIZE] = {
  APPLE_REMOTE_RELEADER,
  APPLE_REMOTE_STOP
};

AppleRemote::AppleRemote(int pin, int model)
{
  this->irdump = new IRDump();
  this->model = model;
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
}

void AppleRemote::send(int code)
{
  unsigned int s[APPLE_REMOTE_SIGNAL_SIZE];
  unsigned int *z;

  z = (unsigned int *)s;

  this->set(z, code);

  this->irdump->Emit(this->pin, z, APPLE_REMOTE_KHZ);
}

void AppleRemote::Menu()
{
  this->send(APPLE_REMOTE_MENU);
}

void AppleRemote::Right()
{
  this->send(APPLE_REMOTE_RIGHT);
}

void AppleRemote::Left()
{
  this->send(APPLE_REMOTE_LEFT);
}

void AppleRemote::Up()
{
  this->send(APPLE_REMOTE_UP);
}

void AppleRemote::Down()
{
  this->send(APPLE_REMOTE_DOWN);
}

void AppleRemote::Play()
{
  this->send(APPLE_REMOTE_PLAY);
}

void AppleRemote::Center()
{
  this->send(APPLE_REMOTE_CENTER);
}

void AppleRemote::Repeat()
{
  this->send(APPLE_REMOTE_REPEAT);
}

void AppleRemote::memcpy16(unsigned int *signal, int offset,
  unsigned int a0,
  unsigned int a1,
  unsigned int a2,
  unsigned int a3,
  unsigned int a4,
  unsigned int a5,
  unsigned int a6,
  unsigned int a7,
  unsigned int a8,
  unsigned int a9,
  unsigned int aa,
  unsigned int ab,
  unsigned int ac,
  unsigned int ad,
  unsigned int ae,
  unsigned int af)
{
  int i;
  unsigned int b[16] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, aa, ab, ac, ad, ae, af };

  for (i = 0; i < 16; i++) {
    signal[offset + i] = b[i];
  }
}

void AppleRemote::set(unsigned int *signal, int code)
{
  int i;

  if (code == APPLE_REMOTE_REPEAT) {
    for (i = 0; i < APPLE_REMOTE_SIGNAL_REPEAT_SIZE; i++) {
      signal[i] = apple_remote_signal_repeat[i];
    }
    return;
  }

  // Copying signal template.
  for (i = 0; i < APPLE_REMOTE_SIGNAL_SIZE; i++) {
    signal[i] = apple_remote_signal_wrapper[i];
  }

  if (this->model == APPLE_REMOTE_MODEL_A) {
    switch (code) {
      case APPLE_REMOTE_MENU:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_MENU);
      break;
      case APPLE_REMOTE_RIGHT:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_RIGHT);
      break;
      case APPLE_REMOTE_LEFT:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_LEFT);
      break;
      case APPLE_REMOTE_UP:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_UP);
      break;
      case APPLE_REMOTE_DOWN:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_DOWN);
      break;
      case APPLE_REMOTE_PLAY:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_PLAY);
      break;
      case APPLE_REMOTE_CENTER:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_A_CODE_CENTER);
      break;
    }
    this->memcpy16(signal, APPLE_REMOTE_ID_OFFSET, APPLE_REMOTE_A_ID);
  }

  if (this->model == APPLE_REMOTE_MODEL_B) {
    switch (code) {
      case APPLE_REMOTE_MENU:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_MENU);
      break;
      case APPLE_REMOTE_RIGHT:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_RIGHT);
      break;
      case APPLE_REMOTE_LEFT:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_LEFT);
      break;
      case APPLE_REMOTE_UP:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_UP);
      break;
      case APPLE_REMOTE_DOWN:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_DOWN);
      break;
      case APPLE_REMOTE_PLAY:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_PLAY);
      break;
      case APPLE_REMOTE_CENTER:
        this->memcpy16(signal, APPLE_REMOTE_BODY_OFFSET, APPLE_REMOTE_B_CODE_CENTER);
      break;
    }
    this->memcpy16(signal, APPLE_REMOTE_ID_OFFSET, APPLE_REMOTE_B_ID);
  }
}

int AppleRemote::Match(unsigned int *signal)
{
  int i, j;

  unsigned int s[APPLE_REMOTE_SIGNAL_SIZE];
  unsigned int *z;

  z = (unsigned int *)s;

  for (i = 0; i < APPLE_REMOTE_SIGNALS; i++) {
    this->set(z, i);
    if (this->irdump->Match(z, signal, APPLE_REMOTE_THRESHOLD)) {
      return i;
    }
  };

  return -1;
}
