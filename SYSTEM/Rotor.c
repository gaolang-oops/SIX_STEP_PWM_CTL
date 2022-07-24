/*============================================================================*/
//�������������������������
//ʹ��MCU��dsPIC33EP128MC506
//�ļ�����Rotor.c
//�ļ����ܣ�ת��λ�û�ȡ
//���ڣ�2022��3��25��
/*============================================================================*/
#include "Rotor.h"
#include "Error.h"
#include "Moto.h"
#include "../HARDWARE/Led.h"
tHall_Type ROTOR_RAM tHall;

/*
 * �������ܣ���ȡ�����˿�ֵ
 * �������룺��
 * �����������
 * ��������ע�⣺���Buf0һֱ������Word��ֵ����������ѭ����ADCD�ж����ȼ�����IC�жϣ��޷���������ѭ����
 * �������������޷�����״̬������Σ�ա�������Ҫj
 * ��������j=5,12.8us�ڻ�������ȡ5*3=18��hall������޷��ɳ�hallֵ�����ô����־��Ȼ��break
 */
static void ROTOR_SECTION GetHallValue(void) {
    unsigned char i;
    unsigned char j = 5;
    UNION_WORD Temp;
    do {
        i = 0;
        do {
            Temp.Word = 0; //��ȡ֮ǰ����
            Temp.Bits.B2 = HALLU_Bit;
            Temp.Bits.B1 = HALLV_Bit;
            Temp.Bits.B0 = HALLW_Bit;
            tHall.Hall_Value_Buf[i++] = Temp.Word;
        } while (i < 3);
        if (!(--j)) {
            Error_Flag.Bits.Hall = 1;  //hall���Ź��������
            break;
        } 
    }while (tHall.Hall_Value_Buf[0] != Temp.Word);


    tHall.Hall_Value_Cur = Temp.Word;
    if (tHall.Hall_Value_Cur != tHall.Hall_Value_Old) {
        tHall.Hall_Value_Old = tHall.Hall_Value_Cur;
        if ((tHall.Hall_Value_Cur > 0) && (tHall.Hall_Value_Cur < 7)) {
            tHall.Hall_Update = 1; //hall������ȷ
        } else {//�����תʱhall�����쳣��0��7������¼��Error_Flag.Bits.Hall
            Error_Flag.Bits.Hall = 2;
        }
    }
    //�����źų�ʱ�䲻���£���Ҫ������
}

/*
 * �������ܣ���ȡ����ֵ
 * �������룺��
 * �����������
 * ����ֵ���£�Hall_Update=1����ͻ�������if��֧��
 * Ϊ����һ�θ��»�����������Ҫ��Hall_Update��0.
 * Hall_Update_Count�������Ǻ���Ϊ���������õģ�Ҳ���ǻ����źų�ʱ�䲻���£������״̬������̬��Hall_Update_Count++
 * ��������ź��������£���ôHall_Update_Count�����ͻ���������0.���Hall_Update=0һֱ�����£�Hall_Update_Count�޷�������״̬������
 * ��������֮�󣬾Ͱѻ������ֵ���ݸ����������ȥ��Ϊ�����ź�ʹ�á�
 */
static void ROTOR_SECTION GetCommutationValue(void) {
    if (tHall.Hall_Update != 0) {
        tHall.Hall_Update = 0;
        tHall.Hall_Update_Count = 0;
        tMotor.CommutationValue = tHall.Hall_Value_Cur;
    }
}

/*
 * �������ܣ���ȡת�ӻ�����Ϣ
 * �������룺��
 * �����������
 */
void ROTOR_SECTION GetRotorInfo(void) {
    GetHallValue();
    GetCommutationValue();
}
