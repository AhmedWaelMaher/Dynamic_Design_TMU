/******************************************************************************
 *
 * Module: Application Layer
 *
 * File Name: app.c
 *
 * Description: Application with TMU test cases
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "TMU.h"
#include "Dio.h"

uint8 g_closeTask =0;
void Test_1(void){

	g_closeTask++;
	TOGGLE_BIT(PORTC,PC0);
}

void Test_2(void){

	TOGGLE_BIT(PORTC,PC1);
}

void Test_3(void){


	TOGGLE_BIT(PORTC,PC2);
}

int main(void)
{
	DIO_Init();
	DIO_Write(PIN0,LOW);
	DIO_Write(PIN1,LOW);
	DIO_Write(PIN2,LOW);
	TMU_Init(&TMU_Config);

	TMU_Start_Timer(500,Test_1,PERIODIC);
	TMU_Start_Timer(1000,Test_2,ONESHOT);
	TMU_Start_Timer(1500,Test_3,PERIODIC);


	while(1)
	{
		TMU_Dispatch();
		if(g_closeTask == 10){
			TMU_Stop_Timer(Test_1);
		}
	}
}



