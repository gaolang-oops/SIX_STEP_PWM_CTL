/* 
 * File:   Key.h
 * Author: GaoLa
 *
 * Created on 2022��6��26��, ����7:27
 */

#ifndef KEY_H
#define	KEY_H
#include "../USER/User.h"

//�����궨��
/*
 * PORTx �Ĵ���:
 * ͨ��PORTx�Ĵ�������I/O�����ϵ����ݡ�����������������Ϊ�����ʱ��
 * ��PORTx�Ĵ����Ƕ�ȡI/O�����ϵ�ֵ����ȡ�����ϵĵ�ƽ״̬��
 */
#define KEY1_PIN        PORTCbits.RC1
#define KEY2_PIN        PORTCbits.RC2
#define KEY3_PIN        PORTCbits.RC11

#define KEY_DOWN        0
#define KEY_UP          1

/*----------------------------------------------------------------------------*/
typedef union
{
    unsigned int word;
    struct{
        unsigned Pressed:1;
        unsigned unused :15;
    }BITS;
}UNION_KEY_FLAG;

typedef struct
{
    UNION_KEY_FLAG FLAG;
}tKey_Type;
/*----------------------------------------------------------------------------*/
extern tKey_Type KEY_RAM tKey;
extern void KEY_SECTION KeyScan(void);
#endif	/* KEY_H */

