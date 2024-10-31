#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCDClearScreen 0x01  // Clears screen
#define LCDReturnHome 0x02   // Return cursor to first line first char
#define LCDFunctionSet 0x28  // Display in 4-bit bus mode, 2 lines and 5x7 dots char
#define LCDTurnOn 0x0c       // Turns display on with cursor off
#define LCDTurnOff 0x08      // Turns display off
#define LCDEntryMode 0x06    // Cursor moves right on read/write
#define LCDReset 0x30        // Reset LCD
#define LCDFirstLine 0x80    // Forces cursor to the beginning of 1st line
#define LCDSecondLine 0xc0   // Forces cursor to the beginning of 2nd line
#define LCDCursorRight 0x14  // Moves cursor right by one char
#define LCDCursorLeft 0x10   // Moves cursor left by one char
#define LCDDisplayRight 0x1c // Moves display right by one char
#define LCDDisplayLeft 0x18  // Moves display left by one char

#define LCDPort PORTC

#define RS PORTC4
#define E PORTC5

void LCDInit();
void LCDSendCommand(char command);
void LCDPrintString(char *string);
void LCDPrintCharToPin(char c);
void LCDDataInput();
void LCDInstructionInput();
void LCDWriteData();