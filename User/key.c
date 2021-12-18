#include "key.h"
#include "core_cm3.h"

#include "bsp_led.h"

void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; 

    /*��������GPIO�ڵ�ʱ��*/
    KEY1_INT_GPIO_CLK_ENABLE();
    KEY2_INT_GPIO_CLK_ENABLE();
		KEY3_INT_GPIO_CLK_ENABLE();

    /* ѡ�񰴼�1������ */ 
    GPIO_InitStructure.Pin = KEY1_INT_GPIO_PIN;
    /* ��������Ϊ����ģʽ */ 
    GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;	    		
    /* ������������ */
    GPIO_InitStructure.Pull = GPIO_PULLDOWN;
		GPIO_InitStructure.Speed=GPIO_SPEED_FREQ_HIGH;//����
    /* ʹ������Ľṹ���ʼ������ */
    HAL_GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure); 
    /* ���� EXTI �ж�Դ ��key1 ���š������ж����ȼ�*/
    HAL_NVIC_SetPriority(KEY1_INT_EXTI_IRQ, 0, 1);
    /* ʹ���ж� */
    HAL_NVIC_EnableIRQ(KEY1_INT_EXTI_IRQ);

    /* ѡ�񰴼�2������ */ 
    GPIO_InitStructure.Pin = KEY2_INT_GPIO_PIN;
    /* ������������ */
    GPIO_InitStructure.Pull = GPIO_PULLUP;
		/* ��������Ϊ����ģʽ */ 
    GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;	    		
    /* ����������������ͬ */
    HAL_GPIO_Init(KEY2_INT_GPIO_PORT, &GPIO_InitStructure);      
    /* ���� EXTI �ж�Դ ��key1 ���š������ж����ȼ�*/
    HAL_NVIC_SetPriority(KEY2_INT_EXTI_IRQ, 0, 1);
    /* ʹ���ж� */
    HAL_NVIC_EnableIRQ(KEY2_INT_EXTI_IRQ);
		
		/* ѡ�񰴼�3������ */ 
    GPIO_InitStructure.Pin = KEY3_INT_GPIO_PIN;
    /* ������������ */
    GPIO_InitStructure.Pull = GPIO_PULLUP;
		/* ��������Ϊ����ģʽ */ 
    GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;	    		
    /* ����������������ͬ */
    HAL_GPIO_Init(KEY3_INT_GPIO_PORT, &GPIO_InitStructure);      
    /* ���� EXTI �ж�Դ ��key1 ���š������ж����ȼ�*/
    HAL_NVIC_SetPriority(KEY3_INT_EXTI_IRQ, 0, 1);
    /* ʹ���ж� */
    HAL_NVIC_EnableIRQ(KEY3_INT_EXTI_IRQ);
		
		return ;
}


void KEY1_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_INT_GPIO_PIN);		//�����жϴ����ú���
}

void KEY2_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY2_INT_GPIO_PIN);		//�����жϴ����ú���
}

void KEY3_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY3_INT_GPIO_PIN);		//�����жϴ����ú���
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
		//Delay_ms(10);
		//delay_ms(100);      //����
		//HAL_Delay(20);
    switch(GPIO_Pin)
    {
        case KEY1_INT_GPIO_PIN:
            if(KEY1==1) 
            {
							LED1_OFF;				//����LED0��ת
            }
            break;
        case KEY2_INT_GPIO_PIN:
            if(KEY2==0)  					//����LED1��ת
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