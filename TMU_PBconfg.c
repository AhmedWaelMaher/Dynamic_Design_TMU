/*
 * TMU_PBconfg.c
 *
 * Created: 10/12/2019 8:57:44 PM
 *  Author: ahmed
 */ 
#include "TMU_confg.h"

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define RESOLUTION 1
 
 
 
 
//typedef enum{NOK,OK};
	
#include "std_types.h"
#include "TMU_PBconfg.h"

TMU_ConfigType TMU_Config = {TIMER0,1};
TMU_ConfigType *TMU_ConfigType_Ptr = &TMU_Config;

Buffer Buff_arr[NUM_OF_FUNCS] = {
	{NULL,0,0,0},
		{NULL,0,0,0},
			{NULL,0,0,0}
	};


