# include "delay.h"


static uint16_t fac_us = 0;
static uint32_t fac_ms = 0;

void delay_init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	fac_us = SystemCoreClock / 1000000;
	//fac_us = 180;
	fac_ms = SystemCoreClock / 1000;
}

void delay_us(uint16_t delay)
{
	u32 temp;	    	 
	SysTick->LOAD=delay*fac_us; 					//ʱ�����	  		 
	SysTick->VAL=0x00;        					//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����	  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;      					 //��ռ�����	
}

void delay_ms(uint16_t delay)
{
	u32 temp;		
	uint16_t i;
	for(i = 0;i < delay;i++)
	{
		SysTick->LOAD=(u32)fac_ms;				//ʱ�����(SysTick->LOADΪ24bit)
		SysTick->VAL =0x00;							//��ռ�����
		SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����  
		do
		{
			temp=SysTick->CTRL;
		}while((temp&0x01)&&!(temp&(1<<16)));		//�ȴ�ʱ�䵽��   
		SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
		SysTick->VAL =0X00;       					//��ռ�����	
	}	 
}


