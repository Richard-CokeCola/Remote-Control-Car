#include "mycommon.h"

extern uint16_t ganger_flag  = 0;

uint32_t steering_motor_pwm_duty=DEFAULT_STEERING_PWM_DUTY ;  //默认正向

uint16_t delay_time = 800;     //延迟时间   1秒 =（1*1000）


void steering_init()
{
  FTM_PWM_QuickInit( FTM_PWM_STEERING , kPWM_EdgeAligned, STEERING_FREQUENCY);
  steering_loop();
}


void steering_loop()
{
  if(steering_motor_pwm_duty>SW_MAX_STEERING_PWM_DUTY)
  {
    steering_motor_pwm_duty=SW_MAX_STEERING_PWM_DUTY;
  }
  if(steering_motor_pwm_duty<SW_MIN_STEERING_PWM_DUTY)
  {
    steering_motor_pwm_duty=SW_MIN_STEERING_PWM_DUTY;
  }
  
  FTM_PWM_ChangeDuty(FTM_STEERING, FTM_CHL_STEERING, steering_motor_pwm_duty);
}


void steering_turn_r() //右转
{
  steering_motor_pwm_duty=ganger_turn_r;
  steering_loop();
  DWT_DelayMs(600);
 
  steering_motor_pwm_duty=DEFAULT_STEERING_PWM_DUTY;
}
  
void steering_turn_l() //左转
{
  steering_motor_pwm_duty=ganger_turn_l;
  steering_loop();
  DWT_DelayMs(600);
  
  steering_motor_pwm_duty=DEFAULT_STEERING_PWM_DUTY;
}


// 2左   1中    3右
void steering_control(ganger_flag,sample_value1,sample_value2,sample_value3) //控制转向
{

  if(ganger_flag==1)
  {
    if( (sample_value1>infrared_theshold) )  //中间检测到
    {
      if(sample_value2>sample_value3) //左大于右
      {
         steering_turn_r();
      }
      if(sample_value2<sample_value3) //右大于左
      {
         steering_turn_l();
      }
    }
    if( (sample_value1<infrared_theshold) ) //中间未检测到
    {
      if( (sample_value2>infrared_theshold) &&(sample_value3<infrared_theshold) ) //左大于右
      {
         steering_turn_r();
      }
      if( (sample_value3>infrared_theshold) &&(sample_value2<infrared_theshold) ) //右大于左
      {
         steering_turn_l();
      }
    }

  }
  else
  {
   
      steering_motor_pwm_duty = get_turn;
      steering_loop();
    

  }

}




void turn_main()  //转向控制主程序
{
    steering_control(ganger_flag,sample_value1,sample_value2,sample_value3);
  
}