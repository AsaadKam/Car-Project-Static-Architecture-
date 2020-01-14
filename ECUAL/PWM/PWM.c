/*
 * PWM.c
 *
 * Created: 11/21/2222 22:42:35
 *  Author: Native_programmer
 */ 
#include "Timer.h"
#include "PWM.h"
#include "DIO.h"

#define   PWM_State_Inc				0
#define   PWM_State_Dec				1
#define   PWM_NO_STATE				2

volatile  static uint8_t  vsu8_PWM_TIMER0_Duty_Cycle=0;
volatile  static uint8_t  vsu8_PWM_TIMER1_Duty_Cycle=0;
volatile  static uint8_t  vsu8_PWM_TIMER2_Duty_Cycle=0;

volatile  static uint8_t  vsu8_PWM_TIMER0_PIN=0;
volatile  static uint8_t  vsu8_PWM_TIMER1_PIN=0;
volatile  static uint8_t  vsu8_PWM_TIMER2_PIN=0;

volatile  static uint8_t  vsu8_PWM_COUNT_TIMER0=0;
volatile  static uint8_t  vsu8_PWM_COUNT_TIMER1=0;
volatile  static uint8_t  vsu8_PWM_COUNT_TIMER2=0;


static PWM_TIMER0_INTERRUPT_SERVICE_ROUTINE(void)
{
           uint16_t u16_PWM_TIMER0_VALUE=(vsu8_PWM_TIMER0_Duty_Cycle*255)/100.0;
	static uint16_t su16_PWM_TIMER0_Counter=0U;
	static uint8_t  su8_PWM_TIMER0_State=PWM_State_Inc;

	if(u16_PWM_TIMER0_VALUE==0U)
	{
		DIO_Write_Pin(vsu8_PWM_TIMER0_PIN,0);
		su8_PWM_TIMER0_State=PWM_NO_STATE;
	}
	else if(u16_PWM_TIMER0_VALUE==255U)
	{
		su8_PWM_TIMER0_State=PWM_NO_STATE;
	}
	else
	{
		/*Do Nothing*/
	}


	switch(su8_PWM_TIMER0_State)
	{
		case PWM_State_Inc:
		{
			if(su16_PWM_TIMER0_Counter==u16_PWM_TIMER0_VALUE)
			{

				su16_PWM_TIMER0_Counter++;
				DIO_toggle_Pin(vsu8_PWM_TIMER0_PIN);
			}
			else if(su16_PWM_TIMER0_Counter==255U)
			{
				su8_PWM_TIMER0_State=PWM_State_Dec;
				su16_PWM_TIMER0_Counter--;
			}
			else
			{
				su16_PWM_TIMER0_Counter++;
			}

		}
		break;
			       
		case PWM_State_Dec:
		{
			if(su16_PWM_TIMER0_Counter==u16_PWM_TIMER0_VALUE)
			{
				DIO_toggle_Pin(vsu8_PWM_TIMER0_PIN);
			}
			else if(su16_PWM_TIMER0_Counter==1U)
			{
				su8_PWM_TIMER0_State=PWM_State_Inc;
			}

			su16_PWM_TIMER0_Counter--;
		}
		break;
			       
		case PWM_NO_STATE:
		{
			/*Do Nothing*/
		}
		break;
	}
}
static PWM_TIMER1_INTERRUPT_SERVICE_ROUTINE(void)
{
	uint16_t u16_PWM_TIMER1_VALUE=(vsu8_PWM_TIMER1_Duty_Cycle*255)/100.0;
	static uint16_t su16_PWM_TIMER1_Counter=0U;
	static uint8_t  su8_PWM_TIMER1_State=PWM_State_Inc;
	
	if(u16_PWM_TIMER1_VALUE==0U)
	{
		DIO_Write_Pin(vsu8_PWM_TIMER1_PIN,0);
		su8_PWM_TIMER1_State=PWM_NO_STATE;
	}
	else if(u16_PWM_TIMER1_VALUE==255U)
	{
		su8_PWM_TIMER1_State=PWM_NO_STATE;
	}
	else
	{
		/*Do Nothing*/
	}


	switch(su8_PWM_TIMER1_State)
	{
		case PWM_State_Inc:
		{
			if(su16_PWM_TIMER1_Counter==u16_PWM_TIMER1_VALUE)
			{

				su16_PWM_TIMER1_Counter++;
				DIO_toggle_Pin(vsu8_PWM_TIMER1_PIN);
			}
			else if(su16_PWM_TIMER1_Counter==255U)
			{
				su8_PWM_TIMER1_State=PWM_State_Dec;
				su16_PWM_TIMER1_Counter--;
			}
			else
			{
				su16_PWM_TIMER1_Counter++;
			}

		}
		break;
		
		case PWM_State_Dec:
		{
			if(su16_PWM_TIMER1_Counter==u16_PWM_TIMER1_VALUE)
			{
				DIO_toggle_Pin(vsu8_PWM_TIMER1_PIN);
			}
			else if(su16_PWM_TIMER1_Counter==1U)
			{
				su8_PWM_TIMER1_State=PWM_State_Inc;
			}

			su16_PWM_TIMER1_Counter--;
		}
		break;
		
		case PWM_NO_STATE:
		{
			/*Do Nothing*/
		}
		break;
	}
}
static PWM_TIMER2_INTERRUPT_SERVICE_ROUTINE(void)
{
	uint16_t u16_PWM_TIMER2_VALUE=(vsu8_PWM_TIMER2_Duty_Cycle*255)/100.0;
	static uint16_t su16_PWM_TIMER2_Counter=0U;
	static uint8_t  su8_PWM_TIMER2_State=PWM_State_Inc;
	
	if(u16_PWM_TIMER2_VALUE==0U)
	{
		DIO_Write_Pin(vsu8_PWM_TIMER2_PIN,0	);
		su8_PWM_TIMER2_State=PWM_NO_STATE;
	}
	else if(u16_PWM_TIMER2_VALUE==255U)
	{
		su8_PWM_TIMER2_State=PWM_NO_STATE;
	}
	else
	{
		/*Do Nothing*/
	}


	switch(su8_PWM_TIMER2_State)
	{
		case PWM_State_Inc:
		{
			if(su16_PWM_TIMER2_Counter==u16_PWM_TIMER2_VALUE)
			{

				su16_PWM_TIMER2_Counter++;
				DIO_toggle_Pin(vsu8_PWM_TIMER2_PIN);
			}
			else if(su16_PWM_TIMER2_Counter==255U)
			{
				su8_PWM_TIMER2_State=PWM_State_Dec;
				su16_PWM_TIMER2_Counter--;
			}
			else
			{
				su16_PWM_TIMER2_Counter++;
			}

		}
		break;
		
		case PWM_State_Dec:
		{
			if(su16_PWM_TIMER2_Counter==u16_PWM_TIMER2_VALUE)
			{
				DIO_toggle_Pin(vsu8_PWM_TIMER2_PIN);
			}
			else if(su16_PWM_TIMER2_Counter==1U)
			{
				su8_PWM_TIMER2_State=PWM_State_Inc;
			}

			su16_PWM_TIMER2_Counter--;
		}
		break;
		
		case PWM_NO_STATE:
		{
			/*Do Nothing*/
		}
		break;
	}
}

PWM_ERROR_t PWM_INIT(gstr_PWM_INIT_CONFIG*pstr_PWM_INIT_CONFIG)
{
	
	gStrTimerConfiguration_t Str_PWM_Timer_Config;
	PWM_ERROR_t PWM_Error_PWM_INIT=PWM_INIT_NO_ERROR;
	
	if(pstr_PWM_INIT_CONFIG->u8_PWM_Execution_Method==PWM_Software_Config)
	{
		if(pstr_PWM_INIT_CONFIG->u8_PWM_Mode==PWM_Phase_Corret_Config)
		{
			if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type<TIMER0  ||pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type>TIMER2)
			{
			}
			else
			{
				if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type==TIMER0)
				{
					vsu8_PWM_COUNT_TIMER0=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Count;
				}
				else if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type==TIMER1)
				{
					vsu8_PWM_COUNT_TIMER1=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Count;
				}
				else if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type==TIMER2)
				{
					vsu8_PWM_COUNT_TIMER2=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Count;
				}
				Str_PWM_Timer_Config.Timer_Channel=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type;
				Str_PWM_Timer_Config.Timer_Psc=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Prescaler;
				Str_PWM_Timer_Config.Timer_Mode=COUNTER_MODE;
				Str_PWM_Timer_Config.Interrupt_Mode=INTERRUPT;			
				Timer_Init(&Str_PWM_Timer_Config);
			}
		}
		else if(pstr_PWM_INIT_CONFIG->u8_PWM_Execution_Method==PWM_Fast_Config)
		{
			
		}		
		else
		{
			
		}
	}
	else if(pstr_PWM_INIT_CONFIG->u8_PWM_Execution_Method==PWM_Hardware_Config)
	{
		
	}
	else 
	{
		
	}
}

PWM_ERROR_t PWM_Start(uint8_t u8_TIMER_Used,uint8_t u8_PWM_Pin,uint8_t u8_PWM_Duty_Cycle)
{
    DIO_Init_Pin(u8_PWM_Pin,1);
	DIO_Write_Pin(u8_PWM_Pin,1);
    
	if(u8_TIMER_Used==TIMER0)
	{
		vsu8_PWM_TIMER0_Duty_Cycle=u8_PWM_Duty_Cycle;
		Timer_Start(u8_TIMER_Used,vsu8_PWM_COUNT_TIMER0,PWM_TIMER0_INTERRUPT_SERVICE_ROUTINE);	
		vsu8_PWM_TIMER0_PIN=u8_PWM_Pin;
	}
	else if(u8_TIMER_Used==TIMER1)
	{
		vsu8_PWM_TIMER1_Duty_Cycle=u8_PWM_Duty_Cycle;		
		Timer_Start(u8_TIMER_Used,vsu8_PWM_COUNT_TIMER1,PWM_TIMER1_INTERRUPT_SERVICE_ROUTINE);	
	    vsu8_PWM_TIMER1_PIN=u8_PWM_Pin;	
	}
	else if(u8_TIMER_Used==TIMER2)
	{
		vsu8_PWM_TIMER2_Duty_Cycle=u8_PWM_Duty_Cycle;		
		Timer_Start(u8_TIMER_Used,vsu8_PWM_COUNT_TIMER2,PWM_TIMER2_INTERRUPT_SERVICE_ROUTINE);
	    vsu8_PWM_TIMER2_PIN=u8_PWM_Pin;					
	}
	else
	{
		
	}	

}