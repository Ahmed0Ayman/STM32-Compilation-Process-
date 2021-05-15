CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 

LDFLAGS= -nostdlib -T STM32.ld -Wl,-Map=final.map

all:main.o startup.o final.elf
	
main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

startup.o: startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf:main.o startup.o 
	$(CC) $(LDFLAGS) -o $@ $^
	
clean:
	rm -rf *.o *.elf
	
	