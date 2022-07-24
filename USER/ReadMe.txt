//
void SYS_SECTION CloseAllMos(void) {
    __builtin_write_PWMSFR(&IOCON1, IOCON_HL_INVALID, &PWMKEY);
    __builtin_write_PWMSFR(&IOCON2, IOCON_HL_INVALID, &PWMKEY);
    __builtin_write_PWMSFR(&IOCON3, IOCON_HL_INVALID, &PWMKEY);
    Delay(); //�������Delay()���Ļ���bug����Ӱ��ADC�жϵ�ʱ����ʱ�����ĺܴ�ԭ��δ֪���²�������ڽ��������治�ܽ���д���
}

hall���⣺(��error.c��������ͣ����
Error_Flag.Bits.Hall = 1;//hall���Ź�������𻵣���Ҫͣ��  
Error_Flag.Bits.Hall = 2;//�����תʱhall�����쳣��0��7������Ҫͣ��  
Error_Flag.Bits.Hall = 3;//���תʱhall����û�и��£�hall���ϻ��ת����Ҫͣ��          

vbusˢ������ 3.2ms������������ ʲôʱ��ȥ��ȡ ����С��64��ʱavengeΪ�� 

#ifndef DEFINE_H
#define DEFINE_H
#include "../SOC/p33EP128MC506.h"

#define UART_SECTION     __attribute__((section(".uart_section")))

#define UART_RAM    __attribute__((section(".uart_ram")))
#define tUART_RAM    __attribute__((section(".t_uart_ram")))

//Uart�ṹ�嶨��

typedef struct {
    unsigned TxStart : 1; //�ñ�־λ����1��ʾ��Ҫ��ʼ����һ������
    unsigned SendReq : 1; //���ݷ������󡣸ñ�־λ����1��ʾ������׼���ã���Ҫ���͡�����0��ʾ��Ҫ׼���µ�����
    unsigned ReceReq : 1; //�����������󡣸ñ�־λ����1��ʾ�����ݽ����˻�û�д�������0��ʾ���У�û�������ڴ���
    unsigned RxStart : 1; //��ʼ����һ�����ݵı�־λ���ñ�־λ����1��ʾ��������Ҫ���ա�����0��ʾ����
    unsigned Unusual : 1; //�쳣��־����λ��1Ϊ֡β�쳣���߽��յ�������Ч
} STRUCT_UART_FLAG;

typedef struct {
    STRUCT_UART_FLAG Flag;
    unsigned int TxNum; //�跢�͵�һ�����ݰ�����������ۼ�ֵ 
    unsigned int TxNo; //��Ҫ���͵����ݵİ�������
    unsigned int TxData; //��Ҫ���͵�����
    unsigned int TxSum; //��ŷ������ݵ����ֵ
    unsigned int RxSum; //��ŷ������ݵ����ֵ
    unsigned int RxNum; //���յ���һ�����ݰ�����������ۼ�ֵ
    unsigned int RDBUFF[3]; //�������ڴ�Ž��յ�������
} tUart_type;

#endif

#if 0
/*=============UART2����ģ���ʼ��====================*/
static void INIT_SECTION McuUart2Initialize(void) {
    U2BRG = U2BRG_INIT;
    U2MODE = U2MODE_INIT;
    U2STA = U2STA_INIT;
}
#endif


/*--------------UART2����ģ����ƼĴ�����ʼֵ�궨��--------------------*/
//U2BRG =(Fcy/(16*������))-1=(60 000 000/(16*19200))-1=194.3125
//U2MODE 8λ���� ����żУ�� 1ֹͣλ
#define U2BRG_INIT      194
#define U2MODE_INIT     0x8000
#define U2STA_INIT      0x0400

