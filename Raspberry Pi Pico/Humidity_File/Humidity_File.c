#include <stdio.h>
#include "pico/stdlib.h"
#include "DHT11.h"

void init()
{
    stdio_init_all();

    uint64_t bitmask = (1 << DHT11);
    gpio_init_mask(bitmask);
    gpio_set_dir_out_masked(bitmask);
}

int main()
{
    init();
    
    float temperature, humidity;    // Required variables for GetValues function
    int timer = 0;

    while(true)
    {
        if (GetValues(&temperature, &humidity) == 0) 
            printf("%i %.2f\n", timer, humidity);
        else
            printf("Invalid checksum.\n");
        busy_wait_ms(1000);    // Delay for 1 minute
        timer += 1;
    }
}
