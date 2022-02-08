 /****************************************************************************
 *
 * File Name: STM32_LS.ld
 *
 * Description: Linker Script for STM32F103C4
 *
 * Author: Islam Adel
 *
 * Created on: Feb 6, 20222
 *
 *****************************************************************************/
ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx) :ORIGIN =0x08000000,LENGTH =128K
	SRAM(rwx) :ORIGIN =0x20000000,LENGTH =20K

}
/* make sure when u write symbol "[name][space]=[space][value][semicloun]"
*example : end_of_text = .; */
SECTIONS
{
	.text :
	{
		*(.ist_vector)
		*(.text) /*of main.o led.o startup.o*/
		*(.text.*)/*this line because stander lib add alot of text section and we wanna put it in comman section */		
		/* these comming section are pure code "i know that because the VMA and LMA have same address"section */
		/*so we can put them in text section */
		*(.init)
		*(.fini)
		*(.rodata)
		*(.rodata.*)/*this line because stander lib add alot of rodata section and we wanna put it in comman section */
		/* we know it is bad the section start from not aligned address and linker donot care */
		/*so we should force linker to make that satrt of section aligned address*/
		/* we know the 'end_of_text ' symbol is the start of .data section in flash */
		/*so 'end_of_text 'should aligned address*/ 
		. = ALIGN(4);/* we do that to force the linker to align the address of 'end_of_text'*/
		end_of_text = .;	 /* store the updated location counter value in  a symbol 'end_of_text; */ 
		/* (.) is the location counter thatis incremented by the size of output section */
		/* at the beginning the 'end_of_text ' is equal VMA 'ORIGIN of flash ' but after .text section it hold the address of end of text section*/
	}> FLASH 
	/* because of std lib the end of text section now not be the start of data section */
	/* so we should add symbole to start copy data from FLASH to SRAM*/
	load_address_of_data = LOADADDR(.data);/* this symbol i will use it to start copy data from it */
	.data :
	{
		start_of_data = .;  	/* location counter alwayes tracks VMA of the section of the section in which it is begin to used */
		*(.data)
		*(.data.*)/*this line because stander lib add alot of data section and we wanna put it in comman section */
		. = ALIGN(4);/* we do that to force the linker to align the address of 'end_of_data'*/
		/*because it will be the beginning of bss dection in SRAM */
		end_of_data = .;   /* it hold the address of end of data section*/
	}> SRAM AT> FLASH
	
	.bss :
	{
		start_of_bss = .;
		__bss_start__ = start_of_bss;/* this because crt0.o want that symbol */
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);/* we do that to force the linker to align the address of 'end_of_bss'*/
		end_of_bss = .;
		__bss_end__ = end_of_bss;/* this because crt0.o want that symbol */
		. = ALIGN(4);/* because heap section come after bss section */
		end = .;/* this symbole help to mange memory 'start of heap'*/
		/* that symbole is used by sbrk function in syscalls.c file */
	
	}> SRAM	

}