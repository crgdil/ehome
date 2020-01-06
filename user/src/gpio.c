#include "includes.h"



void GPIO_init(void)
{
	GPIO_InitTypeDef GPIOB_InitStructure,GPIOA_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA,ENABLE);
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_11;
  GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOB_InitStructure);
	
	GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_InitStructure);
}


