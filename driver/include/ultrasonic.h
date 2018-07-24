#ifndef __ULTRASONIC_H
#define __ULTRASONIC_H

#define uchar           unsigned char
#define uint            unsigned int
#define CPU_F           ((double)4000000)
#define delay_ms(x)     __delay_cycles((long)CPU_F*(double)x/1000.0)    //ms绾у欢鏃�
#define delay_us(x)     __delay_cycles((long)CPU_F*(double)x/1000000.0) //us绾у欢鏃�

extern float dst_f;

void ultrasonic_Init(void);
float get_dst();
float get_dst_f();

#endif
