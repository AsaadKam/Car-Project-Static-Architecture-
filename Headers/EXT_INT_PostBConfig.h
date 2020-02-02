/*
 * EXT_INT_PostBConfig.h
 *
 * Created: 15/01/2020 01:52:41
 *  Author: Native_programmer
 */ 


#ifndef EXT_INT_POSTBCONFIG_H_
#define EXT_INT_POSTBCONFIG_H_
#include "Data_Types.h"

typedef struct
{
	uinteg8_t EXT_INT_TYPE;
	uinteg8_t EXT_INT_EVENT;
	
}gStr_EXT_INT_CONFIG_t;

/*
*	Definition of Extern interrupt  modes
*/
/*EXT_INT_TYPE*/
#define EXT_INT_TYPE_0_CONFIG             0
#define EXT_INT_TYPE_1_CONFIG             1
#define EXT_INT_TYPE_2_CONFIG             2
/*EXT_INT_EVENT*/
#define EXT_INT_EVENT_RISING_EDGE_CONFIG  3
#define EXT_INT_EVENT_FALLING_EDGE_CONFIG 4

extern gStr_EXT_INT_CONFIG_t  gStr_ICU_FALLING_EXT_INT2_CONFIG;
extern gStr_EXT_INT_CONFIG_t  gStr_ICU_RISING_EXT_INT2_CONFIG;

#endif /* EXT_INT_POSTBCONFIG_H_ */