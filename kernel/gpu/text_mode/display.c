#include "colours.h"

#define COLS (80 * 2) // 2 bytes per char
#define ROWS 25
#define FRAME_SIZE (ROWS * COLS)

char *video_ram = (char *) 0xB8000;
int cursor_pos = 0;
int char_attribute_byte = 0x07;

void scrn_clear()
{
  for (int i = 0; i < FRAME_SIZE; i = i + 2)
  {
    video_ram[i] = ' ';
    video_ram[i + 1] = char_attribute_byte;
  };
  cursor_pos = 0;
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
}

void scrn_println(char *msg)
{
  scrn_print(msg);
  int current_line = cursor_pos / COLS;
  cursor_pos = (current_line + 1) * COLS;
}

void scrn_set_text_colour(int foreground, int background) 
{
  char_attribute_byte = (background << 4) | foreground;
}

void scrn_putchar(unsigned char byte)
{
  video_ram[cursor_pos++] = byte;
  video_ram[cursor_pos++] = char_attribute_byte;
}

// TODO - jump cursor to prev non 0 text char rather than reversing through whole array
void scrn_backspace()
{
  if (cursor_pos != 0) 
  {
    video_ram[--cursor_pos] = char_attribute_byte;
    video_ram[--cursor_pos] = 0;
  }
}

void scrn_newline()
{
  int current_line = cursor_pos / COLS;
  cursor_pos = (current_line + 1) * COLS;
}