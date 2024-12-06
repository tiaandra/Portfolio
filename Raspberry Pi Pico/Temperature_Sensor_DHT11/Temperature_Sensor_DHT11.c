#include <stdio.h>
#include "pico/stdlib.h"
#include "DHT11.h"

#define LED 0 // LED connected to GPIO 0

void init()
{
    stdio_init_all();

    uint64_t bitmask = (1 << DHT11) | (1 << LED);
    gpio_init_mask(bitmask);
    gpio_set_dir_out_masked(bitmask);
}

int main()
{
    init();
    
    float temperature, humidity;

    while(true)
    {
        if (GetValues(&temperature, &humidity) == 0) {
            printf("Temperature: %.2f°C\n", temperature);
            printf("Humidity: %.2f%%\n", humidity);
        } else {
            printf("Invalid checksum.\n");
        }
        (gpio_get(LED)) ? gpio_put(LED, false) : gpio_put(LED, true);
        busy_wait_ms(5000);
    }
}