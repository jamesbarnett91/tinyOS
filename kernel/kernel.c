#include "./io/vga/text_mode_display.h"
#include "./io/vga/colours.h"
#include "./io/keyboard/keyboard_handler.h"
#include "global_descriptor_table.h"

void run_kern_demo()
{
  vga_set_text_colour(COLOUR_LIGHT_GREEN, COLOUR_BLACK);
  vga_clear_screen();

  vga_print_ln("  _   _              ____   _____ ");
  vga_print_ln(" | | (_)            / __ \\ / ____|");
  vga_print_ln(" | |_ _ _ __  _   _| |  | | (___  ");
  vga_print_ln(" | __| | '_ \\| | | | |  | |\\___ \\ ");
  vga_print_ln(" | |_| | | | | |_| | |__| |____) |");
  vga_print_ln("  \\__|_|_| |_|\\__, |\\____/|_____/ ");
  vga_print_ln("               __/ |              ");
  vga_print_ln("              |___/               ");

  vga_print_ln("");
  vga_print_ln("Supported colours");
  vga_set_text_colour(COLOUR_BLUE, COLOUR_BLACK);
  vga_print("blue ");
  vga_set_text_colour(COLOUR_GREEN, COLOUR_BLACK);
  vga_print("green ");
  vga_set_text_colour(COLOUR_CYAN, COLOUR_BLACK);
  vga_print("cyan ");
  vga_set_text_colour(COLOUR_RED, COLOUR_BLACK);
  vga_print("red ");
  vga_set_text_colour(COLOUR_PURPLE, COLOUR_BLACK);
  vga_print("purple ");
  vga_set_text_colour(COLOUR_BROWN, COLOUR_BLACK);
  vga_print("brown ");
  vga_set_text_colour(COLOUR_GRAY, COLOUR_BLACK);
  vga_print_ln("gray ");
  vga_set_text_colour(COLOUR_DARK_GREY, COLOUR_BLACK);
  vga_print("dark gray ");
  vga_set_text_colour(COLOUR_LIGHT_BLUE, COLOUR_BLACK);
  vga_print("light blue ");
  vga_set_text_colour(COLOUR_LIGHT_GREEN, COLOUR_BLACK);
  vga_print("light green ");
  vga_set_text_colour(COLOUR_LIGHT_CYAN, COLOUR_BLACK);
  vga_print_ln("light cyan");
  vga_set_text_colour(COLOUR_LIGHT_RED, COLOUR_BLACK);
  vga_print("light red ");
  vga_set_text_colour(COLOUR_LIGHT_PURPLE, COLOUR_BLACK);
  vga_print("light purple ");
  vga_set_text_colour(COLOUR_YELLOW, COLOUR_BLACK);
  vga_print("yellow ");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_BLACK);
  vga_print_ln("white ");

  vga_set_text_colour(COLOUR_BLACK, COLOUR_WHITE);
  vga_print("B");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_BLUE);
  vga_print("A");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_GREEN);
  vga_print("C");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_CYAN);
  vga_print("K");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_RED);
  vga_print("G");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_PURPLE);
  vga_print("R");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_BROWN);
  vga_print("O");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_GRAY);
  vga_print("U");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_LIGHT_BLUE);
  vga_print("N");
  vga_set_text_colour(COLOUR_BLACK, COLOUR_YELLOW);
  vga_print("D");
  vga_set_text_colour(COLOUR_BLACK, COLOUR_LIGHT_GREEN);
  vga_print(" ");

  vga_set_text_colour(COLOUR_BLACK, COLOUR_LIGHT_CYAN);
  vga_print("C");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_LIGHT_RED);
  vga_print("O");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_LIGHT_PURPLE);
  vga_print("L");
  vga_set_text_colour(COLOUR_BLACK, COLOUR_WHITE);
  vga_print("O");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_RED);
  vga_print("U");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_PURPLE);
  vga_print("R");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_BROWN);
  vga_print("S");
  vga_set_text_colour(COLOUR_WHITE, COLOUR_GRAY);
}



void kernel_entrypoint()
{
  init_gdt();
  init_keyboard_handler();
  run_kern_demo();
  while(1);
}
