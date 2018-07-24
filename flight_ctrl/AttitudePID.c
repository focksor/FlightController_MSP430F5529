#include "AttitudePid.h"


float Pitch_PID,Roll_PID,Yaw_PID, Height_PID, Distance_PID,Angle_PID;
float MOTOR1_Def,MOTOR2_Def,MOTOR3_Def,MOTOR4_Def;
static float Pitch_Idle, Roll_Idle, Yaw_Idle;

PidObject pidPitchAngle;
PidObject pidRollAngle;
PidObject pidYawAngle;
PidObject pidPitchAngularRate;
PidObject pidRollAngularRate;
PidObject pidYawAngularRate;
PidObject pidHeight;

PidObject piddistance;
PidObject pidAngle;

PidConfig pidPitchAngleConfig = 		{0.7, 0.0, 0.0};
PidConfig pidRollAngleConfig = 		    {0.7, 0.0, 0.0};
PidConfig pidYawAngleConfig =           {0.0, 0.0, 0.0};
PidConfig pidPitchAngularRateConfig =   {1.6, 0.0, 0.0405};
PidConfig pidRollAngularRateConfig =    {1.5, 0.0, 0.043};
PidConfig pidYawAngularRateConfig =     {5.3, 0.0, 0.0};
PidConfig pidHeightConfig =             {3.1, 0.0, 0.01};

PidConfig pidPosConfig =                {0.05, 0.0, 0.0};
PidConfig pidAngleConfig =              {0.0, 0.0, 0.0};
//PidConfig pidHeightConfig = {2.8, 0, 0};   遥控器定高
/*
PidConfig pidPitchAngularRateConfig =	{ 1.74 , 0.000, 0.035 };  // 0.0024
PidConfig pidRollAngularRateConfig = 	{ 1.74,  0.000, 0.035 };   // 0.0031
PidConfig pidYawAngularRateConfig = 	{ 2.05, 0.002,  0.035  };
*/
//PidConfig pidPitchAngularRateConfig =   { 0.10 , 0.0001, 0.0017};  // 0.0024
//PidConfig pidRollAngularRateConfig =    { 0.10,  0.0001, 0.0017};   // 0.0031
//PidConfig pidYawAngularRateConfig =     { 2.05, 0.002,  0.035  };


//PidConfig pidPitchAngularRateConfig =	{0,0,0};
//PidConfig pidRollAngularRateConfig = 	{0,0,0};
//PidConfig pidYawAngularRateConfig = 	{0,0,0};

//PID OF PX4
//PidConfig pidPitchAngleConfig = 		{4.5,0,0};
//PidConfig pidRollAngleConfig = 			{4.5,0,0};
//PidConfig pidYawAngleConfig = 			{0,0,0};
//PidConfig pidPitchAngularRateConfig =	{0.135,0.09,0.0036};
//PidConfig pidRollAngularRateConfig = 	{0.135,0.09,0.0036};
//PidConfig pidYawAngularRateConfig = 	{0.18,0.018,0};



void InitSelfStability(void){
	InitPidObject(&pidPitchAngle,pidPitchAngleConfig,50,-50,dTime);
	InitPidObject(&pidRollAngle,pidRollAngleConfig,50,-50,dTime);
	InitPidObject(&pidYawAngle,pidYawAngleConfig,36,0,dTime);
	InitPidObject(&pidPitchAngularRate,pidPitchAngularRateConfig,6,-6,dTime);
	InitPidObject(&pidRollAngularRate,pidRollAngularRateConfig,6,-6,dTime);
	InitPidObject(&pidYawAngularRate,pidYawAngularRateConfig,36,-36,dTime);
	InitPidObject(&pidHeight,pidHeightConfig,6,-6,dTime);

	InitPidObject(&piddistance, pidPosConfig, 6, -6,dTime);
	InitPidObject(&pidAngle, pidAngleConfig, 6, -6,dTime);

}
/************************************
void SelfStability(float Pitch_exp,float Roll_exp,float Yaw_exp){	
	calcPidSelfStability(Pitch_exp,Roll_exp,Yaw_exp,
						 -(Pitch_Sensor),-(Roll_Sensor),Yaw_Sensor,
						 -(GYRO_X-GYROxIdle),(GYRO_Y-GYROyIdle),-(GYRO_Z-GYROzIdle),
						 &Pitch_PID,&Roll_PID,&Yaw_PID);
}
***********************************/
void SelfStability(float Pitch_exp,float Roll_exp,float Yaw_exp){
    calcPidSelfStability(Pitch_exp,Roll_exp,Yaw_exp,
                         IMU.pitch, IMU.roll, IMU.yaw,      //IMU.yaw -->变为兔子给的数据
                         gyro.x, gyro.y, gyro.z,
                         &Pitch_PID, &Roll_PID, &Yaw_PID);
}

//void calcPid(PidObject *APidObject,PidConfig *APidConfig,float exp,float data_now);
/*
void LightDisCtrl(float distance_exp,float distance_now, float *distance_Pid){
    calcPid_Find(&piddistance, distance_exp, distance_now);
    clacPid(&pidAngle, Angle_exp, Angle_now);
    *distance_Pid = piddistance.output;

}
void LightAngleCtrl(float Angle_exp, float Angle_now, float *Angle_Pid){
    calcPid(&pidAngle, Angle_exp, Angle_now);
    *Angle_Pid = pidAngle.output;
}
*/
void calcPidHeight(float Height_exp, float Height_now, float *Height_Pid){
    calcPid(&pidHeight, Height_exp, Height_now);
/*
    if(pidHeight.output > 105){
        pidHeight.output = 105;
    }
    else if(pidHeight.output < -105){
        pidHeight.output = -105;
    }
*///遥控器的限幅

    if(pidHeight.output > 55){
        pidHeight.output = 55;
    }
    else if(pidHeight.output < -70){
        pidHeight.output = -70;
    }
    *Height_Pid = pidHeight.output;

}

void calcPidSelfStability(float Pitch_exp,float Roll_exp,float Yaw_exp,
						  float Pitch_now,float Roll_now,float Yaw_now,
						  float GYROx_now,float GYROy_now,float GYROz_now,
						  float *Pitch_Pid,float *Roll_Pid,float *Yaw_Pid) {
	calcPid(&pidPitchAngle,Pitch_exp,Pitch_now);
	calcPid(&pidRollAngle,Roll_exp,Roll_now);
	calcPid(&pidYawAngle,Yaw_exp,Yaw_now);

					  
	calcPid(&pidPitchAngularRate,pidPitchAngle.output,GYROx_now);
	calcPid(&pidRollAngularRate,pidRollAngle.output,GYROy_now);
	calcPid(&pidYawAngularRate,pidYawAngle.output,GYROz_now);
							  
	*Pitch_Pid = pidPitchAngularRate.output;
	*Roll_Pid = pidRollAngularRate.output;
	*Yaw_Pid = pidYawAngularRate.output;
}
