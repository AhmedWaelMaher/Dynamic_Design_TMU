/*
 * TMU_PBconfg.h
 *
 * Created: 10/12/2019 8:59:20 PM
 *  Author: ahmed
 */ 


#ifndef TMU_PBCONFG_H_
#define TMU_PBCONFG_H_

#include "std_types.h"
#include "TMU_confg.h"

 typedef struct{
	uint8 TIMER_ID;
	uint8 RES;
}TMU_ConfigType;





typedef struct{
	volatile void (*g_function)(void);
	uint8 ACTION;
	uint8 STATUS;
	uint16 TIME;
	}Buffer;
	
extern Buffer Buff_arr[NUM_OF_FUNCS];

#endif /* TMU_PBCONFG_H_ */