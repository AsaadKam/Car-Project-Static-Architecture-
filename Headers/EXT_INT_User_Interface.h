/*
 * Ext_Int2.h
 *
 * Created: 15/01/2020 01:36:40
 *  Author: Native_programmer
 */ 

#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_PostBConfig.h"
#include "EXT_INT_Designer.h"
#include "Data_Types.h"




/** 
 * \brief EXT_INT_INIT : Function that initiate external interrupt with the desired mode
 *
 * \param gStr_EXT_INT_CONFIG_t* pntrStr_EXT_INT_CONFIG(Input) : The desired mode to initiate external interrupt  ( It has to be one of the defined modes (FALLING EDGE  .. etc) )
 * \return EXT_INT_ERROR_t : The return of this function will be an indication of the execution
 *
 **/     
extern EXT_INT_ERROR_t EXT_INT_INIT(gStr_EXT_INT_CONFIG_t* Copy_pntrStr_EXT_INT_CONFIG);
  
extern EXT_INT_ERROR_t EXT_INT0_CALL_BACK(PntrToFunc_t Copy_pntrToFunc_EXT_INT0_ISR);
    
extern EXT_INT_ERROR_t EXT_INT1_CALL_BACK(PntrToFunc_t Copy_pntrToFunc_EXT_INT1_ISR);

extern EXT_INT_ERROR_t EXT_INT2_CALL_BACK(PntrToFunc_t Copy_pntrToFunc_EXT_INT2_ISR);

#endif /* EXT_INT_H_ */