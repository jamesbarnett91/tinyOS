#include "../kernel/gpu/text_mode/display.h"
#include "../kernel/gpu/text_mode/colours.h"
#include "main.h"
#include "./shell/shell.h"
#include "./stdlib/sdtlib.h"

Program_t focused_program;

void os_show_splash()
{
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

void line_pad(unsigned int width)
{
  for(int i = 0; i < width; i++)
  {
    scrn_putchar(' ');
  }
}

void os_update_infobar_rc() 
{

  int curr_attr_byte = scrn_get_char_attr_byte();
  int curr_r = scrn_get_cursor_row();
  int curr_c = scrn_get_cursor_col();

  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLUE);
  scrn_set_cursor_pos(0, 64);
  scrn_print("row ");
  
  if (curr_r < 9) {
    scrn_print("0");    
  }
  scrn_print(int_to_str(curr_r +1));

  scrn_print(", col ");
  if (curr_c < 9) {
    scrn_print("0");    
  }
  scrn_print(int_to_str(curr_c+1));
  
  scrn_set_char_attr_byte(curr_attr_byte);
  scrn_set_cursor_pos(curr_r, curr_c);
}

void os_update_infobar_program() {
  int curr_attr_byte = scrn_get_char_attr_byte();
  int curr_r = scrn_get_cursor_row();
  int curr_c = scrn_get_cursor_col();

  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLUE);
  scrn_set_cursor_pos(0, 11);
  line_pad(64);
  scrn_set_cursor_pos(0, 11);
  scrn_print(focused_program.name);

  scrn_set_char_attr_byte(curr_attr_byte);
  scrn_set_cursor_pos(curr_r, curr_c);
}

void os_init_infobar()
{
  scrn_clear();
  scrn_set_cursor_pos(0, 0);
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLUE);
  line_pad(80); // fill line
  scrn_set_cursor_pos(0, 2);
  scrn_print("tinyOS - ");
  scrn_print(focused_program.name);
  
  os_update_infobar_rc();
  scrn_set_text_colour(COLOUR_WHITE, COLOUR_BLACK);
  scrn_set_cursor_pos(1, 0);
}

// TODO keep a stack of running programs
void os_update_focused_program(Program_t program) {
  focused_program = program;
  os_update_infobar_program();
}

// Send keypress from kernel to the currently focused programs keypress handler
void os_proxy_keypress(unsigned char key) {
  (focused_program.keypress_handler)(key);
  os_update_infobar_rc();  
}

void os_start()
{
  scrn_enable_cursor(10, 12);
  os_init_infobar();
  os_show_splash();
  
  os_update_focused_program(shell_run());

  os_update_infobar_rc();
}