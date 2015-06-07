# Arduino library for the Apple Remote control

The primary purpose of this library is to emit [Apple Remote][1] infrared
pulses using an Arduino-compatible board and an IR LED.

This library can also recognize [Apple Remote][1] pulses with a little help
from [IRDump][2] and an IR receiver.

## Sending a pulse

```arduino
#include <AppleRemote.h>

// The PWM~ PIN number that is connected to an IR LED
#define PIN_IR_OUTPUT 3

AppleRemote *appleRemote;

void setup() {
  // We can pass either APPLE_REMOTE_MODEL_A or APPLE_REMOTE_MODEL_B to define
  // the Apple Remote model we want to use.
  appleRemote = new AppleRemote(PIN_IR_OUTPUT, APPLE_REMOTE_MODEL_A);
}

void loop() {
  appleRemote->Menu();
  delay(10000);
}
```

## How to install

Create new a folder named `MakerWorkshop` within the Arduino's library folder.
If you're on a Mac it should be `Documents/Arduino/libraries/` on Linux it
probably would be in `/usr/share/arduino/libraries/`. If that folder already
exists you don't need to create it again.

Download and uncompress the latest [.ZIP package][4], a folder named
`arduino_apple_remote-master` will be created, rename the uncompressed folder
to `arduino_apple_remote` and put it into your recently created `MakerWorkshop`
folder.

That's all! this library should be ready to use in your projects now. See the
Arduino's documentation on [importing libraries][3] whenever you're in doubt.

## Quick start

See the [example project][1] for a quick start and wiring diagrams.

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

[1]: https://github.com/makerworkshop/arduino_apple_remote_example
[2]: https://github.com/makerworkshop/arduino_irdump
[3]: http://www.arduino.cc/en/guide/libraries
[4]: https://github.com/makerworkshop/arduino_apple_remote/archive/master.zip
