# Example project for the Apple Remote library for Arduino

![apple-remote](https://cloud.githubusercontent.com/assets/385670/8023793/26128b18-0ce0-11e5-8671-54fcc06c3e75.jpg)

This is an example project for the [Apple Remote][1] library. Throughout this
example you'll learn how to use the library to print the name of the pressed
button into the screen.

## Hardware

![ir debugger_picture](https://cloud.githubusercontent.com/assets/385670/8024906/3774e5a2-0d0a-11e5-8785-e1bf2faaa0dc.jpg)

We're going to use the same hardware setup that we used for the [IRDump
example][3].

## Software

### Prerequisites

1. [Arduino IDE 1.6+][4].

### Getting up a project copy

1. Install the [IRDump][2] and the [AppleRemote][1] libraries.
2. Open the `SendAndReceiveButtonCodes.ino` file with the Arduino IDE.
3. Verify and upload the code to the board.
4. Click the "Serial Monitor" command in the Arduino's IDE tools menu to bring
   on the serial monitor.
5. Change the baud rate to `115200 baud`.

Point a remote controller to the IR sensor and press any key. You'll see the
name of the button you pressed printed in the serial console.

```
Apple Remote for Arduino.

[menu]
[play]
[repeat]
...
```

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

[1]: https://github.com/makerworkshop/arduino_apple_remote
[2]: https://github.com/makerworkshop/arduino_irdump
[3]: https://github.com/makerworkshop/arduino_irdump/tree/master/examples/CaptureAndReplay
[4]: https://www.arduino.cc/en/Main/Software
