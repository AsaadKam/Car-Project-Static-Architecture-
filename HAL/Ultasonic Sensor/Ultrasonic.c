/*
 * Ultrasonic.c
 *
 * Created: 20/01/2020 06:59:12
 *  Author: Native_programmer
 */ 
#include "Delay_without_timer.h"
#include "PWM.h"
#include "PWM_PostBConfig.h"
#include "ICU.h"
#include "ICU_PostBConfig.h"
#include "Timer.h"
#include "Timer_PostBConfig.h"
#include "Ultrasonic_Designer.h"
/** 
 * \brief Ultra_Sonic_Init : Initializing the ultra sonic sensor by initializing the used timer and the used external interrupt
 *
 * \param void
 * \return void
 *
 **/     
Ultra_Error_t Ultra_Sonic_Init(void )
{
	 /**Ultrasonic initalization**/
	 ICU_Init(&gStr_ICU_Config);
	 DIO_Init_Pin(15,1);
     DIO_Write_Pin(15,0);
}
static void Ultra_Sonic_Triger(void)
{
	DIO_Write_Pin(15,1);
	_delay_us(100);
	DIO_Write_Pin(15,0);
}
/** 
 * \brief Ultra_Sonic_Get_Distance : This function uses timer0 & external interrupt 2 to measure the time between sending a certain wave and recieving it from the ultra sonic sensor
 *
 * \param *pu64Reading (Output) : The time reading is passed to this parameter
 * \return void
 *
 **/     
Ultra_Error_t Ultra_Sonic_Get_Distance(uinteg64_t *pu64Reading)
{
	static uinteg8_t u8_Ultrasonic_flag_1st_time=1;
	uinteg64_t u64_ICU_TIME_IN_MICRO=0;
	
	ICU_Get_Time_In_MICROSECONDS(&u64_ICU_TIME_IN_MICRO);
	*pu64Reading=u64_ICU_TIME_IN_MICRO*0.017;
	if(u8_Ultrasonic_flag_1st_time==1)
	{				
        Ultra_Sonic_Triger();
	    u8_Ultrasonic_flag_1st_time=0;
	}
	if(vgu8_ICU_TRIGER_FLAG==1)
	{
/*		Debug_By_Toggle(23);	*/
        Ultra_Sonic_Triger();
		vgu8_ICU_TRIGER_FLAG=0;	
	}

}


