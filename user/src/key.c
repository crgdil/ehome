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
	if(KEY1)//���°���ʱ���ж���һ�����ϳɹ�
	{
		systick_delayms(20);//��ʱ��Խ���������򣬽�����߳ɹ���
		if(KEY1)//����ʱ�������ٴ��ж������Ƿ��Դ��ڰ�������״̬
		{
			while(KEY1);//�ȴ������ɿ��������ж����ɿ�ǰ������һֱ�����µ�
			return 1;
		}
	}
	else if(KEY2)//����
	{
		systick_delayms(20);//��ʱ��Խ���������򣬽�����߳ɹ���
		if(KEY2)//�ڰ����ɿ�֮ǰ���ٴ��ж������Ƿ��Դ��ڰ�������״̬
		{
			while(KEY2);//�ȴ������ɿ��������ж����ɿ�ǰ������һֱ�����µ�
			return 2;
		}
	}
	else if(KEY3)//����
	{
		systick_delayms(20);//��ʱ��Խ���������򣬽�����߳ɹ���
		if(KEY3)//�ڰ����ɿ�֮ǰ���ٴ��ж������Ƿ��Դ��ڰ�������״̬
		{
			while(KEY3);//�ȴ������ɿ��������ж����ɿ�ǰ������һֱ�����µ�
			return 3;
		}
	}

	return 0;
	
}