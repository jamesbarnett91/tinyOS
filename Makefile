
CC = gcc
CFLAGS = -m32 -std=c99 -fno-stack-protector -Wno-builtin-declaration-mismatch

default: build

setup:
	mkdir -p bin

build: setup kernel/kernel.c kernel/global_descriptor_table.c kernel/gpu/text_mode/display.c kernel/io/keyboard/keyboard_handler.c kernel/kernel-bootstrap.asm
	nasm -f elf32 kernel/kernel-bootstrap.asm -o bin/kernel-bootstrap.o
	$(CC) $(CFLAGS) -c kernel/kernel.c -o bin/kernel.o
	$(CC) $(CFLAGS) -c kernel/global_descriptor_table.c -o bin/global_descriptor_table.o
	$(CC) $(CFLAGS) -c kernel/gpu/text_mode/display.c -o bin/text_mode_display.o
	$(CC) $(CFLAGS) -c kernel/io/keyboard/keyboard_handler.c -o bin/keyboard_handler.o
	$(CC) $(CFLAGS) -c os/main.c -o bin/main.o
	$(CC) $(CFLAGS) -c os/shell/shell.c -o bin/shell.o
	$(CC) $(CFLAGS) -c os/stdlib/stdlib.c -o bin/stdlib.o
	$(CC) $(CFLAGS) -c os/commands/echo.c -o bin/echo.o
	$(CC) $(CFLAGS) -c os/commands/files.c -o bin/files.o
	$(CC) $(CFLAGS) -c os/filesystem/ramfs.c -o bin/ramfs.o
	ld -m elf_i386 -T link.ld -o bin/kernel.bin bin/*.o

clean:
	rm -f bin/*
	rm -f boot-iso/boot/kernel.bin
	rm -f tinyOS.iso

run:
	cpulimit -l 20 qemu-system-i386 -kernel bin/kernel.bin

build-and-run: build run

iso: build
	cp bin/kernel.bin boot-iso/boot/
	grub-mkrescue -o tinyOS.iso boot-iso/