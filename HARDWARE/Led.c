/*==================================================
�ļ�������Led�ļ�
ʹ��MCU��dsPIC33EP128MC506
�ļ�����Led.c
�ļ����ܣ�Led����
���ߣ�����
==================================================*/
#include "Led.h"

void LED_SECTION Led_All_On(void) {
    LED0_PIN = LED1_PIN = LED2_PIN = LED3_PIN = LED_ON; //����LAT�Ĵ���д��ֵ
}

void LED_SECTION Led_All_Off(void) {
    LED0_PIN = LED1_PIN = LED2_PIN = LED3_PIN = LED_OFF; //����LAT�Ĵ���д��ֵ
}

