#include "mycommon.h"
extern unsigned int sensor_num;
extern unsigned char uart_buf[12];
extern unsigned char rx_num;
extern unsigned char rx_flag;
extern uint32_t w_count  ;
extern uint32_t a_count  ;
extern uint32_t d_count  ;
extern uint32_t q_count  ;
extern uint32_t e_count  ;

void init(){
  
    DelayInit();
    
    //driver
    motor_init();
    steering_init();
    clk_init();
    speed_init(50);//参数是采样周期值，要随着采样周期变化而变化
    sensor_init(1000);  //可以调节曝光时间
    
    sensor_initial();
      
      
    //debug
    uart_init();
   

}

void mission_50ms()
{

  //if(w_count > 0 )
  //    w_count --;
  
  
  if(w_count >0)
      get_speed=1 ;
  else 
      get_speed=0;
  
  if(a_count >0 )
    a_count --;
  
  if(d_count >0)
    d_count --;

  if(q_count >0 )
    q_count --;
  
  if(e_count >0)
    e_count --;  
  

  if(a_count + d_count == q_count +e_count){
    get_turn=750;
  }
  else if(a_count + d_count > q_count +e_count){
    if(a_count == 0 && d_count ==0  )
      get_turn=750;
    else if(a_count <d_count )
      get_turn=560;
    else if(a_count >d_count )
      get_turn=890;
    else 
      get_turn=750;
  }else if(a_count + d_count < q_count +e_count){
    if(q_count == 0 && e_count ==0  )
      get_turn=750;
    else if(q_count <e_count )
      get_turn=690;
    else if(q_count >e_count )
      get_turn=820;
    else 
      get_turn=750;
  }
  
  
  //  auto_report_loop();
    
  //  steering_motor_pwm_duty=CENTER_PWM_DUTY;//对中矫正 
 
  //  turn_main();
  //  motor_pwm_duty=1000;  //motor_pid(600,550,0,target_speed);
  //  motor_loop();
  //  speed_loop();

}

void mission_100ms(){}
void mission_200ms(){}
void mission_250ms(){}
void mission_1000ms(){}

 void main()
{
  init();
  //unsigned char i=0;
  
  while(1)
  { 
    UART_WriteByte(HW_UART0,0x01);
    UART_WriteByte(HW_UART0,0x02);
    //UART_WriteByte(HW_UART0,0x30);
    if(flag_50ms==1)
    {
      flag_50ms=0;
      mission_50ms();
    }
     if(flag_100ms==1)
     {
      flag_100ms=0;
      mission_100ms();
    }
     if(flag_200ms==1)
     {
      flag_200ms=0;
      mission_200ms();
    }
     if(flag_250ms==1)
     {
      flag_250ms=0;
      mission_250ms();
    }
     if(flag_1000ms==1)
     {
      flag_1000ms=0;
      mission_1000ms();
    }
//    if(rx_flag==1)
//    {
//      rx_flag=0;
//      for(i=0;i<=10;i++)
//      {
//        UART_WriteByte(HW_UART0,uart_buf[i]);
//      }
//    }
  }
}