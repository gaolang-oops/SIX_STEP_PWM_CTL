/*==================================================
�ļ������������ʼ���ļ�
ʹ��MCU��dsPIC33EP128MC506
�ļ����ܣ���ʼ����������
���ߣ�����
==================================================*/
#include "HardWare.h"
#include "Sfr_Init.h"

/*=============�˿ڳ�ʼ��====================*/
static void INIT_SECTION McuPortInitialize(void) {

    /*-----------PORTA�Ĵ�����ʼ��----------------------*/
    TRISA = TRISA_INIT;
    PORTA = PORTA_INIT;
    LATA = LATA_INIT;
    ODCA = ODCA_INIT;
    CNENA = CNENA_INIT;
    CNPUA = CNPUA_INIT;
    CNPDA = CNPDA_INIT;
    ANSELA = ANSELA_INIT;
    /*-----------PORTB�Ĵ�����ʼ��----------------------*/
    TRISB = TRISB_INIT;
    PORTB = PORTB_INIT;
    LATB = LATB_INIT;
    ODCB = ODCB_INIT;
    CNENB = CNENB_INIT;
    CNPUB = CNPUB_INIT;
    CNPDB = CNPDB_INIT;
    ANSELB = ANSELB_INIT;
    /*-----------PORTC�Ĵ�����ʼ��----------------------*/
    TRISC = TRISC_INIT;
    PORTC = PORTC_INIT;
    LATC = LATC_INIT;
    ODCC = ODCC_INIT;
    CNENC = CNENC_INIT;
    CNPUC = CNPUC_INIT;
    CNPDC = CNPDC_INIT;
    ANSELC = ANSELC_INIT;
    /*-----------PORTD�Ĵ�����ʼ��----------------------*/
    TRISD = TRISD_INIT;
    PORTD = PORTD_INIT;
    LATD = LATD_INIT;
    ODCD = ODCD_INIT;
    CNEND = CNEND_INIT;
    CNPUD = CNPUD_INIT;
    CNPDD = CNPDD_INIT;
    /*-----------PORTE�Ĵ�����ʼ��----------------------*/
    TRISE = TRISE_INIT;
    PORTE = PORTE_INIT;
    LATE = LATE_INIT;
    ODCE = ODCE_INIT;
    CNENE = CNENE_INIT;
    CNPUE = CNPUE_INIT;
    CNPDE = CNPDE_INIT;
    ANSELE = ANSELE_INIT;

    /*-----------PORTG�Ĵ�����ʼ��----------------------*/
    TRISG = TRISG_INIT;
    PORTG = PORTG_INIT;
    LATG = LATG_INIT;
    ODCG = ODCG_INIT;
    CNENG = CNENG_INIT;
    CNPUG = CNPUG_INIT;
    CNPDG = CNPDG_INIT;
}

/*=============��������ѡ�����ù��ܳ�ʼ��====================*/
static void INIT_SECTION McuPpsInitialize(void) {
    //��������ѡ����������Ĵ�����ʼ��
    //    RPINR0 = RPINR0_INIT;
    //    RPINR1 = RPINR1_INIT;
    //    RPINR3 = RPINR3_INIT;
    RPINR7 = RPINR7_INIT;  //���벶��IC1 IC2����
    RPINR8 = RPINR8_INIT;  //���벶��IC3����
    //    RPINR11 = RPINR11_INIT;
    //    RPINR12 = RPINR12_INIT;
    //    RPINR14 = RPINR14_INIT;
    //    RPINR15 = RPINR15_INIT;
    //    RPINR18 = RPINR18_INIT;
    //    RPINR19 = RPINR19_INIT;
    //    RPINR22 = RPINR22_INIT;
    //    RPINR23 = RPINR23_INIT;
    //    RPINR26 = RPINR26_INIT;
    //    RPINR37 = RPINR37_INIT;
    //    RPINR38 = RPINR38_INIT;
    //    RPINR39 = RPINR39_INIT;
    //��������ѡ����������Ĵ�����ʼ��
    //    RPOR0 = RPOR0_INIT;
    //    RPOR1 = RPOR1_INIT;
    //    RPOR2 = RPOR2_INIT;
    //    RPOR3 = RPOR3_INIT;
    //    RPOR4 = RPOR4_INIT;
    //    RPOR5 = RPOR5_INIT;
    //    RPOR6 = RPOR6_INIT;
    //    RPOR7 = RPOR7_INIT;
    //    RPOR8 = RPOR8_INIT;
    //    RPOR9 = RPOR9_INIT;
}


/*=============MCU�жϳ�ʼ��====================*/
static void INIT_SECTION McuIntInitialize(void) {
    IcIntInitialize(7);//�������벶׽IC1~3�ж����ȼ�λΪ7 �û��ж�����ȼ�7Ϊ���
    AdcIntInitialize(6);
}

/*=============MCU��ʼ��====================*/
void INIT_SECTION McuInitialize(void) {
    McuPortInitialize();
    McuPpsInitialize();
    //McuSpi1Initialize();
    McuTimer3Initialize();
    McuIcInitialize();
    //McuUart2Initialize();
    McuPwmInitialize();
    McuCompInitialize();
    McuAdcInitialize();
    McuIntInitialize();
}





