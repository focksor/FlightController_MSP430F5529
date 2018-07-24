#ifndef __Control_H
#define __Control_H

#define EXP_HEIGHT  150


//#include <stm32f10x.h>
#include <sys.h>
#include <imu.h>
#include <ppm.h>
#include <AttitudePid.h>
#include <motor.h>
#include "ultrasonic.h"

extern float height_exp;
float dst_f;
float Height_PID;
void init_Control(void);
void control_All(__flight_mode_t flight_mode,
                 int *motor_1, int *motor_2, int *motor_3, int *motor_4);

bool control_Safety(void);

// Acro 特技模式
bool init_Ctrl_Acro(void);
void calc_Target_Acro(__rc_channel _rc);
void calc_Throttle_Acro(__rc_channel _rc, int *motor_out);
void control_PID_Acro(float g_roll, float g_pitch, float g_yaw,
                      float *roll_out, float *pitch_out, float *yaw_out);

// Stabilized 自稳模式
bool init_Ctrl_Stabilized(void);
void calc_Target_Stabilized(__rc_channel _rc);
void calc_Throttle_Stabilized(__rc_channel _rc, int *motor_out);
void control_PID_Stabilized(float g_roll, float g_pitch, float g_yaw,
                            float roll,   float pitch,   float yaw,
                            float *roll_out, float *pitch_out, float *yaw_out);

extern const float d_time_attitude;

#endif  // __Control_H
