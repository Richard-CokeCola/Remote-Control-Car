#include "mycommon.h"

uint16_t clk_ms=0;
uint8_t  clk_s=0;
uint8_t  clk_m=0;
uint16_t tmp_clk_ms=0; //防止中断处理过程中clk_ms的值发生变化，在过程中应先存起来

uint8_t flag_50ms=0;
uint8_t flag_100ms=0;
uint8_t flag_200ms=0;
uint8_t flag_250ms=0;
uint8_t flag_1000ms=0;

void clk_init()
{
  PIT_QuickInit(PIT_CHL_CLK, PIT_CLK_TERM);
  PIT_CallbackInstall(PIT_CHL_CLK, fifty_ms);
  PIT_ITDMAConfig(PIT_CHL_CLK, kPIT_IT_TOF, true);
}

void fifty_ms()
{
  
   clk_ms+=50;

  tmp_clk_ms=clk_ms;
  if(tmp_clk_ms%50==0)
    flag_50ms=1;
  if(tmp_clk_ms%100==0)
    flag_100ms=1;
  if(tmp_clk_ms%200==0)
    flag_200ms=1;
  if(tmp_clk_ms%250==0)
    flag_250ms=1;
  if(tmp_clk_ms%1000==0)
    flag_1000ms=1;
  
  
   if(clk_ms==1000)
   {
      clk_ms=0;
      clk_s++;
     if(clk_s==60)
     {
        clk_s=0;
        clk_m++;
        }
   }

   
}


