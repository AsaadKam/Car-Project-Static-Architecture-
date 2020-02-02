/*
 * Ultra_Sonic.h
 *
 * Created: 11/18/2019 11:09:34 PM
 *  Author: A.Elkady
 */ 


#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

/*
*	Header files inclusions
*/
#include "Timer.h"
#include "Data_Types.h"
#include "DIO.h"
#include "ICU.h"
#include "Ultra_Sonic_Ret_Val.h"
#include "Ultra_Sonic_cfg.h"

/** 
 * \brief Ultra_Sonic_Get_Distance : This function uses timer0 & external interrupt 2 to measure the time between sending a certain wave and recieving it from the ultra sonic sensor
 *
 * \param *pu16Reading (Output) : The time reading is passed to this parameter
 * \return void
 *
 **/     
extern Error Ultra_Sonic_Get_Distance(uinteg16_t *pu16Reading);

/** 
 * \brief Ultra_Sonic_Init : Initializing the ultra sonic sensor by initializing the used timer and the used external interrupt
 *
 * \param void
 * \return void
 *
 **/     
extern Error Ultra_Sonic_Init();

#endif /* ULTRA_SONIC_H_ */