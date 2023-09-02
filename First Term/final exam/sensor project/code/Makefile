CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2 -g
INCS=-I .
LIBS= 
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
project_name=sensor_project

all: $(project_name).bin
	@echo "==========Done=========="

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) -mthumb $< -o $@


$(project_name).elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	@echo "==========All Deleted=========="

clean:
	rm *.elf *.bin
	@echo "==========Elf & Bin Deleted=========="