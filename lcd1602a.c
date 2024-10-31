#include "lcd1602a.h"

void LCDInit()
{
	_delay_ms(20);
	LCDSendCommand(LCDReturnHome);
	LCDSendCommand(LCDFunctionSet);
	LCDSendCommand(LCDTurnOn);
	LCDSendCommand(LCDShift);
	LCDSendCommand(LCDClear);
	_delay_ms(2);
}

void LCDSendCommand(char command)
{
	LCDInstructionInput();
	LCDPrintCharToPin(command);
}

/*void LCDPrintCharToPin(char c)
{
	LCDResetSignal();
	LCDSetPin(c, D7, MaskD7);
	LCDSetPin(c, D6, MaskD6);
	LCDSetPin(c, D5, MaskD5);
	LCDSetPin(c, D4, MaskD4);
	LCDResetSignal();
	LCDSetPin(c, D3, MaskD3);
	LCDSetPin(c, D2, MaskD2);
	LCDSetPin(c, D1, MaskD1);
	LCDSetPin(c, D0, MaskD0);
	_delay_ms(1);
}

void LCDSetPin(char c, uint8_t port, uint8_t mask)
{
	if ((c & mask) != 0)
		PORTC |= (1 << port);
	else
		PORTC &= ~(1 << port);
}*/

void LCDPrintCharToPin(char c)
{
	LCDResetSignal();
	PORTC = (PORTC & 0x0F) | (c & 0xF0);
	LCDResetSignal();
	PORTC = (PORTC & 0x0F) | (c << 4);
	_delay_ms(1);
}

void LCDInstructionInput()
{
	PORTC &= ~(1 << RS);
	_delay_ms(1);
}

void LCDDataInput()
{
	PORTC |= (1 << RS);
	_delay_ms(1);
}

void LCDResetSignal()
{
	PORTC &= ~(1 << E);
	_delay_ms(1);
	PORTC |= (1 << E);
	_delay_ms(1);
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