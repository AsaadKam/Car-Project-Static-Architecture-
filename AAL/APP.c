/* 
 *APP.c
 *(STATE MACHINE)
 * Created: 06/01/2020 13:29:26
 *  Author: Native_programmer
  */
#include"Car_Steering.h"
/*Definition of states*/ 
#define Car_State_Check_Distance					  0
#define Car_State_Distance_More_than_50               1
#define Car_State_Distance_Less_than_50_More_than_30  2
#define Car_State_Distance_Equal_30                   3
#define Car_State_Distance_Less_than_30               4
#define True                                          1
int main()
{
	/*Initialization of variables*/
    uinteg8_t u8_Car_State=Car_State_Check_Distance;
	uinteg8_t u8_Measured_Distance;
	/*Car initialization,includes DC motor driver and ultrasonic sensor*/
    Car_Init();
	
	while(True)
	{
		/*State Machine of car*/
		switch(u8_Car_State)
		{
		   /*Car check distance*/
			case Car_State_Check_Distance:
			{
				Car_Seen_Distance(&u8_Measured_Distance);
				   
				if(u8_Measured_Distance>DISTANCE_50_CM)
				{
					u8_Car_State=Car_State_Distance_More_than_50;
				}
				else if((u8_Measured_Distance<DISTANCE_50_CM)&&(u8_Measured_Distance>DISTANCE_30_CM))
				{
					u8_Car_State=Car_State_Distance_Less_than_50_More_than_30;					   
				}
				else if(u8_Measured_Distance==DISTANCE_30_CM)
				{
					u8_Car_State=Car_State_Distance_Equal_30;
				}	
				else if(u8_Measured_Distance<DISTANCE_30_CM)
				{
					u8_Car_State=Car_State_Distance_Less_than_30;
				}				   			   
			}
			break;
		   /*Car move forward 100 percentage of speed in case of the distance more than 50*/			
			case Car_State_Distance_More_than_50:
			{
				Car_Forward(SPEED_RATIO_100);
				u8_Car_State=Car_State_Check_Distance;
			}
			break;
		   /*Car move forward 50 percentage of speed in case of the distance less than 50 and more than 30*/			
			case Car_State_Distance_Less_than_50_More_than_30 :
			{
				Car_Forward(SPEED_RATIO_50);
				u8_Car_State=Car_State_Check_Distance;																				
			}
			break;
		   /*Car move rotate 90 degree in case of the distance equal 30 */							
			case Car_State_Distance_Equal_30 :
			{
				Car_Rotate_90_Degree();
				u8_Car_State=Car_State_Check_Distance;										
			}
			break;
		   /*Car move backward 15 percentage of speed in case of the distance ;ess than  30 */						
			case Car_State_Distance_Less_than_30 :
			{
				Car_Backward(SPEED_RATIO_15);		
				u8_Car_State=Car_State_Check_Distance;								
			}
			break;			
						
		}
	}
	
}