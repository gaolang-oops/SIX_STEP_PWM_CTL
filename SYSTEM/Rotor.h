/* 
 * File:   Rotor.h
 * Author: GaoLa
 *
 * Created on 2022��7��3��, ����9:37
 */

#ifndef ROTOR_H
#define	ROTOR_H
#include "../USER/User.h"

//hall�ź�����궨��
#define HALLU_Bit       PORTGbits.RG8
#define HALLV_Bit       PORTGbits.RG7
#define HALLW_Bit       PORTGbits.RG6

/*
 * hall�ṹ�����Ͷ���
 */
typedef struct
{
unsigned int Hall_Value_Buf[3];
unsigned int Hall_Value_Old;
unsigned int Hall_Value_Cur;
unsigned int Hall_Update;
unsigned int Hall_Update_Count;
}tHall_Type;

extern tHall_Type ROTOR_RAM tHall;
extern void ROTOR_SECTION GetRotorInfo(void);
#endif	/* ROTOR_H */

