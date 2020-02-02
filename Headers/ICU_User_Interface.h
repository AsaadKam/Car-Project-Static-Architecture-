/*
 * ICU_User_Interface.h
 *
 * Created: 20/01/2020 04:52:42
 *  Author: Native_programmer
 */ 


#ifndef ICU_USER_INTERFACE_H_
#define ICU_USER_INTERFACE_H_




#include "ICU_PostBConfig.h"
#include "ICU_Designer.h"


/** 
 * \brief ICU_Init: A function that init the timer and the external interrupt used to make the software ICU
 *
 * \param gStr_ICU_CONFIG_t* Copy_p_gstr_ICU_CONFIG
 * \return void
 *
 **/     
extern ICU_ERROR_t ICU_Init(gStr_ICU_CONFIG_t* Copy_p_gstr_ICU_CONFIG);


/** 
 * \brief ICU_Get_Time : This function only passes the the on & off time to the two passed pointers
 *
 * \param *pu8On_time_buffer (Output) : The on time measured will be passed to this parameter
 * \param *pu8Off_time_buffer (Output) : The off time measured will be passed to this parameter
 * \return void
 *
 **/     
extern ICU_ERROR_t ICU_Get_Time_In_MICROSECONDS(uinteg64_t *Copy_pu64_On_off_time_buffer);


#endif /* ICU_USER_INTERFACE_H_ */