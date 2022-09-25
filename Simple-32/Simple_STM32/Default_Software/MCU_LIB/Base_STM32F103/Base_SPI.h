#ifndef _BASE_SPI_H__
#define _BASE_SPI_H__

#include "Items.h"

/*
            SCK    ->  
                        /----\
            MISO   ->   |SPI1|    <-    NSS/NSS2/NSS3  (Serial) 
                        \----/
            MOSI   ->
    
    分为硬件SPI/软件SPI
    软件SPI慢，但是它可以指定任意IO口(目前只发不收)。
    尽量使 SPI_GPIO 在同一组GPIO上（A/B/C/D）
    SPI是主动通信（主从），主机的收发逻辑不需要中断，但是从机需要。
																					2022.02.26
    SPI的唯一要求————越快越好，目前软件模拟 461kHz(8bit)，硬件SPI参考-SPI_Speed-定义。

                                                                                    2022.07.26
    SPI的软件模拟方式为size-8bit,硬件SPI可以是size-8bit/size-16bit
    SPI软件方模拟方式为上升沿读(0,0)
    SPI一般只会使用一个（SPI1），但是硬件可能被占用于是选择SPI2（推荐只使用一个SPI）
                                                                                    2022.08.15
    SPI的硬件NSS就是一直拉低。狗都不用。
                                                                                    2022.08.19

*/

// 选择输出模式
//#define SPI_Software	//屏蔽就是硬件模式
//#define SPI_DMA			//屏蔽就是普通模式
#define HOST_MODE
#define SPI_X   2


#ifdef SPI_Software
#define SPI_MODE_IN    GPIO_Mode_IPU
#define SPI_MODE_OUT   GPIO_Mode_Out_PP
#else                                               //硬件SPI
#define SPI_MODE_IN    GPIO_Mode_IPU
#define SPI_MODE_OUT   GPIO_Mode_AF_PP
#define SPI_Speed   SPI_BaudRatePrescaler_8        //16-9MHZ   8-18MHZ     4-36MHZ     2-72MHZ
#define SPI_Size    SPI_DataSize_8b                //8b   16b
#endif

//SPI1
#define SPI1_NSS        GPIO_Pin_4      //(CS)
#define SPI1_SCK        GPIO_Pin_5
#define SPI1_MISO       GPIO_Pin_6
#define SPI1_MOSI       GPIO_Pin_7
#define GPIO_SPI1       GPIOA

//SPI2
#define SPI2_NSS        GPIO_Pin_12      //(CS)
#define SPI2_SCK        GPIO_Pin_13
#define SPI2_MISO       GPIO_Pin_14
#define SPI2_MOSI       GPIO_Pin_15
#define GPIO_SPI2       GPIOB

void SPI_Start_Init(int Set);

//    驱动层      //

void SPI_CS_Set(char Serial,char State);

void SPI_Send_DATA(const uint16_t DATA);

//    调用层      //

void SPI_SET_Addr_SendData(char Serial,uint16_t Addr,uint16_t DATA);
uint16_t SPI_SET_Addr_ReadData(char Serial,uint16_t Addr);




#if (SPI_X == 1)
#define SPI_NSS_H()  GPIO_SPI1->BSRR = SPI1_NSS		//置高电平
#define SPI_NSS_L()  GPIO_SPI1->BRR = SPI1_NSS 		//置低电平
#define SPI_SCK_H()  GPIO_SPI1->BSRR = SPI1_SCK
#define SPI_SCK_L()  GPIO_SPI1->BRR = SPI1_SCK 
#define SPI_MOSI_H() GPIO_SPI1->BSRR = SPI1_MOSI
#define SPI_MOSI_L() GPIO_SPI1->BRR = SPI1_MOSI

#define SPI_MISO_IN() GPIO_SPI1->IDR & SPI1_MISO      //读取引脚电平

#elif (SPI_X == 2)
#define SPI_NSS_H()  GPIO_SPI2->BSRR = SPI2_NSS		//置高电平
#define SPI_NSS_L()  GPIO_SPI2->BRR = SPI2_NSS 		//置低电平
#define SPI_SCK_H()  GPIO_SPI2->BSRR = SPI2_SCK
#define SPI_SCK_L()  GPIO_SPI2->BRR = SPI2_SCK 
#define SPI_MOSI_H() GPIO_SPI2->BSRR = SPI2_MOSI
#define SPI_MOSI_L() GPIO_SPI2->BRR = SPI2_MOSI

#define SPI_MISO_IN() GPIO_SPI2->IDR & SPI2_MISO      //读取引脚电平

#endif



#endif
