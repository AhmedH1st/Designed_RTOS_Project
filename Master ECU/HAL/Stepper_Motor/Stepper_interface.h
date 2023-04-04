/*
 * Stepper_interface.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Ahmed Hesham
 */

#ifndef STEPPER_MOTOR_STEPPER_INTERFACE_H_
#define STEPPER_MOTOR_STEPPER_INTERFACE_H_


#include "Stepper_tpyes.h"
#include "Stepper_private.h"
#include "Stepper_cfg.h"


void Stepper_UniPoler_Step_CW (void);
void Stepper_Step1(void);
void Stepper_Step2(void);
void Stepper_Step3(void);
void Stepper_Step4(void);

#endif /* STEPPER_MOTOR_STEPPER_INTERFACE_H_ */
