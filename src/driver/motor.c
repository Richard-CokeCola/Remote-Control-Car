#include "mycommon.h"
uint32_t motor_pwm_duty = DEFAULT_MOTOR_PWM_DUTY ; //д╛хо0%

void motor_init()
{
  //motor right
  FTM_PWM_QuickInit(FTM_PWM_MOTOR_RIGHT , kPWM_EdgeAligned,MOTOR_FREQUENCY);   
  GPIO_QuickInit(HW_GPIOC, 2, kGPIO_Mode_OPP);
  GPIO_WriteBit(HW_GPIOC, 2, 0);
  
  //motor left
  FTM_PWM_QuickInit(FTM_PWM_MOTOR_LEFT , kPWM_EdgeAligned,MOTOR_FREQUENCY);   
  GPIO_QuickInit(HW_GPIOC, 3, kGPIO_Mode_OPP);
  GPIO_WriteBit(HW_GPIOC, 3, 0);

  motor_loop();
}

void motor_loop()
{
  //fault tolerant
  if((motor_pwm_duty>MAX_MOTOR_PWM_DUTY) && (motor_pwm_duty<MAX_MOTOR_PWM_DUTY+5000)) 
      motor_pwm_duty=MAX_MOTOR_PWM_DUTY;
  if(motor_pwm_duty>MAX_MOTOR_PWM_DUTY+10000) 
      motor_pwm_duty=MIN_MOTOR_PWM_DUTY;
  
  FTM_PWM_ChangeDuty(FTM_MOTOR_RIGHT, FTM_CHL_MOTOR_RIGHT, motor_pwm_duty);
  FTM_PWM_ChangeDuty(FTM_MOTOR_LEFT, FTM_CHL_MOTOR_LEFT, motor_pwm_duty);

}
