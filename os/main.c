#include "../kernel/gpu/text_mode/display.h"
#include "../kernel/gpu/text_mode/colours.h"
#include "main.h"
#include "./shell/shell.h"

Program_t focused_program;

void os_show_splash()
{
  scrn_enable_cursor(10, 12);
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

void os_start()
{
  os_show_splash();
}

// TODO keep a stack of running programs
void os_update_focused_program(Program_t program) {
  focused_program = shell_run();
}

// Send keypress from kernel to the currently focused programs keypress handler
void os_proxy_keypress(unsigned char key) {
  (focused_program.keypress_handler)(key);
}

// TODO display handling