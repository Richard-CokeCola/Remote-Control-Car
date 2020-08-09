#include "mycommon.h"

uint32_t speed_value=0;//返回平均1s接收到的脉冲数x10，与速度成正比
static uint32_t speed_v0=0;
static uint32_t speed_v1=0;
static uint32_t speed_v2=0; //缓存前两次的值，来做平均滤波
static uint16_t sample_period=0;

static void DMA_PulseCountInit(uint32_t dmaChl, uint32_t instance, uint32_t pinIndex)
{
  GPIO_QuickInit(instance, pinIndex, kGPIO_Mode_IPU);
  GPIO_ITDMAConfig(instance, pinIndex, kGPIO_DMA_RisingEdge, true);
  static uint8_t dummy1, dummy2;
  DMA_InitTypeDef DMA_InitStruct1 = {0};  
  DMA_InitStruct1.chl = dmaChl;  
  DMA_InitStruct1.chlTriggerSource = DMA_REQ_SPEED;
  DMA_InitStruct1.triggerSourceMode = kDMA_TriggerSource_Normal; 
  DMA_InitStruct1.minorLoopByteCnt = 1;
  DMA_InitStruct1.majorLoopCnt = DMA_CITER_ELINKNO_CITER_MASK; /* 最大值 */
  
  DMA_InitStruct1.sAddr = (uint32_t)&dummy1;
  DMA_InitStruct1.sLastAddrAdj = 0; 
  DMA_InitStruct1.sAddrOffset = 0;
  DMA_InitStruct1.sDataWidth = kDMA_DataWidthBit_8;
  DMA_InitStruct1.sMod = kDMA_ModuloDisable;
  
  DMA_InitStruct1.dAddr = (uint32_t)&dummy2; 
  DMA_InitStruct1.dLastAddrAdj = 0;
  DMA_InitStruct1.dAddrOffset = 0; 
  DMA_InitStruct1.dDataWidth = kDMA_DataWidthBit_8;
  DMA_InitStruct1.dMod = kDMA_ModuloDisable;
  DMA_Init(&DMA_InitStruct1);
  
  DMA_EnableRequest(dmaChl);
}

void speed_init(uint16_t _period)
{
  sample_period=_period;
  DMA_PulseCountInit(DMA_CHL_SPEED,PORT_SPEED,GPIO_PIN_SPEED);
}

void speed_loop()
{
  speed_v2=speed_v1;
  speed_v1=speed_v0;
  speed_v0=(DMA_CITER_ELINKNO_CITER_MASK - DMA_GetMajorLoopCount(DMA_CHL_SPEED))*10000/sample_period;
  
  speed_value=(speed_v2+speed_v1+speed_v0)/4;
  
  DMA_CancelTransfer();
  DMA_SetMajorLoopCounter(DMA_CHL_SPEED, DMA_CITER_ELINKNO_CITER_MASK);
  DMA_EnableRequest(DMA_CHL_SPEED);
  
}



