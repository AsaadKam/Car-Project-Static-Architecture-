/*
 * DC_Motor_PostBConfig.h
 *
 * Created: 20/01/2020 20:05:11
 *  Author: Native_programmer
 */ 


#ifndef DC_MOTOR_DRIVER_POSTBCONFIG_H_
#define DC_MOTOR_DRIVER_POSTBCONFIG_H_

#include"Timer.h"

typedef struct
{
	uinteg8_t u8_DC_Motor_Driver_TIMER_NAME;
	uinteg8_t u8_DC_Motor_Driver_PWM_Pin;
	uinteg8_t u8_DC_Motor_Driver_Backward_Pin;
	uinteg8_t u8_DC_Motor_Driver_Forward_Pin;
	
}gStr_DC_Motor_Driver_CONFIG_t;

extern gStr_DC_Motor_Driver_CONFIG_t  gStr_DC_Motor_Driver_1_CONFIG;
extern gStr_DC_Motor_Driver_CONFIG_t  gStr_DC_Motor_Driver_2_CONFIG;
/*u8_DC_Motor_Driver_TIMER_NAME*/
#define DC_Motor_Driver_TIMER_0 TIMER0
#define DC_Motor_Driver_TIMER_1 TIMER1
#define DC_Motor_Driver_TIMER_2 TIMER2


#endif /* DC_MOTOR_POSTBCONFIG_H_ */