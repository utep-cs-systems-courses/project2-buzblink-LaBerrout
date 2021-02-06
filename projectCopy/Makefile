# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf 

#additional rules for files  ---reference to libTimer.h instead 
project.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o buzzer.o Main.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

led.o: led.c led.h

buzzer.o: buzzer.c buzzer.h

# missing the state_machines

switches.o: switches.c switches.h

clean:
	rm -f *.o *.elf

