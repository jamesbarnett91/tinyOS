#!/bin/bash

# TODO - proper makefile

rm -rf bin/kernel/*
mkdir -p bin/kernel/io/vga
nasm -f elf32 kernel/kernel-bootstrap.asm -o bin/kernel-bootstrap.o
gcc -m32 -std=c99 -c kernel/kernel.c -o bin/kernel/kernel.o
gcc -m32 -std=c99 -c kernel/io/vga/text_mode_display.c -o bin/kernel/io/vga/text_mode_display.o
ld -m elf_i386 -T link.ld -o bin/kern bin/kernel-bootstrap.o bin/kernel/kernel.o bin/kernel/io/vga/text_mode_display.o
#ld -m elf_i386 -T link.ld -o bin/kern bin/kernel-bootstrap.o bin/**/*.o