#ifndef __KEY_H
#define	__KEY_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"



#define KEY1_INT_GPIO_PORT                GPIOA
#define KEY1_INT_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE();
#define KEY1_INT_GPIO_PIN                 GPIO_PIN_0
#define KEY1_INT_EXTI_IRQ                 EXTI0_IRQn
#define KEY1_IRQHandler                   EXTI0_IRQHandler

#define KEY2_INT_GPIO_PORT                GPIOE
#define KEY2_INT_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOE_CLK_ENABLE();
#define KEY2_INT_GPIO_PIN                 GPIO_PIN_3
#define KEY2_INT_EXTI_IRQ                 EXTI3_IRQn
#define KEY2_IRQHandler                   EXTI3_IRQHandler


#define KEY3_INT_GPIO_PORT                GPIOE
#define KEY3_INT_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOE_CLK_ENABLE();
#define KEY3_INT_GPIO_PIN                 GPIO_PIN_4
#define KEY3_INT_EXTI_IRQ                 EXTI4_IRQn
#define KEY3_IRQHandler                   EXTI4_IRQHandler

#define KEY1        HAL_GPIO_ReadPin(KEY1_INT_GPIO_PORT,KEY1_INT_GPIO_PIN)  //KEY0°´¼üPE4
#define KEY2        HAL_GPIO_ReadPin(KEY2_INT_GPIO_PORT,KEY2_INT_GPIO_PIN)  //KEY1°´¼üPE3
#define KEY3        HAL_GPIO_ReadPin(KEY3_INT_GPIO_PORT,KEY3_INT_GPIO_PIN)  //WKUP°´¼üPA0

void Key_Init(void);


#endif

