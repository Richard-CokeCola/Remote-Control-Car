#include "mycommon.h"

extern uint16_t ganger_flag  = 0;

uint32_t steering_motor_pwm_duty=DEFAULT_STEERING_PWM_DUTY ;  //Ĭ������

uint16_t delay_time = 800;     //�ӳ�ʱ��   1�� =��1*1000��


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


void steering_turn_r() //��ת
{
  steering_motor_pwm_duty=ganger_turn_r;
  steering_loop();
  DWT_DelayMs(600);
 
  steering_motor_pwm_duty=DEFAULT_STEERING_PWM_DUTY;
}
  
void steering_turn_l() //��ת
{
  steering_motor_pwm_duty=ganger_turn_l;
  steering_loop();
  DWT_DelayMs(600);
  
  steering_motor_pwm_duty=DEFAULT_STEERING_PWM_DUTY;
}


// 2��   1��    3��
void steering_control(ganger_flag,sample_value1,sample_value2,sample_value3) //����ת��
{

  if(ganger_flag==1)
  {
    if( (sample_value1>infrared_theshold) )  //�м��⵽
    {
      if(sample_value2>sample_value3) //�������
      {
         steering_turn_r();
      }
      if(sample_value2<sample_value3) //�Ҵ�����
      {
         steering_turn_l();
      }
    }
    if( (sample_value1<infrared_theshold) ) //�м�δ��⵽
    {
      if( (sample_value2>infrared_theshold) &&(sample_value3<infrared_theshold) ) //�������
      {
         steering_turn_r();
      }
      if( (sample_value3>infrared_theshold) &&(sample_value2<infrared_theshold) ) //�Ҵ�����
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




void turn_main()  //ת�����������
{
    steering_control(ganger_flag,sample_value1,sample_value2,sample_value3);
  
}