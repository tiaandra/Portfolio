#include "lcd1602a.h"

void LCDInit()
{
	_delay_ms(40);
	LCDSendCommand(LCDReset);
	_delay_ms(10);
	LCDSendCommand(LCDReset);
	_delay_us(150);
	LCDSendCommand(LCDReset);
	_delay_us(200);
	LCDSendCommand(LCDFunctionSet);
	LCDSendCommand(LCDTurnOff);
	LCDSendCommand(LCDClearScreen);
	LCDSendCommand(LCDEntryMode);
	LCDSendCommand(LCDTurnOn);
	_delay_ms(2);
}

void LCDSendCommand(char command)
{
	LCDInstructionInput();
	LCDPrintCharToPin(command);
}

void LCDPrintCharToPin(char c)
{
	LCDWriteData();
	LCDPort = (LCDPort & 0x0F) | (c & 0xF0);
	LCDWriteData();
	LCDPort = (LCDPort & 0x0F) | (c << 4);
	_delay_ms(2);
}

void LCDInstructionInput()
{
	LCDPort &= ~(1 << RS);
	_delay_ms(2);
}

void LCDDataInput()
{
	LCDPort |= (1 << RS);
	_delay_ms(2);
}

void LCDWriteData()
{
	LCDPort |= (1 << E);
	_delay_ms(2);
	LCDPort &= ~(1 << E);
}

void LCDPrintString(char *string)
{
	LCDDataInput();
	while (*string != 0)
		LCDPrintCharToPin(*string++);
}

/*	https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42743-ATmega324P_Datasheet.pdf
	https://github.com/stirback/LCDDriver/blob/master/LCD/LCD.c
	https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf
	https://www.asciitable.com/
*/