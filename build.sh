#!/bin/bash
mkdir -p bin
rm -f bin/*
nasm -f elf32 kernel-bootstrap.asm -o bin/kernel-bootstrap.o
gcc -m32 -std=c99 -c kernel.c -o bin/kernelc.o
ld -m elf_i386 -T link.ld -o bin/kernel bin/kernel-bootstrap.o bin/kernelc.o
