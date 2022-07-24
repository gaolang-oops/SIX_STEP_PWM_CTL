/*==================================================
�ļ�������Key�ļ�
ʹ��MCU��dsPIC33EP128MC506
�ļ�����Key.c
�ļ����ܣ�Key����
���ߣ�����
==================================================*/
#include "Key.h"
/*------------------------------------------------------------------------*/
extern void Delay(void); //�����ʱ���� λ��systemĿ¼��

tKey_Type KEY_RAM tKey;

void KEY_SECTION KeyScan(void) {
    static unsigned char key_down_flag = 0;
    if (KEY1_PIN == KEY_DOWN) {
        Delay();
        if (KEY1_PIN == KEY_DOWN)
            key_down_flag = 1;
    } else {
        if (key_down_flag == 1) { //֮ǰ����key1�������ɿ�Ϊһ�Ρ���¼��Pressed
            key_down_flag = 0;
            tKey.FLAG.BITS.Pressed = 1;
        }
    }
}
/*------------------------------------------------------------------------*/ 