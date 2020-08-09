#include "mycommon.h"


uint8_t infrared_PWM;

uint8_t ccd_buffer[128];

extern uint16_t sample_value1 =0;
extern uint16_t sample_value2 =0;
extern uint16_t sample_value3 =0;

uint16_t last_sample_value1 =0 ;
uint16_t last_sample_value2 =0 ;
uint16_t last_sample_value3 =0 ;

uint16_t countnum = 0;
void sensor_init(uint32_t period)
{
  //ADC 初始化配置
  
  //ADC 1 设置
  ADC_InitTypeDef ADC_InitStruct1;
  ADC_InitStruct1.instance = HW_ADC1;
  ADC_InitStruct1.clockDiv = kADC_ClockDiv4;                     /* ADC采样时钟8分频 */
  ADC_InitStruct1.resolutionMode = kADC_SingleDiff10or11;        //kADC_SingleDIff16;  //kADC_SingleDiff8or9; //kADC_SingleDiff12or13
  ADC_InitStruct1.triggerMode = kADC_TriggerSoftware;            /* 软件触发转换 */
  ADC_InitStruct1.singleOrDiffMode = kADC_Single;                /*单端模式 */
  ADC_InitStruct1.continueMode = kADC_ContinueConversionDisable; /* 启动连续转换 转换一次后 自动开始下一次转换*/
  ADC_InitStruct1.hardwareAveMode = kADC_HardwareAverageDisable; /*禁止 硬件平均 功能 */
  ADC_InitStruct1.vref = kADC_VoltageVREF;                       /* 使用外部VERFH VREFL 作为模拟电压参考 */
  ADC_Init(&ADC_InitStruct1);
  
  
  PORT_PinMuxConfig(HW_GPIOC,9,kPinAlt0); 
  ADC_ChlMuxConfig(ADC_HW,kADC_ChlMuxB);
  
//  ADC_ChlMuxConfig(HW_ADC0,kADC_ChlMuxB);
  
  

  //pit设置
  PIT_QuickInit(PIT_CHL_CCD_CLK, period);
  PIT_CallbackInstall(PIT_CHL_CCD_CLK, sensor_clk_isr);
  PIT_ITDMAConfig(PIT_CHL_CCD_CLK, kPIT_IT_TOF, true);
  
  //si clk 初始化
  GPIO_QuickInit(GPIO_PIN_CCD_HW, GPIO_PIN_CCD_SI, kGPIO_Mode_OPP);
  GPIO_QuickInit(GPIO_PIN_CCD_HW, GPIO_PIN_CCD_CLK, kGPIO_Mode_OPP);
  
  GPIO_ResetBit(GPIO_PIN_CCD_HW, GPIO_PIN_CCD_SI);
  GPIO_ResetBit(GPIO_PIN_CCD_HW, GPIO_PIN_CCD_CLK);
  
}

void sensor_initial(void)
{
     ADC_QuickInit( ADC1_SE6B_PC10, kADC_SingleDiff10or11);   //ccd1
     ADC_QuickInit( ADC1_SE5B_PC9, kADC_SingleDiff10or11);    //ccd2
     ADC_QuickInit( ADC1_SE7B_PC11, kADC_SingleDiff10or11);   //ccd3
}       
  





void infrared_collection() //红外测距
{

     sample_value1 = ADC_QuickReadValue(ADC1_SE6B_PC10);
 
     sample_value2 = ADC_QuickReadValue(ADC1_SE5B_PC9);
       
     sample_value3 = ADC_QuickReadValue( ADC1_SE7B_PC11);
     
}


void distance_caculation(sample_value1,sample_value2,sample_value3) //判断安全距离
{
  
  if(  (sample_value1>infrared_theshold) || (sample_value2>infrared_theshold) || (sample_value3>infrared_theshold) )  
  {
    ganger_flag=1;  
  }
  else
  {
    ganger_flag=0;
  }

}

void sensor_clk_isr()    //定时器触发的 周期函数
{
  infrared_collection();
  distance_caculation(sample_value1,sample_value2,sample_value3);
  //turn_main();
  steering_motor_pwm_duty = get_turn;
  steering_loop();
  motor_pwm_duty = get_speed*790;  //motor_pid(600,550,0,target_speed);
  motor_loop();
  speed_loop();
  
}



