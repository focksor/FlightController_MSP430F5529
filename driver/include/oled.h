#ifndef _OLED_H
#define _OLED_H


/*******************************************************************************************************************
 * CHANGE BY FOCKSOR
 * TRANSFER OLED LIB FROM STM32 TO MSP430
 * USING I2C LIB FROM GHOST 6.30.2018
 * CHANGE DATE: 7.13.2018
 *******************************************************************************************************************/
#include "msp430.h"
#include <sys.h>
#define OLED_GPIO    P3DIR
#define OLED_RCCEN   RCC_APB2Periph_GPIOC
#define OLED_SCL     BIT5      //D0
#define OLED_SDA     BIT6      //D1
#define OLED_RST     BIT7      //RST
#define OLED_DC      BIT7      //DC

#define OLED_CMD  0 //写命令
#define OLED_DATA 1 //写数据

#define HIGH 1
#define LOW 0

#define OLED_D0_OL      setgpio(OLED_SCL, LOW)    //D0 IO口输出低电平
#define OLED_D0_OH      setgpio(OLED_SCL, HIGH)   //D0 IO口输出高电平

#define OLED_D1_OL      setgpio(OLED_SDA, LOW)    //D1 IO口输出低电平
#define OLED_D1_OH      setgpio(OLED_SDA, HIGH)   //D1 IO口输出高电平

#define OLED_RST_OL     setgpio(OLED_RST, LOW) //RST IO口输出低电平
#define OLED_RST_OH     setgpio(OLED_RST, HIGH)   //RST IO口输出高电平

#define OLED_DC_OL      setgpio(OLED_DC, LOW)  //DC IO口输出低电平
#define OLED_DC_OH      setgpio(OLED_DC, HIGH)    //DC IO口输出高电平

#define OLED_RST_Clr()  setgpio(OLED_RST, LOW) //RST IO口输出低电平
#define OLED_RST_Set()  setgpio(OLED_RST, HIGH)   //RST IO口输出高电平

#define OLED_RS_Clr()   setgpio(OLED_DC, LOW)  //DC IO口输出低电平
#define OLED_RS_Set()   setgpio(OLED_DC, HIGH)      //DC IO口输出高电平

#define OLED_SCLK_Clr() setgpio(OLED_SCL, LOW)    //D0 IO口输出低电平
#define OLED_SCLK_Set() setgpio(OLED_SCL, HIGH)   //D0 IO口输出高电平

#define OLED_SDIN_Clr() setgpio(OLED_SDA, LOW) //D1 IO口输出低电平
#define OLED_SDIN_Set() setgpio(OLED_SDA, HIGH)   //D1 IO口输出高电平
/*******************************************************************************************************************
 * CHANGE END
 *******************************************************************************************************************/

void setgpio(unsigned char, unsigned char);
void OLED_Init(void);
void OLED_CLS(void);
void OLED_4num(unsigned char x,unsigned char y,int number);
void OLED_3num(unsigned char x,unsigned char y,unsigned int number);
void OLED_Num(unsigned char x,unsigned char y,unsigned char asc);
void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[]);
void OLED_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
void OLED_P14x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
void OLED_Print(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_PutPixel(unsigned char x,unsigned char y);
void OLED_Rectangle(int16_t acc_x,int16_t acc_y);
void Draw_Logo(void);
void Draw_BMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char bmp[]); 
void OLED_Fill(unsigned char dat);
void Dis_String(unsigned char y, unsigned char x, unsigned char ch[]);
void Dis_Char(unsigned char y,unsigned char x,unsigned char asc);
void Dis_Num(unsigned char, unsigned char, unsigned int,unsigned char);
void Dis_Float(unsigned char,unsigned char,double,unsigned char);
void Dis_Float2(unsigned char Y,unsigned char X,double real,unsigned char N1,unsigned char N2);
void OLED_P6x8Num_8bit(unsigned char x,unsigned char y,unsigned char Number); 
void OLED_Num5(unsigned char x,unsigned char y,unsigned int number);
#endif
