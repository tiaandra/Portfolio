#define F_CPU 8000000UL
#include <avr/io.h>
#include "lcd1602a.h"

void main()
{
    MicroInit();
    LCDInit();
    LCDPrintString("Hello");
    LCDSendCommand(LCDSecondLine);
    LCDPrintString("Wordl");
    while (1)
    {
    }
}

void MicroInit()
{
    DDRC = 1;
}