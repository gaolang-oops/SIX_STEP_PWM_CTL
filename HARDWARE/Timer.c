#include "Timer.h"

/*=============MCU_Timer3��ʼ��====================*/
void INIT_SECTION McuTimer3Initialize(void) {
    T3CONbits.TON = 0; //�رն�ʱ��3
    T3CON = T3CON_INIT; //T3CON�Ĵ�������
    TMR3 = TMR3_INIT; //�趨��ʱ��3��ʼ����ֵΪ��
    PR3 = PR3_INIT; //�趨��ʱ��3���ڼĴ�����ʼֵ��1ms�ж�һ��
    T3CONbits.TON = 1; //�򿪶�ʱ��3
}
