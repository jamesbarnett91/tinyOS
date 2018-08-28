#include "./io/text_mode_diplay.h"

void run_kern()
{
  clear_screen();

  print_ln("I am a kernel!");
  print("I am on a new line");
  print(" - I am not");
}

void kernel_entrypoint()
{
  run_kern();
}
