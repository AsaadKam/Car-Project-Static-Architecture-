/*
 * PWM_PostBConfig.c
 *
 * Created: 11/21/2222 22:41:16
 *  Author: Native_programmer
 */ 
#include "PWM_PostBConfig.h"

gstr_PWM_INIT_CONFIG str_Motor_0_PWM_INIT_CONFIG={	 PWM_Software_Config
													,PWM_Phase_Corret_Config
													,PWM_TIMER0
													,F_CPU_CLOCK_64_PWM_TIMER_0
													,125
												 };
gstr_PWM_INIT_CONFIG str_Motor_1_PWM_INIT_CONFIG={   PWM_Software_Config
										            ,PWM_Phase_Corret_Config
												    ,PWM_TIMER1
												    ,F_CPU_CLOCK_64_PWM_TIMER_1
												    ,125  
												  };
												  	/*T=( (Count*Prescaler)/800000Y. 0(FREQOF CPU)  )=(Period/510)	*/