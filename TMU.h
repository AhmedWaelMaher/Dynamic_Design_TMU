/*
 * TMU.h
 *
 * Created: 10/12/2019 8:57:57 PM
 *  Author: ahmed
 */ 


#ifndef TMU_H_
#define TMU_H_

#include "Timer.h"
#include "TMU_confg.h"
#include "TMU_PBconfg.h"
extern TMU_ConfigType TMU_Config ;
extern TMU_ConfigType *TMU_ConfigType_Ptr;
extern EnmTMUError_t TMU_Init (const TMU_ConfigType * ConfigPtr );
extern void TMU_cal(void);
extern void TMU_cal_1(void);
extern uint8 TMU_Start_Timer(uint8 time,void (*ptr)(void),uint8 periodicORoneshot);
extern void TMU_Stop_Timer(void (*ptr)(void));
extern void TMU_Dispatch(void);
extern EnmTMUError_t TMU_DeInit(void);





#endif /* TMU_H_ */