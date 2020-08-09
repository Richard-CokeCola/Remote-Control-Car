#ifndef _MYCOMMON_
#define _MYCOMMON_

#define DEBUG

#include "gpio.h"
#include "common.h"
#include "uart.h"
#include "ftm.h"
#include "dma.h"
#include "pit.h"
#include "i2c.h"
#include "adc.h"

#include "res_ref.h"
#include "driver/driver.h"
#include "strategy/strategy.h"

//constant-UART_BT 
#define UART_BT_BAUD_RATE 115200

//constant-MOTOR
#define MAX_MOTOR_PWM_DUTY 10000
#define MIN_MOTOR_PWM_DUTY 0
#define MOTOR_FREQUENCY (8*1000) //HZ
#define DEFAULT_MOTOR_PWM_DUTY 0

//variable-MOTOR
extern uint32_t motor_pwm_duty;

//constant-steering
#define HW_MAX_STEERING_PWM_DUTY 1500
#define HW_MIN_STEERING_PWM_DUTY 400
#define SW_MAX_STEERING_PWM_DUTY 890
#define SW_MIN_STEERING_PWM_DUTY 570
#define STEERING_FREQUENCY 60
#define CENTER_PWM_DUTY 750  ////                     
#define DEFAULT_STEERING_PWM_DUTY CENTER_PWM_DUTY

//variable-steering
extern uint32_t steering_motor_pwm_duty;

//constant-PIT
#define PIT_CLK_TERM (50*1000)   // 50ms

//variable-PIT
extern uint16_t clk_ms;
extern uint8_t clk_s;
extern uint8_t clk_m;

extern uint8_t flag_50ms;
extern uint8_t flag_100ms;
extern uint8_t flag_200ms;
extern uint8_t flag_250ms;
extern uint8_t flag_1000ms;

//variable-speed
extern uint32_t speed_value;

//variable-PID
extern uint32_t target_speed;

//variable-CCD
//extern uint8_t ccd_buffer[128];

//variable_UI
extern uint32_t debug_value;

//steering
extern uint16_t sample_value1 ;
extern uint16_t sample_value2 ;
extern uint16_t sample_value3 ;

#define ganger_turn_r 590   //±‹’œ◊™Ω« (880----740----570) (l 775----m 650----580 r)
#define ganger_turn_l 850
#define infrared_theshold 760 //∫ÏÕ‚„–÷µ

//flags
extern uint16_t ganger_flag;
extern uint16_t delay_flag;
extern uint16_t al_move_flag;

//ui

extern int16_t get_data;

extern uint16_t get_turn;
extern uint16_t get_speed;

extern uint16_t byteReceived;
extern uint16_t r_l_flag;

extern uint16_t countnum;
#endif