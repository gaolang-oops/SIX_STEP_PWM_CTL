/*============================================================================*/
//�������������������������
//ʹ��MCU��dsPIC33EP128MC506
//�ļ�����Error.c
//�ļ����ܣ����ϼ��
//���ڣ�2022��3��25��
/*============================================================================*/
#include "Error.h"
#include "../HARDWARE/Adc.h"
#include "../HARDWARE/Led.h"
#include "../SYSTEM/Moto.h"
/*
 * ��������
 */
UNION_ERRORFLAGS ERROR_RAM Error_Flag;
unsigned char ERROR_RAM Error_Code;
/* 
 * PWM������50us��ÿ��50usִ��_AD1Interrupt����_AD1Interrupt����CntUp_Timer����
 * ÿ1ms��CntUp_Timer�������ݼ� Led_Count
 */
unsigned int ERROR_RAM Led_Count;
unsigned int ERROR_RAM Led_Value;
unsigned int ERROR_RAM Led_Value_Buf;
unsigned int ERROR_RAM Led_Time_Tick;

/*
 * �������ܣ���ѹ���
 * �������룺��
 * �����������
 */
static void ERROR_SECTION VbusVoltageDetect(void) {
    if (tAdc.BusValue < VBUS_LOW_LIMIT) {
        Error_Flag.Bits.LackVol = 1;
        Error_Flag.Bits.OverVol = 0;
    } else if (tAdc.BusValue > VBUS_HIGH_LIMIT) {
        Error_Flag.Bits.LackVol = 0;
        Error_Flag.Bits.OverVol = 1;
    } else {
        Error_Flag.Bits.LackVol = 0;
        Error_Flag.Bits.OverVol = 0;
    }
}

/*�������ܣ����ϴ�������ͣ��
 * �������룺��
 * �����������
 * ���hall�쳣ͬʱ��Ƿѹ���޷�ͬʱ��ʾ�ġ���ʾ���ȼ���hall>overvol>lackvol
 */
static void ERROR_SECTION ErrorProcess(void) {
    if (Error_Flag.Word == 0) {//��ѹ������hallû������
        Led_Value = 0;
    } else {
        if (Motor_Flag.Bits.Status)  //��������������
            Motor_Flag.Bits.ReqOff = 1; //����ͣ��
        if (Error_Flag.Bits.Hall)
            Led_Value = 1;
        else if (Error_Flag.Bits.OverVol)
            Led_Value = 2;
        else if (Error_Flag.Bits.LackVol)
            Led_Value = 3;
        else
            Led_Value = 0;
    }
    Error_Code = Led_Value;
}

/*
 * �������ܣ�����LED��ʾ
 * �������룺��
 * �����������
 */
static void ERROR_SECTION ErrorDisplay(void) {
    unsigned int Flash_Num;
    if (Led_Value != Led_Value_Buf) {
        LED3_PIN = LED_ON;  //����vbus��ѹ�쳣״̬�ص���ѹ����״̬���˵Ƴ�������ʾ������ѹ�쳣 ����λ���ָ�����
        Led_Time_Tick = 0;
        Led_Count = 0;
        Led_Value_Buf = Led_Value;
    }
    if (Led_Count == 0) {
        Led_Count = LED_TICK_TIME;
        if (Led_Value_Buf != 0) {
            Led_Time_Tick++;
            Flash_Num = Led_Time_Tick >> 1;
            if (Led_Value_Buf >= Flash_Num) {
                if ((Led_Time_Tick & 0x0001) == 0x0000)
                    LED3_PIN = LED_ON; //on
                else
                    LED3_PIN = LED_OFF; //off
            } else {
                if (Flash_Num == (Led_Value_Buf + LED_OFF_TIME))
                    Led_Time_Tick = 0;  //��ʼ��һ�ֵ���˸
                LED3_PIN = LED_OFF; //off   ������˸�м��Ϩ��״̬
            }
        }
    }
}

/*�������ܣ�����ģ��
 * �������룺��
 * �����������
 */
void ERROR_SECTION ErrorModule(void) {
    VbusVoltageDetect();
    ErrorProcess();
    ErrorDisplay();
}


