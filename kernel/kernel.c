#include "./io/vga/text_mode_diplay.h"
#include "./io/vga/colours.h"

void run_kern()
{
  clear_screen();

  print_ln("I am a kernel!");
  set_text_colour(COLOUR_WHITE, COLOUR_GREEN);
  print("I am on a new line");
  print_ln(" - I am not");

  set_text_colour(COLOUR_RED, COLOUR_WHITE);
  print_ln("red on white");

  set_text_colour(COLOUR_WHITE, COLOUR_BLUE);
  print_ln("white on blue");
}

void kernel_entrypoint()
{
  run_kern();
}
