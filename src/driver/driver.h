#ifndef _DRIVER_
#define _DRIVER_

void uart_init();

void UART_RX_ISR(int8_t byteReceived);

void steering_init();
void steering_loop();

void motor_init();
void motor_loop();

void clk_init();
void fifty_ms();

void speed_loop();
void speed_init(uint16_t _period);

void sensor_init(uint32_t period);
void sensor_clk_isr();

#endif



//可用的 ADC通道及引脚 - 144P
/*
 ADC0_SE0_DP0        
 ADC0_SE1_DP1        
 ADC0_SE3_DP3        
 ADC0_SE4B_PC2       
 ADC0_SE5B_PD1       
 ADC0_SE6B_PD5       
 ADC0_SE7B_PD6       
 ADC0_SE8_PB0        
 ADC0_SE9_PB1        
 ADC0_SE12_PB2       
 ADC0_SE13_PB3       
 ADC0_SE14_PC0       
 ADC0_SE15_PC1       
 ADC0_SE17_E24       
 ADC0_SE18_E25       
 ADC0_SE19_DM0       
 ADC0_SE20_DM1       
 ADC0_SE26_TEMP

 ADC1_SE0_DP0        
 ADC1_SE1_DP1        
 ADC1_SE3_DP3        
 ADC1_SE4_PE0        
 ADC1_SE5_PE1        
 ADC1_SE6_PE2        
 ADC1_SE7_PE3        
 ADC1_SE4B_PC8 

 ADC1_SE5B_PC9    //ccd 2       
 ADC1_SE6B_PC10   //ccd 1   
 ADC1_SE7B_PC11   //ccd 3  

 ADC1_SE8_PB0        
 ADC1_SE9_PB1

 ADC1_SE14_PB10      
 ADC1_SE15_PB11

 ADC1_SE17_PB117     
 ADC1_SE19_DM0       
 ADC1_SE20_DM1       
 ADC1_SE26_TEMP      
*/