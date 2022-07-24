/*============================================================================
�ļ�������MCU�����ļ�
ʹ��MCU��dsPIC33EP128MC506
�ļ�����Config.c
�ļ����ܣ�����MCU����λ HS+PLL  ʱ�Ӿ����Ƶ��ʽ�������ļ�������
���ߣ�����
============================================================================*/

/*============================================================================*/
//����λ����
/*============================================================================*/
// FGS
//�������ʱ��ͨ�öβ����д��뱣����д����
#pragma config GWRP = OFF            
#pragma config GCP = OFF   
//������ͨ�öν��д��뱣����д����
//#pragma config GWRP = ON                // General Segment Write-Protect bit (General Segment is write protected)
//#pragma config GCP = ON                 // General Segment Code-Protect bit (General Segment Code protection Enabled)

// FOSCSEL
//ѡ���PLLģ�����������PWM������˫��������ʹ��
#pragma config FNOSC = PRIPLL           // Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL)
#pragma config PWMLOCK = ON             // Certain PWM registers may only be written after key sequence
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)

// FOSC
//ѡ�����HS����ģʽ
#pragma config POSCMD = HS               // HS Crystal Oscillator Mode
//OSC2 ���Ź���λ ��XT �� HS ģʽ���⣬���߱����ܣ�����ʹ�õ����ⲿ��Դ����OSC2����Ҫ��Ϊ���������ź�����     
#pragma config OSCIOFNC = OFF            // OSC2 is clock output
//����ѡ��Ĵ�������������       
#pragma config IOL1WAY = OFF            // Peripheral pin select configuration (Allow multiple reconfigurations)
//ʱ���л���ʱ�Ӽ��ӱ���ֹ
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)

// FWDT �رտ��Ź�
//���Ź����ƵΪ32768��Ƶ
#pragma config WDTPOST = PS32768          // Watchdog Timer Postscaler bits (1:32768)
//���Ź���ʱ����ƵΪ128��Ƶ
#pragma config WDTPRE = PR128            // Watchdog Timer Prescaler bit (1:128)
//����PLL����ʹ�ܡ�û��ʱ���л��Ļ����������������Ҳ��Ч���������������������Ժ���ʱ���л���
#pragma config PLLKEN = ON              // PLL Lock Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
//���Ź���ʱ���Ĵ���ģʽʧ��
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
//���Ź���ʱ����ֹ
#pragma config FWDTEN = OFF              // Watchdog Timer Enable bit (Watchdog timer always disabled)

// FPOR
//I2C����ӳ�䵽SDA1/SCL1 SDA2/SCL2
#pragma config ALTI2C1 = OFF            // Alternate I2C1 pins (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = OFF            // Alternate I2C2 pins (I2C2 mapped to SDA2/SCL2 pins)
//���Ź�����Ϊ���Ź���ʱ�����ڵ�25%����Ϊ����û��ʹ�ÿ��Ź���������Ȼѡ����25%�����ǿ��Ź���ֹ�ˣ���������Ҳ����Ч�ġ�
#pragma config WDTWIN = WIN25           // Watchdog Window Select bits (WDT Window is 25% of WDT period)

// FICD
//ͨ��PGEC2��PGED2����ͨѶ
#pragma config ICS = PGD2               // ICD Communication Channel Select bits (Communicate on PGEC2 and PGED2)
//JTAGʧ��
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

/*======================================================*/
