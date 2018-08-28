
#define FRAME_SIZE (80 * 25 * 2) // 80 cols, 25 rows, 2 bytes per char

char *video_ram = (char *) 0xB8000;
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


void run_kern()
{
  clear_screen();

  print("I am a kernel!");
  print(" another message");
}

void kernel_entrypoint()
{
  run_kern();
}
