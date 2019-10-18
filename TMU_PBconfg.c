/******************************************************************************
 *
 * Module: TMU
 *
 * File Name: TMU_PBconfg.c
 *
 * Description: TMU postbuild configuration file source
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "std_types.h"
#include "TMU_confg.h"
#include "TMU_PBconfg.h"

TMU_ConfigType TMU_Config = {TIMER0,1};
TMU_ConfigType *TMU_ConfigType_Ptr = &TMU_Config;



