/*
 * RTOS_interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Ahmed Hesham
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_

#include "RTOS_types.h"
#include "RTOS_cfg.h"


void RTOS_Init (void);
void RTOS_Start(void);
void RTOS_void_CreateTask (u8 local_priority,u8 local_periodicity, void (local_PtoFunc)(void),u8 local_first_delay,Task_Status_t local_status);
void RTOS_void_SusbendTask (u8 local_priority);
void RTOS_void_SusbendTask_Delay (u8 local_priority, u8 local_desired_delay);
void RTOS_void_ResumeTask (u8 local_priority);
void RTOS_void_DeleteTask (u8 local_priority);



void Delay_Task_Checker (void);





#endif /* RTOS_RTOS_INTERFACE_H_ */
