/*
 * ppm.c
 *
 *  Created on: 2018��7��11��
 *      Author: ghost
 */
#include "include/ppm.h"
#include "AttitudePID.h"
#include "control.h"
int  channel[8] = { 0 };
__rc_channel rc;
char is_first_time = 0;	//��־λflag���ж��Ƿ���һ�δ�ӡ�Ŀ�ʼ
char is_find_start = 0;	//��־λflag2���ж��Ƿ�
/*
static float Pitch_AllErr, Roll_AllErr, Yaw_AllErr;
static float PErr_cntr, RErr_cntr, YErr_cntr;
*/
static unsigned char Flight_Mode;
unsigned int _val;
unsigned int _preval;	//���ڴ洢��һ�ε���ֵ��


/*
 * focksor
 * 7.14.2018

void PPM_Capture_Init(void){
    P2DIR &= ~BIT0;
    P2IE  |= BIT0;
    P2IES &= ~BIT0;
}

#pragma vector = PORT2_VECTOR
__interrupt void PORT2_VECTOR_ISR(void){
    static unsigned int cntr = 0;
    if(cntr++ % 2 == 0){
        P2IFG &= ~BIT0;
        return;
    }

    if(P2IES & BIT0 == 0x00){
        //��ʱ������
        //������ʱ����ʱ
        P2IES |= BIT0;//�½��ش���
        //������ʱ���ж�
    }
    else{
        P2IES &= ~BIT0;
        //��¼��ʱ��ʱ�䵽Ƶ��
    }
    //P2IFG &= ~BIT0;

    if(cntr++ >= 50){
        P4DIR |= BIT7;
        P4OUT ^= BIT7;
        //P1DIR |= BIT0;
        //P1OUT ^= BIT0;
        cntr = 0;
    }
}

//��ʱ���жϣ�����Ƶ��

 */

void PPM_Capture_Init()
{
	P2DIR &=~BIT0;  	//����P1.1Ϊ����ģʽ
	P2SEL |= BIT0;		//����P1.2Ϊ��������
	P2REN |= BIT0;		//����P1.2�����ڲ���������
	TA1CCTL1 |= CAP + CM_1 + CCIS_0 + SCS + CCIE;//����ģʽ����������ѡ��CCI0A��ͬ���������жϿ�
	TA1CTL |= TASSEL_2 + MC_2 + ID_1 + TACLR; //SMCLK=4M,��������ģʽ,��ȥ����һ��TAIE���Ͳ������overflow����ж�
}

void fresh_rc(int i){
    switch(--i){
        case 0:
            rc.roll = channel[i];
            break;
        case 1:
            rc.pitch = channel[i];
            break;
        case 2:
            if(channel[i] < 2020){
                if(Flight_Mode == Normal)
                    rc.throttle = channel[i];
                else if(Flight_Mode == ToHeight){
                    rc.throttle = 1550;
                    if(fabs(channel[i] - 1500) > 20){
                        height_exp += (float)((channel[i] - 1500) / 1000.0);
                        if(height_exp < 10)  height_exp = 10;
                    }
                }
            }
            break;
        case 3:
            rc.yaw = channel[i];
            break;
        case 4:
            if(channel[i] >= 950 && channel[i] <= 1050)
                Flight_Mode = Normal;
            if(channel[i] >= 1150 && channel[i] <= 1250){
                Flight_Mode = ToHeight;
                rc.unlock = 1;
            }
            break;
        case 5:
            if(channel[i] > 1300){
                if(rc.throttle < 1100)
                    rc.unlock = 1;
            }
            else rc.unlock = 0;
            break;
        case 6:
            if(channel[i] > 1300)
                rc.withoutDream = 1;
            else rc.withoutDream = 0;
            break;
    }
}

#pragma vector=TIMER1_A1_VECTOR				//��ʱ��1��A1��������
__interrupt void TIMER1_A1_ISR(void)
{
	static unsigned int i = 0;
	static unsigned int cntr = 0;
	switch( __even_in_range(TA1IV,14))					//ֻ�ж�ż�����ӿ�Ч��
	{
		case 2:
			if(is_first_time == 0)
			{
				//print_str("\nthis is first time\n");	//�������
				_preval = TA1CCR1;						//��һ�ν��������������жϣ���������ֵ��ֵ��PerVal
				is_first_time = 1;						//flag��־λ��1����ʾ����һ�ζ�ȡ
			}
			else
			{	//flag��1֮�󣬽���else���
				_val = TA1CCR1 - _preval;				//�洢��������ֵ
				_preval = TA1CCR1;						//������һ������

				if(_val >= 20000)						//�ж��Ƿ����20000����ʾһ�����ĸߵ�ƽ�Ŀ�ʼ���������
				{										//���õø���һ�㡣8ms��Ӧ32000��ʱ�����ڣ�4MHzʱ��Ƶ�ʣ�
					is_find_start = 1;					//flag2��1�����ڱ�ʾ��ȡ���˿�ʼ�������8������Ϊ8ͨ��
				}
				if(is_find_start == 1&& (_val <= 20000))//�ж�flag2�Ƿ���1������val���ò��ᳬ��20000
				{										//�������С�ڵ���20000������ʵ�ⷢ���޷��������ϵġ�
					channel[i++] = _val / 6;			    // ʱ��4M�������Ҫ����4����us������ȷ��ң����ֵ
				    fresh_rc(i);
					if(i == 8)							//�ж��Ƿ�Ϊ8�飬40/5=8
					{
						//�����һ��֮�����ж�������
						TA1CTL |= TACLR;				//��������0
						//TA1CCTL1 |= CCIE;				//�жϴ򿪣���Ӧ֮ǰ�Ĺر�
						_preval = 0;					//��һ����������ֵ����
						i = 0;							//�����������־λ����
						is_first_time = 0;
						is_find_start = 0;
					}

				}
				TA1CCTL1 &= ~CCIFG;						//�˳���ʱ���жϣ����жϱ�־λ�����0
				break;
	    case 4:											//����Ķ���debug���
	    	//send_byte('4');
	    	break;
	    case 6:
	    	//send_byte('6');
	    	break;
	    case 8:
	    	//send_byte('8');
	    	break;
	    case 0xA:
	    	//send_byte('A');
	    	TA1CCTL0 &= ~CCIFG;
	    	break;
	    case 0xC:
    		//send_byte('C');
    		break;
    	case 0xE:										//������TAIE��ʱ��Ҳ���Ƕ�ʱ������жϿ�������������
    		//send_byte('E');							//����ӡ'E'.
    		break;
	  }
	}
    if(cntr++ >= 200){
        P4DIR |= BIT7;
        P4OUT ^= BIT7;
        cntr = 0;
    }
}

