#include "pipeout.h"
#include "core_cm3.h"

static uint8_t outputlist_0[PIPEOUT_SEGMENT] =
				{  127 ,140 ,152 ,165 ,177 ,188 ,199 ,209 ,218 ,227 
          ,234 ,240 ,246 ,250 ,253 ,254 ,254 ,254 ,251 ,248 
          ,243 ,237 ,231 ,223 ,214 ,204 ,193 ,182 ,171 ,158 
          ,146 ,133 ,121 ,108 , 96 , 83 , 72 , 61 , 50 , 40 
          , 31 , 23 , 17 , 11 ,  6 ,  3 ,  0 ,  0 ,  0 ,  1 
          ,  4 ,  8 , 14 , 20 , 27 , 36 , 45 , 55 , 66 , 77 
          , 89 ,102 ,114 ,127 };
				
static uint8_t outputlist_1[PIPEOUT_SEGMENT] =
				{  127 ,140 ,152 ,165 ,177 ,188 ,199 ,209 ,218 ,227 
          ,234 ,240 ,246 ,250 ,253 ,254 ,254 ,254 ,251 ,248 
          ,243 ,237 ,231 ,223 ,214 ,204 ,193 ,182 ,171 ,158 
          ,146 ,133 ,121 ,108 , 96 , 83 , 72 , 61 , 50 , 40 
          , 31 , 23 , 17 , 11 ,  6 ,  100 ,  0 ,  0 ,  0 ,  1 
          ,  4 ,  8 , 14 , 20 , 27 , 36 , 45 , 55 , 66 , 77 
          , 89 ,102 ,114 ,127 };

static uint8_t *(outputlist[PIPEOUT_LIST]) = { outputlist_0 , outputlist_1 } ;

uint16_t current_out = 0;
uint16_t current_list = 0;

 
void PipeOut_NextValue()
	{
			if(current_out<PIPEOUT_SEGMENT-1)
			{current_out++;}
			else
			{current_out = 0;}
			return ;
	}
	
void PipeOut_Output()
	{
		HAL_GPIO_WritePin(L1_GPIO_PORT,L1_PIN,outputlist[1][current_out]&0x01);
		HAL_GPIO_WritePin(L2_GPIO_PORT,L2_PIN,(outputlist[1][current_out]&0x02)>>1);
		HAL_GPIO_WritePin(L3_GPIO_PORT,L3_PIN,(outputlist[1][current_out]&0x04)>>2);
		HAL_GPIO_WritePin(L4_GPIO_PORT,L4_PIN,(outputlist[1][current_out]&0x08)>>3);
		
		HAL_GPIO_WritePin(L5_GPIO_PORT,L5_PIN,(outputlist[1][current_out]&0x10)>>4);
		HAL_GPIO_WritePin(L6_GPIO_PORT,L6_PIN,(outputlist[1][current_out]&0x20)>>5);
		HAL_GPIO_WritePin(L7_GPIO_PORT,L7_PIN,(outputlist[1][current_out]&0x40)>>6);
		HAL_GPIO_WritePin(L8_GPIO_PORT,L8_PIN,(outputlist[1][current_out]&0x80)>>7);
		
		return ;
	}
	
	void PipeOut_Init()
	{
		GPIO_InitTypeDef  GPIO_InitStruct;

    /*开启LED相关的GPIO外设时钟*/
    L1_GPIO_CLK_ENABLE();
    L2_GPIO_CLK_ENABLE();
    L3_GPIO_CLK_ENABLE();
		L4_GPIO_CLK_ENABLE();
		L5_GPIO_CLK_ENABLE();
		L6_GPIO_CLK_ENABLE();
		L7_GPIO_CLK_ENABLE();
		L8_GPIO_CLK_ENABLE();
  


    /*设置引脚的输出类型为推挽输出*/
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  

    /*设置引脚为上拉模式*/
    GPIO_InitStruct.Pull  = GPIO_PULLUP;

    /*设置引脚速率为高速 */   
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		
    /*选择要控制的GPIO引脚*/															   		
		/*调用库函数，使用上面配置的GPIO_InitStructure初始化GPIO*/
    GPIO_InitStruct.Pin = L1_PIN;	
    HAL_GPIO_Init(L1_GPIO_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.Pin = L2_PIN;	
    HAL_GPIO_Init(L2_GPIO_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.Pin = L3_PIN;	
    HAL_GPIO_Init(L3_GPIO_PORT, &GPIO_InitStruct);	
		
		GPIO_InitStruct.Pin = L4_PIN;	
    HAL_GPIO_Init(L4_GPIO_PORT, &GPIO_InitStruct);
		
		
		
		GPIO_InitStruct.Pin = L5_PIN;	
    HAL_GPIO_Init(L5_GPIO_PORT, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = L6_PIN;	
    HAL_GPIO_Init(L6_GPIO_PORT, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = L7_PIN;	
    HAL_GPIO_Init(L7_GPIO_PORT, &GPIO_InitStruct);
		
		GPIO_InitStruct.Pin = L8_PIN;	
    HAL_GPIO_Init(L8_GPIO_PORT, &GPIO_InitStruct);
		

		return ;
	}
	
	
	
	
	
