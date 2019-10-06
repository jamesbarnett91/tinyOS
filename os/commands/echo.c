#include "../../kernel/gpu/text_mode/display.h"

void cmd_echo(char *args) {
  scrn_println(args);
}