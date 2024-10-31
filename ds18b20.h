#include <util/delay.h>

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
#define DS18B20_PIN PINC5
#define DS18B20_P PC5

#define DS18B20_WriteMode DS18B20_DDR &= ~(1 << DS18B20_PIN)
#define DS18B20_ReadMode DS18B20_DDR |= (1 << DS18B20_PIN)
#define DS18B20_Low DS18B20_DDR &= ~(1 << DS18B20_PIN)
#define DS18B20_High DS18B20_DDR |= (1 << DS18B20_PIN)