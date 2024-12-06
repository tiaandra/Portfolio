#include <pico/stdlib.h>

#define TRIG 26 //TRIG pin is connected to GPIO3
#define ECHO 27 //ECHO pin is connected to GPIO2

float Get_Distance(float *distance) ;
void Send_Start_Signal();
void HCSR04_Init();