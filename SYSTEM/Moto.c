/*============================================================================*/
//工程描述：方波六步换相控制
//使用MCU：dsPIC33EP128MC506
//文件名：Motor.c
//文件功能：电机运行控制
//日期：2022年3月25日
/*============================================================================*/
#include "Moto.h"
#include "Error.h"
#include "../HARDWARE/Key.h"
#include "../HARDWARE/Adc.h"
#include "Kernel.h"

UNION_MOTORFLAGS MOTO_RAM Motor_Flag;
tMotor_Type MOTO_RAM tMotor;

/*
 * 函数功能：电机模块初始化
 * 函数输入：无
 * 函数输出：无
 * 设置电机旋转方向 
 * 设置状态机为停止态 确保ADC中断不会运行状态机
 * 设置电机标志为停 确保外力误将电机拧动也不会触发换相
 */
void MOTO_SECTION MotorInitialize(unsigned char direction) {
    Motor_Flag.Bits.Direction = direction;
    tKernel.State = KERNEL_STATE_STOP;
    Motor_Flag.Bits.Status = 0;
}

/*
 * 函数功能：电机启停控制
 * 函数输入：无
 * 函数输出：无
 */
static void MOTO_SECTION MotorRunStopControl(void) {
    if (Motor_Flag.Bits.Status == 0) {
        //无异常，有占空比，启动键按下 均满足电机才能启动
        if ((Error_Flag.Word == 0) && (tAdc.PotValue > 0) && (tKey.FLAG.BITS.Pressed == 1)) {
            Motor_Flag.Bits.Status = 1; //IC中断可以触发换相
            tSysTick.TickPwmSet = 50; //每50MS一次更新电机占空比
            tKey.FLAG.BITS.Pressed = 0;
            KernelStartUp();
        }
    } else if ((Motor_Flag.Bits.ReqOff == 1) || (tAdc.PotValue == 0)) {
        Motor_Flag.Bits.Status = 0; //Status置为0，说明电机处于停止状态
        Motor_Flag.Bits.ReqOff = 0; //清零，为后续故障请求停机做准备。
        KernelStop(); //状态机的状态修改为停止状态
    }
}

/*
 * 函数功能：占空比调节控制
 * 函数输入：无
 * 函数输出：无
 * 在stop状态时tMotor.PwmValue = MINDUTY; 占空比已经有了最小值，此值在init状态写入PDC
 * 所以PwmDutyControl函数的作用在电机run状态每50ms调节占空比
 */
void MOTO_SECTION PwmDutyControl(void) {
    unsigned int Temp;
    DISIE();
    Temp = tSysTick.TickPwmSet;
    ENIE();
    if ((tKernel.State == KERNEL_STATE_RUN)&&(Temp == 0)) {
        DISIE();
        tSysTick.TickPwmSet = 50;
        ENIE();
        if (tAdc.PotValue >= tMotor.PwmValue) {
            Temp = tAdc.PotValue - tMotor.PwmValue;
            if (Temp > 100) {
                tMotor.PwmValue += 100;
            } else if (Temp > 10) {
                tMotor.PwmValue += 10;
            } else {
                tMotor.PwmValue = tAdc.PotValue;
            }
        } else {
            Temp = tMotor.PwmValue - tAdc.PotValue;
            if (Temp > 100) {
                tMotor.PwmValue -= 100;
            } else if (Temp > 10) {
                tMotor.PwmValue -= 10;
            } else {
                tMotor.PwmValue = tAdc.PotValue;
            }
        }
    }
}

/*
 * 函数功能：电机驱动模块
 * 函数输入：无
 * 函数输出：无
 */
void MOTO_SECTION MotorModule(void) {
    KeyScan(); //检测是否按下启动键
    MotorRunStopControl();
    PwmDutyControl();
}

/*
 * 函数功能：换相控制
 * 根据IC中断中的hall值换相
 * 根据旋钮电压值调节占空比
 * 函数输入：无
 * 函数输出：无
 * 注意取反
 */
void MOTO_SECTION CommutationControl(void) {
    PDC1 = tMotor.PwmValue;
    PDC2 = tMotor.PwmValue;
    PDC3 = tMotor.PwmValue;
    if (!Motor_Flag.Bits.Direction) {
        switch (tMotor.CommutationValue) {
            case 5://U V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 4://U W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 6://V W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 2://V U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 3://W U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            case 1://W V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            default:
                CloseAllMos();
                break;
        }
    } else {
        switch (tMotor.CommutationValue) {
            case 2://U V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 3://U W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 1://V W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 5://V U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 4://W U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            case 6://W V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            default:
                CloseAllMos();
                break;
        }
    }
}




