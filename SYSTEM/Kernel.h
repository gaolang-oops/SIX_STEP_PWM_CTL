/* 
 * File:   kernel.h
 * Author: GaoLa
 *
 * Created on 2022年7月2日, 下午9:21
 */

#ifndef KERNEL_H
#define	KERNEL_H
#include "../USER/User.h"

/*
 * 宏定义
 */
#define     KERNEL_STATE_STOP           0
#define     KERNEL_STATE_READY          1
#define     KERNEL_STATE_BOOTCHARGE     2
#define     KERNEL_STATE_INIT           3
#define     KERNEL_STATE_RUN            4


/*
 * 系统软件计数器结构体类型定义
 */
typedef struct
{
    unsigned char Tick50us;
    unsigned char TickPwmSet;
    unsigned int Tick1ms;
    unsigned int TickStartup;
}tSysTick_Type;

/*
 * 系统控制结构体类型定义
 */
typedef struct
{
    unsigned char State;
    unsigned int DownCounter;
}tKernel_Type;

extern tSysTick_Type SYS_RAM tSysTick; 
extern tKernel_Type SYS_RAM tKernel;

extern void SYS_SECTION Sys_CntUp_Timer(void);
extern void SYS_SECTION KernelRunStateMachine(void);
extern void SYS_SECTION KernelStartUp(void);
extern void SYS_SECTION KernelStop(void);
extern void SYS_SECTION CloseAllMos(void);
#endif	/* KERNEL_H */

