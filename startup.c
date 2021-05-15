

#include <stdint.h>


/* define the available mamory in our microcontroller */
#define START_SRAM					0x20000000u 
#define SIZE_SRAM					(192*1024)	
#define START_FLASH                 0x08000000u
#define SIZE_FLASH                  (2048*1024)
 
 
 
 /* this is the ens of SRAM also the is ths initialization of stack pointer because ARM stack pointer is descending  */ 
#define SRAM_END                    (START_SRAM+SIZE_SRAM)


/* symbols defined by linker import here for later use */
extern uint32_t end_of_text ;
extern uint32_t start_of_data ;
extern uint32_t end_of_data ;
extern uint32_t _strat_of_bss ;
extern uint32_t _end_of_bss ;

/* extren the main prototype to avoid compiler implicit define for prototype */
extern int main(void);




/* prototype for reset handler */ 
void RESET_Handler(void)__attribute__((section(".text")));

void NMI_Handler(void)__attribute__((weak,alias("Default_Handler"))); 
void HardFault_Handler(void)__attribute__((weak,alias("Default_Handler"))); 

/* vector table its work as array of pointers to functions */
uint32_t Vector_Table[]__attribute__((section(".vector"))) = 
{/* this is minimal configuration */
	SRAM_END,
	(uint32_t)&RESET_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,

};

void Default_Handler(void)
{
	
	while(1);
	
}


void RESET_Handler(void)  /* reset handler run  before main function to perform initialization MCU */
{
	
	uint32_t size = &end_of_data - &start_of_data ;
	uint8_t *PDst = (uint8_t*)&start_of_data ;
	uint8_t *PSrc = (uint8_t*)&end_of_text ;
	
	
	for(int i=0;i<size ;i++)
	{
		*PDst++ = *PSrc++;
	}
	size = &_end_of_bss - &_strat_of_bss ;	
	PDst = (uint8_t*)&_strat_of_bss ;
	PSrc = (uint8_t*)&end_of_text ;
	
	
	for(int i=0;i<size ;i++)
	{
		*PDst++ = 0;
	}	
	
	main();   /* jumb to mian functuion */ 
//	__asm__("bl main \n\t");
}