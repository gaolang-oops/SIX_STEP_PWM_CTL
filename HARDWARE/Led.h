/* 
 * File:   Led.h
 * Author: GaoLa
 *
 * Created on 2022��6��26��, ����5:01
 */
#ifndef LED_H
#define	LED_H
#include "../USER/User.h"

/*---------------LED�궨��----------------------*/
/* 
 * LATx �Ĵ���:
 * ר�������ű�����Ϊ����������ܵ�ʱ������������ߵ�ƽ���ߵ͵�ƽ�ġ�
 * ��Ӧ��λ�У�д0���Ƕ�Ӧ��������͵�ƽ��д1������������ߵ�ƽ��
 */
#define LED0_PIN        LATEbits.LATE12
#define LED1_PIN        LATEbits.LATE13
#define LED2_PIN        LATEbits.LATE14
#define LED3_PIN        LATEbits.LATE15

#define LED_ON          0
#define LED_OFF         1

/* 
 * PWM������50us��ÿ��50us LedCount����_AD1Interrupt��Adc_CntUp_Timer������ݼ�
 * LEDFLICK_TIMEΪ20�� ��LEDFLICK_TIME�ݼ�����Ϊ1ms 
 */

extern void LED_SECTION Led_All_On(void);
extern void LED_SECTION Led_All_Off(void);
#endif	/* LED_H */