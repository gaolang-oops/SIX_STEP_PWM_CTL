/*************************************************************************
;MCU:       dsPIC33EP128MC506
;Date:      2020.03.25
;File:      Spi.c
;Function:  SpiC文件
 ***************************************************************************/
#include "Spi.h"
#include "Adc.h"
/*--------------------------------------------------------------*/
//SPI结构体定义
tSpi_Type SPI_RAM tSpi;
/*-------------------------SPI初始化------------------------*/
void INIT_SECTION McuSpi1Initialize(void)
{
    SPI1STATbits.SPIEN = 0; //禁止SPI1模块(SPI1STAT<15>=0）
    SPI1STAT = SPI1STAT_INIT;
    SPI1CON1 = SPI1CON1_INIT;
    SPI1CON2 = SPI1CON2_INIT;
    SPI1STATbits.SPIEN = 1;
}

/*------------------------------------------------------------------------*/
//Spi设备初始化
void INIT_SECTION Spi_Device_Initialize(void) {
    SPI1BUF = 0x3000;
    tSpi.Index &= 0x0003;
}

/*------------------------------------------------------------------------*/
//Spi数据更新
//AN0-Ia       AN1-Ib          AN2-Ic
//AN3-Vbus     AN4-旋钮电压    AN6-Ibus
static void SPI_SECTION SpiDataUpdate(void) {
//        tSpi.DataOut1A = tAdc.An0.ValueInstant << 2;//ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
//        tSpi.DataOut1B = tAdc.An1.ValueInstant << 2;//ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
//        tSpi.DataOut2A = tAdc.An2.ValueInstant << 2;//ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
//        tSpi.DataOut2B = tAdc.An3.ValueInstant << 2;//ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
    tSpi.DataOut1A = tAdc.An4.ValueInstant << 2; //ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
    tSpi.DataOut1B = tAdc.An6.ValueInstant << 2; //ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
    tSpi.DataOut2A = tAdc.An2.ValueInstant << 2; //ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果
    tSpi.DataOut2B = tAdc.An3.ValueInstant << 2; //ADC配置为10位模式，所以这里送到DAC通道，需要左移两位变为12位结果

    tSpi.ReadyData[0] = tSpi.DataOut1A;
    tSpi.ReadyData[1] = tSpi.DataOut1B;
    tSpi.ReadyData[2] = tSpi.DataOut2A;
    tSpi.ReadyData[3] = tSpi.DataOut2B;
}

/*------------------------------------------------------------------------*/
//SPI数据发送
void SPI_SECTION SpiTransmit(void) {
    unsigned int Temp;
    if (!SPI1STATbits.SPITBF) {
        SpiDataUpdate();
        Temp = tSpi.ReadyData[tSpi.Index];
        Temp &= 0x0fff;
        Temp |= 0x3000;
        switch (tSpi.Index) {
            case 0: //OUT1A
                SPI1_CS2 = 1;
                SPI1_CS1 = 0;
                DELAY100NS();
                break;
            case 1: //OUT1B
                SPI1_CS1 = 1;
                DELAY100NS();
                SPI1_CS1 = 0;
                Temp |= 0x8000;
                break;
            case 2: //OUT2A
                SPI1_CS1 = 1;
                SPI1_CS2 = 0;
                DELAY100NS();
                break;
            case 3: //OUT2B
                SPI1_CS2 = 1;
                DELAY100NS();
                SPI1_CS2 = 0;
                Temp |= 0x8000;
                break;
        }
        SPI1BUF = Temp;
        tSpi.Index++;
        tSpi.Index &= 0x0003;
    }
}
/*------------------------------------------------------------------------*/
