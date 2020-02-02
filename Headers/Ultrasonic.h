/*
 * Ultrasonic.h
 *
 * Created: 20/01/2020 06:55:33
 *  Author: Native_programmer
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "Ultrasonic_Designer.h"
/** 
 * \brief Ultra_Sonic_Get_Distance : This function uses timer0 & external interrupt 2 to measure the time between sending a certain wave and recieving it from the ultra sonic sensor
 *
 * \param *pu16Reading (Output) : The time reading is passed to this parameter
 * \return void
 *
 **/     
/*Distance used in code*/
#define DISTANCE_50_CM                               50U
#define DISTANCE_30_CM                               30U

extern Ultra_Error_t Ultra_Sonic_Get_Distance(uinteg16_t *pu16Reading);

/** 
 * \brief Ultra_Sonic_Init : Initializing the ultra sonic sensor by initializing the used timer and the used external interrupt
 *
 * \param void
 * \return void
 *
 **/     
extern Ultra_Error_t Ultra_Sonic_Init();



#endif /* ULTRASONIC_H_ */