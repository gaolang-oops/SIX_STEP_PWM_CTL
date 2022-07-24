/* 
 * File:   Adc.h
 * Author: GaoLa
 *
 * Created on 2022��7��1��, ����9:26
 */
#ifndef ADC_H
#define	ADC_H
#include "../USER/User.h"
/*==================================================*/
/* 1.65Vģ���ѹ���VREFIO - ����Ĵ�����ʼֵ�궨�� */
#define CVRCON_INIT 0x00c8
/*==================================================*/

/*==================================================*/
/* ADCģ�� - �Ĵ�����ʼֵ�궨��
 * 4ͨ���Զ�ͬʱ������PWM1����ת������
 * ͨ��0��ͬ�������ʼѡ��ΪAN3   
 * ������·����MUXA��ͨ��1��2��3��ͬ������ѡ��ΪAN0/1/2 (CH123SA = 0)
 * AN0-Ia       AN1-Ib          AN2-Ic
 * AN3-Vbus     AN4-��ť��ѹ    AN6-Ibus
 */
#define AD1CON1_INIT    0x001c  //ѡ��10λ4ͨ������ ���������ʽΪ�޷������� PWM������1������������������ʼת�� �Զ�����
#define AD1CON2_INIT    0x0200  //ת�����ο���ѹΪ VREFH AVDD VREFL AVSS ת��ͨ��ѡ��CH0/1/2/3 ʹ��MUXAѡ�������ͨ��
#define AD1CON3_INIT    0x0004  //ADCת����ʱ��Դѡ��ϵͳʱ�� �Զ�����ʱ��Ϊ0TAD ADCת��ʱ��TAD = 5Tp = 5*16.6ns = 83.3ns
#define AD1CON4_INIT    0x0000  //��ʹ��DMA
#define AD1CHS123_INIT  0x0000  //CH1-CH3 MUXA/B ���������ѡ��VREFL ͬ�������ѡ��AN0/AN1/AN2
#define AD1CHS0_INIT    0x0303  //CH0 MUXA/B ���������ѡ��VREFL ͬ�������ѡ��AN3
#define AD1CSSH_INIT    0x0000  //û��ʹ��ͨ��ɨ��
#define AD1CSSL_INIT    0x0000  //û��ʹ��ͨ��ɨ��
/*==================================================*/
//adc�˲�����  ע�⣬tanx��ValueSum�����65535��ADC���������10λ����max 1023������ô�����ʹ�������64��ValueSum�����
#define    ANU_SAMPLE_NUM    64 
#define    ANP_SAMPLE_NUM    8      //adc�˲�����

/*==============================================================================
 ADCģ��ṹ�����Ͷ���
==============================================================================*/
typedef struct {
    unsigned int ValueInstant;
    unsigned int ValueAverage;
    unsigned int ValueSum;
    unsigned int ValueNum;
    unsigned int ValueFilter;
} tAnx_Type;

/*==================================================*/
typedef struct {
    tAnx_Type An0, An1, An2, An3, An4, An6;
    //AN0-Ia    AN1-Ib   AN2-Ic     AN3-Vbus    AN4-��ť��ѹ    AN6-Ibus
    unsigned int Index;
    unsigned int PotValue; //�˲������ť��ѹֵ
    unsigned int BusValue; //�˲����Vbus��ѹֵ
} tAdc_Type;

/*==================================================*/
extern tAdc_Type ADC_RAM tAdc;
extern void ADC_SECTION AdcModule(void);
extern void INIT_SECTION McuCompInitialize(void);
extern void INIT_SECTION McuAdcInitialize(void);
extern void INIT_SECTION AdcIntInitialize(unsigned int IPC);
/*==================================================*/
#endif	/* ADC_H */

