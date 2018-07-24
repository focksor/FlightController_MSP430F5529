/*
 * usart.c
 *
 *  Created on: 2018年7月21日
 *      Author: God_F
 */


#include "usart.h"
uint usart_flag = 0;  //标志位flag，判断是否是一次打印的开始
uint usart_flag2 = 0; //标志位flag2，判断是否

//***************************串口初始化函数***************************//
void uart_init()
{
    P4SEL = BIT4+BIT5;                            // P5_6和P5_7第二功能打开，设置方向
    UCA1CTL1 |= UCSWRST;          // 首先使RST位置位，只有这样后面的设置才有效
    UCA1CTL1 |= UCSSEL__SMCLK;                  // SMCLK，为系统时钟4MHz
    UCA1BR0 = 104;                            // 4MHz 115200
    UCA1BR1 = 0;                               // 4MHz 115200
    UCA1MCTL |= 0x02;        // 设置调整参数UCBRSx=1, UCBRFx=0
    UCA1CTL1 &= ~UCSWRST;                // RST复位
    UCA1IE |= UCRXIE;
}
//********************************************************************//

//***********************单个字符发送函数*****************************//
void send_byte(uchar c)
{
    if(c == '\n')
        send_byte('\r');
        while (!(UCA1IFG & UCTXIFG));       //等待上一个字节发送完毕
        UCA1TXBUF = c;
}
//********************************************************************//

//************************发送字符串函数******************************//
void print_str(uchar *s)
{
    while(*s != '\0')
        send_byte(*s++);

}
//********************************************************************//

//************************内存空间赋值********************************//
void memset(uchar *p, int val, int length)
{
    int i;

    for (i=0; i<length; i++)
    {
        p[i] = val;
    }
}
//********************************************************************//


//**************************串口接受中断isr***************************//

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
    switch(__even_in_range(UCA1IV,4))
    {
    case 0:break;
    case 2:
            while (!(UCA1IFG&UCTXIFG));
            UCA1TXBUF = UCA1RXBUF;
            break;
    case 4:break;
    default: break;
    }
}


//************************TIMER0_A1_VECTOR****************************//

