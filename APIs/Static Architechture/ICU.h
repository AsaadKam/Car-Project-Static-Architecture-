/*
 * ICU.h
 *
 * Created: 11/16/2019 4:58:40 PM
 *  Author: A.Elkady
 */ 


#ifndef ICU_H_
#define ICU_H_

/*
*	Header files inclusions
*/
#include "Data_Types.h"
#include "Delay.h"
#include "Timer.h"
#include "Ext_Int2.h"
#include "avr/interrupt.h"
#include "ICU_Ret_Val.h"
#include "ICU_cfg.h"

/*
*	Used macros
*/
#define GETTING_OFF_TIME 0
#define GETTING_ON_TIME 1

/*
*	Enumeration that holds the target from using this software ICU whether to get one of the on / off times or both of them
*/
typedef enum int
{
	ON_PERIOD = 0 ,
	DUTY_CYCLE
}ICU_target;

/** 
 * \brief ICU_Get_Time : This function only passes the the on & off time to the two passed pointers
 *
 * \param *pu8On_time_buffer (Output) : The on time measured will be passed to this parameter
 * \param *pu8Off_time_buffer (Output) : The off time measured will be passed to this parameter
 * \return void
 *
 **/     
extern Error ICU_Get_Time(u8 *pu8On_time_buffer , u8 *pu8Off_time_buffer);

/** 
 * \brief ICU_Init: A function that init the timer and the external interrupt used to make the software ICU
 *
 * \param void
 * \return void
 *
 **/     
extern Error ICU_Init(void);

#endif /* ICU_H_ */