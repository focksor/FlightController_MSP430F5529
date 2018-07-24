/*
 * sys.h
 *
 *  Created on: 2018Äê6ÔÂ30ÈÕ
 *      Author: ghost
 */

#ifndef SYS_H_
#define SYS_H_

#include <stdint.h>

#define PI 3.1415926535897932384626

#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int

typedef unsigned char bool;
#define true  1
#define false 0


typedef uchar  u8;
typedef ushort u16;

typedef struct {
	float roll;
	float pitch;
	float yaw;
} __imu;

typedef struct {
	float x;
	float y;
	float z;
} __vector3f;

typedef struct{
    float x;
    float y;
} __picpos;

typedef enum {
    roll_ch     = 1,
    pitch_ch    = 2,
    throttle_ch = 3,
    yaw_ch      = 4,
    sw_5_ch     = 5,
    sw_6_ch     = 6,
    sw_7_ch     = 7,
    sw_8_ch     = 8,
    sw_9_ch     = 9,
    sw_10_ch    = 10,
} __rc_info_t;


typedef enum {
    mode_stabilized = 1,
    mode_acro       = 2,
} __flight_mode_t;

typedef struct {
    short pitch;
    short roll;
    short throttle;
    short yaw;
    unsigned short unlock;
    unsigned short withoutDream;
} __rc_channel;

typedef struct {
    bool _200Hz;
    bool _100Hz;
    bool _50Hz;
    bool _25Hz;
    bool _10Hz;
    bool _5Hz;
    bool _1Hz;
} __time_slice;

#define CPU_F ((double)4000000)
#define _delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define _delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))


#endif /* SYS_H_ */
