#ifndef __GPIO__
#define __GPIO__

#define	LED1_FZ		GPIOA->ODR ^= (1<<11)
void GPIO_init(void);

#endif