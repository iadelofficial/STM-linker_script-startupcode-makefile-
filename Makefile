 #****************************************************************************
 #
 # File Name: Makefile.mak
 #
 # Description: makefile
 #
 # Author: Islam Adel
 #
 # Created on: Feb 6, 20222
 #
 #*****************************************************************************
CC=arm-none-eabi-gcc
MACH=cortex-m3
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T STM32_LS.ld -Wl,-Map=final.map

all:main.o led.o STM32_startup.o syscalls.o final.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^

STM32_startup.o:STM32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf:main.o led.o STM32_startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf
	
