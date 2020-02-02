/*
 * Car_Steering_User_Interface.h
 *
 * Created: 24/01/2020 19:52:23
 *  Author: Native_programmer
 */ 


#ifndef CAR_STEERING_USER_INTERFACE_H_
#define CAR_STEERING_USER_INTERFACE_H_

#include "Car_Steering_Designer.h"

/*Speed used in code*/
#define SPEED_RATIO_100                              100U
#define SPEED_RATIO_50                               50U
#define SPEED_RATIO_30                               30U
#define SPEED_RATIO_15                               15U

extern Car_Steering_Error_t Car_Init(void);
extern Car_Steering_Error_t Car_Forward(uinteg8_t u8_Ratio_From_Max_Speed);
extern Car_Steering_Error_t Car_Backward(uinteg8_t u8_Ratio_From_Max_Speed);
extern Car_Steering_Error_t Car_Stop(void);
extern Car_Steering_Error_t Car_Rotate_90_Degree(void);
extern Car_Steering_Error_t Car_Seen_Distance(uinteg64_t* Copy_pu64_DIST_IN_CM);

#endif /* CAR_STEERING_USER_INTERFACE_H_ */