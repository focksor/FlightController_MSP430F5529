#include <msp430.h>
#include <msp430_clock.h>
#include <sys.h>
#include <imu.h>
#include <control.h>
#include <motor.h>
#include <ppm.h>
#include <ultrasonic.h>
#include <usart.h>

//void clock_init();

int main(void) {
    WDTCTL=WDTPW+WDTHOLD;          //关闭看门狗
    msp430_clock_init(12000000L, 2);
    PPM_Capture_Init();
    Motor_Init();
    ultrasonic_Init();
    InitSelfStability();
    uart_init();

    send_byte('A');

    while (mpu_dmp_init()) {

    }

    static unsigned int cntr = 0;
    static unsigned int cntr2 = 0;

    __enable_interrupt();
    while (1) {

        send_byte('A');

        if (update_IMU_Data() == true){
            send_byte('c');
            if(cntr++ >= 6){
                P3DIR |= BIT7;
                P3OUT ^= BIT7;
                cntr = 0;
            }
            get_dst_f();
            if(cntr2++ >= 20){
                if(dst_f <= EXP_HEIGHT){
                    P4DIR |= BIT0;
                    P4DIR |= BIT3;
                    P4OUT &= ~BIT0;
                    P4OUT |= BIT3;
                }
                else{
                    P4DIR |= BIT0;
                    P4DIR |= BIT3;
                    P4OUT |= BIT0;
                    P4OUT &= ~BIT3;

                }
                cntr2 = 0;
            }

            int motor_1 = 0, motor_2 = 0, motor_3 = 0, motor_4 = 0;
            //refine_RC_PPM_Data();
            control_All(mode_acro, &motor_1, &motor_2, &motor_3, &motor_4);
            Motor_set_Values(motor_1, motor_2, motor_3, motor_4);
        }

    }

//    return 0;
}

/*
void clock_init()
{
    P5SEL |= BIT2|BIT3; //将IO配置为XT2功能
    UCSCTL6 &= ~XT2OFF; //使能XT2

    UCSCTL4 = UCSCTL4&(~(SELA_7))|SELA_1; //先将ACLK配置为VLOCLK
    UCSCTL3 |= SELREF_2;                  //将REFCLK配置为REFCLK

    while (SFRIFG1 & OFIFG)
    {
        UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);         // 清除三类时钟标志位，这里需要清除三种标志位，因为任何一种标志位都会将OFIFG置位
        SFRIFG1 &= ~OFIFG;                                  // 清除时钟错误标志位
    }
    UCSCTL4 = UCSCTL4&(~(SELS_7|SELM_7))|SELS_5|SELM_5;     //将SMCLK和MCLK时钟源配置为XT2

}
*/

/*
#pragma vector = TIMER2_A0_VECTOR
__interrupt void Timer2_A0_IRQHandler(void)
{
    static unsigned char cntr = 0;
    __enable_interrupt();

    if (update_IMU_Data() == true) {
        if(cntr++ >= 3){
            P1DIR |= BIT0;
            P1OUT ^= BIT0;
            cntr = 0;
        }
        //refine_RC_PPM_Data();
        short motor_1 = 0, motor_2 = 0, motor_3 = 0, motor_4 = 0;
        control_All(mode_acro, &motor_1, &motor_2, &motor_3, &motor_4);
        Motor_set_Values(motor_1, motor_2, motor_3, motor_4);
    }
    P6OUT ^= BIT1;							// 反转LED
}
*/
