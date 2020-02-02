/*
 * Car_Steering.c
 *
 * Created: 24/01/2020 19:33:40
 *  Author: Native_programmer
 */ 
#include"Car_Steering.h"

Car_Steering_Error_t Car_Init(void)
{
	/*Ultrasonic sensor initiate*/	
	Ultra_Sonic_Init();
	/*DC Motor initiate*/
	DC_Motor_Driver_Init(&gStr_DC_Motor_Driver_1_CONFIG);
	DC_Motor_Driver_Init(&gStr_DC_Motor_Driver_2_CONFIG);
}
Car_Steering_Error_t Car_Forward(uinteg8_t u8_Ratio_From_Max_Speed)
{
	DC_Motor_Driver_Forward(&gStr_DC_Motor_Driver_1_CONFIG,u8_Ratio_From_Max_Speed);
	DC_Motor_Driver_Forward(&gStr_DC_Motor_Driver_2_CONFIG,u8_Ratio_From_Max_Speed);	
}
Car_Steering_Error_t Car_Backward(uinteg8_t u8_Ratio_From_Max_Speed)
{
	DC_Motor_Driver_Backward(&gStr_DC_Motor_Driver_1_CONFIG,u8_Ratio_From_Max_Speed);
	DC_Motor_Driver_Backward(&gStr_DC_Motor_Driver_2_CONFIG,u8_Ratio_From_Max_Speed);
}
Car_Steering_Error_t Car_Stop(void)
{
	DC_Motor_Driver_Stop(&gStr_DC_Motor_Driver_1_CONFIG);
	DC_Motor_Driver_Stop(&gStr_DC_Motor_Driver_2_CONFIG);	
}
Car_Steering_Error_t Car_Rotate_90_Degree(void)
{
	Car_Stop();
	_delay_ms(200);	
	DC_Motor_Driver_Forward(&gStr_DC_Motor_Driver_1_CONFIG,15);
	DC_Motor_Driver_Backward(&gStr_DC_Motor_Driver_2_CONFIG,15);
	_delay_ms(600);
	Car_Stop();
	_delay_ms(200);		
}

Car_Steering_Error_t Car_Seen_Distance(uinteg64_t* Copy_pu64_DIST_IN_CM)
{
	Ultra_Sonic_Get_Distance(Copy_pu64_DIST_IN_CM);
}
