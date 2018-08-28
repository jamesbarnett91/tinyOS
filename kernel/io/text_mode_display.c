#define COLS 80
#define ROWS 25
#define FRAME_SIZE (ROWS * COLS * 2) // 2 bytes per char

char *video_ram = (char *)0xB8000;
int cursor_pos = 0;

void clear_screen()
{
  for (int i = 0; i < FRAME_SIZE; i = i + 2)
  {
    video_ram[i] = ' ';
    video_ram[i + 1] = 0x07;
  };
  cursor_pos = 0;
}

void print(char *msg)
{
  int j = 0;
  while (msg[j] != '\0')
  {
    video_ram[cursor_pos++] = msg[j];
    video_ram[cursor_pos++] = 0x07;
    ++j;
  }
}

void print_ln(char *msg)
{
  print(msg);
  int current_line = cursor_pos / COLS;
  cursor_pos = (current_line + 1) * (COLS*2);
}
