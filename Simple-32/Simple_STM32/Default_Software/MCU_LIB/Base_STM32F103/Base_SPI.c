#include "Base_SPI.h"

int SPI_State[3] = {0};

void SPI1_GPIO_Init(int Set)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    if (Set)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
        
        GPIO_InitStructure.GPIO_Pin = SPI1_SCK | SPI1_MOSI;
        #ifndef SPI_Software
        GPIO_InitStructure.GPIO_Mode = SPI_MODE_OUT;        //输出模式（复用）
        #else
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;        //输出模式（推挽）
        #endif
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   //高速
        GPIO_Init(GPIO_SPI1, &GPIO_InitStructure);
        
        GPIO_InitStructure.GPIO_Pin = SPI1_NSS;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //输出模式（输出）
        GPIO_Init(GPIO_SPI1, &GPIO_InitStructure);
        
        GPIO_InitStructure.GPIO_Pin = SPI1_MISO;
        GPIO_InitStructure.GPIO_Mode = SPI_MODE_IN;
        GPIO_Init(GPIO_SPI1, &GPIO_InitStructure);

    }
    else
    {
        GPIO_InitStructure.GPIO_Pin = SPI1_NSS|SPI1_SCK|SPI1_MOSI|SPI1_MISO;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;        //模拟输入
        GPIO_Init(GPIO_SPI1, &GPIO_InitStructure);
    }
}

void SPI2_GPIO_Init(int Set)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    if (Set)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
        
        GPIO_InitStructure.GPIO_Pin = SPI2_SCK | SPI2_MOSI;
        #ifndef SPI_Software
        GPIO_InitStructure.GPIO_Mode = SPI_MODE_OUT;        //输出模式（复用）
        #else
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;        //输出模式（推挽）
        #endif
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   //高速
        GPIO_Init(GPIO_SPI2, &GPIO_InitStructure);
        
        GPIO_InitStructure.GPIO_Pin = SPI2_NSS;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //输出模式（输出）
        GPIO_Init(GPIO_SPI2, &GPIO_InitStructure);
        
        GPIO_InitStructure.GPIO_Pin = SPI2_MISO;
        GPIO_InitStructure.GPIO_Mode = SPI_MODE_IN;
        GPIO_Init(GPIO_SPI2, &GPIO_InitStructure);

    }
    else
    {
        GPIO_InitStructure.GPIO_Pin = SPI2_NSS|SPI2_SCK|SPI2_MOSI|SPI2_MISO;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;        //模拟输入
        GPIO_Init(GPIO_SPI2, &GPIO_InitStructure);
    }
}

void SPI_Start_Init(int Set)
{
#ifdef Exist_SPI
    FunctionalState set = DISABLE;
    if (Set)
        set = ENABLE;
    #if (SPI_X == 1)
        SPI1_GPIO_Init(Set);
    #elif (SPI_X == 2)
        SPI2_GPIO_Init(Set);
    #endif
    
    #ifndef SPI_Software
        #if (SPI_X == 1)
        SPI_InitTypeDef SPI_InitStructure = {0};
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
        
            #ifdef HOST_MODE
            SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
            #else
            SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
            #endif
        SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
        SPI_InitStructure.SPI_DataSize = SPI_Size;
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;          //空闲时SCK高电平
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;        //偶数边沿采样
        SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;   //SPI_NSS_Hard/SPI_NSS_Soft
        SPI_InitStructure.SPI_BaudRatePrescaler = SPI_Speed;  //分频
        SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;  //高位先行
        SPI_InitStructure.SPI_CRCPolynomial = 7;
        SPI_Init(SPI1, &SPI_InitStructure);

//      SPI_SSOutputCmd(SPI1,ENABLE);

        SPI_Cmd(SPI1,set);
        #endif
        #if (SPI_X == 2)
        SPI_InitTypeDef SPI_InitStructure = {0};
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
        
            #ifdef HOST_MODE
            SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
            #else
            SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
            #endif
        SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
        SPI_InitStructure.SPI_DataSize = SPI_Size;
        SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;          //空闲时SCK高电平
        SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;        //偶数边沿采样
        SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;   //SPI_NSS_Hard/SPI_NSS_Soft
        SPI_InitStructure.SPI_BaudRatePrescaler = SPI_Speed;  //分频
        SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;  //高位先行
        SPI_InitStructure.SPI_CRCPolynomial = 7;
        SPI_Init(SPI2, &SPI_InitStructure);

        SPI_Cmd(SPI2,set);
        #endif
    #endif
#endif
}

#ifdef Exist_SPI
static void SPI_Delay (int time)
{
    #if MCU_SYS_Freq >= 72000000 
    volatile int temp;
    for (int i = 0; i < time; ++i)
    {
        temp = 10;            //SET
        while((temp--) > 0);
    }
    #else
    while((time--) > 0);
    #endif
}
#endif

void SPI_CS_Set(char Serial,char State)
{
    switch (Serial)
    {
        case 1:
            if (State) {
                SPI_NSS_L();      //  Low
            }
            else {
                SPI_NSS_H();     //  High
            }
            break;
        case 2:

            break;
        default:
            break;
    }

}



void SPI_Send_DATA(const uint16_t DATA)
{
    /*
     * 写标志位
     * 写数据
     * 等忙位
     */
#ifdef HOST_MODE
    SPI_TypeDef *Temp_SPI;
    #if (SPI_X == 1)
    Temp_SPI = SPI1;
    #elif (SPI_X == 2)
    Temp_SPI = SPI2;
    #endif

    #ifdef SPI_Software
    char temp;
    for (int i = 0; i < 8; i++)
    {
        SPI_SCK_H();           //预备上升沿
        temp = (DATA << i) & 0x80;
        if (temp)
            SPI_MOSI_H();      //数据1
        else
            SPI_MOSI_L();      //数据0
        SPI_SCK_L();           //完成上升沿
    }
    SPI_MOSI_H();
    SPI_SCK_H();
    #else
    while(SPI_I2S_GetFlagStatus(Temp_SPI,SPI_I2S_FLAG_TXE) == RESET); //检查发送是否完成，完成以后再发送数据
    SPI_I2S_SendData(Temp_SPI, DATA);
    while(SPI_I2S_GetFlagStatus(Temp_SPI,SPI_I2S_FLAG_BSY) == RESET); //必要  <????>
    #endif
	
#endif
}


//    调用层      //
void SPI_SET_Addr_SendData(char Serial,uint16_t Addr,uint16_t DATA)
{
// Addr &= 0xBFFF;
    SPI_CS_Set(Serial,ENABLE);      //SPI开始（片选）
    SPI_Delay (1);

    SPI_Send_DATA(Addr);
//    SPI_Delay (1);
    SPI_Send_DATA(DATA);

    SPI_Delay (1);
    SPI_CS_Set(Serial,DISABLE);     //SPI结束
}

uint16_t SPI_SET_Addr_ReadData(char Serial,uint16_t Addr)
{
    /*
     * 等能读
     * 读
     */
    uint16_t temp = 0;
    // Addr &= 0xBFFF;

#ifdef SPI_Software

#else
    SPI_TypeDef *Temp_SPI;
    #if (SPIX == 1)
    Temp_SPI = SPI1;
    #elif (SPIX == 1)
    Temp_SPI = SPI1;
    #endif

    SPI_CS_Set(Serial,ENABLE);      //SPI开始（片选）
    SPI_Delay (1);
    
    SPI_Send_DATA(Addr);

    SPI_I2S_ReceiveData(Temp_SPI);
    SPI_Send_DATA(0);
    while(SPI_I2S_GetFlagStatus(Temp_SPI,SPI_I2S_FLAG_RXNE) == RESET);
    temp = SPI_I2S_ReceiveData(Temp_SPI);

    SPI_Send_DATA(0);
    while(SPI_I2S_GetFlagStatus(Temp_SPI,SPI_I2S_FLAG_RXNE) == RESET);
    temp = SPI_I2S_ReceiveData(Temp_SPI);

    SPI_Delay (1);
    SPI_CS_Set(Serial,DISABLE);     //SPI结束
#endif
    return temp;
}

