/* Includes ------------------------------------------------------------------*/
#include "mode.h"


// HSE      外部晶振
// HSI      内部晶振

void Main_Init(void);

U8 Temp_u8 = 0xaa;
U8 Temp_str[100] = {0xaa};

int main(void)
{
    Main_Init();

    while (1)
    {
//        Mode_User.Delay.Delay_ms(5);
//        Mode_User.LED.LED_SET(1,ENABLE);
//        Mode_User.BZZ.BZZ_SET(ENABLE);
//        Mode_User.TIME.Get_TIME();
//        Mode_User.Delay.Delay_ms(5);
//        Mode_User.LED.LED_SET(1,DISABLE);
//        Mode_User.BZZ.BZZ_SET(DISABLE);

//        Mode_User.HC595.Set_DATA(Temp_str,1);
////        printf("Time : %2d/%2d/%2d s \r\n",SYS_Time.Watch.hour,SYS_Time.Watch.minutes,SYS_Time.Watch.second);
//        if(KEY_State (1) == 0)
//        {
//            printf("key \r\n");
//        }
    }
}

void Main_Init(void)
{
    Mode_Index();

//    Mode_Init.TIME(ENABLE);
//    Mode_Init.UART(1,115200,ENABLE);
//    Mode_Init.UART(2,115200,ENABLE);
//    Mode_Init.UART(3,115200,ENABLE);
//    Mode_Init.LED(ENABLE);
//    Mode_Init.BZZ(ENABLE);
//    Mode_Init.HC_595(ENABLE);
//    Mode_Init.KEY(1,ENABLE);
//    

//    Mode_User.Delay.Delay_ms(100);
//    Mode_User.TIME.Set_TIME(SYS_Time.Watch);
//    Mode_User.LED.LED_SET(1,ENABLE);
//    
//    
//    Mode_User.UART.Send_String(2,"hello world 2 !\r\n");
//    Mode_User.UART.Send_String(3,"hello world 3 !\r\n");
//    
//    Mode_User.UART.Send_String(1,"hello world !\r\n");
//    Mode_User.Debug_Out("hello world !\r\n");
//    printf("hello world !\r\n");
}
