#include "includes.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef KEY1_InitStructure,KEY2_InitStructure,KEY3_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA,ENABLE);
	KEY1_InitStructure.GPIO_Pin = GPIO_Pin_0;
	KEY1_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &KEY1_InitStructure);
	KEY2_InitStructure.GPIO_Pin = GPIO_Pin_8;
	KEY2_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &KEY2_InitStructure);
	KEY3_InitStructure.GPIO_Pin = GPIO_Pin_10;
	KEY3_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &KEY3_InitStructure);	
}

int KEY_Scan(void)
{
	if(KEY1)//按下按键时，判定第一次贴合成功
	{
		systick_delayms(20);//延时，越过抖动区域，进而提高成功率
		if(KEY1)//在延时结束后，再次判定按键是否仍处于按下贴合状态
		{
			while(KEY1);//等待按键松开，反向判定，松开前按键是一直被按下的
			return 1;
		}
	}
	else if(KEY2)//按下
	{
		systick_delayms(20);//延时，越过抖动区域，进而提高成功率
		if(KEY2)//在按键松开之前，再次判定按键是否仍处于按下贴合状态
		{
			while(KEY2);//等待按键松开，反向判定，松开前按键是一直被按下的
			return 2;
		}
	}
	else if(KEY3)//按下
	{
		systick_delayms(20);//延时，越过抖动区域，进而提高成功率
		if(KEY3)//在按键松开之前，再次判定按键是否仍处于按下贴合状态
		{
			while(KEY3);//等待按键松开，反向判定，松开前按键是一直被按下的
			return 3;
		}
	}

	return 0;
	
}