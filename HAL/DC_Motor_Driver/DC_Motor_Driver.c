/*
 * DC_Motor_Driver.c
 *
 * Created: 20/01/2020 20:03:21
 *  Author: Native_programmer
 */ 
#include "DIO.h"
#include "PWM.h"
#include "DC_Motor_Driver_PostBConfig.h"
#include "DC_Motor_Driver_Designer.h"

DC_Motor_Driver_Error_t DC_Motor_Driver_Init(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG)
{
	gstr_PWM_INIT_CONFIG str_DC_Motor_PWM_INIT_CONFIG={  PWM_Software_Config
														,PWM_Phase_Corret_Config
														,PWM_TIMER1
														,PWM_Periodicty_30_HZ_TIMER_1
														,Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_PWM_Pin
														};
														
	PWM_INIT(&str_DC_Motor_PWM_INIT_CONFIG);
	DIO_Init_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Backward_Pin,1);
	DIO_Init_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Forward_Pin,1);
}
DC_Motor_Driver_Error_t DC_Motor_Driver_Stop(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG)
{
	DIO_Write_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Backward_Pin,0);
	DIO_Write_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Forward_Pin,0);	
}
DC_Motor_Driver_Error_t DC_Motor_Driver_Forward(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG,uinteg8_t Copy_u8_DC_Motor_Driver_Speed_Duty_cycle)
{

   PWM_Start(PWM_TIMER1,Copy_u8_DC_Motor_Driver_Speed_Duty_cycle);
   DIO_Write_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Forward_Pin,1);
   DIO_Write_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Backward_Pin,0);

}
DC_Motor_Driver_Error_t DC_Motor_Driver_Backward(gStr_DC_Motor_Driver_CONFIG_t* Copy_str_DC_Motor_Driver_CONFIG,uinteg8_t Copy_u8_DC_Motor_Driver_Speed_Duty_cycle)
{
	PWM_Start(PWM_TIMER1,Copy_u8_DC_Motor_Driver_Speed_Duty_cycle);
	DIO_Write_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Backward_Pin,1);
	DIO_Write_Pin(Copy_str_DC_Motor_Driver_CONFIG->u8_DC_Motor_Driver_Forward_Pin,0);
}