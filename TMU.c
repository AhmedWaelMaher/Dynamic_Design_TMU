/*
 * TMU.c
 *
 * Created: 10/12/2019 8:57:23 PM
 *  Author: ahmed
 */ 


#include "TMU.h"
volatile uint16 Res =0;
volatile uint8 counter =0;
volatile uint8 g_flag=0;
volatile uint8 count =4;
volatile uint8 index=0;

EnmTMUError_t TMU_Init (const TMU_ConfigType * ConfigPtr )
{
	TIMER0_CMP_setCallBack(TMU_cal);
	TIMER2_CMPA_setCallBack(TMU_cal);
	TIMER1_CMPA_setCallBack(TMU_cal_1);
	
	uint8 status =OK;
	Res=ConfigPtr->RES;
	volatile uint16 val=Res*1000;
	
	switch(ConfigPtr->TIMER_ID){
		case TIMER0:
		TIMER_cnfg_arr[TIMER0].TIMER_ID = ConfigPtr->TIMER_ID;
		TIMER_cnfg_arr[TIMER0].OCR_ChA = 250;
		TIMER_init();
		break;
		case TIMER2:
		TIMER_cnfg_arr[TIMER2].TIMER_ID = ConfigPtr->TIMER_ID;
		TIMER_cnfg_arr[TIMER2].OCR_ChA = 250;
		TIMER_init();
		break;
		case TIMER1:
		TIMER_cnfg_arr[TIMER2].TIMER_ID = ConfigPtr->TIMER_ID;
		TIMER_cnfg_arr[TIMER2].OCR_ChA = val;
		TIMER_init();
		break;
		default:
		status =NOK;
	}
	return status;
}

void TMU_cal(void){
	counter++;
	if(counter == count*Res){
		g_flag++;
		counter=0;
	}
}

void TMU_cal_1(void){
	g_flag++;
}


void TMU_Start_Timer(uint8 time,void (*ptr)(void),uint8 periodicORoneshot){
	index++;
	Buff_arr[index].g_function = ptr;
	Buff_arr[index].STATUS = INITIALIZED;
	Buff_arr[index].TIME =  time;
	Buff_arr[index].ACTION = periodicORoneshot;
}

void TMU_Stop_Timer(void (*ptr)(void)){
	uint8 i;
	for(i=0;i<NUM_OF_FUNCS;i++){
		if(Buff_arr[i].g_function == ptr){
			Buff_arr[i].STATUS = NOT_INITIALIZED;
			break;
		}
	}
	index=i-1;
}

void TMU_Dispatch(void){
	uint8 i;
		for(i =0 ;i <NUM_OF_FUNCS; i++){
			if(Buff_arr[i].STATUS == INITIALIZED){
				if(Buff_arr[i].TIME == g_flag){
					Buff_arr[i].g_function();
					if(Buff_arr[i].ACTION == ONESHOT){
						TMU_Stop_Timer(Buff_arr[i].g_function);
					}
				}
			}
			else{
				
			}
			}
		}


EnmTMUError_t TMU_DeInit(void){
	uint8 status =OK;
	uint8 FUNC= TMU_ConfigType_Ptr->TIMER_ID;
	status = TIMER_stop(FUNC);
	return status;
}