#include <stdio.h>
#include "pico/stdlib.h"
#include "LCD_16x2.h"
#include "DS18B20.h"

#define LED 15

void Init()
{
    // Create a bitmask for the LCD IO, Sensor and LED
    uint32_t gpio_bitmask = (1 << RS) | (1 << EN) | (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7) | (1 << DS18B20) | (1 << LED);

    // Initialise the GPIOs for the LCD,  Sensor and LED
    gpio_init_mask(gpio_bitmask);

    // Set GPIOs direction (all as output by default)
    gpio_set_dir_out_masked(gpio_bitmask);

    // LCD init
    LCD_Init();
}

int main()
{
    Init();
    float temperature = 0;
    char str[16];
    LCD_WriteString("Temperature:");
    while (true)
    {
        temperature = DS18B20_GetTemperature();
        LCD_WriteInstruction(LCD_SecondLine);
        sleep_us(40);
        sprintf(str, "%.4f C", temperature);
        LCD_WriteString(str);
        (gpio_get(LED))
            ? gpio_put(LED, false)
            : gpio_put(LED, true);
        sleep_ms(250);
    }
}
