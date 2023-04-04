/*
 * RTOS_types.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Ahmed Hesham
 */

#ifndef RTOS_RTOS_TYPES_H_
#define RTOS_RTOS_TYPES_H_


typedef enum{
	TASK_SUSPEND,
	TASK_RESUMED
}Task_Status_t;

typedef struct{
	u8 Task;
	u8 delay;
}delay_t;



#endif /* RTOS_RTOS_TYPES_H_ */
