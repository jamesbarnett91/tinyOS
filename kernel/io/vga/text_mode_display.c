#include "colours.h"

#define COLS (80 * 2) // 2 bytes per char
#define ROWS 25
#define FRAME_SIZE (ROWS * COLS)

char *video_ram = (char *)0xB8000;
int cursor_pos = 0;
int char_attribute_byte = 0x07;

void clear_screen()
{
  for (int i = 0; i < FRAME_SIZE; i = i + 2)
  {
    video_ram[i] = ' ';
    video_ram[i + 1] = char_attribute_byte;
  };
  cursor_pos = 0;
}

void print(char *msg)
{
  int j = 0;
  while (msg[j] != '\0')
  {
    video_ram[cursor_pos++] = msg[j];
    video_ram[cursor_pos++] = char_attribute_byte;
    ++j;
  }
}

void print_ln(char *msg)
{
  print(msg);
  int current_line = cursor_pos / COLS;
  cursor_pos = (current_line + 1) * COLS;
}

void set_text_colour(int foreground, int background) 
{
  char_attribute_byte = (background << 4) | foreground;
}