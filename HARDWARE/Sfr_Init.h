/* 
 * File:   Sfr_Init.h
 * Author: GaoLa
 *
 * Created on 2022��6��26��, ����6:31
 */
/*==================================================
�ļ����������⹦�ܼĴ���ͷ�ļ�
ʹ��MCU��dsPIC33EP128MC506
�ļ����ܣ��������⹦�ܼĴ�����ʼֵ
==================================================*/

#ifndef SFR_INIT_H
#define	SFR_INIT_H

//�Ĵ�����ʼֵ�궨��
/*---------------PORTA----------------------*/
//F:    RA0-IA(AN0)(I)  RA1-IB(AN1)(I)  RA2(-)      RA3(-)
//E:    RA4-SDO(O)      RA5(-)          RA6(-)      RA7-NC(I) 
//D:    RA8-RX(I)       RA9-CS1(O)      RA10--NC(I) RA11-NC(I) 
//F:    RA12-NC(I)      RA13-15(-)
#define TRISA_INIT      0xFDEF   //TRISx �Ĵ�������λ������I/O �˿���صĸ����������������Ż���������š�
//���ĳ��I/O ���ŵ�TRIS λΪ1������������������š����ĳ��I/O ���ŵ�TRIS λΪ0��������ű�����Ϊ������š�
//��ܺüǣ���Ϊ1 ����I ��Input�����룩�� 0 ����O ��Output�����������λ�����ж˿����ž�����Ϊ���롣
#define PORTA_INIT      0x0000   //ͨ��PORTx�Ĵ�������I/O�����ϵ����ݡ���PORTx�Ĵ����Ƕ�ȡI/O�����ϵ�ֵ��
//��дPORTx�Ĵ����ǽ�ֵд��˿���������������- �޸�- дָ��ʱ����������ܣ���������Ĵ�����ʹ��LAIx
#define LATA_INIT      0x0000 //��I/O ������ص�LATx �Ĵ��������˿�����ִ�ж�- �޸�- дָ��ʱ���������⡣
//��LATx �Ĵ��������ر����ڶ˿�����������е�ֵ��������I/O �����ϵ�ֵ��
//����ĳ��I/O �˿���ص�LAT�Ĵ������ж�- �޸�- д�����������˽���������ֵд��˿��������Ŀ����ԡ�
//дLATx �Ĵ�����дPORTx �Ĵ�����Ч����ͬ��
#define ODCA_INIT      0x0000 //��ʹ�ÿ�©���������Ϊ��
#define CNENA_INIT      0x0000 //CNENx�������ƽ�仯֪ͨ�ж�����Ĵ������������Ӧλ���ó�1��
//�������Ӧ�������ϵ�ƽ�����仯�����Ϳ��Բ����жϡ�
#define CNPUA_INIT      0x0000 //CNPUx�������ƽ�仯֪ͨ����ʹ�ܼĴ���
#define CNPDA_INIT      0x0000 // CNPDx�������ƽ�仯֪ͨ����ʹ�ܼĴ���
#define ANSELA_INIT      0x0003 // ANSELx��ģ��ѡ����ƼĴ������������ʹ��ģ�⹦�ܣ���Ҫ��������Ϊ����IO�ţ�
//�Ͱ���Ӧ��λ���ó�0�Ϳ����ˡ�ע�⣬����˿��Ǵ�ģ��ͨ���Ļ����ϵ縴λ��ʱ�����������Щλ���Ǳ�����Ϊ1�ġ�

/*---------------PORTB----------------------*/
//F:    RB0-Ic(AN2)(I)          RB1-Voltage(AN3)(I)     RB2-ACCELE(AN4)(I)      RB3-NC(I)
//6:    RB4-TX(O)               RB5-PGD(I)              RB6-PGC(I)              RB7-CAN_TX(O) 
//3:    RB8-CVREFIO(ģ��)(I)    RB9-NC(I)               RB10-PWM3H(O)           RB11-PWM3L(O)
//0:    RB12-PWM2H(O)           RB13-PWM2L(O)           RB14-PWM1H(O)           RB15-PWM1L(O)
#define TRISB_INIT      0x036F
#define PORTB_INIT      0x0000
#define LATB_INIT       0x0000
#define ODCB_INIT       0x0000
#define CNENB_INIT      0x0000
#define CNPUB_INIT      0x0000
#define CNPDB_INIT      0x0000
#define ANSELB_INIT     0x0107

/*---------------PORTC----------------------*/
//7:    RC0-IBUS(AN6)(I)    RC1-KEY1(I)     RC2-KEY2(I)         RC3-SPI1_SCK(O)
//3:    RC4-FLT ����(I)     RC5-NC(I)       RC6-SPI2_SDO(O)     RC7-SPI2_CS��չ�ӿ�(O) 
//C:    RC8-SPI2_SCK(O)     RC9-OC1(O)      RC10-CAN_RX(I)      RC11-KEY3(I)
//7:    RC12-OSC1(I)        RC13-NC(I)      RC14(-)             RC15-OSC2(O)
#define TRISC_INIT      0x7C37   //TRISx �Ĵ�������λ������I/O �˿���صĸ����������������Ż���������š�
//���ĳ��I/O ���ŵ�TRIS λΪ1������������������š����ĳ��I/O ���ŵ�TRIS λΪ0��������ű�����Ϊ������š�
//��ܺüǣ���Ϊ1 ����I ��Input�����룩�� 0 ����O ��Output�����������λ�����ж˿����ž�����Ϊ���롣
#define PORTC_INIT      0x0000   //ͨ��PORTx�Ĵ�������I/O�����ϵ����ݡ���PORTx�Ĵ����Ƕ�ȡI/O�����ϵ�ֵ��
//��дPORTx�Ĵ����ǽ�ֵд��˿���������������- �޸�- дָ��ʱ����������ܣ���������Ĵ�����ʹ��LAIx
#define LATC_INIT       0x0000 //��I/O ������ص�LATx �Ĵ��������˿�����ִ�ж�- �޸�- дָ��ʱ���������⡣
//��LATx �Ĵ��������ر����ڶ˿�����������е�ֵ��������I/O �����ϵ�ֵ��
//����ĳ��I/O �˿���ص�LAT�Ĵ������ж�- �޸�- д�����������˽���������ֵд��˿��������Ŀ����ԡ�
//дLATx �Ĵ�����дPORTx �Ĵ�����Ч����ͬ��
#define ODCC_INIT       0x0000 //��ʹ�ÿ�©���������Ϊ��
#define CNENC_INIT      0x0000 //CNENx�������ƽ�仯֪ͨ�ж�����Ĵ������������Ӧλ���ó�1��
//�������Ӧ�������ϵ�ƽ�����仯�����Ϳ��Բ����жϡ�
#define CNPUC_INIT      0x0000 //CNPUx�������ƽ�仯֪ͨ����ʹ�ܼĴ���
#define CNPDC_INIT      0x0000 // CNPDx�������ƽ�仯֪ͨ����ʹ�ܼĴ���
#define ANSELC_INIT     0x0001 // ANSELx��ģ��ѡ����ƼĴ������������ʹ��ģ�⹦�ܣ���Ҫ��������Ϊ����IO�ţ�
//�Ͱ���Ӧ��λ���ó�0�Ϳ����ˡ�ע�⣬����˿��Ǵ�ģ��ͨ���Ļ����ϵ縴λ��ʱ�����������Щλ���Ǳ�����Ϊ1�ġ�

/*---------------PORTD----------------------*/
//F:    RD0-3(-)(I)
//F:    RD4(-)(I)       RD5-NC(I)     RD6-NC(I)     RD7(-)(I)
//E:    RD8-CS2(O)      RD9-11(-)(I)
//F:    RD12-15(-)(I)        
#define TRISD_INIT      0xFEFF
#define PORTD_INIT      0x0000
#define LATD_INIT      0x0000
#define ODCD_INIT      0x0000
#define CNEND_INIT      0x0000
#define CNPUD_INIT      0x0000
#define CNPDD_INIT      0x0000

/*---------------PORTE----------------------*/
//F:    RE0-3(-)
//F:    RE4-7(-)
//F:    RE8-11(-) 
//0:    RE12-LED0(O)    RE13-LED1(O)    RE14-LED2(O)    RE15-LED3(O) ��ΪLEDΪ�������ӷ�������Ϊ1����
#define TRISE_INIT      0x0FFF
#define PORTE_INIT      0xF000
#define LATE_INIT       0xF000
#define ODCE_INIT       0x0000
#define CNENE_INIT      0x0000
#define CNPUE_INIT      0x0000
#define CNPDE_INIT      0x0000
#define ANSELE_INIT     0x0000

/*---------------PORTG----------------------*/
//F:    RG0-3(-)
//F:    RG4-5(-)        RG6-HALL_W(I)       RG7-HALL_V(I) 
//F:    RG8-HALL_U(I)   RG9-NC(I)           RG10-RG11(-)
//F:    RG12-15(-)       
#define TRISG_INIT      0xFFFF
#define PORTG_INIT      0x0000
#define LATG_INIT       0x0000
#define ODCG_INIT       0x0000
#define CNENG_INIT      0x0000
#define CNPUG_INIT      0x0000
#define CNPDG_INIT      0x0000


/*--------------��������ѡ�����üĴ�����ʼֵ�궨��--------------------*/
//����Ĵ���
//����μ���11-2 �˽���������ѡ���ţ�
//HALL_U RP120      HALL_V RP119-IC1   HALL_W RP118
#define RPINR0_INIT      0x0000 //δʹ�� bit 14-8 INT1R<6:0>�����ⲿ�ж�1 ��INT1���������ӦRPn ���ŵ�λ��
#define RPINR1_INIT      0x0000 //δʹ�� bit 6-0 INT2R<6:0>�����ⲿ�ж�2 ��INT2���������ӦRPn ���ŵ�λ
#define RPINR3_INIT      0x0000 //δʹ�� bit 6-0 T2CKR<6:0>����Timer2 �ⲿʱ�ӣ�T2CK���������ӦRPn ���ŵ�λ
#define RPINR7_INIT      0x7778 //ʹ��   bit 14-8 IC2R<6 :0>�������벶׽2 ��IC2���������ӦRPI119���ŵ�λ 111 0111
//bit 6-0 IC1R<6:0>�������벶׽1 ��IC1���������ӦRP120���ŵ�λ 111 1000
#define RPINR8_INIT      0x0076 //ʹ��   bit 14-8 IC4R<6:0>�������벶׽4 ��IC4���������ӦRPn ���ŵ�λ
//bit 6-0 IC3R<6:0>�������벶׽3 ��IC3���������ӦRP118���ŵ�λ 111 0110
#define RPINR11_INIT     0x0000 //δʹ�� bit 6-0 OCFAR<6:0>��������ȽϹ���A ��OCFA���������ӦRPn ���ŵ�λ
#define RPINR12_INIT     0x0000 //δʹ�� bit 14-8 FLT2R<6:0>����PWM ����2 ��FLT2���������ӦRPn ���ŵ�λ

#define RPINR14_INIT     0x0000 //δʹ�� bit 14-8 QEB1R<6:0>����B �����루QEB���������ӦRPn ���ŵ�λ

#define RPINR15_INIT     0x0000 //δʹ�� bit 14-8 HOME1R<6:0>����QEI1 HOME1 ��HOME1���������ӦRPn ���ŵ�λ

#define RPINR18_INIT     0x0000 //δʹ�� bit 6-0 U1RXR<6:0>����UART1 ���գ�U1RX���������ӦRPn ���ŵ�λ
#define RPINR19_INIT     0x0018 //ʹ��   bit 6-0 U2RXR<6:0>����UART2 ���գ�U2RX���������ӦRPI24 ���ŵ�λ 001 1000
#define RPINR22_INIT     0x0000 //δʹ�� bit 14-8 SCK2INR<6:0>: ��SPI2 ʱ�����루SCK2���������ӦRPn ���ŵ�λ

#define RPINR23_INIT     0x0000 //δʹ�� bit 6-0 SS2R<6:0>: ��SPI2 ��ѡ��SS2���������ӦRPn ���ŵ�λ
#define RPINR26_INIT     0x0000 //δʹ�� bit 6-0 C1RXR<6:0>����CAN1 �������루CRX1���������ӦRPn ���ŵ�λ
#define RPINR37_INIT     0x0000 //δʹ�� bit 14-8 SYNCI1R<6:0>����PWM ͬ������1 �������ӦRPn ���ŵ�λ
#define RPINR38_INIT     0x0000 //δʹ�� bit 14-8 DTCMP1R<6:0>����PWM ������������1 �������ӦRPn ���ŵ�λ
#define RPINR39_INIT     0x0000 //δʹ�� bit 14-8 DTCMP3R<6:0>����PWM ������������3 �������ӦRPn ���ŵ�λ
//bit 6-0 DTCMP2R<6:0>����PWM ������������2 �������ӦRPn ���ŵ�λ

//����Ĵ���
#define RPOR0_INIT       0x0000 //δʹ�� bit 13-8 RP35R<5:0>��������������ܷ����RP35 ������ŵ�λ

#define RPOR1_INIT       0x0003 //ʹ�� bit 13-8 RP37R<5:0>��������������ܷ����RP37 ������ŵ�λ
//bit 5-0 RP36R<5:0>���������������U2TX�����RP36 ������ŵ�λ 
#define RPOR2_INIT       0x0000 //δʹ�� bit 13-8 RP39R<5:0>��������������ܷ����RP39 ������ŵ�λ

#define RPOR3_INIT       0x0000 //δʹ�� bit 13-8 RP41R<5:0>��������������ܷ����RP41 ������ŵ�λ

#define RPOR4_INIT       0x0000 //δʹ�� bit 13-8 RP43R<5:0>��������������ܷ����RP43 ������ŵ�λ

#define RPOR5_INIT       0x0000 //δʹ�� bit 13-8 RP55R<5:0>��������������ܷ����RP55 ������ŵ�λ

#define RPOR6_INIT       0x0000 //δʹ�� bit 13-8 RP57R<5:0>��������������ܷ����RP57 ������ŵ�λ

#define RPOR7_INIT       0x0000 //δʹ�� bit 13-8 RP97R<5:0>��������������ܷ����RP97 ������ŵ�λ

#define RPOR8_INIT       0x0000 //δʹ�� bit 13-8 RP118R<5:0>��������������ܷ����RP118 ������ŵ�λ

#define RPOR9_INIT       0x0000 //δʹ�� bit 5-0 RP120R<5:0>��������������ܷ����RP120 ������ŵ�λ


#endif	/* SFR_INIT_H */
