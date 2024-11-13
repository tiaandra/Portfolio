#include "DS18B20.h"

// Initialization sequence for the sensor
unsigned int DS18B20_Reset()
{
    DS18B20_Release();
    sleep_us(490);
    DS18B20_Set();
    sleep_us(70);
    unsigned int aux = DS18B20_ReadBit();
    sleep_us(410);
    DS18B20_Set();
    return aux;
}

void DS18B20_Set()
{
    gpio_set_dir(DS18B20, true);
    gpio_put(DS18B20, 1);
}

void DS18B20_Release()
{
    gpio_set_dir(DS18B20, true);
    gpio_put(DS18B20, 0);
}

// Read a Bit from the sensor
unsigned char DS18B20_ReadBit()
{
    DS18B20_Release();
    sleep_us(6);
    DS18B20_Set();
    sleep_us(9);
    unsigned char bit_read = gpio_get(DS18B20);
    sleep_us(55);
    return bit_read;
}

// Read a Byte from the sensor
unsigned char DS18B20_ReadByte()
{
    unsigned char byte;
    for (int i = 0; i < 8; i++)
    {
        byte = byte >> 1;
        if (DS18B20_ReadBit() & 0x01)
            byte = byte | 0x80;
    }
    return byte;
}

// Send a Bit to the sensor
void DS18B20_WriteBit(unsigned char c)
{
    if (c)
    {
        DS18B20_Release();
        sleep_us(6);
        DS18B20_Set();
        sleep_us(64);
    }
    else
    {
        DS18B20_Release();
        sleep_us(60);
        DS18B20_Set();
        sleep_us(10);
    }
}

// Send a Byte to the sensor
void DS18B20_WriteByte(char byte)
{
    for (int i = 0; i < 8; i++)
    {
        (byte & 0x01) ? DS18B20_WriteBit(true) : DS18B20_WriteBit(false);
        byte = byte >> 1;
    }
    sleep_us(5);
}

// Get Sensor Temperature
float DS18B20_GetTemperature()
{
    DS18B20_Reset();
    DS18B20_WriteByte(DS18B20_SkipRom);
    DS18B20_WriteByte(DS18B20_ConvertT);
    while (!gpio_get(DS18B20))
        ;
    DS18B20_Reset();
    DS18B20_WriteByte(DS18B20_SkipRom);
    sleep_ms(750); // Max conversion time on 12 bits (defualt value)
    DS18B20_WriteByte(DS18B20_ReadScratchpad);
    unsigned char LSB = DS18B20_ReadByte();
    unsigned char MSB = DS18B20_ReadByte();
    DS18B20_Reset();
    unsigned int data = MSB;
    float temperature = (data << 8) | LSB;
    return (temperature / 16);
}