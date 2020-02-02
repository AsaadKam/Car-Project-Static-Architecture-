/*
 * EXT_INT_PreLConfig.h
 *
 * Created: 15/01/2020 01:59:20
 *  Author: Native_programmer
 */ 


#ifndef EXT_INT_PRELCONFIG_H_
#define EXT_INT_PRELCONFIG_H_

#include "Atmega32Registers.h"

/*-  Defination of Vectors----------------------------------------*/

#define INT0_VECTOR		__vector_1
#define INT1_VECTOR		__vector_2
#define INT2_VECTOR     __vector_3

/*-  Defination of ISR -------------------------------------------*/

#define EXT_INT_ISR(N)            \
void N (void)__attribute((signal,used)); \
void N (void)

/*- NickNames for Registers and configuration values--------*/

#define EXT_INT_ENABLE_INT0_REG		      GICR  
#define EXT_INT_ENABLE_INT1_REG		      GICR 
#define EXT_INT_ENABLE_INT2_REG			  GICR
 
#define EXT_INT0_ENABLE_BITS			  0b01000000
#define EXT_INT1_ENABLE_BITS			  0b10000000
#define EXT_INT2_ENABLE_BITS			  0b00100000

#define EXT_INT_EVENT_INT0_REG			  MCUCR 
#define EXT_INT_EVENT_INT1_REG			  MCUCR 
#define EXT_INT_EVENT_INT2_REG			  MCUCSR 

#define EXT_INT0_EVENT_FALLING_EDGE_BITS  0b00000010
#define EXT_INT0_EVENT_RISING_EDGE_BITS   0b00000011
#define EXT_INT1_EVENT_FALLING_EDGE_BITS  0b00000010
#define EXT_INT1_EVENT_RISING_EDGE_BITS   0b00000011
#define EXT_INT2_EVENT_FALLING_EDGE_BITS  0b00000000
#define EXT_INT2_EVENT_RISING_EDGE_BITS   0b00000001
#endif /* EXT_INT_PRELCONFIG_H_ */