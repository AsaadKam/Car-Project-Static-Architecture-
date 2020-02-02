/*
 * EXT_INT.c
 *
 * Created: 15/01/2020 01:55:26
 *  Author: Native_programmer
 */ 
#include "BitManipulation.h"
#include "EXT_INT_User_Interface.h"


volatile PntrToFunc_t vgpntrToFunc_EXT_INT0_ISR=NullPointer,vgpntrToFunc_EXT_INT1_ISR=NullPointer,vgpntrToFunc_EXT_INT2_ISR=NullPointer;

EXT_INT_ERROR_t EXT_INT_INIT(gStr_EXT_INT_CONFIG_t* pntrStr_EXT_INT_CONFIG)
{
	EnableGeneralInterrupt();
	if(pntrStr_EXT_INT_CONFIG->EXT_INT_TYPE==EXT_INT_TYPE_0_CONFIG)
	{
  
		  if(pntrStr_EXT_INT_CONFIG->EXT_INT_EVENT==EXT_INT_EVENT_RISING_EDGE_CONFIG)
		  {
			  EXT_INT0_EVENT_RISING_EDGE();
		  }
		  else if(pntrStr_EXT_INT_CONFIG->EXT_INT_EVENT==EXT_INT_EVENT_FALLING_EDGE_CONFIG)
		  {
			  EXT_INT0_EVENT_FALLING_EDGE();		  
		  }
		  else
		  {
		  
		  }
		  EXT_INT0_ENABLE();
	}
	else if(pntrStr_EXT_INT_CONFIG->EXT_INT_TYPE==EXT_INT_TYPE_1_CONFIG)
	{
		
		if(pntrStr_EXT_INT_CONFIG->EXT_INT_EVENT==EXT_INT_EVENT_RISING_EDGE_CONFIG)
		{
			EXT_INT1_EVENT_RISING_EDGE();
		}
		else if(pntrStr_EXT_INT_CONFIG->EXT_INT_EVENT==EXT_INT_EVENT_FALLING_EDGE_CONFIG)
		{
			EXT_INT1_EVENT_FALLING_EDGE();
		}
		else
		{
			
		}
		EXT_INT1_ENABLE();
	}
	else if(pntrStr_EXT_INT_CONFIG->EXT_INT_TYPE==EXT_INT_TYPE_2_CONFIG)
	{
		
		if(pntrStr_EXT_INT_CONFIG->EXT_INT_EVENT==EXT_INT_EVENT_RISING_EDGE_CONFIG)
		{
			EXT_INT2_EVENT_RISING_EDGE();
		}
		else if(pntrStr_EXT_INT_CONFIG->EXT_INT_EVENT==EXT_INT_EVENT_FALLING_EDGE_CONFIG)
		{
			EXT_INT2_EVENT_FALLING_EDGE();
		}
		else
		{
			
		}
		EXT_INT2_ENABLE();
	}
    else
	{
		
	}
}
EXT_INT_ERROR_t EXT_INT0_CALL_BACK(PntrToFunc_t Copy_pntrToFunc_EXT_INT0_ISR)
{
	vgpntrToFunc_EXT_INT0_ISR=Copy_pntrToFunc_EXT_INT0_ISR;
}
EXT_INT_ERROR_t EXT_INT1_CALL_BACK(PntrToFunc_t Copy_pntrToFunc_EXT_INT1_ISR)
{
	vgpntrToFunc_EXT_INT1_ISR=Copy_pntrToFunc_EXT_INT1_ISR;	
}
EXT_INT_ERROR_t EXT_INT2_CALL_BACK(PntrToFunc_t Copy_pntrToFunc_EXT_INT2_ISR)
{
	vgpntrToFunc_EXT_INT2_ISR=Copy_pntrToFunc_EXT_INT2_ISR;
}
EXT_INT_ISR(INT0_VECTOR)
{
	vgpntrToFunc_EXT_INT0_ISR();
}
EXT_INT_ISR(INT1_VECTOR)
{
	vgpntrToFunc_EXT_INT1_ISR();	
}
EXT_INT_ISR(INT2_VECTOR)
{
	vgpntrToFunc_EXT_INT2_ISR();
}
