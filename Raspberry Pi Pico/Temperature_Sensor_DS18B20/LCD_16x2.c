#include "LCD_16x2.h"

void LCD_Init()
{
    sleep_ms(100); // Power-up delay
    LCD_InstructionInput();
    LCD_EnableLow();
    LCD_WriteNibble(LCD_FunctionReset); // Reset sequence
    sleep_ms(10);
    LCD_WriteNibble(LCD_FunctionReset); // Reset sequence
    sleep_us(200);
    LCD_WriteNibble(LCD_FunctionReset); // Reset sequence
    sleep_us(200);
    LCD_WriteNibble(LCD_FunctionSet); // Set 4bit bus mode
    sleep_us(80);
    LCD_WriteInstruction(LCD_FunctionSet); // Set mode, lines and char
    sleep_us(80);
    LCD_WriteInstruction(LCD_TurnOff); // Power up routine
    sleep_us(80);
    LCD_WriteInstruction(LCD_ClearScreen); // Power up routine
    sleep_ms(4);
    LCD_WriteInstruction(LCD_EntryMode); // Power up routine
    sleep_us(80);
    LCD_WriteInstruction(LCD_TurnOn); // Initialization finished, display ON
    sleep_us(80);
}

void LCD_WriteNibble(uint8_t nibble)
{
    (nibble & 1 << 7) ? gpio_put(D7, true) : gpio_put(D7, false);
    (nibble & 1 << 6) ? gpio_put(D6, true) : gpio_put(D6, false);
    (nibble & 1 << 5) ? gpio_put(D5, true) : gpio_put(D5, false);
    (nibble & 1 << 4) ? gpio_put(D4, true) : gpio_put(D4, false);
    LCD_EnableHigh();
    sleep_us(1);
    LCD_EnableLow();
    sleep_us(1);
}

void LCD_WriteInstruction(uint8_t instruction)
{
    LCD_InstructionInput();
    LCD_EnableLow();
    LCD_WriteNibble(instruction);
    LCD_WriteNibble(instruction << 4);
}

void LCD_EnableLow()
{
    gpio_put(EN, false);
}

void LCD_EnableHigh()
{
    gpio_put(EN, true);
}

void LCD_InstructionInput()
{
    gpio_put(RS, false);
}

void LCD_DataInput()
{
    gpio_put(RS, true);
}

void LCD_WriteChar(uint8_t character)
{
    LCD_DataInput();
    LCD_EnableLow();
    LCD_WriteNibble(character);
    LCD_WriteNibble(character << 4);
}

void LCD_WriteString(char string[])
{
    while (*string)
    {
        LCD_WriteChar(*string++);
        sleep_us(80);
    }
}