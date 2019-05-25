bits 32                   ; nasm 32-bit mode
section .text

                          ; multiboot header
align 4
dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)  ; checksum

global flush_gdt
global read_port
global write_port
global load_idt
global keyboard_handler
global start

extern kernel_entrypoint
extern handle_keypress
extern gdt_pointer

flush_gdt:
	lgdt [gdt_pointer]
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:flush
flush:
  ret

read_port:
	mov edx, [esp + 4]
	in al, dx	
	ret

write_port:
	mov edx, [esp + 4]    
	mov al, [esp + 4 + 4]  
	out dx, al  
	ret

load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret

keyboard_handler:                 
	call handle_keypress
	iretd


start:
  cli
  mov esp, stack_space
  call kernel_entrypoint
  hlt

section .bss
resb 8192
stack_space: