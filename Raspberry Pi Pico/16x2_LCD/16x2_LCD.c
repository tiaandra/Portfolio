#include <stdio.h>
#include "pico/stdlib.h"
#include "LCD_16x2.h"

void IO_Init()
{
    // Initialise the GPIOs for the LCD
    gpio_init(RS);
    gpio_init(EN);
    gpio_init(D4);
    gpio_init(D5);
    gpio_init(D6);
    gpio_init(D7);

    // Set GPIOs direction (all as output by default)
    gpio_set_dir(RS, true);
    gpio_set_dir(EN, true);
    gpio_set_dir(D4, true);
    gpio_set_dir(D5, true);
    gpio_set_dir(D6, true);
    gpio_set_dir(D7, true);
}

int main()
{
    IO_Init();
    LCD_Init();
    LCD_WriteString("Tiago");
    LCD_WriteInstruction(LCD_SecondLine);
    sleep_us(40);
    LCD_WriteString("Andrade");
    while (true)
        ;
    return 0;
}
