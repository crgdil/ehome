#include "includes.h"

void DHT11_IO_Out(void)
{
	
}



void DHT11_Start(void)
{
	//???????
	DHT11_IO_Out();
	//????
	DHT11_Out_L;
	//??????18ms
	systick_delayms(20);
	//????
	DHT11_Out_H;
	//????20~40us
	systick_delayus(30);
}





u8 DHT11_init(void)
{
	DHT11_Start();
	return DHT11_Answer();
}