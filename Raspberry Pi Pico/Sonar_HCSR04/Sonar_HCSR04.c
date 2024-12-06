#include <stdio.h>
#include "pico/stdlib.h"
#include "HCSR04.h"

#define LED 0   
#define POLL_RATE 250 // Rate at which we measure distance in ms

void init()
{
    stdio_init_all();

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    HCSR04_Init();
}

int main()
{
    init();
    float distance = 0;
    while (true) 
    {
        if(Get_Distance(&distance) == 0)
            printf("Distance = %.2f cm\n", distance);
        else
            printf("Invalid Data Read.\n");
        (gpio_get(LED)) ? gpio_put(LED, false) : gpio_put(LED, true);
        sleep_ms(POLL_RATE);
    }
}