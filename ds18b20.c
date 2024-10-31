#include "ds18b20.h"

/*
1st step - Read Rom - returns the 64-bit ROM code, can be used because there is only 1 slave
2nd step - Read Power Supply - followed by a read time slot to determine inactive state
3rd step - Match Rom/Skip Rom - either works, match rom has to be followed by the 64-bit ROM code, skip rom will address all (in this case, the one i'm using)
4th step - Convert T - converts temperature into the scratchpad
5th step - Read Scratchpad -
*/

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

/*
https://www.analog.com/media/en/technical-documentation/data-sheets/DS18B20.pdf
https://teslabs.com/openplayer/docs/docs/other/ds18b20_pre1.pdf
*/