#include "includes.h"

void My_NVIC_init(IRQn_Type IRQn,u32 PG,u32 PP,u32 SP)
{
	uint32_t priority ;
	NVIC_SetPriorityGrouping(PG);
	priority = NVIC_EncodePriority(PG,PP,SP);
	NVIC_SetPriority (IRQn,priority);
	NVIC_EnableIRQ (IRQn);
}

void USART1_init(int baud_rate)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	USART_InitTypeDef usart_init;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                                   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA , &GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                     
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;    
	GPIO_Init(GPIOA , &GPIO_InitStructure);

	usart_init.USART_BaudRate            = baud_rate;
	usart_init.USART_WordLength          = USART_WordLength_8b;
	usart_init.USART_StopBits            = USART_StopBits_1;
	usart_init.USART_Parity              = USART_Parity_No ;
	usart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart_init.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_Init(USART1, &usart_init);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	My_NVIC_init(USART1_IRQn,7-3,7,1); 	
	
	USART_Cmd(USART1,ENABLE);
}

void USART1_Sendbyte(u8 data)
{
	//�ȴ��������ݵ�״̬��־λ�����ˣ���1��
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	//���������״̬��־λ
	//��ʼ�������ݣ�ֻ��Ҫ�����ݼĴ���������ݼ���
	USART_SendData(USART1,data); 
}

u8 USART1_Recvbyte(USART_TypeDef * pUSARTx)
{
	u8 data=0;
	//�ȴ��������ݵ�״̬��־λ�����ˣ���1��
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) != SET);
	//���������״̬��־λ
	//��ʼ�������ݣ�ֻ��Ҫ�����ݼĴ�����ȡ���ݼ���
	data = USART_ReceiveData(USART1);
	return  data; 
}

void Usart_SendString( USART_TypeDef * pUSARTx, char *str)
{
	unsigned int k=0;
	do 
	{
		USART1_Sendbyte(*(str+k));		
		k++;
	} while(*(str + k)!='\0');
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);             
}

void USART1_RecvString(USART_TypeDef * pUSARTx,u8 *str)
{
	*str = USART1_Recvbyte(pUSARTx);
	while(*str != '\0'&&*str != '\r'&&*str != '\n')
	{
		str++;
		*str = USART1_Recvbyte(pUSARTx);
	}
//	*(++str) = '\n';
	*(++str) = '\0';
}
	
void USART1_IRQHandler(void)
{
	u8 buf[100]={0};
	if(USART1->SR & (1<<5))//�ж��ж��¼��Ƿ���
	{
		//���жϱ�־λ
		USART1_RecvString(USART1,buf);		
		Usart_SendString(USART1,(char*)buf);
		
		if(strncmp((char*)buf,"LED1_FZ",7)==0)
		{
			LED1_FZ;
		}	
	}	
}

int fputc(int ch, FILE *f) {
	USART1_Sendbyte(ch);//�����滻Ϊ�Լ������У����ڷ��͵��ֽڵĺ���
  return (ch);
}
