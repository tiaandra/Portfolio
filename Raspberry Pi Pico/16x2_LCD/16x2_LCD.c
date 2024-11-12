#include <stdio.h>
#include "pico/stdlib.h"
#include "LCD_16x2.h"

void IO_Init()
{
    uint32_t gpio_bitmask = (1 << RS) | (1 << EN) | (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7);
    // Initialise the GPIOs for the LCD
    gpio_init_mask(gpio_bitmask);

    // Set GPIOs direction (all as output by default)
    gpio_set_dir_out_masked(gpio_bitmask);
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
