/* 
 * File:   HALL_IC.h
 * Author: GaoLa
 *
 * Created on 2022��6��26��, ����8:24
 */

#ifndef HALL_IC_H
#define	HALL_IC_H
#include "../USER/User.h"

/*--------------���벶׽ģ����ƼĴ�����ʼֵ�궨��--------------------*/
/*
 * ICxCON1�����벶׽x ���ƼĴ���1
 * 0 = ��CPU ����ģʽ�����벶׽����������
 * 000 = T3CLK ��ICx ��ʱ��Դ
 * 00 = ÿ�β�׽�¼�����һ���ж�
 * 0 = δ�������벶׽���������
 * 001 = ��׽ģʽ��ÿ�����أ������غ��½��أ���׽һ��
 * 
 * ICxCON2�����벶׽x ���ƼĴ���2
 * 0 = ��ֹ����ģ�����
 * �������������ܼ򵥣�ֻ��Ҫ��ʱ���ܹ�������֮�󣬸�λ���㼴�ɣ�
 * ����Ҫ���������Ĳ������ö�ʱ����λ�����ԣ�ʵ���ϣ�
 * ������ȫ�ò�����������ͬ�����ܡ����ԣ���5��λ��
 * ������Ҫ����Ϊ��û�д���Դ����ͬ��Դ������Ҳ�����ö�ʱ���Լ�������λ��
 */
//������⣺��Ҫʹ��T3CLK������ICxBUF���м���ֵ���������Ҫ������֮���ʱ�䣬���Բ�ʹ��T3CLK
//T3CLK��16λ�ļ�������1us����1�� ��������벶׽��ʱ����������ʱ���� 65.535ms
#define IC1CON1_INIT      0x0001
#define IC1CON2_INIT      0x0000
#define IC2CON1_INIT      0x0001
#define IC2CON2_INIT      0x0000
#define IC3CON1_INIT      0x0001
#define IC3CON2_INIT      0x0000

extern void INIT_SECTION McuIcInitialize(void);
extern void INIT_SECTION IcIntInitialize(unsigned int IPC);
#endif	/* HALL_IC_H */

