/*============================================================================*/
//工程描述：方波六步换相控制
//使用MCU：dsPIC33EP128MC506
//文件名：Rotor.c
//文件功能：转子位置获取
//日期：2022年3月25日
/*============================================================================*/
#include "Rotor.h"
#include "Error.h"
#include "Moto.h"
#include "../HARDWARE/Led.h"
tHall_Type ROTOR_RAM tHall;

/*
 * 函数功能：读取霍尔端口值
 * 函数输入：无
 * 函数输出：无
 * ！！！！注意：如果Buf0一直不等于Word的值，程序会进死循环，ADCD中断优先级低于IC中断，无法打断这个死循环，
 * ！！！！导致无法运行状态机！！危险。所以需要j
 * ！！！！j=5,12.8us内会连续读取5*3=18次hall，如果无法采出hall值，会置错误标志，然后break
 */
static void ROTOR_SECTION GetHallValue(void) {
    unsigned char i;
    unsigned char j = 5;
    UNION_WORD Temp;
    do {
        i = 0;
        do {
            Temp.Word = 0; //读取之前清零
            Temp.Bits.B2 = HALLU_Bit;
            Temp.Bits.B1 = HALLV_Bit;
            Temp.Bits.B0 = HALLW_Bit;
            tHall.Hall_Value_Buf[i++] = Temp.Word;
        } while (i < 3);
        if (!(--j)) {
            Error_Flag.Bits.Hall = 1;  //hall干扰过大或者损坏
            break;
        } 
    }while (tHall.Hall_Value_Buf[0] != Temp.Word);


    tHall.Hall_Value_Cur = Temp.Word;
    if (tHall.Hall_Value_Cur != tHall.Hall_Value_Old) {
        tHall.Hall_Value_Old = tHall.Hall_Value_Cur;
        if ((tHall.Hall_Value_Cur > 0) && (tHall.Hall_Value_Cur < 7)) {
            tHall.Hall_Update = 1; //hall数据正确
        } else {//电机旋转时hall数据异常（0或7），记录在Error_Flag.Bits.Hall
            Error_Flag.Bits.Hall = 2;
        }
    }
    //霍尔信号长时间不更新，则要报故障
}

/*
 * 函数功能：获取换相值
 * 函数输入：无
 * 函数输出：无
 * 霍尔值更新，Hall_Update=1，则就会进入这个if分支。
 * 为了下一次更新霍尔，所以需要把Hall_Update清0.
 * Hall_Update_Count变量，是后续为了做保护用的，也就是霍尔信号长时间不更新，则会在状态机运行态中Hall_Update_Count++
 * 如果霍尔信号正常更新，那么Hall_Update_Count变量就会在这里清0.如果Hall_Update=0一直不更新，Hall_Update_Count无法清零则状态机报错
 * 正常更新之后，就把霍尔组合值传递给换相变量，去作为换相信号使用。
 */
static void ROTOR_SECTION GetCommutationValue(void) {
    if (tHall.Hall_Update != 0) {
        tHall.Hall_Update = 0;
        tHall.Hall_Update_Count = 0;
        tMotor.CommutationValue = tHall.Hall_Value_Cur;
    }
}

/*
 * 函数功能：获取转子换相信息
 * 函数输入：无
 * 函数输出：无
 */
void ROTOR_SECTION GetRotorInfo(void) {
    GetHallValue();
    GetCommutationValue();
}
