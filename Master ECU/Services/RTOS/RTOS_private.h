/*
 * RTOS_private.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Ahmed Hesham
 */

#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_


typedef struct{
	void (*TaskHandler)(void);
	u8 Periodicity;
	u8 First_Delay;
	Task_Status_t status;

}Task_t;


void Set_OS_Timer (void);  //Function passed to timer
void RTOS_void_Schedular (void);


#endif /* RTOS_RTOS_PRIVATE_H_ */
