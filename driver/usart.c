/*
 * usart.c
 *
 *  Created on: 2018��7��21��
 *      Author: God_F
 */


#include "usart.h"
uint usart_flag = 0;  //��־λflag���ж��Ƿ���һ�δ�ӡ�Ŀ�ʼ
uint usart_flag2 = 0; //��־λflag2���ж��Ƿ�

//***************************���ڳ�ʼ������***************************//
void uart_init()
{
    P4SEL = BIT4+BIT5;                            // P5_6��P5_7�ڶ����ܴ򿪣����÷���
    UCA1CTL1 |= UCSWRST;          // ����ʹRSTλ��λ��ֻ��������������ò���Ч
    UCA1CTL1 |= UCSSEL__SMCLK;                  // SMCLK��Ϊϵͳʱ��4MHz
    UCA1BR0 = 104;                            // 4MHz 115200
    UCA1BR1 = 0;                               // 4MHz 115200
    UCA1MCTL |= 0x02;        // ���õ�������UCBRSx=1, UCBRFx=0
    UCA1CTL1 &= ~UCSWRST;                // RST��λ
    UCA1IE |= UCRXIE;
}
//********************************************************************//

//***********************�����ַ����ͺ���*****************************//
void send_byte(uchar c)
{
    if(c == '\n')
        send_byte('\r');
        while (!(UCA1IFG & UCTXIFG));       //�ȴ���һ���ֽڷ������
        UCA1TXBUF = c;
}
//********************************************************************//

//************************�����ַ�������******************************//
void print_str(uchar *s)
{
    while(*s != '\0')
        send_byte(*s++);

}
//********************************************************************//

//************************�ڴ�ռ丳ֵ********************************//
void memset(uchar *p, int val, int length)
{
    int i;

    for (i=0; i<length; i++)
    {
        p[i] = val;
    }
}
//********************************************************************//


//**************************���ڽ����ж�isr***************************//

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

