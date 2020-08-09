#ifndef _STRATEGY_
#define _STRATEGY_

extern  int32_t lastoutput;
extern int32_t error_v2;
extern int32_t error_v1;
extern int32_t error_v0;


//void report();
void UI_init();
signed int angle_get();
void angle_set(int);
//void auto_report_loop();
//void wave_send();
//void ccd_send();
//void processed_ccd_send();
//void debug_value_output();
void UART_Write4Byte(uint32_t  instance,uint32_t value);
void UART_Write2Byte(uint32_t  instance,uint16_t value);
uint32_t motor_pid(uint16_t kp,uint16_t ki,uint16_t kd,uint32_t target_speed);

void UART_RX_ISR(int8_t byteReceived);

#endif

