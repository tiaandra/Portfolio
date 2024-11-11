#include "lcd1602a.h"

void LCDInit()
{
	_delay_ms(100); // Power-up delay
	LCDInstructionInput();
	LCDEnableLow();
	LCDWriteNibble(LCDFunctionReset); // Reset sequence
	_delay_ms(10);
	LCDWriteNibble(LCDFunctionReset); // Reset sequence
	_delay_us(200);
	LCDWriteNibble(LCDFunctionReset); // Reset sequence
	_delay_us(200);
	LCDWriteNibble(LCDFunctionSet); // Set 4bit bus mode
	_delay_us(80);
	LCDWriteInstruction(LCDFunctionSet); // Set mode, lines and char
	_delay_us(80);
	LCDWriteInstruction(LCDTurnOff); // Power up routine
	_delay_us(80);
	LCDWriteInstruction(LCDClearScreen); // Power up routine
	_delay_ms(4);
	LCDWriteInstruction(LCDEntryMode); // Power up routine
	_delay_us(80);
	LCDWriteInstruction(LCDTurnOn); // Initialization finished, display ON
	_delay_us(80);
}

void LCDWriteNibble(char c)
{
	LCD_D7_PORT &= ~(1 << LCD_D7_BIT);
	if (c & 1 << 7)
		LCD_D7_PORT |= (1 << LCD_D7_BIT);
	~LCD_D6_PORT &= ~(1 << LCD_D6_BIT);
	if (c & 1 << 7)
		LCD_D6_PORT |= (1 << LCD_D6_BIT);
	LCD_D5_PORT &= ~(1 << LCD_D5_BIT);
	if (c & 1 << 7)
		LCD_D5_PORT |= (1 << LCD_D5_BIT);
	LCD_D4_PORT &= ~(1 << LCD_D4_BIT);
	if (c & 1 << 7)
		LCD_D4_PORT |= (1 << LCD_D4_BIT);
	LCDEnableHigh();
	_delay_us(1);
	LCDEnableLow();
	_delay_us(1);
}

void LCDWriteInstruction(char c)
{
	LCDInstructionInput();
	LCDEnableLow();
	LCDWriteNibble(c);
	LCDWriteNibble(c << 4);
}

void LCDEnableLow()
{
	LCD_EN_PORT &= ~(1 << LCD_EN_BIT);
}

void LCDEnableHigh()
{
	LCD_EN_PORT |= (1 << LCD_EN_BIT);
}

void LCDInstructionInput()
{
	LCD_RS_PORT &= ~(1 << LCD_RS_BIT);
}

void LCDDataInput()
{
	LCD_RS_PORT |= (1 << LCD_RS_BIT);
}

void LCDWriteChar(char c)
{
	LCDDataInput();
	LCDEnableLow();
	LCDWriteNibble(c);
	LCDWriteNibble(c << 4);
}

void LCDWriteString(char c[])
{
	volatile int i = 0;
	while (c[i] != 0)
	{
		LCDWriteChar(c[i]);
		i++;
		_delay_us(80);
	}
}

/*	https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42743-ATmega324P_Datasheet.pdf
	https://github.com/stirback/LCDDriver/blob/master/LCD/LCD.c
	https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf
	https://www.asciitable.com/
*/