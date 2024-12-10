#include "DHT11.h"

uint8_t ReadByte() {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++)
    {
        while (gpio_get(DHT11) == 0);   // Waits for sensor to start transmiting a bit
        busy_wait_us(28);   // Waits the lenght of the '0' bit
        if (gpio_get(DHT11))    // If the signal is still 1 means the bit is 1
            byte |= (1 << (7 - i));
        while (gpio_get(DHT11));    // Waits the rest of the bit in case it was 1, otherwise it will just skip this line
    }
    return byte;
}

int GetValues(float *temperature, float *humidity) {
    uint8_t values[5] = {0};  // Array to store data read from sensor
    
    // Start of start Signal procedure
    // Pull low for 18us, high for 20-40us
    gpio_set_dir(DHT11, GPIO_OUT);
    gpio_put(DHT11, 0);
    sleep_ms(18);
    gpio_put(DHT11, 1);
    busy_wait_us(20);

    // Sensor pulls low for 80us and up for 80us
    gpio_set_dir(DHT11, GPIO_IN);
    while (gpio_get(DHT11) == 1);   // Waits for sensor to pull signal LOW
    while (gpio_get(DHT11) == 0);   // Waits while sensor has signal LOW
    while (gpio_get(DHT11) == 1);   // Waits while sensor has signal HIGH
    // End of start Signal procedure

    // Data reading
    for (int i = 0; i < 5; i++) {
        values[i] = ReadByte();
    }

    // CheckSum validation
    if (values[0] + values[1] + values[2] + values[3] != values[4])
        return -1;  // Invalid Checksum

    // Data process 
    *humidity = (float)values[0] + (float)values[1] / 256.0f;
    *temperature = (float)values[2] + (float)values[3] / 256.0f;
    
    return 0;  // Valid data read
}