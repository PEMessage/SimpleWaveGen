#ifndef __PIPEOUT_H
#define	__PIPEOUT_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"


/*******************************************************/
//L1
#define L1_PIN                  	GPIO_PIN_5                
#define L1_GPIO_PORT            	GPIOF                     
#define L1_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOF_CLK_ENABLE()

//L2
#define L2_PIN                  	GPIO_PIN_3                
#define L2_GPIO_PORT            	GPIOF                     
#define L2_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOF_CLK_ENABLE()

//L3
#define L3_PIN                  	GPIO_PIN_1                
#define L3_GPIO_PORT            	GPIOF                     
#define L3_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOF_CLK_ENABLE()

//L4
#define L4_PIN                  	GPIO_PIN_13                
#define L4_GPIO_PORT            	GPIOC                     
#define L4_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOC_CLK_ENABLE()

//L5
#define L5_PIN                  	GPIO_PIN_5              
#define L5_GPIO_PORT            	GPIOE                     
#define L5_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOE_CLK_ENABLE()

//L6
#define L6_PIN                  	GPIO_PIN_0              
#define L6_GPIO_PORT            	GPIOE                     
#define L6_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOE_CLK_ENABLE()

//L7
#define L7_PIN                  	GPIO_PIN_1              
#define L7_GPIO_PORT            	GPIOE                     
#define L7_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOE_CLK_ENABLE()

//L8
#define L8_PIN                  	GPIO_PIN_9              
#define L8_GPIO_PORT            	GPIOB                     
#define L8_GPIO_CLK_ENABLE()   		__HAL_RCC_GPIOB_CLK_ENABLE()


/************************************************************/

#define PIPEOUT_SEGMENT 64
#define PIPEOUT_LIST 2

#define FREQ_NUM 11
#define FREQ_SCALER_FACTOR  15625 // ARR Value = (FREQ_SCALER_FACTOR / FREQ) - 1

void PipeOut_Init(void);
void PipeOut_NextValue(void);
void PipeOut_NextList(void);
void PipeOut_NextFreq(void);
void PipeOut_Output(void);

#endif

