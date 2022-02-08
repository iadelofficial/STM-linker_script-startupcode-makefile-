 /****************************************************************************
 *
 * File Name: STM32_startup.c
 *
 * Description: startup code  for STM32F103C4
 *
 * Author: Islam Adel
 *
 * Created on: Feb 4, 20222
 *
 *****************************************************************************/
#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (20*1024) /*20 kB*//* 20 it is specific for stmf103c mc*/
#define SRAM_END ((SRAM_START)+(SRAM_SIZE))

/* extern boundries of sections to apply Reset_Handler function */

extern uint32_t end_of_text;
extern uint32_t start_of_data;
extern uint32_t end_of_data;
extern uint32_t start_of_bss;
extern uint32_t end_of_bss;
extern uint32_t load_address_of_data ;

/* prototype of main */

int main (void);
/*prototype of std lib */
void __libc_init_array(void);

/* el STACK b tbda2 men el end of SRAM */
#define STACK_START SRAM_END


	/* prototype of reset handler function */
void Reset_Handler(void) ;
/*leh 3malna modo3 el alias da 3shan itdoesnot make sense to creat function for eacj one of them */
/*leh 3malna weak 3lshan programmer can override and make the exact function for handler functions */
/* for that the programmer can implement the real impelementation of handling that exceptions */

  /* prototype of non maskable interrupt. The RCC Clock Security System (CSS) is linked to the NMI vector handler function */
void NMI_Handler											(void)	__attribute__ ((weak,alias ("Default_Handler")));
	/* prototype of All class of fault handler function */
void HardFault_Handler								(void)	__attribute__ ((weak,alias ("Default_Handler")));	
	/* prototype of Memory management handler function */
void MemManage_Handler								(void)	__attribute__ ((weak,alias ("Default_Handler"))); 				
	/* prototype of Prefetch fault, memory access fault handler function */
void BusFault_Handler									(void)	__attribute__ ((weak,alias ("Default_Handler"))); 				
	/* prototype of Undefined instruction or illegal state handler function */
void UsageFault_Handler								(void)	__attribute__ ((weak,alias ("Default_Handler"))); 			
	/* prototype of System service call via SWI instructio handler function */
void SVC_Handler											(void)	__attribute__ ((weak,alias ("Default_Handler"))); 					
	/* prototype of Debug Monitor handler function */
void DebugMon_Handler									(void)	__attribute__ ((weak,alias ("Default_Handler"))); 				
	/* prototype of Pendable request for system service handler function */
void PendSV_Handler										(void)	__attribute__ ((weak,alias ("Default_Handler")));   				
	/* prototype of System tick timer handler function */
void SysTick_Handler									(void)	__attribute__ ((weak,alias ("Default_Handler")));

void WWDG_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMPER_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler"))); 
void FLASH_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));             
void RCC_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_channel0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_channel1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_channel2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_channel3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_channel4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_channel5_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_channel6_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));  
void DMA1_channel7_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler"))); 
void ADC1_2_IRQHandler 								(void) __attribute__ ((weak, alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void USB_HP_CAN_RX0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));    
void CAN_RX1_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN_SCE_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI9_5_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_IRQHandler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 							(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  								(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 									(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  							(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  							(void) __attribute__ ((weak, alias("Default_Handler")));        
void USART3_IRQHandler   							(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   					(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTCAlarm_IRQHandler    					(void) __attribute__ ((weak, alias("Default_Handler")));    
void USBWakeup_IRQHandler     				(void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_BRK_IRQHandler   						(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler    						(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler          			(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC3_IRQHandler     							(void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler             			(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             			(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             			(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             			(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler            			(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler            			(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_IRQHandler         					(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler             			(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel0_IRQHandler     		(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler     		(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler     		(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler     		(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Channel4_5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
      


/* creat an array to hold MSP and handlers address */
/* first addres STACK the we will go to vector table in data sheet to get another addresses*/
/* casting of Reset_handler because itis a function pointer but the array is unit32_t so i make casting*/
/* we donot want to put this data in .data section so we will tell the compile to donot so that using compiler attribute */
/* go to documentation of compiler ->variable attribute->section */
/*this is the form that tell compiler donot do that 
*	struct duart a __attribute__ ((section ("DUART_A"))) = { 0 };
* the "DUART_A" is the section name u want ur compiler to save this data on it  
*/
uint32_t vectors[] __attribute__ ((section (".isr_vector")))={
	STACK_START,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,
	(uint32_t)WWDG_IRQHandler,
	(uint32_t)PVD_IRQHandler,
	(uint32_t)TAMPER_IRQHandler,
	(uint32_t)RTC_IRQHandler,
	(uint32_t)FLASH_IRQHandler,
	(uint32_t)RCC_IRQHandler,
	(uint32_t)EXTI0_IRQHandler,
	(uint32_t)EXTI1_IRQHandler,
	(uint32_t)EXTI2_IRQHandler,
	(uint32_t)EXTI3_IRQHandler,
	(uint32_t)EXTI4_IRQHandler,
	(uint32_t)DMA1_channel0_IRQHandler,
	(uint32_t)DMA1_channel1_IRQHandler,
	(uint32_t)DMA1_channel2_IRQHandler,
	(uint32_t)DMA1_channel3_IRQHandler,
	(uint32_t)DMA1_channel4_IRQHandler,
	(uint32_t)DMA1_channel5_IRQHandler,
	(uint32_t)DMA1_channel6_IRQHandler,
	(uint32_t)DMA1_channel7_IRQHandler,
	(uint32_t)ADC1_2_IRQHandler,
	(uint32_t)USB_HP_CAN_TX_IRQHandler,
	(uint32_t)USB_HP_CAN_RX0_IRQHandler,
	(uint32_t)EXTI9_5_IRQHandler,
	(uint32_t)TIM1_BRK_IRQHandler,
	(uint32_t)TIM1_UP_IRQHandler,
	(uint32_t)TIM1_TRG_COM_IRQHandler,
	(uint32_t)TIM1_CC_IRQHandler,
	(uint32_t)TIM2_IRQHandler,
	(uint32_t)TIM3_IRQHandler,
	(uint32_t)TIM4_IRQHandler,
	(uint32_t)I2C1_EV_IRQHandler,     
	(uint32_t)I2C1_ER_IRQHandler,     
	(uint32_t)I2C2_EV_IRQHandler,     
	(uint32_t)I2C2_ER_IRQHandler,     
	(uint32_t)SPI1_IRQHandler,        
	(uint32_t)SPI2_IRQHandler,        
	(uint32_t)USART1_IRQHandler,      
	(uint32_t)USART2_IRQHandler,      
	(uint32_t)USART3_IRQHandler,
	(uint32_t)EXTI15_10_IRQHandler,	
	(uint32_t)RTCAlarm_IRQHandler,
	(uint32_t)USBWakeup_IRQHandler,
	(uint32_t)TIM8_BRK_IRQHandler,
	(uint32_t)TIM8_UP_IRQHandler,
	(uint32_t)TIM8_TRG_COM_IRQHandler,
	(uint32_t)TIM8_CC_IRQHandler,
	(uint32_t)ADC3_IRQHandler,
	(uint32_t)FSMC_IRQHandler,        
	(uint32_t)SDIO_IRQHandler,        
	(uint32_t)TIM5_IRQHandler,        
	(uint32_t)SPI3_IRQHandler,        
	(uint32_t)UART4_IRQHandler,       
	(uint32_t)UART5_IRQHandler,      
	(uint32_t)TIM6_IRQHandler,
	(uint32_t)TIM7_IRQHandler,
	(uint32_t)DMA2_Channel0_IRQHandler,
	(uint32_t)DMA2_Channel1_IRQHandler,
	(uint32_t)DMA2_Channel2_IRQHandler,
	(uint32_t)DMA2_Channel3_IRQHandler,
	(uint32_t)DMA2_Channel4_5_IRQHandler	

};
void Default_Handler(void)
{
	while(1);
	
}
void Reset_Handler(void)
{
	/* copy .data section to SRAM*/
	
	uint32_t Size_Of_Data_Section = ((uint32_t)&end_of_data)-((uint32_t)&start_of_data); 
	
	uint8_t *pSrc=(uint8_t*)&load_address_of_data; /* FLASH */ /* we donot use end_of_text symbol */
	/*because after we use syd lib this symbol doesnot pointer to the first address of data section */
	uint8_t *pDst=(uint8_t*)&start_of_data; /* SRAM */
	
	/* now i will copy every byte ,byte by byte from source 'FLASH' to destinatio 'SRAM' */
	
	for (uint32_t location= 0; location< Size_Of_Data_Section ;location++)
	{
		*pDst++=*pSrc++;
		
	}
	

	/*Init the .bss section to zero in SRAM*/
	
	uint32_t Size_Of_Bss_Section = ((uint32_t)&end_of_bss)-((uint32_t)&start_of_bss); 
	
	pDst=(uint8_t*)&start_of_bss;
	
	/* now i will zero every byte ,byte by byte in bss section SRAM */
	for (uint32_t location= 0; location< Size_Of_Bss_Section ;location++)
	{
		*pDst++=0;
		
	}
	
	/*call init function of std.library*/
	/*you do that if u use a standared library in your code like {scanf ,printf.... }*/
	
	__libc_init_array();

	/*call main ()*/
	main();


}
