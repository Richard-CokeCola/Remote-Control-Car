#include "mycommon.h"

unsigned char uart_buf[12];

unsigned char rx_num=0;

unsigned char rx_flag=0;

extern uint16_t al_move_flag=1;

extern uint16_t byteReceived=0;

extern int16_t get_data=0;

uint16_t r_l_flag = 3;

extern uint16_t get_turn=740;

extern uint16_t get_speed=0;

uint32_t w_count = 0;

uint32_t a_count = 0;
uint32_t d_count = 0;
uint32_t e_count = 0;
uint32_t q_count = 0;

//UART
void uart_init() //串口初始化
{
  
  UART_QuickInit( UART0_RX_PA15_TX_PA14 , 115200);
  UART_CallbackRxInstall(HW_UART0, UART_RX_ISR);   
  UART_ITDMAConfig(HW_UART0, kUART_IT_Rx, true);

}


 void UART_RX_ISR(int8_t byteReceived) //从串口读取数据
{
     switch(byteReceived)
  {
    case 'w': w_count = 7;  break; //前进
    case 'a': a_count = 7;   break; //左转
    case 'd': d_count = 7;   break; //右转
    case 's': q_count =0; e_count =0;a_count = 0; d_count = 0; w_count=0;   break; //停车
    case 'q': q_count= 7;    break; //小左转
    case 'e': e_count = 7;    break; //小右转
  }

}  
/* 通信协议*/



//   if(byteReceived=='$') //开始采集数据
//   {
//     rx_num=0;
//     
//   }
//   uart_buf[rx_num++]=byteReceived;
//   if(byteReceived=='#') //完成一帧采集
//   {
//     
//     rx_flag=1;
//     if(rx_flag ==1 ) //解析指令
//     {
//       get_turn = (uart_buf[1]-0x30)*100 + (uart_buf[2]-0x30)*10 + (uart_buf[3]-0x30);
//       r_l_flag = (uart_buf[4]-0x30);
//       if( r_l_flag ==1 ) //左转
//       {
//         get_turn = 740 + get_turn*2;
//       }
//       if( r_l_flag ==0 ) //右转
//       {
//         get_turn = 740 - get_turn*2;
//       }
//       get_speed = (uart_buf[5]-0x30)*1000;
//     }
//     rx_num=0;
//   }     
//   if(rx_num>=20)
//   {
//     rx_num=0;
//     rx_flag=0;
//   }
//   

