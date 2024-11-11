#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

void USART0_Init(uint16_t BAUDRATE);
void USART0_TxByte(char byte_tx);
void USART0_TxString(char *str);
uint8_t USART0_RxByte();