#include "includes.h"


void systick_delayms(int nms)
{	
	//1，选择时钟源：外部时钟源--9MHZ
	SysTick->CTRL &=~(1<<2);
	//2，设置重装载数值寄存器的数值（决定了计数个数）
	SysTick->LOAD = nms*9000;
	//3，先将当前值寄存器清0，防止干扰下一次的定时
	SysTick->VAL = 0;
	//4，使能定时器，开始计数
	SysTick->CTRL |= (1<<0);
	//5，等待定时时间到
	//1）查询标志位
	while(!(SysTick->CTRL &(1<<16)));
	//2）读取当前值寄存器的数值是否倒数到0
	//while(SysTick->VAL !=0);
	//6，关闭定时器：防止定时器资源消耗
	SysTick->CTRL &=~(1<<0);
}

void systick_delayus(int nus)
{	
	//1，选择时钟源：外部时钟源--9MHZ
	SysTick->CTRL &=~(1<<2);
	//2，设置重装载数值寄存器的数值（决定了计数个数）
	SysTick->LOAD = nus*9;
	//3，先将当前值寄存器清0，防止干扰下一次的定时
	SysTick->VAL = 0;
	//4，使能定时器，开始计数
	SysTick->CTRL |= (1<<0);
	//5，等待定时时间到
	//1）查询标志位
	while(!(SysTick->CTRL &(1<<16)));
	//2）读取当前值寄存器的数值是否倒数到0
	//while(SysTick->VAL !=0);
	//6，关闭定时器：防止定时器资源消耗
	SysTick->CTRL &=~(1<<0);
}
