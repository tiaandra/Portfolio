#include "hardware/uart.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>

#define DS18B20 22 // The sensor is connected to GP22

#define DS18B20_SearchRom 0xF0
#define DS18B20_ReadRom 0x33
#define DS18B20_MatchRom 0x55
#define DS18B20_SkipRom 0xCC
#define DS18B20_AlarmSearch 0xEC

#define DS18B20_ConvertT 0x44
#define DS18B20_WriteScratchpad 0x4E
#define DS18B20_ReadScratchpad 0xBE
#define DS18B20_CopyScratchpad 0x48
#define DS18B20_RecallE2 0xB8
#define DS18B20_ReadPowerSupply 0xB4

#define DS18B20_Resolution9 0x1F
#define DS18B20_Resolution10 0x3F
#define DS18B20_Resolution11 0x5F
#define DS18B20_Resolution12 0x7F

unsigned int DS18B20_Reset();
void DS18B20_Set();
void DS18B20_Release();
unsigned char DS18B20_ReadBit();
unsigned char DS18B20_ReadByte();
void DS18B20_WriteBit(unsigned char c);
void DS18B20_WriteByte(char byte);
float DS18B20_GetTemperature();