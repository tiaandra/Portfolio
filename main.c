#define F_CPU 8000000UL
#include <avr/io.h>
#include "lcd1602a.h"
#include "ds18b20.h"

void MicroInit();

int main()
{
    MicroInit();
    char *temperatura;
    DS18B20_ReadTemp(temperatura);
    LCDWriteString("Temperatura");
    LCDWriteInstruction(LCDSecondLine);
    LCDWriteString(temperatura);
    while (1)
    {
    }
    return 0;
}

void MicroInit()
{
    LCD_D7_DDR |= (1 << LCD_D7_BIT);
    LCD_D6_DDR |= (1 << LCD_D6_BIT);
    LCD_D5_DDR |= (1 << LCD_D5_BIT);
    LCD_D4_DDR |= (1 << LCD_D4_BIT);
    LCD_EN_DDR |= (1 << LCD_EN_BIT);
    LCD_RS_DDR |= (1 << LCD_RS_BIT);
    LCDInit();
};