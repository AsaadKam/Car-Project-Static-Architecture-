/*
 * PWM_PostBConfig.h
 *
 * Created: 14/01/2020 03:34:24
 *  Author: Native_programmer
 */ 


#ifndef PWM_POSTBCONFIG_H_
#define PWM_POSTBCONFIG_H_


#include "PWM_User_Interface.h"

extern gstr_PWM_INIT_CONFIG str_Motor_0_PWM_INIT_CONFIG;
extern gstr_PWM_INIT_CONFIG str_Motor_1_PWM_INIT_CONFIG;
extern gstr_PWM_INIT_CONFIG str_Ultrasonic_Sensor_PWM_INIT_CONFIG;

#define PWM_Periodicty_500_HZ_TIMER_0 F_CPU_CLOCK_64_PWM_TIMER_0
#define PWM_Periodicty_500_HZ_TIMER_1 F_CPU_CLOCK_64_PWM_TIMER_1
#define PWM_Periodicty_500_HZ_TIMER_2 F_CPU_CLOCK_64_PWM_TIMER_2
#define PWM_Periodicty_30_HZ_TIMER_0 F_CPU_CLOCK_1024_PWM_TIMER_0
#define PWM_Periodicty_30_HZ_TIMER_1 F_CPU_CLOCK_1024_PWM_TIMER_1
#define PWM_Periodicty_30_HZ_TIMER_2 F_CPU_CLOCK_1024_PWM_TIMER_2
#endif /* PWM_POSTBCONFIG_H_ */