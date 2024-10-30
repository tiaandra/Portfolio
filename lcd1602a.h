#include <avr/io.h>
#include <util/delay.h>

#define LCDClear 0b00000001
#define LCDSecondLine 0b11000000
#define LCDResetCursor 0b00000010
#define LCDCursorRight 0b00010100
#define LCDCursorLeft 0b00010000
#define LCDDisplayRight 0b00011100
#define LCDDisplayLeft 0b00011000
#define LCDFunctionSet 0b00101000
#define LCDTurnOn 0b00000110
#define LCDShift 0b00001110

#define D0 PORTC0 
#define D1 PORTC1
#define D2 PORTC2
#define D3 PORTC3
#define D4 PORTC0
#define D5 PORTC1
#define D6 PORTC2
#define D7 PORTC3

#define MaskD0 0b00000001
#define MaskD1 0b00000010
#define MaskD2 0b00000100
#define MaskD3 0b00001000
#define MaskD4 0b00010000
#define MaskD5 0b00100000
#define MaskD6 0b01000000
#define MaskD7 0b10000000

#define RS PORTC4
#define E PORTC5

void LCDInit();
void LCDSendCommand(char command);
void LCDPrintString(char *string);
void LCDPrintCharToPin(char c);
void LCDSetPin(char c, uint8_t port, uint8_t mask);
void LCDDataInput();
void LCDInstructionInput();
void LCDDisableSignal();
void LCDEnableSignal();