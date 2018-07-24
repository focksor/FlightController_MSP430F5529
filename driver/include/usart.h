/*
 * usart.h
 *
 *  Created on: 2018年7月21日
 *      Author: God_F
 */


#include <msp430f5529.h>
#include <sys.h>
#ifndef uchar
#define uchar           unsigned char
#endif
#ifndef uint
#define uint            unsigned int
#endif
#define CPU_F           ((double)4000000)
#define delay_ms(x)     __delay_cycles((long)CPU_F*(double)x/1000.0)    //ms级延时
#define delay_us(x)     __delay_cycles((long)CPU_F*(double)x/1000000.0) //us级延时
//#define band          9600
//#define band_setting  (unsigned int)((long)CPU_F/(long)band)
//#define band_h            (unsigned char)(band_setting>>8)    //存储高位，放在BR1
//#define band_l            (unsigned char)(band_setting)       //存储低位，放在BR0

uchar cmd[20];  //用于保存shell命令字符数组
uchar m[80];    //用于保存输出的脉冲数组

uint PerVal;    //用于存储上一次的数值。

//函数声明
void Timer_init();          //比较定时器初始化
void clock_init();          //时钟初始化，4MHz
void uart_init();           //串口初始化，9600比特率，8位数据位，无奇偶校验位，1位停止位
void send_byte(uchar c);    //发送字符，8位
void print_str(uchar *s);   //发送字符串
void memset(uchar *p, int val, int length);//内存空间赋值，这里用来清除cmd数组，不用shell时可以无视
void time_capture_init();   //捕获定时器初始化


/*
#ifndef DRIVER_USART_H_
#define DRIVER_USART_H_

#include <sys.h>
#ifndef uint
#define uint unsigned int
#endif
#ifndef uchar
#define uchar unsigned char
#endif
#ifndef ulong
#define ulong unsigned long
#endif

#ifndef CPU_F
#define CPU_F           ((double)4000000)
#endif
#ifndef delay_ms(x)
#define delay_ms(x)     __delay_cycles((long)CPU_F*(double)x/1000.0)    //ms绾у欢鏃�
#endif
#ifndef delay_us(x)
#define delay_us(x)     __delay_cycles((long)CPU_F*(double)x/1000000.0)
#endif
#define baud           9600                                //设置波特率的大小
#define baud_setting   (uint)((ulong)CPU_F/((ulong)baud))  //波特 率计 算公 式
#define baud_h         (uchar)(baud_setting>>8)            //提 取 高 位
#define baud_l         (uchar)(baud_setting)               //低位
#define DRE485_out     P4DIR |= BIT6     //连接485芯片的DE，RE端口的IO设置为输出状态

#include <msp430.h>

void USCI_A1_UART_init(void);
void UART_A1_sendData(unsigned char *Point,unsigned int CountTemp);
void Send_Byte(uchar data);
void Print_Str(uchar *s);



#endif  DRIVER_USART_H_ */
