/* 
 * File:   Moto.h
 * Author: GaoLa
 *
 * Created on 2022��7��3��, ����5:22
 */

#ifndef MOTO_H
#define	MOTO_H
#include "../USER/User.h"

/*
 * PWM���ƼĴ���ֵ�궨��
 */
#define    IOCON_HL_INVALID        0xcf00
#define    IOCON_HINVALID_LHIGH    0xcf40
#define    IOCON_HPWM_LINVALID     0xcd00

typedef union
{	
	unsigned int Word;
	struct
	{
		unsigned Status:1;
		unsigned ReqOff:1;
		unsigned Direction:1;
		unsigned Unused:13;
	}Bits;
}UNION_MOTORFLAGS;

/*
 * ��������ṹ�����Ͷ���
 */
typedef struct
{
    unsigned int PwmValue;
    unsigned int CommutationValue;
}tMotor_Type;

extern UNION_MOTORFLAGS MOTO_RAM Motor_Flag;
extern tMotor_Type MOTO_RAM tMotor;
extern void MOTO_SECTION MotorModule(void);
extern void MOTO_SECTION MotorInitialize(unsigned char direction);
extern void MOTO_SECTION CommutationControl(void);
#endif	/* MOTO_H */

