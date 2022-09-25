#ifndef _LED__H_
#define _LED__H_

#include "Base.h"
#include "Caven.h"

/*




*/
struct LED_
{
    void (*LED_SET)(char Channel,int Set);
    void (*LED_REG)(struct Caven_Color Color,int Set);
};

void LED_Init(int Set);
void WS2812_Reset (void);

void LED_SET(char Channel,int Set);
void LED_REG(struct Caven_Color Color,int Set);

#endif
