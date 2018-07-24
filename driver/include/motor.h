/*
 * motor.h
 *
 *  Created on: 2018��7��11��
 *      Author: ghost
 */

#ifndef DRIVER_INCLUDE_MOTOR_H_
#define DRIVER_INCLUDE_MOTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys.h>
#include <msp430.h>

#define Motor_PWM_Period 7499		    //PWM��ʱ�����ֵ
#define Motor_PWM_Idle   (2999-170*3)	//PWM��ֵ

void Motor_Init();
void Motor_set_Values(short in_1, short in_2, short in_3, short in_4);

extern bool WithoutDream;
extern bool IfUnlock;

#ifdef __cplusplus
}
#endif

#endif /* DRIVER_INCLUDE_MOTOR_H_ */
