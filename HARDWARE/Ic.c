#include "Ic.h"
#include "../SYSTEM/Rotor.h"
#include "../SYSTEM/Moto.h"
#include "Led.h"

/*=============MCU���벶׽ģ���ʼ��====================*/
void INIT_SECTION McuIcInitialize(void) {
    //���벶׽1ģ��Ĵ�����ʼ��
    IC1CON1 = IC1CON1_INIT;
    IC1CON2 = IC1CON2_INIT;
    //���벶׽2ģ��Ĵ�����ʼ��
    IC2CON1 = IC2CON1_INIT;
    IC2CON2 = IC2CON2_INIT;
    //���벶׽3ģ��Ĵ�����ʼ��
    IC3CON1 = IC3CON1_INIT;
    IC3CON2 = IC3CON2_INIT;
    //���벶׽4ģ��Ĵ�����ʼ��
}

/*=============���벶���жϳ�ʼ��====================*/
void INIT_SECTION IcIntInitialize(unsigned int IPC) {
    //������벶׽IC1~3�жϱ�־λ
    IFS0bits.IC1IF = 0;
    IFS0bits.IC2IF = 0;
    IFS2bits.IC3IF = 0;
    //�������벶׽IC1~3�ж����ȼ�λΪ7 �û��ж�����ȼ�7Ϊ���
    IPC0bits.IC1IP = IPC;
    IPC1bits.IC2IP = IPC;
    IPC9bits.IC3IP = IPC;
    //ʹ�����벶׽IC1~3�ж�����λ
    IEC0bits.IC1IE = 1;
    IEC0bits.IC2IE = 1;
    IEC2bits.IC3IE = 1;
}

/*
 * ���벶׽IC1~3���жϷ�����
 */

void __attribute__((section(".ic_section"), interrupt, no_auto_psv)) _IC1Interrupt(void) {
    //���IC1���жϱ�־λ
    IFS0bits.IC1IF = 0;
    if (Motor_Flag.Bits.Status == 1) {//���������ת
        GetRotorInfo(); //��ȡhallֵ
        CommutationControl(); //����
    }
}

void __attribute__((section(".ic_section"), interrupt, no_auto_psv)) _IC2Interrupt(void) {
    //���IC2���жϱ�־λ
    IFS0bits.IC2IF = 0;
    if (Motor_Flag.Bits.Status == 1) {//���������ת
        GetRotorInfo(); //��ȡhallֵ
        CommutationControl(); //����
    }
}

void __attribute__((section(".ic_section"), interrupt, no_auto_psv)) _IC3Interrupt(void) {
    //���IC3���жϱ�־λ
    IFS2bits.IC3IF = 0;
    if (Motor_Flag.Bits.Status == 1) {//���������ת
        GetRotorInfo(); //��ȡhallֵ
        CommutationControl(); //����
    }
}

