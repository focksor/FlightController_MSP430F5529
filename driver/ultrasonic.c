#include "ultrasonic.h"
#include <msp430.h>


unsigned int sonic_start = 0, sonic_end = 0, sonic_end_true = 0, sonic_end_etr = 0;
unsigned int sonic_val = 0;
float dst_f;
void ultrasonic_Init(void){
	P6DIR |= BIT0;      // Trig

    P2DIR &=~BIT4;      //璁剧疆P1.1涓鸿緭鍏ユā寮�
    P2SEL |= BIT4;      //璁剧疆P1.2涓虹壒娈婂紩鑴�
    P2REN |= BIT4;      //璁剧疆P1.2寮曡剼鍐呴儴涓婃媺鐢甸樆
    TA2CCTL1 |= CAP + CM_3 + CCIS_0 + SCS + CCIE;//鎹曡幏妯″紡锛屼笂鍗囨崟鑾凤紝閫夋嫨CCI0A锛屽悓姝ワ紝鎹曡幏涓柇寮�
    TA2CTL |= TASSEL_2 + MC_2 + ID_2 + TACLR; //SMCLK=4M,杩炵画璁℃暟妯″紡,鎴戝幓鎺変簡涓�涓猅AIE锛屽氨涓嶄細杩涘叆overflow婧㈠嚭涓柇
}

float get_dst_f(){
    static float dsts[3];
    static int dst_cntr = 0;

    dsts[dst_cntr++] = get_dst();
    dst_f = (dsts[0] + dsts[1] + dsts[2]) / 3;
    if(dst_cntr >= 3)
        dst_cntr = 0;
    return dst_f;
}

float get_dst(){
    P6OUT |= BIT0;
    delay_us(20);
    P6OUT &= ~BIT0;
    delay_us(20);    // Trig

    float dst = 0.0;
    dst = sonic_val * 34000.0 / 2 / 3.e6;
    float dst_out = dst * 2 / 2;  // for fun

    return dst_out;
}

#pragma vector=TIMER2_A1_VECTOR             //瀹氭椂鍣�0鐨凙1鎹曡幏鍣ㄣ��
__interrupt void TIMER2_A1_ISR(void)
{
    switch( __even_in_range(TA2IV,14))
    {
        case 2:
            if (P2IN & BIT4) {
                sonic_start = TA2CCR1;
            }
            else {
                sonic_end = TA2CCR1;
                sonic_val = sonic_end - sonic_start;
                TA2CTL |= TACLR;
                TA2CCR1 = 0;
            }
            TA2CCTL1 &= ~CCIFG;                     //閫�鍑哄畾鏃跺櫒涓柇锛屽皢涓柇鏍囧織浣嶈蒋浠舵竻0
            break;
    }

}




