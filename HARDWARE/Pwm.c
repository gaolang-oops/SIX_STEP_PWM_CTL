#include "Pwm.h"

/*
 * PWMģ���ʼ��
 * һ��ģ������PWM����
 * IOCON1�Ĵ�������PWM1H��PWM1L����??U
 * IOCON3�Ĵ�������PWM3H��PWM3L����??W
 */
void INIT_SECTION McuPwmInitialize(void) {
    PTCONbits.PTEN = 0; //��ֹPWMģ��
    PTCON = PTCON_INIT;
    PTCON2 = PTCON2_INIT;

    // PWM������1�ļĴ�����ʼ��
    PWMCON1 = PWMCON1_INIT;
    __builtin_write_PWMSFR(&IOCON1, IOCON1_INIT, &PWMKEY);
    __builtin_write_PWMSFR(&FCLCON1, FCLCON1_INIT, &PWMKEY);
    PHASE1 = PHASE1_INIT;
    PDC1 = PDC1_INIT;
    DTR1 = DTR1_INIT;
    ALTDTR1 = ALTDTR1_INIT;
    TRGCON1 = TRGCON1_INIT;
    TRIG1 = TRIG1_INIT;

    // PWM������2�ļĴ�����ʼ��
    PWMCON2 = PWMCON2_INIT;
    __builtin_write_PWMSFR(&IOCON2, IOCON2_INIT, &PWMKEY);
    __builtin_write_PWMSFR(&FCLCON2, FCLCON2_INIT, &PWMKEY);
    PHASE2 = PHASE2_INIT;
    PDC2 = PDC2_INIT;
    DTR2 = DTR2_INIT;
    ALTDTR2 = ALTDTR2_INIT;

    // PWM������3�ļĴ�����ʼ��
    PWMCON3 = PWMCON3_INIT;
    __builtin_write_PWMSFR(&IOCON3, IOCON3_INIT, &PWMKEY);
    __builtin_write_PWMSFR(&FCLCON3, FCLCON3_INIT, &PWMKEY);
    PHASE3 = PHASE3_INIT;
    PDC3 = PDC3_INIT;
    DTR3 = DTR3_INIT;
    ALTDTR3 = ALTDTR3_INIT;
    PTCONbits.PTEN = 1; //ʹ��PWMģ��
}

/*ռ�ձ����룺PwmDuty% [0,100] */
void PWM_SECTION PwmDutySet(unsigned int PwmDuty1, unsigned int PwmDuty2, unsigned int PwmDuty3) {
    PwmDuty1 = Limit_Val(PwmDuty1, 10, 90);
    PwmDuty2 = Limit_Val(PwmDuty2, 10, 90);
    PwmDuty3 = Limit_Val(PwmDuty3, 10, 90);
    PDC1 = PWM_PERIOD_VALUE / 100 * PwmDuty1; //PWM_PERIOD_VALUEֵ����һ������ʱ����������
    PDC2 = PWM_PERIOD_VALUE / 100 * PwmDuty2;
    PDC3 = PWM_PERIOD_VALUE / 100 * PwmDuty3;
    
}