#include "mycommon.h"

   int32_t lastoutput=0;
   int32_t error_v2=0;
   int32_t error_v1=0;
   int32_t error_v0=0;

uint32_t motor_pid(uint16_t kp,uint16_t ki,uint16_t kd,uint32_t target_speed)
{

  error_v2=error_v1;
  error_v1=error_v0;
  error_v0=target_speed-speed_value;
  
  return lastoutput=lastoutput+(kp*error_v0-ki*error_v1+kd*error_v2)/1000;  
}