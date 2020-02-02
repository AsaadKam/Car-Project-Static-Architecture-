/*
 * EXT_INT_PostBConfig.c
 *
 * Created: 15/01/2020 01:56:13
 *  Author: Native_programmer
 */ 
#include "EXT_INT_PostBConfig.h"

gStr_EXT_INT_CONFIG_t gStr_ICU_RISING_EXT_INT2_CONFIG={ EXT_INT_TYPE_2_CONFIG
															,  EXT_INT_EVENT_RISING_EDGE_CONFIG
															};
													
gStr_EXT_INT_CONFIG_t gStr_ICU_FALLING_EXT_INT2_CONFIG={ EXT_INT_TYPE_2_CONFIG
															 , EXT_INT_EVENT_FALLING_EDGE_CONFIG
															 };