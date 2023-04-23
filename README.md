# hardware-police-light
Getting back into hardware by creating a police light.
The police light has an on/off button and a pattern toggle button. 
Holding the pattern toggle button flashes the lights in a rapid alternate pattern.

# Hardware Requirements
- raspberry pi pico w/raspberry pi pico.
- 2 LEDs, preferably Red and Blue
- 2 push buttons
- 4 220 Ohm resistor
- wires
- breadboard

# Wiring instructions
Red LED connected to pin 16 and GND with a 220 Ohm resistor in series.
Blue LED connected to pin 15 and GND with a 220 Ohm resistor in series.
The 3.3V output of the pico connected to one of the ends of the push buttons.
The other end of the push buttons connected to the ground with 220 Ohm resistors. From this end, also draw wires to pin 12 for one (On/Off button), and pin 10 for the other (Pattern toggle button).

![circuit](https://user-images.githubusercontent.com/46511001/233819066-8c71dc7b-f2d6-4c1c-a37d-be6b7ac92736.png)

# Build instructions
Assuming that the pico sdk is set up properly.
- create a build folder and move into it.
- run cmake with optional -DPICO_BOARD=pico_w if using pi pico w
- run make
- copy coplight.uf2 file to raspberry pi pico
```
mkdir build
cmake -DPICO_BOARD=pico_w ..
make
```

# Demo
https://user-images.githubusercontent.com/46511001/233817653-f877f24e-64b4-447e-94d3-ab689b914290.mp4

# Reflecting Back
Good "Hello World!" type starting point for someone who had previously done some projects in school as part of Coursework.
Wiring could be better but focusing on the programming side of things for now.

### Future extensions possible with the pico w:
- Add buzzer for sound
- Report sent to an api showing when the lights were turned on and off

