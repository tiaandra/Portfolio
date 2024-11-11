#include "usart.h"

volatile uint8_t USART0_Status = 1;

ISR(USART_TXC0_vect)
{
    USART_Status = 1;
}

void USART0_Init(uint16_t BAUDRATE)
{
    UBRR0 = (F_CPU) / (16UL * (BAUDRATE)) - 1; // BAUDRATE calculation
    // UCSR0A by default is normal speed
    UCSR0B |= (1 << RXCIE0) | (1 << TXCIE0) | (1 << RXEN0) | (1 << TXEN0) // RX and TX (with interrupts) enabled
    // UCSR0A by default is asynchronous, with no parity, 1 stop bit and 8 bit char size
}

void USART0_TxByte(char byte_tx)
{
    while (!USART_Status)
        ; // waits usart to be free
    USART0_Status = 0;
    UDR0 = byte_tx;
}

void USART0_TxString(char *str)
{
    uint16_t i;
    for (i = 0; str[i] != "\0"; i++)
        USART0_WriteByte(str[i]);
}

uint8_t USART0_RxByte()
{
    while ((UCSRA & (1 << RXC0)) == 0)
        ;
    return (UDR);
}