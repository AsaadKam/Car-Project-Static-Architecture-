/* 
 *Software PWM using CTC.c
 *
 * Created: 06/01/2020 13:29:26
 *  Author: Native_programmer
  */

/*-  Defination of Vectors----------------------------------------*/

#define TIMER0_COMP_VECTOR		__vector_10
#define TIMER1_COMPA_VECTOR  	__vector_7
#define TIMER1_COMPB_VECTOR 	__vector_8
#define TIMER2_COMP_VECTOR      __vector_4
#define TIMER2_OVF			    __vector_5

/*-  Definition of ISR -------------------------------------------*/

#define Timer_ISR(N)            \
void N (void)__attribute((signal,used)); \
void N (void)

#include "Atmega32Registers.h"
#include "Timer.h"

int main()
{
	/*Initiate Output compare value*/
	OCR1A=127;
	/*Initialize Timer 1 as CTC mode and choose 1024 prescaler value*/
	TCCR1A=0b00000000U;
	TCCR1B=0b00001101;
	/*Enable interrupt*/	
	SREG=1<<7;
	/*Initialize pin of the Led in portD*/		
	DDRD|=1<<5;
	/*Enable timer 1 interrupt*/		
	TIMSK=1<<OCIE1A;
	
	while(1)
	{
       /*Do Nothing ,except prevent code from reach the end*/
	}
	
}
/*ISR implementation*/
Timer_ISR(TIMER1_COMPA_VECTOR)
{
    /*State variable*/
	static uinteg8_t u8_state=0;
	
	switch(u8_state)
	{
		/*In case number one we are going to  set the 1st value to get the software PWM */
		case 0:
		{
			/**Setting the 1nd value to get the relevant duty cycle*/			
			OCR1A=127;
			/**Toggle LED on port D pin 5*/
			PORTD^=(1<<5);
			/*Change the state*/
			u8_state=1;
		}
		break;
		/*In case number two we are going to set the 2nd value  to get the software PWM */		
		case 1 :
		{
			/**Setting the 2nd value to get the relevant duty cycle*/			
			OCR1A=128;
			/**Toggle LED on port D pin 5*/			
			PORTD^=(1<<5);
			/*Change the state*/			
			u8_state=0;
		}
		break;
	}

}

/*



int main()
{
	/*Initiate Output compare value*/	
	OCR2=127;
	/*Initialize Timer 2 as CTC mode and choose 1024 prescaler value*/	
	TCCR2=0B00001111;
	/*Enable interrupt*/	
	SREG=1<<7;
	/*Initialize pin of the Led in portD*/		
	DDRD|=1<<5;
	/*Enable timer 2 interrupt*/			
	TIMSK=1<<OCIE2;
	while(1)
	{

	}
	
}
/*ISR implementation*/
Timer_ISR(TIMER2_COMP_VECTOR)
{
    /*State variable*/
	static uinteg8_t u8_state=0;
	
	switch(u8_state)
	{
		/*In case number one we are going to  set the 1st value to get the software PWM */		
		case 0:
		{
			/**Setting the 1nd value to get the relevant duty cycle*/			
			OCR2=127;
			/**Toggle LED on port D pin 5*/			
			PORTD^=(1<<5);
			/*Change the state*/			
			u8_state=1;
		}
		break;
		/*In case number two we are going to set the 2nd value  to get the software PWM */			
		case 1 :
		{
			/**Setting the 2nd value to get the relevant duty cycle*/			
			OCR2=128;
			/**Toggle LED on port D pin 5*/				
			PORTD^=(1<<5);
			/*Change the state*/			
			u8_state=0;
		}
		break;
	}

}
*/