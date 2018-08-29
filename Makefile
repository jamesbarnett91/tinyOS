
CC = gcc
CFLAGS = -m32 -std=c99 

default: build

setup:
	mkdir -p bin

build: setup kernel/kernel.c kernel/io/vga/text_mode_display.c kernel/kernel-bootstrap.asm
	nasm -f elf32 kernel/kernel-bootstrap.asm -o bin/kernel-bootstrap.o
	$(CC) $(CFLAGS) -c kernel/kernel.c -o bin/kernel.o
	$(CC) $(CFLAGS) -c kernel/io/vga/text_mode_display.c -o bin/text_mode_display.o
	ld -m elf_i386 -T link.ld -o bin/kernel bin/*.o

clean:
	rm -f bin/*

run:
	qemu-system-i386 -kernel bin/kernel

build-and-run: build run