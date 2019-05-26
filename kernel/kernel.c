#include "./gpu/text_mode/display.h"
#include "./gpu/text_mode/colours.h"
#include "./io/keyboard/keyboard_handler.h"
#include "global_descriptor_table.h"

void run_kern_demo()
{
  
  scrn_clear();
  scrn_set_text_colour(COLOUR_LIGHT_GREEN, COLOUR_BLACK);
  
  scrn_println("  _   _              ____   _____ ");
  scrn_println(" | | (_)            / __ \\ / ____|");
  scrn_println(" | |_ _ _ __  _   _| |  | | (___  ");
  scrn_println(" | __| | '_ \\| | | | |  | |\\___ \\ ");
  scrn_println(" | |_| | | | | |_| | |__| |____) |");
  scrn_println("  \\__|_|_| |_|\\__, |\\____/|_____/ ");
  scrn_println("               __/ |              ");
  scrn_println("              |___/               ");

  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLACK);
  scrn_newline();
}



void kernel_entrypoint()
{
  init_gdt();
  init_keyboard_handler();
  run_kern_demo();
  while(1);
}
