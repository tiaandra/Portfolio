#include <stdio.h>
#include "pico/stdlib.h"
#include "LCD_16x2.h"
#include "hardware/adc.h"

void Init()
{
    // Create a bitmask for the LCD IO
    uint32_t gpio_bitmask = (1 << RS) | (1 << EN) | (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7);

    // Initialise the GPIOs for the LCD
    gpio_init_mask(gpio_bitmask);

    // Set GPIOs direction (all as output by default)
    gpio_set_dir_out_masked(gpio_bitmask);

    // ADC init, enabling and selecting onboard temp sensor
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);

    // LCD init
    LCD_Init();
}

float Read_Temperature()
{
    float adc = (3.3f / (1 << 12)) * (float)adc_read();
    return 27.0f - (adc - 0.706f) / 0.001721f;
}

int main()
{
    Init();
    char temperature[16];
    LCD_WriteString("Temperature:");
    while (true)
    {
        sprintf(temperature, "%.2f C", Read_Temperature());
        LCD_WriteInstruction(LCD_SecondLine);
        sleep_us(40);
        LCD_WriteString(temperature);
        sleep_ms(1000);
    }
}
