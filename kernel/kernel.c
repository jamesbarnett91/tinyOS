#include "./gpu/text_mode/display.h"
#include "./gpu/text_mode/colours.h"
#include "./io/keyboard/keyboard_handler.h"
#include "global_descriptor_table.h"

void run_kern_demo()
{
  scrn_set_text_colour(COLOUR_LIGHT_GREEN, COLOUR_BLACK);
  scrn_clear();

  scrn_println("  _   _              ____   _____ ");
  scrn_println(" | | (_)            / __ \\ / ____|");
  scrn_println(" | |_ _ _ __  _   _| |  | | (___  ");
  scrn_println(" | __| | '_ \\| | | | |  | |\\___ \\ ");
  scrn_println(" | |_| | | | | |_| | |__| |____) |");
  scrn_println("  \\__|_|_| |_|\\__, |\\____/|_____/ ");
  scrn_println("               __/ |              ");
  scrn_println("              |___/               ");

  scrn_println("");
  scrn_println("Supported colours");
  scrn_set_text_colour(COLOUR_BLUE, COLOUR_BLACK);
  scrn_print("blue ");
  scrn_set_text_colour(COLOUR_GREEN, COLOUR_BLACK);
  scrn_print("green ");
  scrn_set_text_colour(COLOUR_CYAN, COLOUR_BLACK);
  scrn_print("cyan ");
  scrn_set_text_colour(COLOUR_RED, COLOUR_BLACK);
  scrn_print("red ");
  scrn_set_text_colour(COLOUR_PURPLE, COLOUR_BLACK);
  scrn_print("purple ");
  scrn_set_text_colour(COLOUR_BROWN, COLOUR_BLACK);
  scrn_print("brown ");
  scrn_set_text_colour(COLOUR_GRAY, COLOUR_BLACK);
  scrn_println("gray ");
  scrn_set_text_colour(COLOUR_DARK_GREY, COLOUR_BLACK);
  scrn_print("dark gray ");
  scrn_set_text_colour(COLOUR_LIGHT_BLUE, COLOUR_BLACK);
  scrn_print("light blue ");
  scrn_set_text_colour(COLOUR_LIGHT_GREEN, COLOUR_BLACK);
  scrn_print("light green ");
  scrn_set_text_colour(COLOUR_LIGHT_CYAN, COLOUR_BLACK);
  scrn_println("light cyan");
  scrn_set_text_colour(COLOUR_LIGHT_RED, COLOUR_BLACK);
  scrn_print("light red ");
  scrn_set_text_colour(COLOUR_LIGHT_PURPLE, COLOUR_BLACK);
  scrn_print("light purple ");
  scrn_set_text_colour(COLOUR_YELLOW, COLOUR_BLACK);
  scrn_print("yellow ");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLACK);
  scrn_println("white ");

  scrn_set_text_colour(COLOUR_BLACK, COLOUR_WHITE);
  scrn_print("B");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLUE);
  scrn_print("A");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_GREEN);
  scrn_print("C");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_CYAN);
  scrn_print("K");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_RED);
  scrn_print("G");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_PURPLE);
  scrn_print("R");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BROWN);
  scrn_print("O");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_GRAY);
  scrn_print("U");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_LIGHT_BLUE);
  scrn_print("N");
  scrn_set_text_colour(COLOUR_BLACK, COLOUR_YELLOW);
  scrn_print("D");
  scrn_set_text_colour(COLOUR_BLACK, COLOUR_LIGHT_GREEN);
  scrn_print(" ");

  scrn_set_text_colour(COLOUR_BLACK, COLOUR_LIGHT_CYAN);
  scrn_print("C");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_LIGHT_RED);
  scrn_print("O");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_LIGHT_PURPLE);
  scrn_print("L");
  scrn_set_text_colour(COLOUR_BLACK, COLOUR_WHITE);
  scrn_print("O");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_RED);
  scrn_print("U");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_PURPLE);
  scrn_print("R");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BROWN);
  scrn_print("S");
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_GRAY);
  scrn_print("!");

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
