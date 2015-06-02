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
 *  https://github.com/xiam/arduino-irdebug
 *  http://techdocs.altium.com/display/ADRR/NEC+Infrared+Transmission+Protocol
 *  http://en.wikipedia.org/wiki/Apple_Remote
* */

#ifndef MAKERWORKSHOP_APPLE_REMOTE
#define MAKERWORKSHOP_APPLE_REMOTE

#include <IRDump.h>

#define APPLE_REMOTE_LEADER     9000, 4500
#define APPLE_REMOTE_B0          560,  560
#define APPLE_REMOTE_B1          560, 1690
#define APPLE_REMOTE_STOP        560,    0
#define APPLE_REMOTE_RELEADER   9000, 2250

#define APPLE_REMOTE_H0         APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B0  // 0x00
#define APPLE_REMOTE_H1         APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B0  // 0x01
#define APPLE_REMOTE_H2         APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B0  // 0x02
#define APPLE_REMOTE_H3         APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B0  // 0x03
#define APPLE_REMOTE_H4         APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B0  // 0x04
#define APPLE_REMOTE_H5         APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B0  // 0x05
#define APPLE_REMOTE_H6         APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B0  // 0x06
#define APPLE_REMOTE_H7         APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B0  // 0x07
#define APPLE_REMOTE_H8         APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B1  // 0x08
#define APPLE_REMOTE_H9         APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B1  // 0x09
#define APPLE_REMOTE_HA         APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B1  // 0x0A
#define APPLE_REMOTE_HB         APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B1  // 0x0B
#define APPLE_REMOTE_HC         APPLE_REMOTE_B0, APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B1  // 0x0C
#define APPLE_REMOTE_HD         APPLE_REMOTE_B1, APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B1  // 0x0D
#define APPLE_REMOTE_HE         APPLE_REMOTE_B0, APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B1  // 0x0E
#define APPLE_REMOTE_HF         APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B1, APPLE_REMOTE_B1  // 0x0F

#define APPLE_CUSTOM_CODE       APPLE_REMOTE_HE, APPLE_REMOTE_HE, APPLE_REMOTE_H7, APPLE_REMOTE_H8  // 0xEE, 0X87

#define APPLE_REMOTE_MODEL_A    0xc7
#define APPLE_REMOTE_MODEL_B    0xcf

#define APPLE_REMOTE_A_ID             APPLE_REMOTE_HF, APPLE_REMOTE_HC          // 0xCF
#define APPLE_REMOTE_A_CODE_MENU      APPLE_REMOTE_H2, APPLE_REMOTE_H0          // 0x02
#define APPLE_REMOTE_A_CODE_RIGHT     APPLE_REMOTE_H7, APPLE_REMOTE_H0          // 0x07
#define APPLE_REMOTE_A_CODE_LEFT      APPLE_REMOTE_H8, APPLE_REMOTE_H0          // 0x08
#define APPLE_REMOTE_A_CODE_UP        APPLE_REMOTE_HB, APPLE_REMOTE_H0          // 0x0B
#define APPLE_REMOTE_A_CODE_DOWN      APPLE_REMOTE_HD, APPLE_REMOTE_H0          // 0x0D
#define APPLE_REMOTE_A_CODE_PLAY      APPLE_REMOTE_HE, APPLE_REMOTE_H5          // 0x5E
#define APPLE_REMOTE_A_CODE_CENTER    APPLE_REMOTE_HD, APPLE_REMOTE_H5          // 0x5D

#define APPLE_REMOTE_B_ID             APPLE_REMOTE_H7, APPLE_REMOTE_HC          // 0xC7
#define APPLE_REMOTE_B_CODE_MENU      APPLE_REMOTE_H3, APPLE_REMOTE_H0          // 0x03
#define APPLE_REMOTE_B_CODE_RIGHT     APPLE_REMOTE_H6, APPLE_REMOTE_H0          // 0x06
#define APPLE_REMOTE_B_CODE_LEFT      APPLE_REMOTE_H9, APPLE_REMOTE_H0          // 0x09
#define APPLE_REMOTE_B_CODE_UP        APPLE_REMOTE_HA, APPLE_REMOTE_H0          // 0x0A
#define APPLE_REMOTE_B_CODE_DOWN      APPLE_REMOTE_HC, APPLE_REMOTE_H0          // 0x0C
#define APPLE_REMOTE_B_CODE_PLAY      APPLE_REMOTE_HF, APPLE_REMOTE_H5          // 0x5F
#define APPLE_REMOTE_B_CODE_CENTER    APPLE_REMOTE_HC, APPLE_REMOTE_H5          // 0x5C

// #define APPLE_REMOTE_SIGNAL(id, code) APPLE_REMOTE_LEADER, APPLE_CUSTOM_CODE, code, id, APPLE_REMOTE_STOP

#define APPLE_REMOTE_MENU   0
#define APPLE_REMOTE_RIGHT  1
#define APPLE_REMOTE_LEFT   2
#define APPLE_REMOTE_UP     3
#define APPLE_REMOTE_DOWN   4
#define APPLE_REMOTE_PLAY   5
#define APPLE_REMOTE_CENTER 6
#define APPLE_REMOTE_REPEAT 7

#define APPLE_REMOTE_SIGNALS (APPLE_REMOTE_REPEAT + 1)

#define APPLE_REMOTE_KHZ                    38
#define APPLE_REMOTE_SIGNAL_SIZE            68
#define APPLE_REMOTE_SIGNAL_REPEAT_SIZE     4

#define APPLE_REMOTE_THRESHOLD      150

#define APPLE_REMOTE_BODY_OFFSET    34
#define APPLE_REMOTE_ID_OFFSET      50

class AppleRemote {
private:
  IRDump *irdump;
  int pin;
  int model;
  void send(int code);
  void set(unsigned int *signal, int code);
  void memcpy16(unsigned int *signal, int offset,
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
    unsigned int af);

public:
  AppleRemote(int pin, int model);

  void Menu();
  void Right();
  void Left();
  void Up();
  void Down();
  void Play();
  void Center();
  void Repeat();

  int Match(unsigned int *);
};

#endif
