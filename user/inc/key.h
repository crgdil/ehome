#ifndef __KEY__
#define __KEY__

#define KEY1	(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
#define KEY2	!(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8))
#define KEY3	!(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10))

int KEY_Scan(void);
void KEY_Init(void);

#endif