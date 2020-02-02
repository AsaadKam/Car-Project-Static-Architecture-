/*
 * DC_Motor_Driver_User_Interface.h
 *
 * Created: 20/01/2020 20:06:44
 *  Author: Native_programmer
 */ 


#ifndef DC_MOTOR_DRIVER_USER_INTERFACE_H_
#define DC_MOTOR_DRIVER_USER_INTERFACE_H_

#include "DC_Motor_Driver_PostBConfig.h"
#include "DC_Motor_Driver_Designer.h"
#include "Data_Types.h"

extern DC_Motor_Driver_Error_t DC_Motor_Driver_Init(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG);
extern DC_Motor_Driver_Error_t DC_Motor_Driver_Stop(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG);
extern DC_Motor_Driver_Error_t DC_Motor_Driver_Forward(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG,uinteg8_t Copy_u8_DC_Motor_Driver_Speed_Duty_cycle);
extern DC_Motor_Driver_Error_t DC_Motor_Driver_Backward(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG,uinteg8_t Copy_u8_DC_Motor_Driver_Speed_Duty_cycle);

#endif /* DC_MOTOR_USER_INTERFACE_H_ */