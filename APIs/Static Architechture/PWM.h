/*
 * PWM.h
 *
 * Created: 12/15/2019 10:35:11 PM
 *  Author: A.Elkady
 */ 


#ifndef PWM_H_
#define PWM_H_

/*
*	Header files inclusions
*/
#include "DIO.h"
#include "Timer.h"
#include "PWM_cfg.h"
#include "PWM_Ret_Val.h"
#include <avr/interrupt.h>

/*
*	Used macros
*/
#define MAX_DUTY_CYCLE 100
/** 
 * \brief PWM_Init : A function that initialize timer 1 to give PWM of different duty cycles on different pins  
 *						but with the same frequency for all of them ( Changing the frequency will affect all pins in the same way)
 * \param void
 * \return void
 *
 **/     
extern Error PWM_Init(void);

/** 
 * \brief PWM_OCRA : A function that gives a certain duty cycle on a pre chosen pin
 *
 * \param u8Duty_cycle (Input) : The duty cycle of that need to be applied 
 * \return void
 *
 **/     
extern Error PWM_OCRA(u8 u8Duty_cycle);

/** 
 * \brief PWM_OCRB : A function that gives a certain duty cycle on a pre chosen pin
 *
 * \param u8Duty_cycle (Input) : The duty cycle of that need to be applied 
 * \return void
 *
 **/
extern Error PWM_OCRB(u8 u8Duty_cycle);


#endif /* PWM_H_ */