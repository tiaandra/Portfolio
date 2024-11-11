#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCDClearScreen 0x01 // Clears screen
#define LCDReturnHome 0x02  // Return cursor to first line first char

#define LCDFunctionSet 0x28   // Display in 4-bit bus mode, 2 lines and 5x7 dots char
#define LCDFunctionReset 0x30 // Reset LCD

#define LCDTurnOn 0x0c  // Turns display on with cursor off
#define LCDTurnOff 0x08 // Turns display off

#define LCDEntryMode 0x06 // Cursor moves right on read/write

#define LCDFirstLine 0x80  // Forces cursor to the beginning of 1st line
#define LCDSecondLine 0xc0 // Forces cursor to the beginning of 2nd line

#define LCDCursorRight 0x14  // Moves cursor right by one char
#define LCDCursorLeft 0x10   // Moves cursor left by one char
#define LCDDisplayRight 0x1c // Moves display right by one char
#define LCDDisplayLeft 0x18  // Moves display left by one char

#define LCD_D4_PORT PORTC
#define LCD_D4_DDR DDRC
#define LCD_D4_BIT PORTC0

#define LCD_D5_PORT PORTC
#define LCD_D5_DDR DDRC
#define LCD_D5_BIT PORTC1

#define LCD_D6_PORT PORTC
#define LCD_D6_DDR DDRC
#define LCD_D6_BIT PORTC2

#define LCD_D7_PORT PORTC
#define LCD_D7_DDR DDRC
#define LCD_D7_BIT PORTC3

#define LCD_RS_PORT PORTC
#define LCD_RS_DDR DDRC
#define LCD_RS_BIT PORTC4

#define LCD_EN_PORT PORTC
#define LCD_EN_DDR DDRC
#define LCD_EN_BIT PORTC5

void LCDInit();
void LCDWriteNibble(char c);
void LCDWriteInstruction(char c);
void LCDEnableLow();
void LCDEnableHigh();
void LCDInstructionInput();
void LCDDataInput();
void LCDWriteChar(char c);
void LCDWriteString(char *c);