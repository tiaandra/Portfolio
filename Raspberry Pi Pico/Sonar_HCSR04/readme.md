LED connected to GPIO 0

HCSR04 pins:
    TRIG connected to GPIO 26
    ECHO connected to GPIO 27

LED has a 220Ohm resistor

System's powered by Micro-USB cable connected to PC working at 3.3V

HCSR04 has issues reading values while working at 3.3V, it is advised to power it with 5V and use resistors to prevent GPIO damage.