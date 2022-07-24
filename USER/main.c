#include "User.h"
#include "../HARDWARE/HardWare.h"
#include "../SYSTEM/Kernel.h"
#include "../SYSTEM/Error.h"
#include "../SYSTEM/Moto.h"

/*=============Ӧ�ò��ʼ��====================*/
static void INIT_SECTION AppInitialize(void) {
    MotorInitialize(CCW); 
}

int MAIN_SECTION StartProgram() {
    DISIE();
    McuInitialize();
    LED1_PIN=LED_ON;//MCU��ʼ������
    AppInitialize();
    tSysTick.TickStartup = 1000; //�ϵ��ʼ����ɺ���ʱ1000ms�ȴ�Ӳ���ȶ�
    ENIE();
    while (tSysTick.TickStartup);//��1s����Ҫ�ȴ�Vbus��ѹ����ť��ѹ�ȶ�
    //�����������IC�жϲ��ᷢ����ADC�ж�һֱ����������״̬���������У�
    LED1_PIN=LED_OFF;//��ʱ����
    while (1) {
        AdcModule(); //��ʱ��ȡVbus��ѹ����ť��ѹ
        MotorModule();//��ʱ����Ƿ����������ֹͣ���+50ms��ʱ������ת�����ռ�ձ�
        ErrorModule();//��ʱ����Ƿ����쳣 ��ʱ��˸����ָʾ��
    }
    return 0;
}





