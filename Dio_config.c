 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_config.c
 *
 * Description: Source file for the Dio link configurations AVR driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/


#include"Dio_config.h"

/*Configure your pins with the same order in the enum
 { port , pin Number , Pin direction , output_value , Pullup/external resistor , initialized/not initialized }*/

DIO_Conf_t DIO_Array[NUM_PINS] = {
		{PORT_C,PIN0,OUTPUT,LOW,PULLUP,INITIALIZED},
		{PORT_C,PIN1,OUTPUT,LOW,PULLUP,INITIALIZED},
		{PORT_C,PIN2,OUTPUT,LOW,PULLUP,INITIALIZED}
};

