/*
* Dynamic_Design_TMU.c
*
* Created: 10/12/2019 8:56:31 PM
*  Author: Ashry
*/


#include "TMU.h"
#include "avr/io.h"

void Test_1(void){
PORTB ^= (1<<PB4);
}

void Test_2(void){
	PORTB ^= (1<<PB5);
}

void Test_3(void){
	PORTB ^= (1<<PB6);
}

int main(void)
{
DDRB |= (1<<PB4) | (1<<PB5) | (1<<PB6);
TMU_Init(&TMU_Config);
TMU_Start_Timer(1000,Test_1,PERIODIC);
TMU_Start_Timer(1,Test_2,PERIODIC);
TMU_Start_Timer(2,Test_3,ONESHOT);

while(1)
{
TMU_Dispatch();
}
}