#include "key.h"
#include "core_cm3.h"

#include "bsp_led.h"

void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; 

    /*开启按键GPIO口的时钟*/
    KEY1_INT_GPIO_CLK_ENABLE();
    KEY2_INT_GPIO_CLK_ENABLE();
		KEY3_INT_GPIO_CLK_ENABLE();

    /* 选择按键1的引脚 */ 
    GPIO_InitStructure.Pin = KEY1_INT_GPIO_PIN;
    /* 设置引脚为输入模式 */ 
    GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;	    		
    /* 设置引脚下拉 */
    GPIO_InitStructure.Pull = GPIO_PULLDOWN;
		GPIO_InitStructure.Speed=GPIO_SPEED_FREQ_HIGH;//高速
    /* 使用上面的结构体初始化按键 */
    HAL_GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure); 
    /* 配置 EXTI 中断源 到key1 引脚、配置中断优先级*/
    HAL_NVIC_SetPriority(KEY1_INT_EXTI_IRQ, 0, 1);
    /* 使能中断 */
    HAL_NVIC_EnableIRQ(KEY1_INT_EXTI_IRQ);

    /* 选择按键2的引脚 */ 
    GPIO_InitStructure.Pin = KEY2_INT_GPIO_PIN;
    /* 设置引脚下拉 */
    GPIO_InitStructure.Pull = GPIO_PULLUP;
		/* 设置引脚为输入模式 */ 
    GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;	    		
    /* 其他配置与上面相同 */
    HAL_GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);      
    /* 配置 EXTI 中断源 到key1 引脚、配置中断优先级*/
    HAL_NVIC_SetPriority(KEY2_INT_EXTI_IRQ, 0, 1);
    /* 使能中断 */
    HAL_NVIC_EnableIRQ(KEY2_INT_EXTI_IRQ);
		
		/* 选择按键3的引脚 */ 
    GPIO_InitStructure.Pin = KEY3_INT_GPIO_PIN;
    /* 设置引脚下拉 */
    GPIO_InitStructure.Pull = GPIO_PULLUP;
		/* 设置引脚为输入模式 */ 
    GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;	    		
    /* 其他配置与上面相同 */
    HAL_GPIO_Init(KEY3_INT_GPIO_PORT, &GPIO_InitStructure);      
    /* 配置 EXTI 中断源 到key1 引脚、配置中断优先级*/
    HAL_NVIC_SetPriority(KEY3_INT_EXTI_IRQ, 0, 1);
    /* 使能中断 */
    HAL_NVIC_EnableIRQ(KEY3_INT_EXTI_IRQ);
		
		return ;
}


void KEY1_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_INT_GPIO_PIN);		//调用中断处理公用函数
}

void KEY2_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY2_INT_GPIO_PIN);		//调用中断处理公用函数
}

void KEY3_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY3_INT_GPIO_PIN);		//调用中断处理公用函数
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
		//Delay_ms(10);
		//delay_ms(100);      //消抖
		//HAL_Delay(20);
    switch(GPIO_Pin)
    {
        case KEY1_INT_GPIO_PIN:
            if(KEY1==1) 
            {
							LED1_OFF;				//控制LED0反转
            }
            break;
        case KEY2_INT_GPIO_PIN:
            if(KEY2==0)  					//控制LED1反转
            {
							LED1_ON;
            }
            break;
        case KEY3_INT_GPIO_PIN:
            if(KEY3==0)  
            {

            }
            break;
    }
}