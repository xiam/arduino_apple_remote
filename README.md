# Arduino library for the Apple Remote

The [Apple Remote][1] is a remote control device that can be used to send
instructions to a variety of Apple products, such as the Apple TV.

![apple-remote](https://cloud.githubusercontent.com/assets/385670/8023793/26128b18-0ce0-11e5-8671-54fcc06c3e75.jpg)

The primary purpose of this library is to emit [Apple Remote][1] infrared
pulses that mimic those produced by the [Apple Remote][1] using an
Arduino-compatible board and an IR LED

```arduino
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
```

This Arduino library can also recognize [Apple Remote][1] pulses sent by an
actual controller with a little help from [IRDump][2] and an IR receiver.

## Usage

```c++
class AppleRemote {
private:
  /* Omitted */

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
```

## Example project

See the [Apple Remote example][3] for a fully working example project.

## How to install

Download the latest [.ZIP package][4] and follow the official instructions on
[importing a .ZIP library][5].


## License

> The MIT License (MIT)
>
> Copyright (c) 2014-2015 José Carlos Nieto, https://menteslibres.net/xiam
>
> Permission is hereby granted, free of charge, to any person obtaining
> a copy of this software and associated documentation files (the
> "Software"), to deal in the Software without restriction, including
> without limitation the rights to use, copy, modify, merge, publish,
> distribute, sublicense, and/or sell copies of the Software, and to
> permit persons to whom the Software is furnished to do so, subject to
> the following conditions:
>
> The above copyright notice and this permission notice shall be
> included in all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
> EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
> MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
> NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
> LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
> OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
> WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[1]: http://en.wikipedia.org/wiki/Apple_Remote
[2]: https://github.com/makerworkshop/arduino_irdump
[3]: https://github.com/makerworkshop/arduino_apple_remote_example
[4]: https://github.com/makerworkshop/arduino_apple_remote/archive/master.zip
[5]: https://www.arduino.cc/en/Guide/Libraries
