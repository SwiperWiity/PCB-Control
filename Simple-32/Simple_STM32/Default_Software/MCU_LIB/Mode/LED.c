#include "LED.h"


void LED_Init(int Set)
{
#ifdef Exist_LED
    LED_GPIO_Init(Set);
    LED_SET(1,DISABLE);
	WS2812_Reset();
	struct Caven_Color empty;
	LED_REG(empty,DISABLE);
#endif
}

void LED_SET(char Channel,int Set)
{
#ifdef Exist_LED
    switch (Channel) {
        case 1:
            if(Set)
                LED_Clr();
            else
                LED_Set();
            break;
        case 2:
            if(Set)
                LEDR_Clr();
            else
                LEDR_Set();
            break;
        default:
            break;
    }

#endif
}


void WS2812_Delay(int time)
{
	do{
		for(int n = 0;n < 10000;n++)
		{
		}
	}
    while(time--);
}

void WS2812_Reset (void)
{
#ifdef Exist_LED
	LED_Clr();
	WS2812_Delay(1000);
	LED_Set();
	WS2812_Delay(10);
#endif
}

void WS2812_write_byte(char data)
{
#ifdef Exist_LED
	char temp = data;
	int time;
	for(char i = 0; i < 8; i++)
	{
		time = 10;
	    if((temp << i) & 0x80)
	    {
	        LED_Set();
	        // WS2812_Delay(1);
			while((time--) > 3);
	        LED_Clr();
			time--;
	        // WS2812_Delay(0);
			// while((time--) > 3);
	    }
	    else
	    {
            LED_Set();
			while((time--) > 8);
            LED_Clr();
			while((time--) > 3);
        }
	}
	
#endif
}

void LED_REG(struct Caven_Color Color,int Set)
{
//    NVIC_SETPRIMASK();
	if(Set)
	{
		WS2812_write_byte(Color.Green);
		WS2812_write_byte(Color.Red);
		WS2812_write_byte(Color.Bule);
		
	}
	else
	{
		WS2812_write_byte(0);
		WS2812_write_byte(0);
		WS2812_write_byte(0);
	}
	WS2812_Delay(10);
//	NVIC_RESETPRIMASK();
}

