#include"Timer.h"


 extern  gStrTimerConfiguration_t TEMP_TIMER_Init_Config;
 extern  gStrTimerConfiguration_t DELAY_TIMER_Init_Config;
 extern  gStrTimerConfiguration_t PWM_TIMER_Init_Config;
 extern  gStrTimerConfiguration_t ICU_TIMER_Init_Config;
 extern  gStrTimerConfiguration_t TRIAL_TIMER_Init_Config;
 
 #define Trial_Timer_name       TIMER0
 #define Trial_Timer_Precaler   F_CPU_CLOCK_64_TIMER_0