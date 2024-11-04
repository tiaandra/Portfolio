#include "ds18b20.h"

uint8_t DS18B20_Reset()
{
    uint8_t i;
    DS18B20_Low;
    DS18B20_WriteMode();
    _delay_us(480);
    DS18B20_ReadMode();
    _delay_us(60);
    i = (DS18B20_PIN & (1 << DS18B20_P));
    _delay_us(420);
    return i; // If 0 ok, if 1 bad
}

void DS18B20_WriteBit(uint8_t bit)
{
    DS18B20_Low;
    DS18B20_WriteMode;
    _delay_us(1);
    if (bit) // If bit is 1, release the line and it will go high, if not wait the 60us leaving the line at 0
        DS18B20_ReadMode;
    _delay_us(60);
    DS18B20_ReadMode;
}

uint8_t DS18B20_ReadBit()
{
    uint8_t bit = 0;
    DS18B20_Low;
    DS18B20_WriteMode;
    _delay_us(1);
    DS18B20_ReadMode;
    _delay_us(14);
    if (DS18B20_PIN & (1 << DS18B20_P))
        bit = 1;
    _delay_us(45);
    return bit;
}

uint8_t DS18B20_ReadByte()
{
    uint8_t i, n = 0;
    while (i--)
    {
        n >>= 1;
        n |= (DS18B20_ReadBit() << 7);
    }
    return n;
}

uint8_t DS18B20_WriteByte(uint8_t byte)
{
    uint8_t i = 8;
    while (i--)
    {
        DS18B20_WriteBit(byte & 1);
        byte >>= 1;
    }
}

void DS18B20_ReadTemp(char *temp)
{
    uint8_t temperature[2];
    int8_t digit;
    uint16_t decimal;

    DS18B20_Reset();
    DS18B20_WriteByte(DS18B20_SkipRom);
    DS18B20_WriteByte(DS18B20_ConvertT);
    while (!DS18B20_ReadBit())
        ;
    DS18B20_Reset();
    DS18B20_WriteByte(DS18B20_SkipRom);
    DS18B20_ReadByte(DS18B20_Read);
    temperature[0] = DS18B20_ReadByte();
    temperature[1] = DS18B20_ReadByte();
    DS18B20_Reset();
    digit = temperature[0] >> 4;
    digit |= (temperature[1] & 0x7) << 4;
    decimal = temperature[0] & 0xf;
    decimal *= 625;
    sprintf(temp, "%+d.%04u C", digit, decimal);
}

/*
https://www.analog.com/media/en/technical-documentation/data-sheets/DS18B20.pdf
https://teslabs.com/openplayer/docs/docs/other/ds18b20_pre1.pdf
*/