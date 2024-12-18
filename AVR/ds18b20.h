#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#define DS18B20_SearchRom 0xf0
#define DS18B20_ReadRom 0x33
#define DS18B20_MatchRom 0x55
#define DS18B20_SkipRom 0xcc
#define DS18B20_AlarmSearch 0xec

#define DS18B20_ConvertT 0x44
#define DS18B20_Write 0x4e
#define DS18B20_Read 0xbe
#define DS18B20_Copy 0x48
#define DS18B20_Recall 0xb8
#define DS18B20_ReadPS 0xb4

#define DS18B20_DDR DDRC
#define DS18B20_PORT PORTC
#define DS18B20_PIN PINC6
#define DS18B20_BIT PORTC6

#define DS18B20_WriteMode DS18B20_DDR &= ~(1 << DS18B20_BIT)
#define DS18B20_ReadMode DS18B20_DDR |= (1 << DS18B20_BIT)
#define DS18B20_Low DS18B20_DDR &= ~(1 << DS18B20_BIT)
#define DS18B20_High DS18B20_DDR |= (1 << DS18B20_BIT)

void DS18B20_WriteMode();
void DS18B20_ReadMode();
void DS18B20_Low();
void DS18B20_High();
uint8_t DS18B20_Reset();
void DS18B20_WriteBit(uint8_t bit);
uint8_t DS18B20_ReadBit();
uint8_t DS18B20_ReadByte();
uint8_t DS18B20_WriteByte(uint8_t byte);
void DS18B20_ReadTemp(char *temp);