/*
 * APP.c
 *
 * Created: 06/01/2020 13:30:26
 *  Author: Native_programmer
 */ 
#include "PWM.h"
#include "PWM_PostBConfig.h"


int main()
{
  PWM_INIT(&str_Motor_0_PWM_INIT_CONFIG);
  PWM_INIT(&str_Motor_1_PWM_INIT_CONFIG);
  
  PWM_Start(PWM_TIMER0,31,50); 
  PWM_Start(PWM_TIMER1,30,70);
  
  while(1)
  {
	  
  }
}
 
