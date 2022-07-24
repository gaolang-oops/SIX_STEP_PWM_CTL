#include "Kernel.h"
#include "Error.h"
#include "Moto.h"
#include "Rotor.h"
#include "../HARDWARE/Led.h"
/*
 * 系统时基定义
 */
tSysTick_Type SYSTICK_RAM tSysTick;
tKernel_Type SYS_RAM tKernel;

extern void Delay(void); //汇编延时函数 位于system目录内

/*
 * 该函数被adc中断调用
 * 20KHz的pwm波每50us触发ADC模块转换数据,则每50us tSysTick.Tick50us 自加1
 * 产生PWM_NUM_1MS个PMW波后，证明1ms时间到 tSysTick.TickStartup 自减1
 * SysTick.TickStartup 自减到零证明1s到了，MCU初始化延时结束
 */
void SYS_SECTION Sys_CntUp_Timer(void) {
    tSysTick.Tick50us++;
    if (tSysTick.Tick50us >= PWM_NUM_1MS)//20*50us=1ms
    {
        tSysTick.Tick50us = 0;
        //1000ms Sys_CntUp_Timer指示灯闪烁一次
        if (tSysTick.Tick1ms > 1000) {
            LED2_PIN = ~LED2_PIN;
            tSysTick.Tick1ms = 0;
        }
        tSysTick.Tick1ms++;
        if (tSysTick.TickStartup != 0)
            tSysTick.TickStartup--;
        if (tSysTick.TickPwmSet != 0)
            tSysTick.TickPwmSet--;
        if (Led_Count != 0) {
            Led_Count--;
        }
    }
}

/*
 * 函数功能：系统启动
 * 函数输入：无
 * 函数输出：无
 */
void SYS_SECTION KernelStartUp(void) {
    tKernel.State = KERNEL_STATE_READY;
}

/*
 * 函数功能：系统停止
 * 函数输入：无
 * 函数输出：无
 */
void SYS_SECTION KernelStop(void) {
    tKernel.State = KERNEL_STATE_STOP;
    CloseAllMos();
    tMotor.PwmValue = MINDUTY; //占空比为最小值，在状态机进入init状态，将被写入PDC
    PDC1 = 0;
    PDC2 = 0;
    PDC3 = 0;
    LED0_PIN = LED_OFF;
}

/*
 * 函数功能：关闭六个MOS管
 * 函数输入：无
 * 函数输出：无
 * 从PWM发出关断信号到mos管真正关断是需要一定时间的
 * 如果这里closeAllMos立马根据输出带占空比的pwm波开通mos管，则可能还没有彻底关断就打开了，导致短路
 */
void SYS_SECTION CloseAllMos(void) {
    __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
    __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
    __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
}

/*
 * 函数功能：关闭三个上管，打开三个下管，用于自举电容充电
 * 函数输入：无
 * 函数输出：无
 */
static void SYS_SECTION BootCharge(void) {
    __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
    __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
    __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
}

/*
 * 函数功能：系统运行状态控制
 * 函数输入：无
 * 函数输出：无
 * 在ADC中断中调用，而ADC中断每50us触发
 */
void SYS_SECTION KernelRunStateMachine(void) {
    if (tKernel.DownCounter != 0)
        tKernel.DownCounter--; //每50us递减

    switch (tKernel.State) {
        case KERNEL_STATE_STOP:
            KernelStop();
            break;
        case KERNEL_STATE_READY:
            BootCharge();
            tKernel.DownCounter = 1000; //设置向下计数变量为1000，如果它从1000减到0，那么就表示50ms的时间充电时间
            tKernel.State = KERNEL_STATE_INIT;
            break;
        case KERNEL_STATE_INIT:
            if (tKernel.DownCounter == 0) {
                //从PWM发出关断信号到mos管真正关断是需要一定时间的
                //如果这里closeAllMos立马根据输出带占空比的pwm波开通mos管，则可能还没有彻底关断就打开了，导致短路
                CloseAllMos();
                Delay(); //汇编延时函数 确保mos管彻底关闭
                //电机准备启动，主动获取当前静止时得hall位置（因为电机静止，hall值固定，不会触发IC中断）
                GetRotorInfo();
                //电机准备启动，需要依据hall信号施加第一组PWM波，这样电机就动了，就会触发IC中断，然后在中断中换相
                CommutationControl();
                tKernel.State = KERNEL_STATE_RUN;
            }
            break;
        case KERNEL_STATE_RUN:
            //只有在hall更新时tHall.Hall_Update为1，其余时间都为零
            if (tHall.Hall_Update == 0) {
                if (tHall.Hall_Update_Count < 65535) //65535 x 50us = 3.276750s
                {
                    tHall.Hall_Update_Count++; //获取hall值时Hall_Update_Count会被清零
                    tMotor.CommutationValue = tHall.Hall_Value_Old; //暂时按照之前的值换相
                } else {
                    if (Motor_Flag.Bits.Status)
                        Error_Flag.Bits.Hall = 3; //hall故障或堵转，需要停机
                    else
                        tHall.Hall_Update_Count = 0;
                }
            }
            LED0_PIN = LED_ON;//电机运行指示灯
            break;
        default:
            break;
    }
}