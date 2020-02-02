/*
 * TimerConfig.c
 *
 * Created: 23/11/2019 04:07:28
 *  Author: Native_programmer
 */ 


#include "Timer_PostBConfig.h"

/*
 *
 * Let's suppose i have two case the 1st one i want to delay for 4ms and we will initiate for 1st case structure
 *              from type called TimerConfig called u_DelayConfig and let us define it 
 *
 *
 */
  gStrTimerConfiguration_t TEMP_TIMER_Init_Config={TIMER1
 
                                                  ,F_CPU_CLOCK_1024_TIMER_1
																  
											      ,COUNTER_MODE
																  
												  ,INTERRUPT                              };
												  
  
  gStrTimerConfiguration_t DELAY_TIMER_Init_Config={   TIMER0
	  
													  ,TIMER_NOTHING_PASSED_FOR_PRESCALER
                                                  
													  ,TIMER_MODE_MICRO
                                                  
													  ,POLLING                              };
												  

 gStrTimerConfiguration_t PWM_TIMER_Init_Config=   {  TIMER2
	 
													,TIMER_NOTHING_PASSED_FOR_PRESCALER
	 
													,TIMER_MODE_MICRO
	 
													,POLLING                              };

gStrTimerConfiguration_t ICU_TIMER_Init_Config=   {  TIMER2
	
													,F_CPU_CLOCK_128_TIMER_2
	
													,COUNTER_MODE
	
													,INTERRUPT                              };
 
 gStrTimerConfiguration_t TRIAL_TIMER_Init_Config=   {  
	                                                     Trial_Timer_name
	 
														,Trial_Timer_Precaler
	 
														,COUNTER_MODE
	 
														,INTERRUPT                              };
 