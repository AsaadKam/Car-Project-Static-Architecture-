/*
 * ICU_INT_PostBConfig.h
 *
 * Created: 20/01/2020 04:57:54
 *  Author: Native_programmer
 */ 


#ifndef ICU_POSTBCONFIG_H_
#define ICU_POSTBCONFIG_H_

#include "Data_Types.h"

typedef struct
{
	uinteg8_t u8_ICU_ON_OR_OFF_MEASURMENT;
	uinteg8_t u8_ICU_Execution_Method;
}gStr_ICU_CONFIG_t;

extern gStr_ICU_CONFIG_t gStr_ICU_Config;

/*
*	Used macros
*/
#define ICU_OFF_TIME_CONFIG     0U
#define ICU_ON_TIME_CONFIG      1U
#define ICU_SOFTWARE_CONFIG     2U
#define ICU_HARDWARE_CONFIG		3U

#endif /* ICU_INT_POSTBCONFIG_H_ */