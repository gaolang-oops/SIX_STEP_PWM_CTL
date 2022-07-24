/* 
 * File:   User.h
 * Author: GaoLa
 *
 * Created on 2022��6��26��, ����6:46
 */
/*============================================================================*/
//ʹ��MCU��dsPIC33EP128MC506
//�ļ����ܣ��û��趨����ͷ�ļ�
/*============================================================================*/
#ifndef USER_H
#define	USER_H
#include "../SOC/p33EP128MC506.h"

/*=============�궨��====================*/
/*==============================================================================
�ж�ʹ��/ʧ�ܺ궨�� GIC�����жϿ��͹�
==============================================================================*/
#define    ENIE()     {INTCON2 = 0x8000;} 
#define    DISIE()    {INTCON2 = 0x0000;} 
// �Ĵ���7-1�� SR��CPU ״̬�Ĵ���(1)���ϵ�Ĭ��000 = CPU �ж����ȼ�Ϊ0 ��8�������û��ж϶�������Ӧ
/*==============================================================================
 * ����CPU_IPL�Ĵ��������ж��ż� ���Դﵽͬ��Ч��
//#define ENIE()  SET_CPU_IPL(6)//���������ֻ��Timer3һ���жϣ�
//��CPU�ж����ȼ�����1λ��7-1=6���������Ϳ�����Ӧ�û��ж����ȼ�Ϊ7���ж�
//#define DISIE()  SET_CPU_IPL(7)

////SET_CPU_IPL����506.h�ڶ��壺
//// #define SET_CPU_IPL(ipl) {       \
////  SRbits.IPL = ipl;              \
////  __builtin_nop();               \
//// } (void) 0
==============================================================================*/

/*==============================================================================
//����κ궨��
==============================================================================*/
#define MAIN_SECTION    __attribute__((section(".main_section")))
#define INIT_SECTION    __attribute__((section(".init_section")))
#define SYS_SECTION     __attribute__((section(".sys_section")))
#define ERROR_SECTION     __attribute__((section(".error_section")))
#define MOTO_SECTION     __attribute__((section(".moto_section")))
#define ROTOR_SECTION     __attribute__((section(".rotor_section")))
#define LED_SECTION     __attribute__((section(".led_section")))
#define KEY_SECTION     __attribute__((section(".key_section")))
#define IC_SECTION      __attribute__((section(".ic_section")))
#define TIMER_SECTION   __attribute__((section(".timer_section")))
#define PWM_SECTION     __attribute__((section(".pwm_section")))
#define ADC_SECTION     __attribute__((section(".adc_section")))
#define SPI_SECTION     __attribute__((section(".spi_section")))
/*==============================================================================
//���ݶκ궨��
==============================================================================*/
#define MAIN_RAM    __attribute__((section(".main_ram")))
#define SYS_RAM     __attribute__((section(".sys_ram")))
#define SYSTICK_RAM     __attribute__((section(".systick_ram")))
#define ERROR_RAM     __attribute__((section(".error_ram")))
#define LED_RAM     __attribute__((section(".led_ram")))
#define KEY_RAM     __attribute__((section(".key_ram")))
#define HALL_RAM    __attribute__((section(".hall_ram")))
#define PWM_RAM     __attribute__((section(".pwm_ram")))
#define ADC_RAM     __attribute__((section(".adc_ram")))
#define SPI_RAM     __attribute__((section(".spi_ram")))
#define MOTO_RAM     __attribute__((section(".moto_ram")))
#define ROTOR_RAM     __attribute__((section(".rotor_ram")))
/*==============================================================================
 PWM - ģʽ�궨��
==============================================================================*/
#define PWM_MODE PWM_EDGE_ALIGNMENT
#define PWM_EDGE_ALIGNMENT 1
#define PWM_CENTER_ALIGNMENT 0
/*==============================================================================
 PWM - �ز�Ƶ�ʺ궨��
==============================================================================*/
#define    CARRIER_FREQUENCY   20000 //PWM�ز�Ƶ�� 20KHz ��1s��20 000������
#if PWM_MODE 
#define    PWM_PERIOD_VALUE    (120000000 / CARRIER_FREQUENCY)  //120MHz/20KHz=6000 ��ʱ������6000Ϊһ������
#else
#define    PWM_PERIOD_VALUE    (120000000 / CARRIER_FREQUENCY / 2)  //120MHz/20KHz/2=3000 ����ʱ�� ���Ķ���
#endif 
/*==============================================================================
 PWM - �����궨��
==============================================================================*/
#define ALIGN_CENTER_DEAD_TIME    0x00F0  //���Ķ���ģʽ������ʱ��Ϊ2us��ALTDTR1=Fosc*����ʱ��/pwmʱ��Ԥ��Ƶ��=120*2/1=240=F0 
#define PWM_NUM_1MS   (CARRIER_FREQUENCY/1000) //PWMƵ����CARRIER_FREQUENCY������1000����ÿ1ms��Ҫ�ж��ٸ�PWM����

/*
 * �����Сռ�ձ�����
 */
#define    MAXDUTY    6000
#define    MINDUTY    300

/*
 * ��ѹ���ϵ��
 */
#define    VBUS_FACTOR        53
#define    VBUS_LOW_LIMIT     18    //18v����
#define    VBUS_HIGH_LIMIT    30    //30v����

/*
 * �����ת����
 * counterclockwise����ʱ�뷽���;
 * clockwise��˳ʱ�뷽���; ˳ʱ�뷽��(��);
 */
#define    CW     0 
#define    CCW    1  

/*
 * �궨�����ƴ�С �����Ʒ�Χ
 */
#define Limit_Max(x,max) ((x)>(max)?(max):(x))
#define Limit_Min(x,min) ((x)<(min)?(min):(x))
#define Limit_Val(x,min,max) ((x)<(min)?(min):((x)>(max)?(max):(x)))

/*---------------------------------------------------------------------------*/
//NOP�����궨��
#define     NOP()       __builtin_nop()
#define     DELAY100NS()    NOP();NOP();NOP();NOP();NOP();NOP()
/*---------------------------------------------------------------------------*/

/*==============================================================================
 ���������Ͷ���
==============================================================================*/
typedef union
{
    unsigned long U32;
    struct
    {
        unsigned int Low;
        unsigned int High;
    }Words;
}UNION_U32;

typedef union
{
	unsigned int Word;
	struct
	{
		unsigned B0:1;	
		unsigned B1:1;
		unsigned B2:1;
		unsigned B3:1;
		unsigned B4:1;
		unsigned B5:1;
		unsigned B6:1;	
		unsigned B7:1;
		unsigned B8:1;	
		unsigned B9:1;
		unsigned B10:1;
		unsigned B11:1;
		unsigned B12:1;
		unsigned B13:1;
		unsigned B14:1;	
		unsigned B15:1;	
	}Bits;
}UNION_WORD;


#endif	/* USER_H */

