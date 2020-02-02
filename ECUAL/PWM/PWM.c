/*
 * PWM.c
 *
 * Created: 11/21/2222 22:42:35
 *  Author: Native_programmer
 */ 
#include "Timer.h"
#include "PWM.h"
#include "DIO.h"
#include "DEBUG.h"

#define   PWM_State_Inc				0
#define   PWM_State_Dec				1
#define   PWM_NOTHING_STATE		    2
#define   PWM_FAST_HIGH_STATE		3
#define   PWM_FAST_LOW_STATE		4
volatile  static uinteg8_t vsgu8_PWM_TIMER0_HIGH_STATE_VALUE=0;
volatile  static uinteg8_t vsgu8_PWM_TIMER0_LOW_STATE_VALUE=0;
volatile  static uinteg8_t vsgu8_PWM_TIMER1_HIGH_STATE_VALUE=0;
volatile  static uinteg8_t vsgu8_PWM_TIMER1_LOW_STATE_VALUE=0;
volatile  static uinteg8_t vsgu8_PWM_TIMER2_HIGH_STATE_VALUE=0;
volatile  static uinteg8_t vsgu8_PWM_TIMER2_LOW_STATE_VALUE=0;
volatile  static float64_t  vsf64_PWM_TIMER1_Duty_Cycle=0;
volatile  static float64_t  vsf64_PWM_TIMER2_Duty_Cycle=0;

volatile  static uinteg8_t  vsu8_PWM_TIMER0_PIN=0;
volatile  static uinteg8_t  vsu8_PWM_TIMER1_PIN=0;
volatile  static uinteg8_t  vsu8_PWM_TIMER2_PIN=0;

volatile  static uinteg8_t  vsu8_PWM_COUNT_TIMER0=0;
volatile  static uinteg8_t  vsu8_PWM_COUNT_TIMER1=0;
volatile  static uinteg8_t  vsu8_PWM_COUNT_TIMER2=0;

volatile static uinteg8_t  sgu8_PWM_TIMER0_State=PWM_FAST_HIGH_STATE;
volatile static uinteg8_t  sgu8_PWM_TIMER1_State=PWM_FAST_HIGH_STATE;
volatile static uinteg8_t  sgu8_PWM_TIMER2_State=PWM_FAST_HIGH_STATE;

static void PWM_TIMER0_INTERRUPT_SERVICE_ROUTINE(void)
{

    if(vsgu8_PWM_TIMER0_LOW_STATE_VALUE==0U)
	{
		DIO_Write_Pin(vsu8_PWM_TIMER0_PIN,0);
	}
	else if(vsgu8_PWM_TIMER0_LOW_STATE_VALUE==255)
	{
		DIO_Write_Pin(vsu8_PWM_TIMER0_PIN,1);		
	}
	else
	{	
		 
		switch(sgu8_PWM_TIMER0_State)
		{
			case PWM_FAST_HIGH_STATE:
			{
				 Timer_Start(TIMER0,vsgu8_PWM_TIMER0_HIGH_STATE_VALUE,PWM_TIMER0_INTERRUPT_SERVICE_ROUTINE);			
				 DIO_Write_Pin(vsu8_PWM_TIMER0_PIN,1);
				 
				 sgu8_PWM_TIMER0_State=PWM_FAST_LOW_STATE;
				 
			}
			break;  
			case PWM_FAST_LOW_STATE:
			{ 

				 Timer_Start(TIMER0,vsgu8_PWM_TIMER0_LOW_STATE_VALUE,PWM_TIMER0_INTERRUPT_SERVICE_ROUTINE);					 
				 DIO_Write_Pin(vsu8_PWM_TIMER0_PIN,0);
				 
				 sgu8_PWM_TIMER0_State=PWM_FAST_HIGH_STATE;

			}
			break; 
			case PWM_NOTHING_STATE:
			{
				/*Do Nothing*//*DIO_toggle_Pin(31);*/
			}
			break;
		}
	}
/*	DIO_Write_Pin(30,0);*/
}
static void PWM_TIMER1_INTERRUPT_SERVICE_ROUTINE(void)
{
	Debug_By_Toggle(31);
    if(vsgu8_PWM_TIMER1_LOW_STATE_VALUE==0U)
    {
	    DIO_Write_Pin(vsu8_PWM_TIMER1_PIN,0);
    }
    else if(vsgu8_PWM_TIMER1_LOW_STATE_VALUE==255)
    {
	    DIO_Write_Pin(vsu8_PWM_TIMER1_PIN,1);
    }
    else
    {
	    switch(sgu8_PWM_TIMER1_State)
	    {
		    case PWM_FAST_HIGH_STATE:
		    {
			    Timer_Start(TIMER1,vsgu8_PWM_TIMER1_HIGH_STATE_VALUE,PWM_TIMER1_INTERRUPT_SERVICE_ROUTINE);
			    DIO_Write_Pin(vsu8_PWM_TIMER1_PIN,0);
			    sgu8_PWM_TIMER1_State=PWM_FAST_LOW_STATE;
			    
		    }
		    break;
		    case PWM_FAST_LOW_STATE:
		    {
			    Timer_Start(TIMER1,vsgu8_PWM_TIMER1_LOW_STATE_VALUE,PWM_TIMER1_INTERRUPT_SERVICE_ROUTINE);
			    DIO_Write_Pin(vsu8_PWM_TIMER1_PIN,1);
			    sgu8_PWM_TIMER1_State=PWM_FAST_HIGH_STATE;
		    }
		    break;
		    case PWM_NOTHING_STATE:
		    {
			    /*Do Nothing*/
		    }
		    break;
	    }
    }
    /*	DIO_Write_Pin(30,0);*/
}
static void PWM_TIMER2_INTERRUPT_SERVICE_ROUTINE(void)
{
	
    if(vsgu8_PWM_TIMER2_LOW_STATE_VALUE==0U)
    {
	    DIO_Write_Pin(vsu8_PWM_TIMER2_PIN,0);
    }
    else if(vsgu8_PWM_TIMER2_LOW_STATE_VALUE==255)
    {
	    DIO_Write_Pin(vsu8_PWM_TIMER2_PIN,1);
    }
    else
    {
	    
	    switch(sgu8_PWM_TIMER2_State)
	    {
		    case PWM_FAST_HIGH_STATE:
		    {
			    Timer_Start(TIMER2,vsgu8_PWM_TIMER2_HIGH_STATE_VALUE,PWM_TIMER2_INTERRUPT_SERVICE_ROUTINE);
			    DIO_Write_Pin(vsu8_PWM_TIMER2_PIN,1);
			    
			    sgu8_PWM_TIMER2_State=PWM_FAST_LOW_STATE;
			    
		    }
		    break;
		    case PWM_FAST_LOW_STATE:
		    {

			    Timer_Start(TIMER2,vsgu8_PWM_TIMER2_LOW_STATE_VALUE,PWM_TIMER2_INTERRUPT_SERVICE_ROUTINE);
			    DIO_Write_Pin(vsu8_PWM_TIMER2_PIN,0);
			    sgu8_PWM_TIMER2_State=PWM_FAST_HIGH_STATE;

		    }
		    break;
		    case PWM_NOTHING_STATE:
		    {
			    /*Do Nothing*//*DIO_toggle_Pin(31);*/
		    }
		    break;
	    }
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

			if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type<TIMER0  || pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type>TIMER2)
			{
			}
			else
			{
				if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type==TIMER0)
				{
					vsu8_PWM_TIMER0_PIN=pstr_PWM_INIT_CONFIG->u8_PWM_PIN;
				}
				else if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type==TIMER1)
				{
					vsu8_PWM_TIMER1_PIN=pstr_PWM_INIT_CONFIG->u8_PWM_PIN;
				}
				else if(pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type==TIMER2)
				{
					vsu8_PWM_TIMER2_PIN=pstr_PWM_INIT_CONFIG->u8_PWM_PIN;
				}
				Str_PWM_Timer_Config.Timer_Channel=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Type;
				Str_PWM_Timer_Config.Timer_Psc=pstr_PWM_INIT_CONFIG->u8_PWM_Timer_Preiodicity;
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
	
	 DIO_Init_Pin(pstr_PWM_INIT_CONFIG->u8_PWM_PIN,1);
	 DIO_Write_Pin(pstr_PWM_INIT_CONFIG->u8_PWM_PIN,0);
	 
}

PWM_ERROR_t PWM_Start(uinteg8_t u8_TIMER_Used,uinteg8_t Copy_u8_PWM_Duty_Cycle)
{
    static uinteg8_t su8_PWM_TIMER0_Duty_Cycle=110;
    static uinteg8_t su8_PWM_TIMER1_Duty_Cycle=110;
    static uinteg8_t su8_PWM_TIMER2_Duty_Cycle=110;
	
	static uinteg8_t u8_PWM_TIMER0_Start_Flag=1;
	static uinteg8_t u8_PWM_TIMER1_Start_Flag=1;
	static uinteg8_t u8_PWM_TIMER2_Start_Flag=1;	
		
	if(u8_TIMER_Used==TIMER0)
	{
		if(Copy_u8_PWM_Duty_Cycle!=su8_PWM_TIMER0_Duty_Cycle)
		{
			vsgu8_PWM_TIMER0_LOW_STATE_VALUE=(Copy_u8_PWM_Duty_Cycle*255)/100.0;
			vsgu8_PWM_TIMER0_HIGH_STATE_VALUE=255-vsgu8_PWM_TIMER0_LOW_STATE_VALUE-1;	
			su8_PWM_TIMER0_Duty_Cycle=Copy_u8_PWM_Duty_Cycle;
		}
		else
		{
			/*Do Nothing*/
		}
		if(u8_PWM_TIMER0_Start_Flag==1)
		{
			Timer_Reset(TIMER0);
			Timer_Start(TIMER0,vsgu8_PWM_TIMER0_LOW_STATE_VALUE,PWM_TIMER0_INTERRUPT_SERVICE_ROUTINE);
			
			u8_PWM_TIMER0_Start_Flag=0;
		}
		else
		{
			/*Do Nothing*/
		}				
	}
	else if(u8_TIMER_Used==TIMER1)
	{
		if(Copy_u8_PWM_Duty_Cycle!=su8_PWM_TIMER1_Duty_Cycle)
		{
			vsgu8_PWM_TIMER1_LOW_STATE_VALUE=(Copy_u8_PWM_Duty_Cycle*255)/100.0;
			vsgu8_PWM_TIMER1_HIGH_STATE_VALUE=255-vsgu8_PWM_TIMER1_LOW_STATE_VALUE-1;
			su8_PWM_TIMER1_Duty_Cycle=Copy_u8_PWM_Duty_Cycle;
		}
		else
		{
			/*Do Nothing*/
		}
		if(u8_PWM_TIMER1_Start_Flag==1)
		{
			Timer_Reset(TIMER1);
			Timer_Start(TIMER1,vsgu8_PWM_TIMER1_LOW_STATE_VALUE,PWM_TIMER1_INTERRUPT_SERVICE_ROUTINE);
			
			u8_PWM_TIMER1_Start_Flag=0;
		}
		else
		{
			/*Do Nothing*/
		}	
	}
	else if(u8_TIMER_Used==TIMER2)
	{
		if(Copy_u8_PWM_Duty_Cycle!=su8_PWM_TIMER2_Duty_Cycle)
		{
			vsgu8_PWM_TIMER2_LOW_STATE_VALUE=(Copy_u8_PWM_Duty_Cycle*255)/100.0;
			vsgu8_PWM_TIMER2_HIGH_STATE_VALUE=255-vsgu8_PWM_TIMER2_LOW_STATE_VALUE-1;
			su8_PWM_TIMER2_Duty_Cycle=Copy_u8_PWM_Duty_Cycle;
		}
		else
		{
			/*Do Nothing*/
		}
		if(u8_PWM_TIMER2_Start_Flag==1)
		{
			Timer_Reset(TIMER2);
			Timer_Start(TIMER2,vsgu8_PWM_TIMER2_LOW_STATE_VALUE,PWM_TIMER2_INTERRUPT_SERVICE_ROUTINE);
			
			u8_PWM_TIMER2_Start_Flag=0;
		}
		else
		{
			/*Do Nothing*/
		}				
	}
	else
	{
		/*Do Nothing*/	
	}	

}