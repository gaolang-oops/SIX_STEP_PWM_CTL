/* 
 * File:   Timer.h
 * Author: GaoLa
 *
 * Created on 2022��6��26��, ����9:57
 */

#ifndef TIMER_H
#define	TIMER_H
#include "../USER/User.h"
/*--------------Timer3�Ĵ�����ʼֵ�궨��--------------------*/
//�ڿ���ģʽ��ģ��������� 
//ʱ��Դѡ���ڲ�ʱ�ӣ�FP��
//����ʱ��Ԥ��Ƶ��1:64 60MHZ/64=0.9375MHZ ��1us
#define T3CON_INIT      0x0020 
#define TMR3_INIT       0x0000 //��������ʼֵ����Ϊ��
#define PR3_INIT        0x03E8 //�趨���ڼĴ���ֵΪ1000��һ�����ڼ�Ϊ1ms��1000us/1=1000

extern void INIT_SECTION McuTimer3Initialize(void);

#endif	/* TIMER_H */

