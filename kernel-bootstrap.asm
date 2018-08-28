bits 32                   ; nasm 32-bit mode
section .text

                          ; multiboot header
align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)  ; checksum

global start
extern kernel_entrypoint

                          ; call kernel and halt
start:
  cli                     ; disable interrups
  mov esp, stack_space
  call kernel_entrypoint
  hlt

section .bss
resb 8192
stack_space: