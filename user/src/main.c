#include "includes.h"
extern void USART1_Sendbyte(u8 data);
int main(void)
{
	u8 RH=0,Temp=0;
	GPIO_init();
	KEY_Init();
	USART1_init(9600);

	while(DHT11_init())
	{
		systick_delayms(500);
	}
	systick_delayms(500);
	systick_delayms(500);
	systick_delayms(500);
	while(1)
	{
		DHT11_Get_Data(&RH,&Temp);
		printf("RH=%d	Temp=%d\r\n",RH,Temp);
		systick_delayms(500);
	}
	
	while(1)
	{	
		printf("RH=%d	Temp=%d\r\n",RH,Temp);
		systick_delayms(1000);
		
	}
}