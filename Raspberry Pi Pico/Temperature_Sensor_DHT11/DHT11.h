#include <stdio.h>
#include "pico/stdlib.h"

#define DHT11 1 //DHT11 Sensor is connected to GPIO 1

int GetValues(float *temperature, float *humididy);
uint8_t ReadByte();