#ifndef __USART__
#define __USART__
#include "includes.h"



void USART1_init(int baud_rate);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void USART1_Recvstr(u8 *str);

#endif