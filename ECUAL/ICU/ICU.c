/*
 * ICU.c
 *
 * Created: 11/21/2222 22:42:35
 *  Author: Native_programmer
 */ 

#include "ICU.h"
#include "ICU_PostBConfig.h"
#include "Timer.h"
#include "Timer_PostBConfig.h"
#include "EXT_INT.h"
#include "EXT_INT_PostBConfig.h"


#define EXT_INT_FIRST_EDGE	            0
#define EXT_INT_SECOND_EDGE			    1
volatile uinteg8_t vgu8_ICU_TRIGER_FLAG=0;
static volatile uinteg64_t svgu64_TIMER_CTC_ON_1_COUNTER=0;
static volatile uinteg8_t  svgu8_TIMER_TICK_COUNT=0;
static volatile uinteg8_t  svgu8_ICU_ON_OR_OFF_MEASURMENT_STATE=ICU_ON_TIME_CONFIG;
static volatile uinteg64_t svgu64_TIME_MICROSECOND=0;
void ICU_ISR(void)
{
	
	static uinteg8_t su8_EX_INT_STATE=EXT_INT_FIRST_EDGE;
	
	if(svgu8_ICU_ON_OR_OFF_MEASURMENT_STATE==ICU_ON_TIME_CONFIG)
	{
		switch(su8_EX_INT_STATE)
		{
			case EXT_INT_FIRST_EDGE:
			{
				Timer_Reset(TIMER2);
				svgu64_TIMER_CTC_ON_1_COUNTER=0;
				EXT_INT_INIT(&gStr_ICU_FALLING_EXT_INT2_CONFIG);
				su8_EX_INT_STATE=EXT_INT_SECOND_EDGE;
			}
			break;
			case EXT_INT_SECOND_EDGE:
			{
				Timer_Get_tickCount(TIMER2,&svgu8_TIMER_TICK_COUNT);
				svgu64_TIME_MICROSECOND=(2*svgu64_TIMER_CTC_ON_1_COUNTER+svgu8_TIMER_TICK_COUNT)*128/8.0;
				EXT_INT_INIT(&gStr_ICU_RISING_EXT_INT2_CONFIG);
				su8_EX_INT_STATE=EXT_INT_FIRST_EDGE;
				vgu8_ICU_TRIGER_FLAG=1;
			}
			break;
		}
	}
	else if(svgu8_ICU_ON_OR_OFF_MEASURMENT_STATE==ICU_OFF_TIME_CONFIG)
	{
		switch(su8_EX_INT_STATE)
		{
			case EXT_INT_FIRST_EDGE:
			{

				EXT_INT_INIT(&gStr_ICU_RISING_EXT_INT2_CONFIG);
				su8_EX_INT_STATE=EXT_INT_SECOND_EDGE;
				Timer_Reset(TIMER2);
				svgu64_TIMER_CTC_ON_1_COUNTER=0;

			}
			break;
			case EXT_INT_SECOND_EDGE:
			{
				EXT_INT_INIT(&gStr_ICU_FALLING_EXT_INT2_CONFIG);
				su8_EX_INT_STATE=EXT_INT_FIRST_EDGE;
				Timer_Get_tickCount(TIMER2,&svgu8_TIMER_TICK_COUNT);
				svgu64_TIME_MICROSECOND=(2*svgu64_TIMER_CTC_ON_1_COUNTER+svgu8_TIMER_TICK_COUNT)*128/8.0;
                vgu8_ICU_TRIGER_FLAG=1;
			}
			break;
		}
	}
	else
	{
		
	}


}

void TIMER_CTC_ON_1_ISR(void)
{
	svgu64_TIMER_CTC_ON_1_COUNTER++;
}
/** 
 * \brief ICU_Init: A function that init the timer and the external interrupt used to make the software ICU
 *
 * \param gStr_ICU_CONFIG_t* Copy_p_gstr_ICU_CONFIG
 * \return void
 *
 **/     
ICU_ERROR_t ICU_Init(gStr_ICU_CONFIG_t* Copy_p_gstr_ICU_CONFIG)
{
	vgu8_ICU_TRIGER_FLAG=0;

	svgu8_ICU_ON_OR_OFF_MEASURMENT_STATE=Copy_p_gstr_ICU_CONFIG->u8_ICU_ON_OR_OFF_MEASURMENT;
	
	if(svgu8_ICU_ON_OR_OFF_MEASURMENT_STATE==ICU_OFF_TIME_CONFIG)
	{
		EXT_INT_INIT(&gStr_ICU_FALLING_EXT_INT2_CONFIG);
	}
	else if(svgu8_ICU_ON_OR_OFF_MEASURMENT_STATE==ICU_ON_TIME_CONFIG)
	{
		EXT_INT_INIT(&gStr_ICU_RISING_EXT_INT2_CONFIG);
		
	}
	
	EXT_INT2_CALL_BACK(ICU_ISR);
	
	Timer_Init(&ICU_TIMER_Init_Config);
	Timer_Start(TIMER2,1,TIMER_CTC_ON_1_ISR);
	

}


/** 
 * \brief ICU_Get_Time : This function only passes the the on & off time to the two passed pointers
 *
 * \param *pu8On_time_buffer (Output) : The on time measured will be passed to this parameter
 * \param *pu8Off_time_buffer (Output) : The off time measured will be passed to this parameter
 * \return void
 *
 **/     
ICU_ERROR_t ICU_Get_Time_In_MICROSECONDS(uinteg64_t *Copy_pu64_On_off_time_buffer)
{
	*Copy_pu64_On_off_time_buffer=svgu64_TIME_MICROSECOND;
}
