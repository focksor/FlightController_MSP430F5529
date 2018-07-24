#ifndef __ATTITUDEPID_H
#define __ATTITUDEPID_H
#include "PID.h"
#include "imu.h"
#include "sys.h"
#define dTime 0.02

extern PidObject pidPitchAngle;
extern PidObject pidRollAngle;
extern PidObject pidYawAngle;
extern PidObject pidPitchAngularRate;
extern PidObject pidRollAngularRate;
extern PidObject pidYawAngularRate;
extern PidObject pidHeight;
extern PidObject piddistance;
extern PidObject pidAngle;

extern __picpos POS;

extern float Pitch_PID,Roll_PID,Yaw_PID, Height_PID,DIS_PID;
static float Pitch_Idle, Roll_Idle, Yaw_Idle;

void InitSelfStability(void);
void calcPidHeight(float Height_exp, float Height_now, float *Height_Pid);
void SelfStability(float Pitch_exp,float Roll_exp,float Yaw_exp);
void calcPidSelfStability(float Pitch_exp,float Roll_exp,float Yaw_exp,
						  float Pitch_now,float Roll_now,float Yaw_now,
						  float GYROx_now,float GYROy_now,float GYROz_now,
						  float *Pitch_PID,float *Roll_PID,float *Yaw_PID);
void LightDisCtrl(float distance_exp,float distance_now, float *distance_Pid);
void LightAngleCtrl(float Angle_exp, float Angle_now, float *Angle_Pid);

#endif
