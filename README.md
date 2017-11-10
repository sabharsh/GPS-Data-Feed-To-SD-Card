# GPS-Data-Feed-To-SD-Card

Basic Description: This program is for an Arduino Nano. Its primary function is to parse through GPS Data Feed and write it to an SD Card  in a tabular format.

# Components need to run code

1. Arduino Nano (and Arduino IDE installed on PC)
2. WaveShare GPS Sensor (or any other Arduino compatible M-6 or 7 GPS sensor)
3. Spark Fun SD card breakout board
4. Preferably a breadboard or pyboard

# Execution

1. Install the TinyGPS++ and the Arduino SD libary on you PC. The links are as follows:
        https://github.com/codegardenllc/tiny_gps_plus
        https://www.arduino.cc/en/Reference/SD

2. Build the circuit using the schematics of your particular components (check pin specifications from the code).
3. Open the project using the Arduino IDE.
4. Choose the port to which your Arduino is connected.
5. Upload the code to the Arduino.
6. Open the serial terminal to run program.
