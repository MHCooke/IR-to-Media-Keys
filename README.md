# IR-to-Media-Keys
Intercepts IR signals from a stereo remote control using an Arduino.

# Requirements
This code uses [IRLib2](https://github.com/cyborg5/IRLib2) for Arduino, and [keyboard](https://pypi.org/project/keyboard/) and [pySerial](https://pypi.org/project/pyserial/) for Python 3.

## Pinout
Vishay TSOP31238 pin 3 to Arduino pin 2. Other combined receivers and op-amps may work as well.

# Future Improvements
Change code to emulate a HID keyboard and send media key presses itself.
