/* 
 * File:   Spi.h
 * Author: GaoLa
 *
 * Created on 2022��7��1��, ����10:22
 */

#ifndef SPI_H
#define	SPI_H
#include "../USER/User.h"
/*---------------------SPI1��ʼֵ�궨��-------------------------------*/
#define SPI1STAT_INIT   0x0000
#define SPI1CON1_INIT   0x047e
#define SPI1CON2_INIT   0x0000
/*---------------------------------------------------------------------------*/
//SPI�궨��
#define     SPI1_CS1    LATAbits.LATA9
#define     SPI1_CS2    LATDbits.LATD8

/*---------------------------------------------------------------------------*/
//SPI�ṹ�嶨��
typedef struct
{
    unsigned int Index;
    unsigned int ReadyData[4];
    unsigned int DataOut1A;
    unsigned int DataOut1B;
    unsigned int DataOut2A;
    unsigned int DataOut2B;
}tSpi_Type;

extern tSpi_Type SPI_RAM tSpi;
extern void INIT_SECTION McuSpi1Initialize(void);
extern void INIT_SECTION Spi_Device_Initialize(void);
extern void SPI_SECTION SpiTransmit(void);
#endif	/* SPI_H */

