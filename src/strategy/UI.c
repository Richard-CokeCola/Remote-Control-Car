#include "mycommon.h"

#define SPEED_STEP 300

uint32_t target_speed=1000;
uint32_t debug_value=0;






//static uint8_t auto_report_flag=1;




//void ccd_send()
//{
//  
//  uint8_t ii;
//  UART_WriteByte(HW_UART0, 0x02);
//  UART_WriteByte(HW_UART0, 0xfd);
//  for(ii=0;ii<128;ii++){
//    UART_WriteByte(HW_UART0, ccd_buffer[ii]);
//  }
//  UART_WriteByte(HW_UART0, 0xfd);
//  UART_WriteByte(HW_UART0, 0x02);
//  
//}



//void UART_Write2Byte(uint32_t  instance,uint16_t value){
//  UART_WriteByte(instance, value&0xff);
//  UART_WriteByte(instance, (value&0xff00)>>8);
//}
//
//void UART_Write4Byte(uint32_t  instance,uint32_t value){
//  UART_WriteByte(instance, value&0xff);
//  UART_WriteByte(instance, (value&0xff00)>>8);
//  UART_WriteByte(instance, (value&0xff0000)>>16);
//  UART_WriteByte(instance, (value&0xff000000)>>24);
//}



//void wave_send(){
//  
//  UART_WriteByte(HW_UART0, 0x03);
//  UART_WriteByte(HW_UART0, 0xfc);
//
//  UART_Write4Byte(HW_UART0,speed_value);
//  UART_Write4Byte(HW_UART0,target_speed);
//  UART_Write4Byte(HW_UART0,debug_value);
//  UART_Write4Byte(HW_UART0,steering_motor_pwm_duty);
//  
//  UART_WriteByte(HW_UART0, 0xfc);
//  UART_WriteByte(HW_UART0, 0x03);
//  
//}


//void processed_ccd_send()
//{
//    //处理，然后调用ccd_send  
//}


//void auto_report_loop()
//{
//  if(auto_report_flag)
//  {
//    do something
//    
//    文本显示
//   report();
//    debug_value_output();
//    
//    上位机显示
//    ccd_send();
//    wave_send();
//    processed_ccd_send();
//  }
//}



//void debug_value_output(){
//  
//  printf("run time:%d:%d:%d  ",clk_m,clk_s,clk_ms);
//  printf("debug_value:%d\n\r",debug_value);
//  
//}



//void report(){
//  
//  printf("\n\r");
//  printf("motor_pwm_duty=%d\n\r",motor_pwm_duty);
//  printf("target_speed:%d\n\r",target_speed);
//  printf("angle=%d\n\r",angle_get());
//  printf("speed_value=%d\n\r",speed_value);
//  printf("run time:%d:%d:%d\n\r",clk_m,clk_s,clk_ms);
//  printf("error_v0:%d\n\r",error_v0);
//  printf("error_v1:%d\n\r",error_v1);
//  printf("error_v2:%d\n\r",error_v2);
//  printf("lastoutput:%d\n\r",lastoutput);
//  printf("debug_value:%d\n\r",debug_value);
//  printf("\n\r");
//  
//}


//
//void response(uint16_t key)
//{
//  
//  switch(key)
//  {
//    case 'w':get_turn=4a; w_count=4  ; break;
//    case 'a':get_turn=58;    break;
//    case 'd':get_turn=39;   break;
//    case 's':get_turn=4a; w_count = 0; break;
//    case 'p':target_speed=0;printf("p confirm\n\r");break;
//    case 't':auto_report_flag=!auto_report_flag;printf("t confirm\n\r");break;
//    case 'g':clk_s=0;clk_m=0;printf("g confirm\n\r");break;
//    case 'r':report();break;
//  }
//  
//}