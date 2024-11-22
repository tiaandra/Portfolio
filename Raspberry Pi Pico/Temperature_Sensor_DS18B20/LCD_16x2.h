#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"

#define LCD_ClearScreen 0x01 // Clears screen
#define LCD_ReturnHome 0x02  // Return cursor to first line first char

#define LCD_FunctionSet 0x28   // Display in 4-bit bus mode, 2 lines and 5x7 dots char
#define LCD_FunctionReset 0x30 // Reset LCD

#define LCD_TurnOn 0x0c  // Turns display on with cursor off
#define LCD_TurnOff 0x08 // Turns display off

#define LCD_EntryMode 0x06 // Cursor moves right on read/write

#define LCD_FirstLine 0x80  // Forces cursor to the beginning of 1st line
#define LCD_SecondLine 0xc0 // Forces cursor to the beginning of 2nd line

#define LCD_CursorRight 0x14  // Moves cursor right by one char
#define LCD_CursorLeft 0x10   // Moves cursor left by one char
#define LCD_DisplayRight 0x1c // Moves display right by one char
#define LCD_DisplayLeft 0x18  // Moves display left by one char

#define RS 16 // RS from LCD is connected to GP16
#define EN 17 // EN from LCD is connected to GP17

#define D4 18 // D4 from LCD is connected to GP18
#define D5 19 // D5 from LCD is connected to GP19
#define D6 20 // D6 from LCD is connected to GP20
#define D7 21 // D7 from LCD is connected to GP21

void LCD_Init();
void LCD_WriteNibble(uint8_t nibble);
void LCD_WriteInstruction(uint8_t instruction);
void LCD_EnableLow();
void LCD_EnableHigh();
void LCD_InstructionInput();
void LCD_DataInput();
void LCD_WriteChar(uint8_t character);
void LCD_WriteString(char string[]);