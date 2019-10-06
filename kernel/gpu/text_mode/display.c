#include "colours.h"

#define COLS (80 * 2) // 2 bytes per char
#define ROWS 25
#define FRAME_SIZE (ROWS * COLS)

char *video_ram = (char *) 0xB8000;
int cursor_pos = 0;
int char_attribute_byte = 0x0F;

extern void write_port(unsigned short port, unsigned char data);
extern char read_port(unsigned short port);

void scrn_enable_cursor(unsigned char start_line, unsigned char end_line)
{
	write_port(0x3D4, 0x0A);
	write_port(0x3D5, (read_port(0x3D5) & 0xC0) | start_line);
 
	write_port(0x3D4, 0x0B);
	write_port(0x3D5, (read_port(0x3D5) & 0xE0) | end_line);
}

void scrn_update_csr()
{
    unsigned short csr = cursor_pos/2;
    write_port(0x3D4, 14);
    write_port(0x3D5, csr >> 8);
    write_port(0x3D4, 15);
    write_port(0x3D5, csr);
}

void scrn_clear()
{
  for (int i = 0; i < FRAME_SIZE; i = i + 2)
  {
    video_ram[i] = 0;
    video_ram[i + 1] = char_attribute_byte;
  };
  cursor_pos = 0;
}

void scrn_set_text_colour(int foreground, int background) 
{
  char_attribute_byte = (background << 4) | foreground;
}

int scrn_get_char_attr_byte() {
  return char_attribute_byte;
}

void scrn_set_char_attr_byte(int byte) {
 char_attribute_byte = byte;
}

void scrn_putchar(unsigned char c)
{
  video_ram[cursor_pos++] = c;
  video_ram[cursor_pos++] = char_attribute_byte;
  scrn_update_csr();
}

// TODO - jump cursor to prev non 0 text char rather than reversing through whole array
void scrn_backspace()
{
  if (cursor_pos != 0) 
  {
    video_ram[--cursor_pos] = char_attribute_byte;
    video_ram[--cursor_pos] = 0;
    scrn_update_csr();
  }
}

void scrn_newline()
{
  int current_line = cursor_pos / COLS;
  cursor_pos = (current_line + 1) * COLS;
  scrn_update_csr();
}

void scrn_print(char *msg)
{
  int j = 0;
  while (msg[j] != '\0')
  {
    video_ram[cursor_pos++] = msg[j];
    video_ram[cursor_pos++] = char_attribute_byte;
    ++j;
  }
  scrn_update_csr();
}

void scrn_println(char *msg)
{
  scrn_print(msg);
  scrn_newline();
}

void scrn_set_cursor_pos(unsigned int row, unsigned int col)
{
  cursor_pos = (row * COLS) + (col * 2);
  scrn_update_csr();
}

int scrn_get_cursor_row()
{
  // 0 index
  return cursor_pos / COLS;
}

int scrn_get_cursor_col()
{
  return (cursor_pos % COLS)/2;
}