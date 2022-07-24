/*============================================================================*/
//�������������������������
//ʹ��MCU��dsPIC33EP128MC506
//�ļ�����Adc.c
//�ļ����ܣ�ģ��ת��ģ�����ݶ�ȡ���䴦��
//���ڣ�2022��3��25��
/*============================================================================*/

//ͷ�ļ�����
#include "Adc.h"
#include "Led.h"
#include "../SYSTEM/Kernel.h"

tAdc_Type ADC_RAM tAdc;

/*
 * 1.65V�ο���ѹ������� - �Ĵ�����ʼ��
 * 1.65V�ο���ѹ��Ҫ�����ǹ���оƬ�ڲ��Ƚ���ʹ��
 * 1.65V�ο���ѹ���������Ϊ�������û���Ҫ�������������������RB8
 */
void INIT_SECTION McuCompInitialize(void) {
    CVRCON = CVRCON_INIT;
}

/*
 * ADCģ�� - �Ĵ�����ʼ��
 */
void INIT_SECTION McuAdcInitialize(void) {
    AD1CON1bits.ADON = 0; //��ֹADCģ��
    AD1CON1 = AD1CON1_INIT;
    AD1CON2 = AD1CON2_INIT;
    AD1CON3 = AD1CON3_INIT;
    AD1CON4 = AD1CON4_INIT;
    AD1CHS123 = AD1CHS123_INIT;
    AD1CHS0 = AD1CHS0_INIT;
    AD1CSSH = AD1CSSH_INIT;
    AD1CSSL = AD1CSSL_INIT;
    AD1CON1bits.ADON = 1; //ʹ��ADCģ��
}

/*
 * ADCת�������жϳ�ʼ��
 */
void INIT_SECTION AdcIntInitialize(unsigned int IPC) {
    //���ADCת�������жϱ�־λ
    IFS0bits.AD1IF = 0;
    //����ADCת�������ж����ȼ�λΪ6 �û��ж�����ȼ�7Ϊ���
    IPC3bits.AD1IP = IPC;
    //ʹ��ADCת�������ж�����λ
    IEC0bits.AD1IE = 1;
}

/*
 * �������ܣ�Vbusת�������˲�
 * �������룺��
 * �����������
 */
static void ADC_SECTION Vbus_Value_Filter(void) {
    //Vbus��ѹ 64��ƽ���˲�����
    tAdc.An3.ValueSum += tAdc.An3.ValueInstant;
    tAdc.An3.ValueNum++;
    if (tAdc.An3.ValueNum >= ANU_SAMPLE_NUM) {
        tAdc.An3.ValueAverage = tAdc.An3.ValueSum >> 6;
        tAdc.An3.ValueSum = 0;
        tAdc.An3.ValueNum = 0;
    }
}

/*
 * �������ܣ���ť��ѹת�������˲�
 * �������룺�޺����������
 */
static void ADC_SECTION Pot_Volt_Filter(void) {
    //��ť��ѹ 8��ƽ���˲�����            
    tAdc.An4.ValueSum += tAdc.An4.ValueInstant;
    tAdc.An4.ValueNum++;
    if (tAdc.An4.ValueNum >= ANP_SAMPLE_NUM) {
        tAdc.An4.ValueAverage = tAdc.An4.ValueSum >> 3;
        tAdc.An4.ValueSum = 0;
        tAdc.An4.ValueNum = 0;
    }
}

/*
 * �������ܣ�ת�����ݶ�ȡ
 * �������룺��
 * �����������
 */
static void ADC_SECTION GetAdcValue(void) {
    switch (tAdc.Index) {
        case(3):
            tAdc.An3.ValueInstant = ADC1BUF0;
            tAdc.An0.ValueInstant = ADC1BUF1;
            tAdc.An1.ValueInstant = ADC1BUF2;
            tAdc.An2.ValueInstant = ADC1BUF3;
            Vbus_Value_Filter();
            AD1CHS0 = 0x0404;
            tAdc.Index = 4;
            break;

        case(4):
            tAdc.An4.ValueInstant = ADC1BUF0;
            tAdc.An0.ValueInstant = ADC1BUF1;
            tAdc.An1.ValueInstant = ADC1BUF2;
            tAdc.An2.ValueInstant = ADC1BUF3;
            Pot_Volt_Filter();
            AD1CHS0 = 0x0606;
            tAdc.Index = 6;
            break;

        case(6):
            tAdc.An6.ValueInstant = ADC1BUF0;
            tAdc.An0.ValueInstant = ADC1BUF1;
            tAdc.An1.ValueInstant = ADC1BUF2;
            tAdc.An2.ValueInstant = ADC1BUF3;
            AD1CHS0 = 0x0303;
            tAdc.Index = 3;
            break;

        default:
            tAdc.An3.ValueInstant = ADC1BUF0;
            tAdc.An0.ValueInstant = ADC1BUF1;
            tAdc.An1.ValueInstant = ADC1BUF2;
            tAdc.An2.ValueInstant = ADC1BUF3;
            AD1CHS0 = 0x0404;
            tAdc.Index = 4;
    }
}

/*
 * �������ܣ�Vbus��ѹˢ��
 * ÿ3.2ms����ˢ�³��µ�Vbus��ѹֵ
 * VBUS=3.3/1023*tAdc.An3.ValueAverage/2k*32k=tAdc.An3.ValueAverage*53/1023
 * tAdc.An3.ValueAverage*53 >> 10
 */
static void ADC_SECTION VbusVolt_Refresh(void) {
    UNION_U32 unTemp32;
    unTemp32.U32 = __builtin_muluu(VBUS_FACTOR, tAdc.An3.ValueAverage);
    unTemp32.U32 >>= 10;
    tAdc.BusValue = unTemp32.Words.Low;
}

/*
 * �������ܣ�������ť�������
 * �������룺��
 * �����������
 */
static void ADC_SECTION AdcPotProcess(void) {
    unsigned int Temp;
    UNION_U32 Temp32;
    //����ѹֵ3.3v��Ӧ10λ����Ϊ0x3FF�� << 6��һ����Ϊ65472����ӦС��0.999
    Temp = tAdc.An4.ValueAverage << 6; //�ȹ�һ��Ϊ�޷�������  
    //��һ�����ת����ռ�ձ�ֵ 65472*6000 Ȼ������16λ����5994
    Temp32.U32 = __builtin_muluu(Temp, (PWM_PERIOD_VALUE));
    Temp = Temp32.Words.High;
    if (Temp < MINDUTY)
        tAdc.PotValue = 0;
    else
        tAdc.PotValue = Limit_Max(Temp, MAXDUTY);
}

/*
 * �������ܣ�ADCģ�鴦��
 * �������룺��
 * �����������
 */
void ADC_SECTION AdcModule(void) {
    AdcPotProcess();
    VbusVolt_Refresh();
}

/*
 * �������ܣ�ADת������жϷ����� 
 * 20KHz��pwm��ÿ50us����ADCģ��ת������
 * �������룺��
 * �����������
 * ���Ե��ж��ں���ִ��ʱ��3us
 * ADC�ж�ʹ����shadow���ԣ������ж��޷�ʹ��shadow��
 */
void __attribute__((section(".adc_section"), interrupt, shadow, no_auto_psv)) _AD1Interrupt(void) {
    //LED1_PIN = LED_ON;
    IFS0bits.AD1IF = 0; //���ADCת����ɱ�־λ
    GetAdcValue(); //��ȡADCת�����+vbus����ť��ѹ�˲�
    KernelRunStateMachine(); //״̬���������50us�жϽ��м��
    Sys_CntUp_Timer(); //������
    //LED1_PIN = LED_OFF; //ͨ������led0�����Ÿߵ�ƽ����ʱ�䡣������֤�ж�ִ��ʱ��Ͷ�ý����ж�
}



