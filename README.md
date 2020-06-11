# IR to Media Keys
There is two versions of this project: one which runs just on the microcontroller, but requires an onboard USB controller. The other communicates with a Python program over serial.

# Requirements
## USB Mode
  - [IRLib2](https://github.com/cyborg5/IRLib2)
  - [HID-Project](https://github.com/NicoHood/HID)

## Serial Mode
  - Arduino
    - [IRLib2](https://github.com/cyborg5/IRLib2)
  - Python 3
    - [keyboard](https://pypi.org/project/keyboard/)
    - [pySerial](https://pypi.org/project/pyserial/)

## Pinout
Vishay TSOP31238 pin 3 to Arduino pin 2. Other combined receivers and op-amps may work as well.
