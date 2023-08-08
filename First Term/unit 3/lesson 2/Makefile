CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)

all: lab1.bin
	
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) -g $< -o $@

%.o: %.c
	$(CC)gcc.exe -c -g $(INCS) $(CFLAGS) $< -o $@


lab1.elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) startup.o $(OBJ) -o $@ -Map=Map_file.map

lab1.bin: lab1.elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin