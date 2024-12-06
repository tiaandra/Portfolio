#include "HCSR04.h"

/*
1 - Hold TRIG for at least 10us HIGH
2 - Module sends 8 40kHz and detects if there is a pulse signal back
3 - If it gets a signal back, the time of HIGH is the time of the sonicwave return
*/

float Get_Distance(float *distance)    // Get Distance in cm
{
    Send_Start_Signal();

    while (gpio_get(ECHO) == 0)  // Waits for the ECHO pulse to start
        tight_loop_contents();

    absolute_time_t startTime = get_absolute_time();

    while (gpio_get(ECHO) == 1)  // Waits for the ECHO signal to come back to LOW
        tight_loop_contents();

    absolute_time_t endTime = get_absolute_time();

    int64_t pulse_duration = absolute_time_diff_us(startTime, endTime);
    *distance = (pulse_duration / 2.0) * 0.0343; 

    /*
        distance = (pulse duration * sound velocity) / 2

        sound velocity is 343 m/s = 0.0343 cm/us
    */

    // Max range is 400
    if (*distance > 400)
        return -1;
    
    return 0;
}

void Send_Start_Signal()
{
    gpio_put(TRIG, true);
    busy_wait_us(10);
    gpio_put(TRIG, false);
}

void HCSR04_Init()
{
    // GPIO initialization
    gpio_init(TRIG);
    gpio_init(ECHO);

    // Set TRIG as output and ECHO as input
    gpio_set_dir(TRIG, GPIO_OUT);
    gpio_set_dir(ECHO, GPIO_IN);

    // Make sure it starts 0
    gpio_put(TRIG, false);  
}