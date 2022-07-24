/* 
 * File:   Timer.h
 * Author: GaoLa
 *
 * Created on 2022年6月26日, 下午9:57
 */

#ifndef TIMER_H
#define	TIMER_H
#include "../USER/User.h"
/*--------------Timer3寄存器初始值宏定义--------------------*/
//在空闲模式下模块继续工作 
//时钟源选择内部时钟（FP）
//输入时钟预分频比1:64 60MHZ/64=0.9375MHZ 既1us
#define T3CON_INIT      0x0020 
#define TMR3_INIT       0x0000 //计数器初始值设置为零
#define PR3_INIT        0x03E8 //设定周期寄存器值为1000，一个周期既为1ms。1000us/1=1000

extern void INIT_SECTION McuTimer3Initialize(void);

#endif	/* TIMER_H */

