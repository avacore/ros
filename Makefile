PREFIX := /home/avacore/scratch/rpi-cross/install/bin/arm-eabi-

CFLAGS := -Wall --std=gnu99 -O2 -fdata-sections -ffunction-sections
CXXFLAGS := -Wall --std=gnu++0x -O2 -fdata-sections -ffunction-sections -fno-exceptions

OBJS := start.o drivers/gpio.o test.o

all:	kernel.img

install: kernel.img
	cp $< /media/0FD6-C103/$<

kernel.img:	first32k.bin kernel.pimg
	cat $? > $@

kernel.pimg:	kernel.elf
	$(PREFIX)objcopy --output-target binary $? $@

kernel.elf:	$(OBJS)
	$(PREFIX)ld -e entry -no-stdlib --gc-sections -o $@ $?

%.o:	%.c
	$(PREFIX)gcc $(CFLAGS) -o $@ -c $?

%.o:	%.cpp
	$(PREFIX)g++ $(CXXFLAGS) -o $@ -c $?

%.o:	%.S
	$(PREFIX)as -o $@ $?

clean:
	-rm kernel.img kernel.pimg kernel.elf $(OBJS)