import keyboard, serial

arduino_serial = serial.Serial('COM7')

while True:
    command = arduino_serial.read_until().decode().strip()
    print(command)
    if command == "Stop" or command == "Pause/Play":
        keyboard.send(-179)
    elif command == "<<":
        keyboard.send(-177)
    elif command == ">>":
        keyboard.send(-176)
