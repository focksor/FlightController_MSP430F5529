/*
 * ppm.c
 *
 *  Created on: 2018年7月11日
 *      Author: ghost
 */
#include "include/ppm.h"
#include "AttitudePID.h"
#include "control.h"
int  channel[8] = { 0 };
__rc_channel rc;
char is_first_time = 0;	//标志位flag，判断是否是一次打印的开始
char is_find_start = 0;	//标志位flag2，判断是否
/*
static float Pitch_AllErr, Roll_AllErr, Yaw_AllErr;
static float PErr_cntr, RErr_cntr, YErr_cntr;
*/
static unsigned char Flight_Mode;
unsigned int _val;
unsigned int _preval;	//用于存储上一次的数值。


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
        //定时器重置
        //开启定时器计时
        P2IES |= BIT0;//下降沿触发
        //开启定时器中断
    }
    else{
        P2IES &= ~BIT0;
        //记录定时器时间到频道
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

//定时器中断，重置频道

 */

void PPM_Capture_Init()
{
	P2DIR &=~BIT0;  	//设置P1.1为输入模式
	P2SEL |= BIT0;		//设置P1.2为特殊引脚
	P2REN |= BIT0;		//设置P1.2引脚内部上拉电阻
	TA1CCTL1 |= CAP + CM_1 + CCIS_0 + SCS + CCIE;//捕获模式，上升捕获，选择CCI0A，同步，捕获中断开
	TA1CTL |= TASSEL_2 + MC_2 + ID_1 + TACLR; //SMCLK=4M,连续计数模式,我去掉了一个TAIE，就不会进入overflow溢出中断
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

#pragma vector=TIMER1_A1_VECTOR				//定时器1的A1捕获器。
__interrupt void TIMER1_A1_ISR(void)
{
	static unsigned int i = 0;
	static unsigned int cntr = 0;
	switch( __even_in_range(TA1IV,14))					//只判断偶数，加快效率
	{
		case 2:
			if(is_first_time == 0)
			{
				//print_str("\nthis is first time\n");	//调试语句
				_preval = TA1CCR1;						//第一次进入上升沿跳变中断，将计数器值赋值给PerVal
				is_first_time = 1;						//flag标志位置1，表示这是一次读取
			}
			else
			{	//flag置1之后，进入else语句
				_val = TA1CCR1 - _preval;				//存储计数器差值
				_preval = TA1CCR1;						//保存上一次数据

				if(_val >= 20000)						//判断是否大于20000，表示一个长的高电平的开始。这里可以
				{										//设置得更大一点。8ms对应32000个时钟周期（4MHz时钟频率）
					is_find_start = 1;					//flag2置1，用于表示读取到了开始，后面的8个数据为8通道
				}
				if(is_find_start == 1&& (_val <= 20000))//判断flag2是否置1，并且val的置不会超过20000
				{										//后面这个小于等于20000，是我实测发现无法工作加上的。
					channel[i++] = _val / 6;			    // 时钟4M，这边需要除以4才是us，即正确的遥控器值
				    fresh_rc(i);
					if(i == 8)							//判断是否为8组，40/5=8
					{
						//输出完一组之后所有东西重置
						TA1CTL |= TACLR;				//计数器清0
						//TA1CCTL1 |= CCIE;				//中断打开，对应之前的关闭
						_preval = 0;					//上一个计数器数值清零
						i = 0;							//各类变量、标志位清零
						is_first_time = 0;
						is_find_start = 0;
					}

				}
				TA1CCTL1 &= ~CCIFG;						//退出定时器中断，将中断标志位软件清0
				break;
	    case 4:											//下面的都是debug语句
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
    	case 0xE:										//当设置TAIE的时候，也就是定时器溢出中断开，则会进入这里
    		//send_byte('E');							//疯狂打印'E'.
    		break;
	  }
	}
    if(cntr++ >= 200){
        P4DIR |= BIT7;
        P4OUT ^= BIT7;
        cntr = 0;
    }
}

