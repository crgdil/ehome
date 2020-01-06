#ifndef __DHT11__
#define __DHT11__

#include "includes.h"

#define	DHT11_Out_L		GPIOB->ODR &=~(1<<3)
#define	DHT11_Out_H		GPIOB->ODR |=~(1<<3)
#define	DHTT11_IN		(GPIOB->IDR &(1<<3))

u8 DHT11_init(void);
void DHT11_Get_Data(u8 *RH,u8 *Temp);


#endif