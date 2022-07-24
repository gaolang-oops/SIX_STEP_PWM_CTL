/*============================================================================*/
//�������������������������
//ʹ��MCU��dsPIC33EP128MC506
//�ļ�����Motor.c
//�ļ����ܣ�������п���
//���ڣ�2022��3��25��
/*============================================================================*/
#include "Moto.h"
#include "Error.h"
#include "../HARDWARE/Key.h"
#include "../HARDWARE/Adc.h"
#include "Kernel.h"

UNION_MOTORFLAGS MOTO_RAM Motor_Flag;
tMotor_Type MOTO_RAM tMotor;

/*
 * �������ܣ����ģ���ʼ��
 * �������룺��
 * �����������
 * ���õ����ת���� 
 * ����״̬��Ϊֹ̬ͣ ȷ��ADC�жϲ�������״̬��
 * ���õ����־Ϊͣ ȷ�������󽫵��š��Ҳ���ᴥ������
 */
void MOTO_SECTION MotorInitialize(unsigned char direction) {
    Motor_Flag.Bits.Direction = direction;
    tKernel.State = KERNEL_STATE_STOP;
    Motor_Flag.Bits.Status = 0;
}

/*
 * �������ܣ������ͣ����
 * �������룺��
 * �����������
 */
static void MOTO_SECTION MotorRunStopControl(void) {
    if (Motor_Flag.Bits.Status == 0) {
        //���쳣����ռ�ձȣ����������� ����������������
        if ((Error_Flag.Word == 0) && (tAdc.PotValue > 0) && (tKey.FLAG.BITS.Pressed == 1)) {
            Motor_Flag.Bits.Status = 1; //IC�жϿ��Դ�������
            tSysTick.TickPwmSet = 50; //ÿ50MSһ�θ��µ��ռ�ձ�
            tKey.FLAG.BITS.Pressed = 0;
            KernelStartUp();
        }
    } else if ((Motor_Flag.Bits.ReqOff == 1) || (tAdc.PotValue == 0)) {
        Motor_Flag.Bits.Status = 0; //Status��Ϊ0��˵���������ֹͣ״̬
        Motor_Flag.Bits.ReqOff = 0; //���㣬Ϊ������������ͣ����׼����
        KernelStop(); //״̬����״̬�޸�Ϊֹͣ״̬
    }
}

/*
 * �������ܣ�ռ�ձȵ��ڿ���
 * �������룺��
 * �����������
 * ��stop״̬ʱtMotor.PwmValue = MINDUTY; ռ�ձ��Ѿ�������Сֵ����ֵ��init״̬д��PDC
 * ����PwmDutyControl�����������ڵ��run״̬ÿ50ms����ռ�ձ�
 */
void MOTO_SECTION PwmDutyControl(void) {
    unsigned int Temp;
    DISIE();
    Temp = tSysTick.TickPwmSet;
    ENIE();
    if ((tKernel.State == KERNEL_STATE_RUN)&&(Temp == 0)) {
        DISIE();
        tSysTick.TickPwmSet = 50;
        ENIE();
        if (tAdc.PotValue >= tMotor.PwmValue) {
            Temp = tAdc.PotValue - tMotor.PwmValue;
            if (Temp > 100) {
                tMotor.PwmValue += 100;
            } else if (Temp > 10) {
                tMotor.PwmValue += 10;
            } else {
                tMotor.PwmValue = tAdc.PotValue;
            }
        } else {
            Temp = tMotor.PwmValue - tAdc.PotValue;
            if (Temp > 100) {
                tMotor.PwmValue -= 100;
            } else if (Temp > 10) {
                tMotor.PwmValue -= 10;
            } else {
                tMotor.PwmValue = tAdc.PotValue;
            }
        }
    }
}

/*
 * �������ܣ��������ģ��
 * �������룺��
 * �����������
 */
void MOTO_SECTION MotorModule(void) {
    KeyScan(); //����Ƿ���������
    MotorRunStopControl();
    PwmDutyControl();
}

/*
 * �������ܣ��������
 * ����IC�ж��е�hallֵ����
 * ������ť��ѹֵ����ռ�ձ�
 * �������룺��
 * �����������
 * ע��ȡ��
 */
void MOTO_SECTION CommutationControl(void) {
    PDC1 = tMotor.PwmValue;
    PDC2 = tMotor.PwmValue;
    PDC3 = tMotor.PwmValue;
    if (!Motor_Flag.Bits.Direction) {
        switch (tMotor.CommutationValue) {
            case 5://U V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 4://U W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 6://V W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 2://V U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 3://W U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            case 1://W V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            default:
                CloseAllMos();
                break;
        }
    } else {
        switch (tMotor.CommutationValue) {
            case 2://U V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 3://U W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 1://V W
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HINVALID_LHIGH, &PWMKEY);
                break;
            case 5://V U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HPWM_LINVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
                break;
            case 4://W U
                __builtin_write_PWMSFR(&IOCON1, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            case 6://W V
                __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON2, IOCON_HINVALID_LHIGH, &PWMKEY);
                __builtin_write_PWMSFR(&IOCON3, IOCON_HPWM_LINVALID, &PWMKEY);
                break;
            default:
                CloseAllMos();
                break;
        }
    }
}




