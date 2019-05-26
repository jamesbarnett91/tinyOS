#include "../../interrupt_descriptor_table.h"
#include "../../gpu/text_mode/display.h"
#include "scancode_map.h"

extern void keyboard_handler(void);
extern char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);
extern void load_idt(unsigned long *idt_ptr);

struct idt_entry keyboard_idt[256];

void init_keyboard_idt()
{
  unsigned long keyboard_address;
  unsigned long idt_address;
  unsigned long idt_ptr[2];

  // Build IDT entry
  keyboard_address = (unsigned long) keyboard_handler;

  keyboard_idt[0x21].offset_lowerbits = keyboard_address & 0xffff;
  keyboard_idt[0x21].selector = 0x08; // Offset by 0x08
  keyboard_idt[0x21].zero = 0;
  keyboard_idt[0x21].type_attr = 0x8E; // Interrupt gate addr
  keyboard_idt[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

  idt_address = (unsigned long) keyboard_idt;
  idt_ptr[0] = (sizeof(struct idt_entry) * 256) + ((idt_address & 0xffff) << 16);
  idt_ptr[1] = idt_address >> 16;

  // Init PIC 1 @ 0x20
  write_port(0x20, 0x11);
  write_port(0x21, 0x20);
  write_port(0x21, 0x00);
  write_port(0x21, 0x01);
  write_port(0x21, 0xff);

  // PIC 2 @ 0xA0
  write_port(0xA0, 0x11);
  write_port(0xA1, 0x28);
  write_port(0xA1, 0x00);
  write_port(0xA1, 0x01);
  write_port(0xA1, 0xff);

  load_idt(idt_ptr);
}

void init_keyboard_handler()
{
  init_keyboard_idt();

  write_port(0x21, 0xFD);
}

int isKeyup(int scancode)
{
  return scancode & 0x80;
}

void handle_keypress() {

  // Ack the interrupt
  write_port(0x20, 0x20);

  unsigned char scancode = read_port(0x60);

  if(!isKeyup(scancode))
  {
    char pressed_key = scancode_map[scancode];
    switch(pressed_key)
    {
      case '\b':
        scrn_backspace();
        break;
      case '\n':
        scrn_newline();
        break;
      default:
        scrn_putchar(pressed_key);
    }
  }

}
