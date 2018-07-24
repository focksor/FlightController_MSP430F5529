/******************* (C) COPYRIGHT 2016 Hentotech Team ***************************
 * 文件名   ：oled.c
 * 描述     ：oled模块配置
 * 实验平台 ：HT-Hawk开源飞控
 * 库版本   ：ST3.5.0
 * 作者     ：Hentotech Team 
 * 官网     ：http://www.hentotech.com 
 * 论坛     ：http://bbs.hentotech.com
 * 商城     ：http://hentotech.taobao.com   
*********************************************************************************/
#include "oled.h"

#define XLevelL		0x00
#define XLevelH		0x10
#define XLevel		((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		  64
#define	Brightness	0xCF 

#define X_WIDTH 128
#define Y_WIDTH 64
//======================================
const unsigned char F6x8[][6] =
{
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   // sp
    { 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !
    { 0x00, 0x00, 0x07, 0x00, 0x07, 0x00 },   // "
    { 0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #
    { 0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $
    { 0x00, 0x62, 0x64, 0x08, 0x13, 0x23 },   // %
    { 0x00, 0x36, 0x49, 0x55, 0x22, 0x50 },   // &
    { 0x00, 0x00, 0x05, 0x03, 0x00, 0x00 },   // '
    { 0x00, 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (
    { 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )
    { 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *
    { 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +
    { 0x00, 0x00, 0x00, 0xA0, 0x60, 0x00 },   // ,
    { 0x08, 0x08, 0x08, 0x08, 0x08, 0x08 },   // -
    { 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 },   // .
    { 0x00, 0x20, 0x10, 0x08, 0x04, 0x02 },   // /
    { 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 0
    { 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 1
    { 0x00, 0x42, 0x61, 0x51, 0x49, 0x46 },   // 2
    { 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 3
    { 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 4
    { 0x00, 0x27, 0x45, 0x45, 0x45, 0x39 },   // 5
    { 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 6
    { 0x00, 0x01, 0x71, 0x09, 0x05, 0x03 },   // 7
    { 0x00, 0x36, 0x49, 0x49, 0x49, 0x36 },   // 8
    { 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E },   // 9
    { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00 },   // :
    { 0x00, 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;
    { 0x08, 0x1C, 0x2A, 0x49, 0x08, 0x08 },   // <
    { 0x00, 0x14, 0x14, 0x14, 0x14, 0x14 },   // =
    { 0x08, 0x08, 0x49, 0x2A, 0x1C, 0x08 },   // >
    { 0x00, 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?
    { 0x00, 0x32, 0x49, 0x59, 0x51, 0x3E },   // @
    { 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C },   // A
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C
    { 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F
    { 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G
    { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H
    { 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I
    { 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J
    { 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K
    { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L
    { 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M
    { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P
    { 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q
    { 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R
    { 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 },   // S
    { 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T
    { 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U
    { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V
    { 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W
    { 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 },   // X
    { 0x00, 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y
    { 0x00, 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z
    { 0x00, 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [
    { 0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55 },   // 55
    { 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]
    { 0x04, 0x02, 0xFF, 0x02, 0x04, 0x00 },   // ^
    { 0x00, 0x20, 0x40, 0xFF, 0x40, 0x20 },   // _
    { 0x00, 0x00, 0x01, 0x02, 0x04, 0x00 },   // '
    { 0x00, 0x20, 0x54, 0x54, 0x54, 0x78 },   // a
    { 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x20 },   // c
    { 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F },   // d
    { 0x00, 0x38, 0x54, 0x54, 0x54, 0x18 },   // e
    { 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f
    { 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C },   // g
    { 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h
    { 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i
    { 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00 },   // j
    { 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k
    { 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l
    { 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x38 },   // o
    { 0x00, 0xFC, 0x24, 0x24, 0x24, 0x18 },   // p
    { 0x00, 0x18, 0x24, 0x24, 0x18, 0xFC },   // q
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r
    { 0x00, 0x48, 0x54, 0x54, 0x54, 0x20 },   // s
    { 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t
    { 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u
    { 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v
    { 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w
    { 0x00, 0x44, 0x28, 0x10, 0x28, 0x44 },   // x
    { 0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C },   // y
    { 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44 },   // z
    { 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 }    // horiz lines
};
const unsigned char F14x16_Idx[] = 
{
	"恒拓科技电调校准请将飞行器置于水平状态且保持静止"
};
const unsigned char F14x16[] = {  
0xE0,0x00,0xFF,0x10,0x20,0x02,0xF2,0x92,0x92,0x92,0x92,0x92,0xF2,0x02,//恒
0x00,0x00,0xFF,0x00,0x00,0x40,0x4F,0x44,0x44,0x44,0x44,0x44,0x4F,0x40,

0x10,0x10,0xFF,0x10,0x90,0x04,0x04,0x84,0xE4,0x9C,0x84,0x84,0x84,0x04,//拓
0x44,0x82,0x7F,0x01,0x04,0x02,0x01,0xFF,0x40,0x40,0x40,0x40,0xFF,0x00,

0x24,0xA4,0xFE,0xA3,0x22,0x00,0x22,0xCC,0x00,0x00,0xFF,0x00,0x00,0x00,//科
0x06,0x01,0xFF,0x00,0x01,0x04,0x04,0x04,0x04,0x04,0xFF,0x02,0x02,0x02,

0x10,0x10,0xFF,0x10,0x90,0x08,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x08,//技
0x44,0x82,0x7F,0x01,0x80,0x80,0x40,0x43,0x2C,0x10,0x28,0x46,0x81,0x80,

0x00,0xF8,0x88,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x88,0xF8,0x00,0x00,//电
0x00,0x1F,0x08,0x08,0x08,0x08,0x7F,0x88,0x88,0x88,0x88,0x9F,0x80,0xF0,

0x42,0xCC,0x00,0x00,0xFE,0x82,0x92,0x92,0xFE,0x92,0x92,0x82,0xFE,0x00,//调
0x00,0x3F,0x10,0x88,0x7F,0x00,0x1E,0x12,0x12,0x12,0x5E,0x80,0x7F,0x00,

0x10,0xD0,0xFF,0x90,0x10,0x80,0x48,0x28,0x09,0x0E,0x08,0x28,0x48,0x88,//校
0x03,0x00,0xFF,0x00,0x01,0x80,0x80,0x43,0x2C,0x10,0x2C,0x43,0x80,0x80,

0x02,0x0C,0xE0,0x40,0x20,0xF8,0x4F,0x48,0x49,0xFE,0x48,0x48,0x48,0x08,//准
0x04,0x7F,0x00,0x00,0x00,0xFF,0x22,0x22,0x22,0x3F,0x22,0x22,0x22,0x20,

0x42,0xCC,0x00,0x00,0x44,0x54,0x54,0x54,0x7F,0x54,0x54,0x54,0x44,0x40,//请
0x00,0x7F,0x20,0x10,0x00,0xFF,0x15,0x15,0x15,0x55,0x95,0x7F,0x00,0x00,

0x08,0x30,0x00,0xFF,0x00,0x88,0x84,0x53,0x22,0x12,0xCA,0x06,0x00,0x00,//将
0x04,0x02,0x01,0xFF,0x00,0x02,0x0A,0x12,0x42,0x82,0x7F,0x02,0x02,0x02,

0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x40,0xA0,0x10,0x08,0x00,//飞
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0C,0x10,0x21,0x42,0xF0,

0x10,0x88,0xC4,0x33,0x00,0x40,0x42,0x42,0x42,0xC2,0x42,0x42,0x42,0x40,//行
0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,

0x80,0x9E,0x92,0x92,0x92,0x9E,0xE0,0x80,0x9E,0xB2,0xD2,0x92,0x9E,0x80,//器
0x08,0xF4,0x94,0x92,0x92,0xF1,0x00,0x01,0xF2,0x92,0x94,0x94,0xF8,0x08,

0x17,0x15,0xD5,0x55,0x57,0x55,0x7D,0x55,0x57,0x55,0xD5,0x15,0x17,0x00,//置
0x40,0x40,0x7F,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x7F,0x40,0x40,0x40,

0x40,0x42,0x42,0x42,0x42,0x42,0xFE,0x42,0x42,0x42,0x42,0x42,0x40,0x40,//于
0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x20,0x20,0x20,0xA0,0x60,0x00,0xFF,0x60,0x80,0x40,0x20,0x18,0x00,0x00,//水
0x10,0x08,0x06,0x01,0x40,0x80,0x7F,0x00,0x01,0x02,0x04,0x08,0x10,0x10,

0x02,0x02,0x12,0x62,0x02,0x02,0xFE,0x02,0x02,0x42,0x32,0x02,0x02,0x00,//平
0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,

0x08,0x30,0x00,0xFF,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x22,0x2C,0x20,//状
0x04,0x02,0x01,0xFF,0x80,0x40,0x30,0x0E,0x01,0x06,0x18,0x20,0x40,0x80,

0x04,0x84,0x84,0x44,0x24,0x54,0x8F,0x14,0x24,0x44,0x84,0x84,0x04,0x00,//态
0x39,0x00,0x00,0x3C,0x40,0x40,0x42,0x4C,0x40,0x40,0x70,0x04,0x09,0x31,

0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00,//且
0x40,0x40,0x7F,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x7F,0x40,0x40,0x40,

0x80,0x60,0xF8,0x07,0x00,0x3E,0x22,0x22,0xE2,0x22,0x22,0x3E,0x00,0x00,//保
0x00,0x00,0xFF,0x20,0x11,0x09,0x05,0x03,0xFF,0x03,0x05,0x09,0x11,0x20,

0x10,0x10,0xFF,0x10,0x10,0x40,0x48,0x48,0x48,0x7F,0x48,0xC8,0x48,0x40,//持
0x44,0x82,0x7F,0x01,0x00,0x02,0x02,0x0A,0x12,0x42,0x82,0x7F,0x02,0x02,

0x54,0x54,0x7F,0x54,0x54,0x44,0x20,0x28,0x27,0xE4,0x34,0x2C,0xE0,0x00,//静
0xFF,0x15,0x55,0x95,0x7F,0x00,0x09,0x49,0x89,0x7F,0x09,0x09,0x1F,0x01,

0x00,0x00,0xF0,0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x40,0x00,0x00,//止
0x40,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x40,0x40
};

//======================================================
// 128X64I液晶底层驱动[8X16]字体库
// 设计者: powerint
// 描  述: [8X16]西文字符的字模数据 (纵向取模,字节倒序)
// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//======================================================
const unsigned char F8X16[]=
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x30,0x00,0x00,0x00,//!1
  0x00,0x10,0x0C,0x06,0x10,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//"2
  0x40,0xC0,0x78,0x40,0xC0,0x78,0x40,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x04,0x00,//#3
  0x00,0x70,0x88,0xFC,0x08,0x30,0x00,0x00,0x00,0x18,0x20,0xFF,0x21,0x1E,0x00,0x00,//$4
  0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00,//%5
  0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x24,0x19,0x27,0x21,0x10,//&6
  0x10,0x16,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//'7
  0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,//(8
  0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,//)9
  0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,//*10
  0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00,//+11
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xB0,0x70,0x00,0x00,0x00,0x00,0x00,//,12
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,//-13
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,//.14
  0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00,///15
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,//016
  0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//117
  0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,//218
  0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,//319
  0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,//420
  0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,//521
  0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,//622
  0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,//723
  0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,//824
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,//925
  0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,//:26
  0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00,//;27
  0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00,//<28
  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00,//=29
  0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00,//>30
  0x00,0x70,0x48,0x08,0x08,0x08,0xF0,0x00,0x00,0x00,0x00,0x30,0x36,0x01,0x00,0x00,//?31
  0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x24,0x23,0x14,0x0B,0x00,//@32
  0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,//A33
  0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,//B34
  0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,//C35
  0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,//D36
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,//E37
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,//F38
  0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,//G39
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,//H40
  0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//I41
  0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,//J42
  0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,//K43
  0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,//L44
  0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00,//M45
  0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,//N46
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,//O47
  0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,//P48
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00,//Q49
  0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,//R50
  0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,//S51
  0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//T52
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//U53
  0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,//V54
  0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00,//W55
  0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,//X56
  0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//Y57
  0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,//Z58
  0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00,//[59
  0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00,//\60
  0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,//]61
  0x00,0x00,0x04,0x02,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^62
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,//_63
  0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//`64
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20,//a65
  0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00,//b66
  0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,//c67
  0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20,//d68
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00,//e69
  0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//f70
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00,//g71
  0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//h72
  0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//i73
  0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,//j74
  0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00,//k75
  0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//l76
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,//m77
  0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//n78
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//o79
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00,//p80
  0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80,//q81
  0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00,//r82
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00,//s83
  0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00,//t84
  0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20,//u85
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00,//v86
  0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,//w87
  0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00,//x88
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00,//y89
  0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00,//z90
  0x00,0x00,0x00,0x00,0x80,0x7C,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,//{91
  0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,//|92
  0x00,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,//}93
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01 //~94

};

const unsigned char LOGO128x64[1024] = { 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x18,0x1C,0x3C,0x3C,0x7C,0xFC,0x3C,0x3C,0x7C,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x60,
	0xE0,0xC0,0xC0,0xC0,0xC0,0x80,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x40,0x20,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x80,0xC0,0x80,0x80,0xC0,0xC0,0xC0,0xC0,0x60,0x60,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x01,0x01,0x19,0xFF,0xFF,0xFF,0xFF,0x73,0xF2,0xF6,0xE4,0xE4,0xEC,0xC8,
	0xC8,0xC0,0xC0,0x80,0xF0,0xFF,0xF0,0xE0,0xF0,0xD0,0xD8,0xFC,0xFE,0xFF,0xFF,0xFF,
	0xFF,0xFC,0xC0,0xC0,0xC0,0xE0,0xE0,0xF0,0xF0,0xE0,0xC0,0xC0,0xC4,0xE4,0xE4,0xE2,
	0xF2,0x72,0x7B,0xFF,0xFF,0xFF,0xFF,0x19,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
	0x80,0x80,0x80,0xC0,0x40,0xC0,0xF0,0xF8,0xF0,0xF0,0xE0,0x60,0xF0,0xF0,0x70,0x70,
	0x70,0x70,0x30,0x30,0x30,0x3F,0xBF,0x9F,0x98,0x98,0x88,0x88,0xC9,0xC9,0xC3,0xC3,
	0xE7,0xEF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xE3,0xE3,0xC1,0xC9,
	0xC8,0xC8,0xC8,0x99,0x9F,0x9F,0x9F,0xB8,0x38,0x38,0x30,0x30,0x30,0x70,0x70,0x70,
	0x70,0x70,0xF0,0xF8,0xF8,0xF8,0xF0,0xE0,0x60,0x40,0x40,0x40,0x40,0x40,0xC0,0xC0,
	0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x06,0x02,0x02,0x02,0x02,0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x00,0x00,0x20,0x70,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x7E,0x3E,0x3E,0x3E,
	0x3E,0x3F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x07,
	0x03,0x01,0x01,0x01,0x01,0x03,0x87,0x8F,0x8F,0x8F,0x87,0xBF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xDF,0x87,0x87,0x8F,0x87,0x81,0x03,0x03,0x01,0x01,0x01,0x01,0x07,0x07,
	0x0F,0x0F,0x0F,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x3F,0x3F,0x3E,0x3E,
	0x3C,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x38,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0x1F,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x7F,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x03,0xFF,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0xF0,0xC0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x7C,0x7F,0x7F,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}; 


/*
 * AUTHOR:FOCKSOR
 * DATE:7.13.2018
 */
void setgpio(unsigned char bit, unsigned char wir){
    if(wir == 0){
        P3DIR |= bit;
        P3OUT &= ~bit;
    }
    else{
        P3DIR |= bit;
        P3OUT |= bit;
    }
}

/**************************实现函数********************************************
*函数原型:    void OLED_WR_Byte(uint8_t dat,uint8_t cmd)
*功　　能:    OLED写入数据/命令
输入参数：    dat  要输入的数据
              cmd  1:命令  0：数据
输出参数：    无
*******************************************************************************/
void OLED_WR_Byte(uint8_t dat,uint8_t cmd)
{	
    uint8_t i;			  
    if(cmd)   OLED_RS_Set();
    else      OLED_RS_Clr();		  
    for(i=0;i<8;i++)
    {			  
	    OLED_SCLK_Clr();
	    if(dat&0x80)   OLED_SDIN_Set();
	    else           OLED_SDIN_Clr();
	    OLED_SCLK_Set();
	    dat<<=1;   
    }				 		 
    OLED_RS_Set();   	  
} 

void OLED_DLY_ms(unsigned int ms)
{                         
  unsigned int a;
  while(ms)
  {
    a=1335;
    while(a--);
    ms--;
  }
  return;
}

void OLED_Init(void)        
{
	OLED_SCLK_Set();  	
	OLED_RST_Clr();
  OLED_DLY_ms(50);
  OLED_RST_Set();
  OLED_WR_Byte(0xAE,OLED_CMD); //关闭显示
	OLED_WR_Byte(0xD5,OLED_CMD); //设置时钟分频因子,震荡频率
	OLED_WR_Byte(0X80,OLED_CMD); //[3:0],分频因子;[7:4],震荡频率
	OLED_WR_Byte(0xA8,OLED_CMD); //设置驱动路数
	OLED_WR_Byte(0X3F,OLED_CMD); //默认0X3F(1/64) 
	OLED_WR_Byte(0xD3,OLED_CMD); //设置显示偏移
	OLED_WR_Byte(0X00,OLED_CMD); //默认为0
	OLED_WR_Byte(0x40|0X00,OLED_CMD); //设置显示开始行 [5:0],行数.													    
	OLED_WR_Byte(0x8D,OLED_CMD); //电荷泵设置
	OLED_WR_Byte(0x14,OLED_CMD); //bit2，开启/关闭
	OLED_WR_Byte(0x20,OLED_CMD); //设置内存地址模式
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
	OLED_WR_Byte(0xA1,OLED_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC8,OLED_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
	OLED_WR_Byte(0xDA,OLED_CMD); //设置COM硬件引脚配置
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]配置		 
	OLED_WR_Byte(0x81,OLED_CMD); //对比度设置
	OLED_WR_Byte(0xEF,OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
	OLED_WR_Byte(0xD9,OLED_CMD); //设置预充电周期
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //设置VCOMH 电压倍率
	OLED_WR_Byte(0x40,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;
	OLED_WR_Byte(0xA4,OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6,OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示	    						   
	OLED_WR_Byte(0xAF,OLED_CMD); //开启显示	 

  OLED_Fill(0x00);  //初始清屏
} 

void OLED_WrDat(unsigned char data)
{
	unsigned char i=8;

    OLED_DC_OH;
	  _NOP();
    OLED_D0_OL;
    _NOP();
  while(i--)
  {
    if(data&0x80)
	  {OLED_D1_OH;}
    else
	  {OLED_D1_OL;}
	  OLED_D0_OH;
    
    _NOP();
            
    OLED_D0_OL;    
    data<<=1;    
  }
}
void OLED_WrCmd(unsigned char cmd)
{
	unsigned char i=8;
	
   OLED_DC_OL;
   OLED_D0_OL;

   _NOP();_NOP();_NOP();
   _NOP();_NOP();_NOP();
   _NOP();_NOP();_NOP();
    
   while(i--)
   {
    if(cmd&0x80)
	  {OLED_D1_OH;}
    else
	  {OLED_D1_OL;}

    OLED_D0_OH;
    _NOP();_NOP();_NOP();
    _NOP();_NOP();_NOP();
    _NOP();_NOP();_NOP();
            
    OLED_D0_OL;   
    cmd<<=1;;   
  } 	
	//LCD_CS=1;
}
void OLED_Set_Pos(unsigned char x, unsigned char y)
{ 
  OLED_WrCmd(0xb0+y);
  OLED_WrCmd(((x&0xf0)>>4)|0x10);
  OLED_WrCmd(x&0x0f);//|0x01);
} 
void OLED_Fill(unsigned char bmp_data) //写数据比如写0x00为清屏 0xff为满频
{
	unsigned char y,x;
	
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		OLED_WrCmd(0x01);
		OLED_WrCmd(0x10);
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(bmp_data);
	}
}
void OLED_CLS(void)
{
	unsigned char y,x;	
	for(y=0;y<8;y++)
	{
		OLED_WrCmd(0xb0+y);
		OLED_WrCmd(0x01);
		OLED_WrCmd(0x10); 
		for(x=0;x<X_WIDTH;x++)
		OLED_WrDat(0);
	}
}

void adjust(unsigned char a)
{
  OLED_WrCmd(a);	//指令数据0x0000~0x003f  
}

void SetStartColumn(unsigned char d)
{
	OLED_WrCmd(0x00+d%16);		// Set Lower Column Start Address for Page Addressing Mode
						//   Default => 0x00
	OLED_WrCmd(0x10+d/16);		// Set Higher Column Start Address for Page Addressing Mode
						//   Default => 0x10
}

void SetAddressingMode(unsigned char d)	
{
	OLED_WrCmd(0x20);			// Set Memory Addressing Mode
	OLED_WrCmd(d);			//   Default => 0x02
						//     0x00 => Horizontal Addressing Mode
						//     0x01 => Vertical Addressing Mode
						//     0x02 => Page Addressing Mode
}

void SetColumnAddress(unsigned char a, unsigned char b)
{
	OLED_WrCmd(0x21);			// Set Column Address
	OLED_WrCmd(a);			//   Default => 0x00 (Column Start Address)
	OLED_WrCmd(b);			//   Default => 0x7F (Column End Address)
}

void SetPageAddress(unsigned char a, unsigned char b)
{
	OLED_WrCmd(0x22);			// Set Page Address
	OLED_WrCmd(a);			//   Default => 0x00 (Page Start Address)
	OLED_WrCmd(b);			//   Default => 0x07 (Page End Address)
}

  void SetStartLine(unsigned char d)
{
	OLED_WrCmd(0x40|d);			// Set Display Start Line
						//   Default => 0x40 (0x00)
}

void SetContrastControl(unsigned char d)
{
	OLED_WrCmd(0x81);			// Set Contrast Control
	OLED_WrCmd(d);			//   Default => 0x7F
}

void Set_Charge_Pump(unsigned char d)
{
	OLED_WrCmd(0x8D);			// Set Charge Pump
	OLED_WrCmd(0x10|d);			//   Default => 0x10
						//     0x10 (0x00) => Disable Charge Pump
						//     0x14 (0x04) => Enable Charge Pump
}

void Set_Segment_Remap(unsigned char d)
{
	OLED_WrCmd(0xA0|d);			// Set Segment Re-Map
						//   Default => 0xA0
						//     0xA0 (0x00) => Column Address 0 Mapped to SEG0
						//     0xA1 (0x01) => Column Address 0 Mapped to SEG127
}

void Set_Entire_Display(unsigned char d)
{
	OLED_WrCmd(0xA4|d);			// Set Entire Display On / Off
						//   Default => 0xA4
						//     0xA4 (0x00) => Normal Display
						//     0xA5 (0x01) => Entire Display On
}

void Set_Inverse_Display(unsigned char d)
{
	OLED_WrCmd(0xA6|d);			// Set Inverse Display On/Off
						//   Default => 0xA6
						//     0xA6 (0x00) => Normal Display
						//     0xA7 (0x01) => Inverse Display On
}

void Set_Multiplex_Ratio(unsigned char d)
{
	OLED_WrCmd(0xA8);			// Set Multiplex Ratio
	OLED_WrCmd(d);			//   Default => 0x3F (1/64 Duty)
}

void Set_Display_On_Off(unsigned char d)
{
	OLED_WrCmd(0xAE|d);			// Set Display On/Off
						//   Default => 0xAE
						//     0xAE (0x00) => Display Off
						//     0xAF (0x01) => Display On
}

void SetStartPage(unsigned char d)
{
	OLED_WrCmd(0xB0|d);			// Set Page Start Address for Page Addressing Mode
						//   Default => 0xB0 (0x00)
}

void Set_Common_Remap(unsigned char d)
{
	OLED_WrCmd(0xC0|d);			// Set COM Output Scan Direction
						//   Default => 0xC0
						//     0xC0 (0x00) => Scan from COM0 to 63
						//     0xC8 (0x08) => Scan from COM63 to 0
}

void Set_Display_Offset(unsigned char d)
{
	OLED_WrCmd(0xD3);			// Set Display Offset
	OLED_WrCmd(d);			//   Default => 0x00
}

void Set_Display_Clock(unsigned char d)
{
	OLED_WrCmd(0xD5);			// Set Display Clock Divide Ratio / Oscillator Frequency
	OLED_WrCmd(d);			//   Default => 0x80
						//     D[3:0] => Display Clock Divider
						//     D[7:4] => Oscillator Frequency
}

void Set_Precharge_Period(unsigned char d)
{
	OLED_WrCmd(0xD9);			// Set Pre-Charge Period
	OLED_WrCmd(d);			//   Default => 0x22 (2 Display Clocks [Phase 2] / 2 Display Clocks [Phase 1])
						//     D[3:0] => Phase 1 Period in 1~15 Display Clocks
						//     D[7:4] => Phase 2 Period in 1~15 Display Clocks
}

void Set_Common_Config(unsigned char d)
{
	OLED_WrCmd(0xDA);			// Set COM Pins Hardware Configuration
	OLED_WrCmd(0x02|d);			//   Default => 0x12 (0x10)
						//     Alternative COM Pin Configuration
						//     Disable COM Left/Right Re-Map
}

void Set_VCOMH(unsigned char d)
{
	OLED_WrCmd(0xDB);			// Set VCOMH Deselect Level
	OLED_WrCmd(d);			//   Default => 0x20 (0.77*VCC)
}

void Set_NOP(void)
{
	OLED_WrCmd(0xE3);			// Command for No Operation
}
 
//==============================================================
//函数名：LCD_P6x8Str(unsigned char x,unsigned char y,unsigned char *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================  
void OLED_P6x8Str(u8 x,u8 y,u8 ch[])//小字符串
{
  u8 c=0,i=0,j=0;
  OLED_Set_Pos(x,y);      
  while (ch[j]!='\0')
  {    
    c =ch[j]-32;
    if(x>126){x=0;y++;}    
  	for(i=0;i<6;i++)     
  	  OLED_WrDat(F6x8[c][i]);  
  	x+=6;
  	j++;
  }
}
//==============================================================
//函数名：LCD_P8x16Str(unsigned char x,unsigned char y,unsigned char *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================  
void OLED_P8x16Str(u8 x,u8 y,u8 ch[])//大字符串
{
  u8 c=0,i=0,j=0;
        
  while (ch[j]!='\0')
  {    
    c =ch[j]-32;
    if(x>120){x=0;y++;}
    OLED_Set_Pos(x,y);    
  	for(i=0;i<8;i++)     
  	  OLED_WrDat(F8X16[c*16+i]);
  	OLED_Set_Pos(x,y+1);    
  	for(i=0;i<8;i++)     
  	  OLED_WrDat(F8X16[c*16+i+8]);  
  	x+=8;
  	j++;
  }
}
//输出汉字字符串
void OLED_P14x16Str(unsigned char x,u8 y,unsigned char ch[])
{
	unsigned char wm=0,ii = 0;
	unsigned int adder=1; 
	
	while(ch[ii] != '\0')
	{
  	wm = 0;
  	adder = 1;
  	while(F14x16_Idx[wm] > 127)
  	{
  		if(F14x16_Idx[wm] == ch[ii])
  		{
  			if(F14x16_Idx[wm + 1] == ch[ii + 1])
  			{
  				adder = wm * 14;
  				break;
  			}
  		}
  		wm += 2;			
  	}
  	if(x>118){x=0;y++;}
  	OLED_Set_Pos(x , y); 
  	if(adder != 1)// 显示汉字					
  	{
  		OLED_Set_Pos(x , y);
  		for(wm = 0;wm < 14;wm++)               
  		{
  			OLED_WrDat(F14x16[adder]);	
  			adder += 1;
  		}      
  		OLED_Set_Pos(x,y + 1); 
  		for(wm = 0;wm < 14;wm++)          
  		{
  			OLED_WrDat(F14x16[adder]);
  			adder += 1;
  		}   		
  	}
  	else			  //显示空白字符			
  	{
  		ii += 1;
      OLED_Set_Pos(x,y);
  		for(wm = 0;wm < 16;wm++)
  		{
  				OLED_WrDat(0);
  		}
  		OLED_Set_Pos(x,y + 1);
  		for(wm = 0;wm < 16;wm++)
  		{   		
  				OLED_WrDat(0);	
  		}
  	}
  	x += 14;
  	ii += 2;
	}
}
//输出汉字和字符混合字符串
void OLED_Print(unsigned char x, unsigned char y, unsigned char ch[])
{
	unsigned char ch2[3];
	unsigned char ii=0;        
	while(ch[ii] != '\0')
	{
		if(ch[ii] > 127)
		{
			ch2[0] = ch[ii];
	 		ch2[1] = ch[ii + 1];
			ch2[2] = '\0';			//汉字为两个字节
			OLED_P14x16Str(x , y, ch2);	//显示汉字
			x += 14;
			ii += 2;
		}
		else
		{
			ch2[0] = ch[ii];	
			ch2[1] = '\0';			//字母占一个字节
			OLED_P8x16Str(x , y , ch2);	//显示字母
			x += 8;
			ii+= 1;
		}
	}
} 

void Dis_Char(unsigned char y,unsigned char x,unsigned char asc) 
{
  unsigned char ch2[2];
	x=x*8;        
	ch2[0] = asc;	
	ch2[1] = '\0';			//字母占一个字节
	OLED_P6x8Str(x , y , ch2);	//显示字母
}
void Dis_String(unsigned char y, unsigned char x, unsigned char ch[])
{
	unsigned char ch2[3];
	unsigned char ii=0;
	x=x*8;        
	while(ch[ii] != '\0')
	{
		if(ch[ii] > 127)
		{
			ch2[0] = ch[ii];
	 		ch2[1] = ch[ii + 1];
			ch2[2] = '\0';			//汉字为两个字节
			OLED_P14x16Str(x , y, ch2);	//显示汉字
			x += 14;
			ii += 2;
		}
		else
		{
			ch2[0] = ch[ii];	
			ch2[1] = '\0';			//字母占一个字节
			OLED_P8x16Str(x , y , ch2);	//显示字母
			x += 8;
			ii+= 1;
		}
	}
}

void Dis_Num(unsigned char y, unsigned char x, unsigned int num,unsigned char dis_N){
		unsigned char j=0;
		unsigned char n[6]={0};
		x=x*8;
		n[0]=(num/10000)%10; 
		n[1]=(num/1000)%10;
		n[2]=(num/100)%10;
		n[3]=(num/10)%10;
		n[4]=num%10;
		//  n[6]='\0';			   
		for(j=0;j<5;j++) n[j]=n[j]+16+32;
		OLED_P8x16Str(x,y,&n[5-dis_N]);//从ACSII码表中读取字节，然后写入液晶
}

void Dis_Float(unsigned char Y, unsigned char X, double real, unsigned char dis_N){
		unsigned char   i_Count=1;
		unsigned char   n[12]={0};
		long   j=1;  
		int    real_int=0;
		double decimal=0;
		unsigned int   real_decimal=0;
		if(real<0)
		{
		  real_int=(int)(-real);
		}
		else
		{
		  real_int=(int)real;
		}
		decimal=real-real_int;
		real_decimal=decimal*1e4;
		while(real_int/10/j!=0)
		{
		  j=j*10;i_Count++;  
		} 
		n[0]=(real_int/10000)%10; 
		n[1]=(real_int/1000)%10;
		n[2]=(real_int/100)%10;
		n[3]=(real_int/10)%10;
		n[4]=(real_int/1)%10; 
		n[5]='.';
		n[6]=(real_decimal/1000)%10;
		n[7]=(real_decimal/100)%10;
		n[8]=(real_decimal/10)%10;
		n[9]=real_decimal%10;
		n[6+dis_N]='\0';
		for(j=0;j<10;j++) n[j]=n[j]+16+32;
		if(real<0) 
		{		 
		  i_Count+=1;
		  n[5-i_Count]='-';
		}
		n[5]='.';
		n[6+dis_N]='\0';
		OLED_P6x8Str(X,Y,&n[5-i_Count]); 
}

void Dis_Float2(unsigned char Y,unsigned char X,double real,unsigned char N1,unsigned char N2) 
{
		unsigned char   i_Count=1;
		unsigned char   n[12]={0};
		long   j=1;  
		unsigned int   real_int=0;
		double decimal=0;
		unsigned int   real_decimal=0;
		X=X*8;
		real_int=(int)real;
		//Dis_Num(2,0,real_int,5);
		decimal=real-real_int;
		real_decimal=decimal*1e4;
		//Dis_Num(2,6,real_decimal,4);
		while(real_int/10/j!=0)
		{
			j=j*10;i_Count++;  
		} 
		n[0]=(real_int/10000)%10; 
		n[1]=(real_int/1000)%10;
		n[2]=(real_int/100)%10;
		n[3]=(real_int/10)%10;

		n[5]='.';
		n[6]=(real_decimal/1000)%10;
		n[7]=(real_decimal/100)%10;
		n[8]=(real_decimal/10)%10;
		n[9]=real_decimal%10;
		n[6+N2]='\0'; 
		for(j=0;j<10;j++) n[j]=n[j]+16+32;
		n[5]='.';
		n[6+N2]='\0';   
		OLED_P8x16Str(X,Y,&n[5-N1]); 
}

void Draw_Logo(void)
{ 	
		unsigned int ii=0;
		unsigned char x,y;       

		for(y=0;y<8;y++)
		{
			OLED_Set_Pos(0,y);				
			for(x=0;x<128;x++)
				{      
					OLED_WrDat(LOGO128x64[ii++]);	    	
				}
		}
} 

void OLED_P8x16Num_8bit(unsigned char x,unsigned char y,unsigned char Number)
{
		unsigned char ch[3]={0};
		int n;
		for(n=2;n>=0;n--)
		{
			ch[n]=Number%10+'0';
			Number=Number/10;
		}
		OLED_P8x16Str(x,y,ch);
}

void OLED_P6x8Num_8bit(unsigned char x,unsigned char y,unsigned char Number)
{
		unsigned char ch[3]={0};
		int n;
		for(n=2;n>=0;n--)
		{
			ch[n]=Number%10+'0';
			Number=Number/10;
		}
		OLED_P6x8Str(x,y,ch);
}

void OLED_2num(unsigned char x,unsigned char y,unsigned char number)
{
		unsigned char ge,shi;
		ge = number % 10;
		shi = number / 10;
		OLED_Num(x+1,y,ge);
		OLED_Num(x,y,shi);
}

void OLED_3num(unsigned char x,unsigned char y,unsigned int number)
{
		unsigned char ge,shi,bai;
		bai = number / 100;
		shi = number % 100 /10;
		ge  = number % 10;
	
		OLED_Num(x,y,bai);
		OLED_Num(x+1,y,shi);
		OLED_Num(x+2,y,ge);
}

void OLED_4num(unsigned char x,unsigned char y, int number)
{
		unsigned char qian,bai,shi,ge;
		int num =number;
		if(num<0)
		{
			 num=-num;
		}
		qian=num/1000;
		bai=num%1000/100;
		shi=num%100/10;
		ge=num%10;

		OLED_Num(x,y,qian);
		OLED_Num(x+1,y,bai);
		OLED_Num(x+2,y,shi);
		OLED_Num(x+3,y,ge);
}

void OLED_Num(unsigned char x,unsigned char y,unsigned char asc) 
{
    int i=0;
    OLED_Set_Pos(x*6,y);
    for(i=0;i<6;i++)
    {
       OLED_WrDat(F6x8[asc+16][i]);         
    }
}

void OLED_Num5(unsigned char x,unsigned char y,unsigned int number)
{
		unsigned char wan,qian,bai,shi,ge;
		wan=number/10000;
		qian = number%10000/1000;
		bai=number%1000/100;
		shi=number%100/10;
		ge=number%10;

		OLED_Num(x,y,wan);
		OLED_Num(x+1,y,qian);
		OLED_Num(x+2,y,bai);
		OLED_Num(x+3,y,shi);
		OLED_Num(x+4,y,ge);
}
