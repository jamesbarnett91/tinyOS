#include "../../os/main.h"
#include "../../kernel/gpu/text_mode/display.h"

void keypress_handler(unsigned char key) {
  switch(key)
    {
      case '\b':
        scrn_backspace();
        break;
      case '\n':
        scrn_newline();
        break;
      default:
        scrn_putchar(key);
    }
}

Program_t shell_run() {
  Program_t this;
  this.keypress_handler = keypress_handler;
  this.name = "shell";
  return this;
}