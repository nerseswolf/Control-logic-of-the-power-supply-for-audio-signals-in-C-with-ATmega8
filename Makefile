## ####
## Makefile for generic avr-projects using avr-gcc and avrdude
## Dependencies: avr-libc, avr-gcc, avr binutils, avrdude
## Run as su, or add user to uucp-group
## For further details and options, try the man pages for avr-gcc and avrdude
## Authors: Stefan Bauroth, Jonathan Schosztak, Marc Dreilich
## ####

# Add all needed object files here
objects := main.o 
# Define which microcontroller we use...
mmcu := atmega8
#...and which programmer.(Use avrisp2 for the standard mkII)
programmer := avrisp2

%.o: %.c
	avr-gcc -Os -std=c99 -mmcu=$(mmcu) -c $< -o $@ -Wextra
	
#Define default behaviour for "make"-command
default:        all clean all program

#Define how avr-gcc should compile the program-code
all: $(objects)
	avr-gcc -std=c99 -mmcu=$(mmcu) $(objects) -o output.elf -Wextra
	avr-objcopy -O ihex -j .text -j .data output.elf output.hex
	avr-size -C --mcu=$(mmcu) output.elf

#Define how avrude should flash the code onto the device und where to
program: all
	avrdude -p $(mmcu) -c $(programmer) -Uflash:w:output.hex:a
	
#Define cleanup for old object- and elf-files
clean:
	rm $(objects)
	rm output.elf
