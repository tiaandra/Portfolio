#define F_CPU 8000000UL
#include <avr/io.h>
#include "lcd1602a.h"

void main()
{
    MicroInit();
    LCDWriteString("Hello");
    LCDWriteInstruction(LCDSecondLine);
    LCDWriteString("World");
    while (1)
    {
    }
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