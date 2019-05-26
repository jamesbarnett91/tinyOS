#include "./gpu/text_mode/display.h"
#include "./gpu/text_mode/colours.h"
#include "./io/keyboard/keyboard_handler.h"
#include "global_descriptor_table.h"
#include "../os/main.h"

void kernel_entrypoint()
{
  init_gdt();
  init_keyboard_handler();
  os_start();
  while(1);
}
