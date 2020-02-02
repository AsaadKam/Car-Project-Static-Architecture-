/*
 * LCD_PostBConfig.c
 *
 * Created: 12/21/2222 19:21:22
 *  Author: Native_programmer
 */ 

#include "LCD_PostBConfig.h"

gstr_LCD_Config_t gstr_Temprature_Sensor_LCD ={  LCD_Execution_Timer_Driven_Enable
												,LCD_4BIT_COMM
												,LCD_Generate_Cursor_Enable
											  };
											  
gstr_LCD_Config_t gstr_CAR_LCD_CONFIG        ={  LCD_Execution_Delay_Enable
												,LCD_4BIT_COMM
												,LCD_Generate_Cursor_Enable
												};