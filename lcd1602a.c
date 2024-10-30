#include "lcd1602a.h"

void LCDInit()
{
	LCDInstructionInput();
	LCDSendCommand(LCDFunctionSet);
	LCDSendCommand(LCDTurnOn);
	LCDSendCommand(LCDShift);
	LCDSendCommand(LCDClear);
}

void LCDSendCommand(char command)
{
	LCDInstructionInput();
	LCDPrintCharToPin(command);
}

void LCDPrintCharToPin(char c)
{
	LCDSetPin(c, D7, MaskD7);
	LCDSetPin(c, D6, MaskD6);
	LCDSetPin(c, D5, MaskD5);
	LCDSetPin(c, D4, MaskD4);
	LCDDisableSignal();
	LCDEnableSignal();
	LCDSetPin(c, D3, MaskD3);
	LCDSetPin(c, D2, MaskD2);
	LCDSetPin(c, D1, MaskD1);
	LCDSetPin(c, D0, MaskD0);
	_delay_us(1);
}

void LCDInstructionInput()
{
	PORTC = (0 << RS);
	_delay_us(1);
}

void LCDDataInput()
{
	PORTC = (1 << RS);
	_delay_us(1);
}

void LCDDisableSignal()
{
	PORTC = (0 << E);
	_delay_us(1);
}

void LCDDisableSignal()
{
	PORTC = (1 << E);
	_delay_us(1);
}

void LCDSetPin(char c, uint8_t port, uint8_t mask)
{
	(c & mask) != 0 ? PORTC = (1 << port) : PORTC = (0 << port);
}

void LCDPrintString(char *string)
{
	while (*string != 0)
		LCDPrintChar(*string++);
}

/*	https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42743-ATmega324P_Datasheet.pdf
	https://github.com/stirback/LCDDriver/blob/master/LCD/LCD.c
	https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf
	https://www.asciitable.com/
*/