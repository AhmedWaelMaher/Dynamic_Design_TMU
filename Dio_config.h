 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_config.h
 *
 * Description: Header file for the Dio link configurations AVR driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef DIO_CONF_H_
#define DIO_CONF_H_

#include "std_types.h"


#define PORT_A		0
#define PORT_B		1
#define PORT_C		2
#define PORT_D		3

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

#define OUTPUT		1
#define INPUT		0

#define HIGH		1
#define LOW			0

#define PULLUP		1
#define EXTRES		0

#define INITIALIZED			1
#define NOT_INITIALIZED		0

#define NA			0xff

#define O_K 1
#define N_O_K 0

typedef struct {

	uint8 PORT;
	uint8 PIN;
	uint8 Dir;
	uint8 Val;
	uint8 Res;
	uint8 IS_Init;

}DIO_Conf_t;

#define NUM_PINS 3

extern DIO_Conf_t DIO_Array[NUM_PINS];


#endif /* DIO_CONF_H_ */
