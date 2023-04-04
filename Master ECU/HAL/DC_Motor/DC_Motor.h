

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_

#include "PORT_Interface.h"




#define inc1   DIO_PB5
#define inc2   DIO_PB3

#define M_EN     DIO_PB6

void H_void_Motor_Start_CCw (void);
void H_void_Motor_Start_Cw (void);
void H_void_Motor_Stop (void);



#endif /* DC_MOTOR_DC_MOTOR_H_ */
