#include "include/control.h"

// 自稳控制: 俯仰、横滚角度，偏航角速度
__imu target_stabilized;
float target_yaw_rate;
float height_exp = 100.0;

const float d_time_attitude = 2.5e-3;


void init_Control(void) {
    
    init_Ctrl_Acro();
    init_Ctrl_Stabilized();
    
}

void control_All(__flight_mode_t flight_mode,
                 int *motor_1, int *motor_2, int *motor_3, int *motor_4) {
    static unsigned char cntr = 0;
    bool is_in_safe;
    int motor_out_throttle = 0;
    //float roll_out = 0.0f, pitch_out = 0.0f, yaw_out = 0.0f;
    //float Pitch_PID,Roll_PID,Yaw_PID;
    
    is_in_safe = control_Safety();
                         
    if (is_in_safe) {
        // 安全开关打开
        // 则切断所有控制，关闭马达，阻止起飞
        // *motor_1 = *motor_2 = *motor_3 = *motor_4 = 0;
        if(cntr++ >= 3){
            P1DIR |= BIT0;
            P1OUT ^= BIT0;
            cntr = 0;
        }
        return;
    }
    calc_Throttle_Acro(rc, &motor_out_throttle);
/*    if(abs(camera_angle) > 2){
        calcPidSelfStability(0, 0, 0,
                                     IMU.pitch, IMU.roll, camera_angle,
                                     gyro.x, gyro.y, gyro.z,
                                     &Pitch_PID, &Roll_PID, &Yaw_PID);

    }
    else if(abs(camera_angle) <= 2){
        if(camera_dis <= (2 / 3 * camera_dis_fir)){
        calcPidSelfStability(2, 0, 0,
                             IMU.pitch, IMU.roll, camera_angle,
                             gyro.x, gyro.y, gyro.z,
                             &Pitch_PID, &Roll_PID, &Yaw_PID);

        }
        else if(camera_dis > (2 / 3 * camera_dis_fir)){
            calcPidSelfStability(-4, 0, 0,
                                 IMU.pitch, IMU.roll, camera_angle,
                                 gyro.x, gyro.y, gyro.z,
                                 &Pitch_PID, &Roll_PID, &Yaw_PID);

        }


    }
    */
    calcPidHeight( EXP_HEIGHT/ (cos(IMU.pitch) * cos(IMU.roll ) ), dst_f, &Height_PID);

/*
    switch (flight_mode) {
        
        case mode_stabilized : {

            calc_Target_Stabilized(rc);
            calc_Throttle_Stabilized(rc, &motor_out_throttle);
            control_PID_Stabilized(gyro.x,   gyro.y,     gyro.z,
                                   IMU.roll, IMU.pitch,  IMU.yaw,
                                   &roll_out, &pitch_out, &yaw_out);
*\
        } break;
        
        case mode_acro : {
                        
            calc_Target_Acro(rc);
            calc_Throttle_Acro(rc, &motor_out_throttle);
            control_PID_Acro(gyro.x, gyro.y, gyro.z,
                             &roll_out, &pitch_out, &yaw_out);
                    
        } break;
        
        default : break;
    }
*/
    *motor_1 = motor_out_throttle - Pitch_PID - Roll_PID + Yaw_PID + Height_PID - 147;
    *motor_2 = motor_out_throttle + Pitch_PID + Roll_PID + Yaw_PID + Height_PID - 126;
    *motor_3 = motor_out_throttle - Pitch_PID + Roll_PID - Yaw_PID + Height_PID - 150;
    *motor_4 = motor_out_throttle + Pitch_PID - Roll_PID - Yaw_PID + Height_PID - 125;
    
}

/*
安全开关相关，应该在主程序内被执行:

*/
bool control_Safety(void) {    

    if (rc.withoutDream == 1) {
        // 紧急停止打开，不能起飞
        WithoutDream = true;
        return true;
    } else {
        WithoutDream = false;
        if (rc.unlock == 0) {
            // 紧急停止关闭但马达没解锁，不能起飞
            IfUnlock = false;
            return true;
        } else if (rc.unlock == 1) {
            // 飞行器安全锁没有开启，可以起飞
            IfUnlock = true;
            return false;
        }
    }
    return true;
}

void Find_Light(){




}

