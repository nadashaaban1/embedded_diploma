CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
project_name=lab2

all: $(project_name).bin
	


%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) -mthumb $< -o $@


$(project_name).elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin