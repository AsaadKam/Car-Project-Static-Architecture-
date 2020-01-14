/*
 * PWM_User_Interface.h
 *
 * Created: 14/01/2020 03:33:28
 *  Author: Native_programmer
 */ 

#ifndef PWM_USER_INTERFACE_H_
#define PWM_USER_INTERFACE_H_

#include"PWM_Designer.h"

typedef struct
{
	uint8_t u8_PWM_Execution_Method;/*Software*/ /*Hardware*/
	uint8_t u8_PWM_Mode;/*Phase correct*/ /*Fast PWM*/
	uint8_t u8_PWM_Timer_Type;/*Timer(0->2)*/ /*Init and start Timer with the type*//*function will be called back to the timer type*/
	uint8_t u8_PWM_Timer_Prescaler;/*Prescaler*//*Init and start Timer with the precaler*/
	uint8_t u8_PWM_Timer_Count;/*Count*//*Init and start Timer with the count*/
	/*T=( (Count*Prescaler)/8000000(FREQY. OF CPU)  )=(Period/510)	*/	
}gstr_PWM_INIT_CONFIG;
	

#define PWM_Software_Config         1
#define PWM_Hardware_Config         2
#define PWM_Phase_Corret_Config     3
#define PWM_Fast_Config		    	4
#define PWM_TIMER0					TIMER0
#define PWM_TIMER1					TIMER1
#define PWM_TIMER2					TIMER2

/*_______PWM_TIMER0__________________________________*/
#define NO_CLOCK_PWM_TIMER_0     					0U
#define F_CPU_CLOCK_PWM_TIMER_0   					1U
#define F_CPU_CLOCK_8_PWM_TIMER_0 					2U
#define F_CPU_CLOCK_64_PWM_TIMER_0					3U
#define F_CPU_CLOCK_256_PWM_TIMER_0			     	4U
#define F_CPU_CLOCK_1024_PWM_TIMER_0				5U
#define F_EXTERNAL_CLOCK_FALLING_PWM_TIMER_0		6U
#define F_EXTERNAL_CLOCK_RISING_PWM_TIMER_0		    7U

/*_______PWM_TIMER1__________________________________*/
#define NO_CLOCK_PWM_TIMER_1     					0U
#define F_CPU_CLOCK_PWM_TIMER_1   					1U
#define F_CPU_CLOCK_8_PWM_TIMER_1 					2U
#define F_CPU_CLOCK_64_PWM_TIMER_1					3U
#define F_CPU_CLOCK_256_PWM_TIMER_1				    4U
#define F_CPU_CLOCK_1024_PWM_TIMER_1				5U
#define F_EXTERNAL_CLOCK_FALLING_PWM_TIMER_1	 	6U
#define F_EXTERNAL_CLOCK_RISING_PWM_TIMER_1	        7U

/*_______PWM_TIMER2__________________________________*/
#define NO_CLOCK_PWM_TIMER_2     					 0U
#define F_CPU_CLOCK_PWM_TIMER_2   					 1U
#define F_CPU_CLOCK_8_PWM_TIMER_2 					 2U
#define F_CPU_CLOCK_32_PWM_TIMER_2					 3U
#define F_CPU_CLOCK_64_PWM_TIMER_2					 4U
#define F_CPU_CLOCK_128_PWM_TIMER_2			         5U
#define F_CPU_CLOCK_256_PWM_TIMER_2		 	         6U
#define F_CPU_CLOCK_1024_PWM_TIMER_2				 7U

#define PWM_TIMER_NOTHING_PASSED_FOR_PRESCALER       0U
/************************************************************************/
/*      (PWM_INIT)--->To init the PWM by configuration structure        */
/************************************************************************/
/**Return PWM_ERROR_t-> Error to PWM_INIT as defined in PWM_Designer.h **/
         /**Passing pointer to configuration structure**/ 

PWM_ERROR_t PWM_INIT(gstr_PWM_INIT_CONFIG* pstr_PWM_INIT_CONFIG);

/************************************************************************/
/*     (PWM_Start)--->To start the PWM by configuration structure       */
/************************************************************************/
/**Return PWM_ERROR_t-> Error to PWM_Start as defined in PWM_Designer.h **/
/**Passing uint8_t type u8_TIMER_USED      as an example PWM_TIMER0     **/
/**Passing uint8_t type u8_PWM_Pin         as an example [0,1,2,3,..,31]**/	
/**Passing uint8_t type u8_PWM_Duty_Cycle  as an example [0-100]        **/	 

PWM_ERROR_t PWM_Start(uint8_t u8_TIMER_USED,uint8_t u8_PWM_Pin,uint8_t u8_PWM_Duty_Cycle);


#endif /* PWM_USER_INTERFACE_H_ */