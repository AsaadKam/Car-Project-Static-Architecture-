/*
 * Ext_Int2.h
 *
 * Created: 11/22/2019 5:56:19 PM
 *  Author: A.Elkady
 */ 


#ifndef EXT_INT2_H_
#define EXT_INT2_H_

/*
*	Header files inclusions
*/
#include <avr/interrupt.h>
#include "Interrupt.h"
#include "Data_Types.h"
#include "EXT_INT2_Ret_Val.h"

/*
*	Definition of external interrupts Control registers
*/
#define MCU_CSR  ( *((volatile unsigned char *) (0x54) ) )
#define GI_CR	 ( *((volatile unsigned char *) (0x5B) ) )
#define GI_FR    ( *((volatile unsigned char *) (0x5A) ) )

/*
*	Definition of interrupt 2 pins
*/
#define INT_2 5
#define INT_F2 5

#define ISC_2 6

/*
*	Definition of Extern interrupt 2 modes
*/
#define FALLING_EDGE_2 0
#define RISING_EDGE_2  1

/** 
 * \brief Ext_Int2_Init : Function that initiate external interrupt 2 with the desired mode
 *
 * \param u8Mode(Input) : The desired mode to initiate external interrupt 2 ( It has to be one of the defined modes (FALLING EDGE  .. etc) )
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/     
extern Error Ext_Int2_Init(u8 u8Mode);

/** 
 * \brief Ext_Int2_Deinit : Function that deinitiate external interrupt 2
 *
 * \param -> Takes not parameters
 * \return -> void
 *
 **/  
extern void Ext_Int2_Deinit();

#endif /* EXT_INT2_H_ */