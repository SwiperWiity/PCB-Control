#include "Base_Exist_GPIO.h"

void LCD_GPIO_Init(int Set)
{
#ifdef Exist_LCD
    GPIO_InitTypeDef  GPIO_InitStructure;
    if (Set)
    {
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);		//将PA15作为普通IO,并且保留SWD
		
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);       //时钟

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_15;            //LCD_DC / LCD_RES
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;        //推挽输出
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //速度50MHz
        GPIO_Init(GPIOA, &GPIO_InitStructure);    //初始化GPIOA
    }
    else
    {
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
}

void LED_GPIO_Init(int Set)
{
#ifdef Exist_LED
    GPIO_InitTypeDef GPIO_InitStructure;
    if (Set) 
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);       //时钟
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
    else                                                    //标志取消GPIO
    {
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
}

void BZZ_GPIO_Init(int Set)
{
#ifdef Exist_BZZ
    GPIO_InitTypeDef GPIO_InitStructure;
    if (Set) 
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
    else                                                    //标志取消GPIO
    {
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
#endif
}

void KEY_GPIO_Init(int Set)
{
#ifdef Exist_KEY
    GPIO_InitTypeDef GPIO_InitStructure;
    if (Set) {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_PU;
//        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
    else {
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
#endif
}

void HC595_GPIO_Init(int Set)
{
#ifdef Exist_HC595
    GPIO_InitTypeDef GPIO_InitStructure;
    if (Set) 
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);       //时钟
        
        GPIO_InitStructure.GPIO_Pin = LATCH_CLOCK | SHIFT_CLOCK | HC595_Data;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
    else                                                    //标志取消GPIO
    {
        GPIO_InitStructure.GPIO_Pin = LATCH_CLOCK | SHIFT_CLOCK | HC595_Data;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
#endif
}

