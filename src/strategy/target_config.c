#include "mycommon.h"

void angle_set(int angle){
  //������׼ȷ�ĽǶȣ����ǽ��ɱ䷶Χ��Ϊ200�ݣ���Χ��-100~100
  if(angle==0)
    steering_motor_pwm_duty=CENTER_PWM_DUTY;
  else if(angle>0&&angle<=100)
    steering_motor_pwm_duty=CENTER_PWM_DUTY+(SW_MAX_STEERING_PWM_DUTY-CENTER_PWM_DUTY)*angle/100;
  else if(angle>=-100&&angle<0)
    steering_motor_pwm_duty=CENTER_PWM_DUTY+(CENTER_PWM_DUTY-SW_MIN_STEERING_PWM_DUTY)*(angle)/100;
}

signed int angle_get(){
  if(steering_motor_pwm_duty<CENTER_PWM_DUTY)
    return 0-(CENTER_PWM_DUTY-steering_motor_pwm_duty)*100/(CENTER_PWM_DUTY-SW_MIN_STEERING_PWM_DUTY);
  else if(steering_motor_pwm_duty==CENTER_PWM_DUTY)
    return 0;
  else
    return (steering_motor_pwm_duty-CENTER_PWM_DUTY)*100/(SW_MAX_STEERING_PWM_DUTY-CENTER_PWM_DUTY);

}
