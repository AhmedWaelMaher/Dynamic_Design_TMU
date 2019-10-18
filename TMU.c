/******************************************************************************
 *
 * Module: TMU
 *
 * File Name: TMU.c
 *
 * Description: TMU source files
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "TMU.h"

typedef void(*ptrToFunction)(void);

typedef struct{
	void (*g_function)(void);
	uint8 ACTION;
	uint16 TIME;
	uint16 COUNTER;
}Buffer;

static Buffer Buff_arr[NUM_OF_FUNCS] = {0} ;

static volatile uint16 g_res =0;
static volatile uint16 g_overflow =0;
static volatile sint16 g_currentPos = 0;
static volatile uint8 g_flag =0;
static volatile uint16 g_index =0;

EnmTMUError_t TMU_Init (const TMU_ConfigType * ConfigPtr )
{

	EnmTMUError_t status =OK;
	g_res=ConfigPtr->RES;


	switch(ConfigPtr->TIMER_ID){
	case TIMER0:
		TIMER_init(TIMER0);
		TIMER0_OVF_setCallBack(TMU_cal);
		break;
	case TIMER1:
		TIMER_init(TIMER1);
		TIMER1_OVF_setCallBack(TMU_cal);
		break;
	case TIMER2:
		TIMER_init(TIMER2);
		TIMER2_OVF_setCallBack(TMU_cal);
		break;
	default:
		status =NOK;
		break;
	}
	TIMER_start(TIMER0);
	return status;
}

static void TMU_cal(void){

	g_overflow++;
	if(g_overflow == g_res){
		g_flag++;
		for(g_index=0;g_index < g_currentPos;g_index++){
			Buff_arr[g_index].COUNTER++;
		}
		g_overflow =0;
	}
}

EnmTMUError_t TMU_Start_Timer(uint16 time,ptrToFunction voidFunc,uint8 periodicORoneshot){


	EnmTMUError_t status=OK;

	if(g_currentPos<NUM_OF_FUNCS){
		Buff_arr[g_currentPos].g_function = voidFunc;
		Buff_arr[g_currentPos].TIME =  time;
		Buff_arr[g_currentPos].ACTION = periodicORoneshot;
		g_currentPos++;
	}
	else{
		status=NOK;
	}
	return status;
}

void TMU_Stop_Timer(ptrToFunction voidFunc){

	for(g_index=0;g_index<g_currentPos;g_index++){
		if(Buff_arr[g_index].g_function == voidFunc){
			Buff_arr[g_index] = Buff_arr[g_currentPos-1];
			g_currentPos--;
			g_index --;
			break;
		}
	}
}

void TMU_Dispatch(void){

	if(g_flag == 1){
		if(g_currentPos <= NUM_OF_FUNCS ){
			for(g_index =0 ;g_index <g_currentPos; g_index++){
				if((((Buff_arr[g_index].COUNTER) >= (Buff_arr[g_index].TIME)) ) \
						&& (((Buff_arr[g_index].TIME)*2) >= (Buff_arr[g_index].COUNTER))){
					Buff_arr[g_index].COUNTER=0;
					if(Buff_arr[g_index].ACTION == ONESHOT){
						Buff_arr[g_index].g_function();
						TMU_Stop_Timer(Buff_arr[g_index].g_function);
					}
					Buff_arr[g_index].g_function();
				}
			}
		}
		g_flag =0;
	}
}


EnmTMUError_t TMU_DeInit(void){
	EnmTMUError_t status =OK;
	status = TIMER_stop(TMU_ConfigType_Ptr->TIMER_ID);
	return status;
}
