/* Includes ------------------------------------------------------------------*/
#include "Mode.h"
//#include "pic.h" //图库
#include "duck.h"

// HSE      外部晶振
// HSI      内部晶振

void Main_Init(void);

U8 Temp_u8 = 0xaa;
char Temp_str[100] = {0xaa};
struct Caven_Color Color_LED;
int main(void)
{
   Main_Init();
   Color_LED.Red = 20;
   Color_LED.Green = 2;
   Color_LED.Bule = 20;
   while (1)
   {
      Mode_User.TIME.Get_TIME();
//      Mode_User.LED.LED_REG(Color_LED,ENABLE);

      Mode_User.Delay.Delay_ms(50);
      
      // Mode_User.LED.LED_SET(1,ENABLE);
//        Mode_User.BZZ.BZZ_SET(ENABLE);

      Mode_User.Delay.Delay_ms(100);
//      SPI_SET_Addr_SendData(1,0xfa,0xaa);
      // Mode_User.LED.LED_SET(1,DISABLE);
//        Mode_User.BZZ.BZZ_SET(DISABLE);

//        Mode_User.HC595.Set_DATA(Temp_str,1);
      printf("Time : %2d/%2d/%2d s \r\n",SYS_Time.Watch.hour,SYS_Time.Watch.minutes,SYS_Time.Watch.second);
      // Mode_User.UART.Send_String(2,Temp_str);
//        if(KEY_State (1) == 0)
//        {
//            printf("key \r\n");
//        }
   }
}

void Main_Init(void)
{
    Mode_Index();

	Mode_Init.TIME(ENABLE);
//    Mode_Init.UART(1,115200,ENABLE);
	Mode_Init.UART(2,9600,ENABLE);
	
	Mode_Init.LED(ENABLE);
	Mode_Init.Voice(ENABLE);
//    Mode_Init.BZZ(ENABLE);
//    Mode_Init.HC_595(ENABLE);
//    Mode_Init.KEY(1,ENABLE);
	Mode_Init.LCD(ENABLE);

	Mode_User.Delay.Delay_ms(100);
	Mode_User.TIME.Set_TIME(SYS_Time.Watch);
	Mode_User.Voice.Speak(JQ8900,1);
//    Mode_User.LED.LED_SET(1,ENABLE);
//    
//    
   Mode_User.UART.Send_String(2,"hello world 2 !\r\n");
//    Mode_User.UART.Send_String(3,"hello world 3 !\r\n");
//    
//    Mode_User.UART.Send_String(1,"hello world !\r\n");
//    Mode_User.Debug_Out("hello world !\r\n");
//    printf("hello world !\r\n");
	Mode_User.LCD.Show_Picture(40,40,160,160,gImage_duck);
//	Mode_User.LCD.Show_String(0,0,"hello world !",WHITE,BACK_COLOR,16);
}
