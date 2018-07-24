/*
 * motor.c
 *
 *  Created on: 2018年7月11日
 *      Author: ghost
 */
#include "include/motor.h"

bool WithoutDream = false;
bool IfUnlock = false;

void Motor_Init() {

	//Initialize
    P1DIR |= BIT0;

    P1OUT |= BIT0;

	P1SEL |= BIT2 | BIT3 | BIT4 | BIT5; 											//从P1.2输出
	P1DIR |= BIT2 | BIT3 | BIT4 | BIT5;

	//初始化定时器
	TA0CTL |= TASSEL_2 + ID_2  + MC_1;
	TA0CCTL1 = OUTMOD_7;
	TA0CCR0 = 7500/*Period*/; //Change me
	TA0CCR1 = 500/*Duty*/;    //Change me

	TA0CCTL2 = OUTMOD_7;
	TA0CCR0 = 7500/*Period*/; //Change me
	TA0CCR2 = 1000/*Duty*/;   //Change me

	TA0CCTL3 = OUTMOD_7;
	TA0CCR0 = 7500/*Period*/; //Change me
	TA0CCR3 = 1500/*Duty*/;   //Change me

	TA0CCTL4 = OUTMOD_7;
	TA0CCR0 = 7500/*Period*/; //Change me
	TA0CCR4 = 2000/*Duty*/;   //Change me

}

void Motor_set_Values(short in_1, short in_2, short in_3, short in_4) {

	if((!WithoutDream) && IfUnlock){
		TA0CCR1 = in_1 * 3/*Duty*/;    	//Change me
		TA0CCR2 = in_2 * 3/*Duty*/;   	//Change me
		TA0CCR3 = in_3 * 3/*Duty*/;   	//Change me
		TA0CCR4 = in_4 * 3/*Duty*/;   	//Change me
	}
	else{
		TA0CCR1 = Motor_PWM_Idle - 100 * 3;//TIM_SetComparex(TIM_TypeDef* TIMx, u16 Comparex)
		TA0CCR2 = Motor_PWM_Idle - 100 * 3;
		TA0CCR3 = Motor_PWM_Idle - 100 * 3;
		TA0CCR4 = Motor_PWM_Idle - 100 * 3;
	}


}

