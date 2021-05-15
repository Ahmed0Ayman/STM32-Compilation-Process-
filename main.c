
#define RCC_AHB1_R      		*((volatile unsigned int  *)0x40023830u)
#define GPIO_MODE_R      		*((volatile unsigned int  *)0x40021800u)
#define GPIO_PUPDR_R      		*((volatile unsigned int  *)0x4002180cu)
#define GPIO_ODR_R      		*((volatile unsigned int  *)0x40021814u)

#define GPIOG_RCC_EN  			(1<<6u)


#define RED_LED                 (1<<13u)
#define REG_GREED 				(1<<14u)

unsigned int  data1[20];

static unsigned int  data2[20];

int main(void)
{


	RCC_AHB1_R  |=	GPIOG_RCC_EN ;

	GPIO_MODE_R  |=	1<<(2*13);
	GPIO_PUPDR_R |= 2<<(2*13);






	while(1)
	{
		GPIO_ODR_R |= 1<<13u;
		for(int i=0 ;i<1000000;i++);
		GPIO_ODR_R  = 0;
		for(int i=0 ;i<1000000;i++);

	}






	return 0;
}
