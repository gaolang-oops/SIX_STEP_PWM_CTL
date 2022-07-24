/* 
 * File:   Pwm.h
 * Author: GaoLa
 *
 * Created on 2022��6��28��, ����8:01
 */

#ifndef PWM_H
#define	PWM_H
#include "../USER/User.h"

#if PWM_MODE
/*--------------�������ƣ�����ն�������ź�ͨ������ʱ�����ض��� PWMģ��Ĵ�����ʼֵ�궨��--------------------*/
#define PTCON_INIT      0x0000
#define PTCON2_INIT     0x0000  //����PWMģ��ļ������ļ���Ƶ�ʡ�ʹ��Ĭ�ϵ�1��Ƶ��PWMģ����Fosc = 120MHz���м���
//PWM������1�Ĵ�����ʼֵ�궨��
#define PWMCON1_INIT    0x0280  //ѡ�����ʱ��ģʽ��ITB=1��PDC1�Ĵ���ΪPWM������1�ṩռ�ձȣ�MDCS=0��ʹ�ñ��ض���ģʽ��CAM=0
#define IOCON1_INIT     0xcd00  //PWM������PWMģ�������ƣ�PWM�����Ч��ƽ�Ǹߵ�ƽ��ʹ��PWM1L���Ÿ�д��PWM1L��������͵�ƽ
#define FCLCON1_INIT    0x0003  //���Ͽ����ź�Դѡ��λ ѡ�����1��3��ʾ���ù�������
#define PHASE1_INIT     PWM_PERIOD_VALUE  //PWM�ز�Ƶ��6000=FOSC/PWM�ز�Ƶ��/Ԥ��Ƶ��=120MHZ/20KHZ/1
#define PDC1_INIT       300     //ռ�ձȳ�ʼֵ300 120Mhzʱ��300/6000��ʾռ�ձ�Ϊ5%
#define DTR1_INIT       0x0000  //�����Ĵ���Ϊ0����Ϊ�Ǳ��ض���ģʽ
#define ALTDTR1_INIT    0x0000  //�����Ĵ���Ϊ0����Ϊ�Ǳ��ض���ģʽ
#define TRGCON1_INIT    0x0000  //TRGCON1_INIT�������ƼĴ�����0x0000���Ǵ����¼�û����ʱ��ÿ�������¼������д����źŵ����������ADC����ת����
#define TRIG1_INIT      300     //���ô���ֵ��Ҳ�������ô���ʱ�̵㡣������ʱ����������PTMRx���Ĵ���ֵ��ָ����TRIGx �Ĵ���ֵƥ��ʱ���������ADC �����źš�
//PWM������2�Ĵ�����ʼֵ�궨��
#define PWMCON2_INIT    0x0280
#define IOCON2_INIT     0xcd00
#define FCLCON2_INIT    0x0003  
#define PHASE2_INIT     PWM_PERIOD_VALUE 
#define PDC2_INIT       300     
#define DTR2_INIT       0x0000  
#define ALTDTR2_INIT    0x0000  
//PWM������3�Ĵ�����ʼֵ�궨��
#define PWMCON3_INIT    0x0280 
#define IOCON3_INIT     0xcd00  
#define FCLCON3_INIT    0x0003  
#define PHASE3_INIT     PWM_PERIOD_VALUE    
#define PDC3_INIT       300     
#define DTR3_INIT       0x0000  
#define ALTDTR3_INIT    0x0000
#else
/*--------------����ʱ�����Ķ��� PWMģ��Ĵ�����ʼֵ�궨��--------------------*/
#define PTCON_INIT      0x0000
#define PTCON2_INIT     0x0000
//PWM������1�Ĵ�����ʼֵ�궨��
#define PWMCON1_INIT    0x0204  //ѡ�����ʱ��ģʽ��ITB=1��ʩ��������DTC=00��PDC1�Ĵ���ΪPWM������1�ṩռ�ձȣ�MDCS=0��ʹ�����Ķ���ģʽ��CAM=1
#define IOCON1_INIT     0xc000  //PWM����1H��1Lȫ����PWMģ�������ƣ�PWM�����Ч��ƽ�Ǹߵ�ƽ��pwm�������ģʽ
#define FCLCON1_INIT    0x0003  //���Ͽ����ź�Դѡ��λ ѡ�����1��3��ʾ���ù�������
#define PHASE1_INIT     PWM_PERIOD_VALUE  //����PWM�ز�Ƶ��Ϊ20KHZ. PHASE1��3000=FOSC/PWM�ز�Ƶ��/Ԥ��Ƶ��/2=120MHZ/20KHZ/1/2
#define PDC1_INIT       300     //ռ�ձȳ�ʼֵ300 120Mhzʱ��300��ʾռ�ձ�Ϊ10%
//����pwm��ʽ�����������ܽ���ʼռ�ձ�����Ϊ0����Ȼ�޷���������
#define DTR1_INIT       0x0000  //���Ķ���ģʽ�£�����ֻ��ALTDTR1����
#define ALTDTR1_INIT    ALIGN_CENTER_DEAD_TIME  //���Ķ���ģʽ������ʱ��Ϊ2us��ALTDTR1=Fosc*����ʱ��/pwmʱ��Ԥ��Ƶ��=120*2/1=240=F0 
#define TRGCON1_INIT    0x1000  //TRGCON1_INIT�������ƼĴ�����0x1000���ǲ�����һ�������¼�ǰ���õȴ�PWM���ڡ�ÿ2�������¼������źŵ����������ADC����ת����
#define TRIG1_INIT      3000    //���ô���ֵ��Ҳ�������ô���ʱ�̵㡣�����ſ�ͨ��PWMxL�ߵ�ƽ���е�ȥ����ADC����
//PWM2 PWM2������TRGCON1��TRIG1����Ϊ����ֻ��Ҫһ������Դ�Ϳ��Դ���ADC��ʼת����

//PWM������2�Ĵ�����ʼֵ�궨��
#define PWMCON2_INIT    0x0204
#define IOCON2_INIT     0xc000
#define FCLCON2_INIT    0x0003  
#define PHASE2_INIT     PWM_PERIOD_VALUE 
#define PDC2_INIT       300     
#define DTR2_INIT       0x0000  
#define ALTDTR2_INIT    ALIGN_CENTER_DEAD_TIME  
//PWM������3�Ĵ�����ʼֵ�궨��
#define PWMCON3_INIT    0x0204 
#define IOCON3_INIT     0xc000  
#define FCLCON3_INIT    0x0003  
#define PHASE3_INIT     PWM_PERIOD_VALUE    
#define PDC3_INIT       300     
#define DTR3_INIT       0x0000  
#define ALTDTR3_INIT    ALIGN_CENTER_DEAD_TIME
#endif 

extern void INIT_SECTION McuPwmInitialize(void);
/*ռ�ձ����룺PwmDuty% [0,100] */
extern void PWM_SECTION PwmDutySet(unsigned int PwmDuty1, unsigned int PwmDuty2, unsigned int PwmDuty3);

#endif	/* PWM_H */

