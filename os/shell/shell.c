#include "../../os/main.h"
#include "../../kernel/gpu/text_mode/display.h"
#include "../stdlib/sdtlib.h"
#include "../commands/echo.h"

#define CMD_BUFFER_SIZE 80

// TODO history buffer
unsigned char cmd_buffer[CMD_BUFFER_SIZE];
int cmd_buffer_p = 0;

// cant malloc yet so just store locally
unsigned char cmd[CMD_BUFFER_SIZE];
unsigned char args[CMD_BUFFER_SIZE];

void shell_set_prompt() {
  scrn_print("$> ");
}

void shell_clear_cmd_buffer() {
  for(int i = 0; i < CMD_BUFFER_SIZE; i++) {
    cmd_buffer[i] = 0;
  }
  cmd_buffer_p = 0;
}

void shell_clear_cmd() {
  for(int i = 0; i < CMD_BUFFER_SIZE; i++) {
    cmd[i] = 0;
  }
}

void shell_clear_args() {
  for(int i = 0; i < CMD_BUFFER_SIZE; i++) {
    args[i] = 0;
  }
}

unsigned char* shell_parse_cmd() {
  shell_clear_cmd();
  for(int i = 0; i < CMD_BUFFER_SIZE; i++) {
    if (cmd_buffer[i] == ' ') {
      break;
    }
    cmd[i] = cmd_buffer[i];
  }
  return cmd;
}

unsigned char* shell_parse_args() {
  shell_clear_args();
  int arg_idx = 0;
  for(int i = 0; i < CMD_BUFFER_SIZE; i++) {
    if (cmd_buffer[i] == ' ') {
      arg_idx = i + 1;
      break;
    }
  }

  if (arg_idx == 0) {
    return args;
  }
  else {
    for(int i = arg_idx; i < CMD_BUFFER_SIZE; i++) {
      args[i - arg_idx] = cmd_buffer[i];
    }
    return args;
  }
}

void shell_exec_cmd(unsigned char* cmd_name, unsigned char* args) {
  // TODO lookup string to funciton pointer
  if (strcmp(cmd_name, "echo") == 0) {
    echo(args);
  }
  else if (strcmp(cmd_name, "") != 0) {
    scrn_print(cmd_name);
    scrn_println(": command not found");
  }
}

void shell_process_cmd_buffer() {
  scrn_newline();

  shell_exec_cmd(shell_parse_cmd(), shell_parse_args());

  shell_clear_cmd_buffer();
  shell_set_prompt();  
}

void shell_handle_backspace() {
  if (cmd_buffer_p != 0) {
    cmd_buffer[--cmd_buffer_p] = 0;
    scrn_backspace();
  }
}

void shell_handle_keypress(unsigned char key) {
  cmd_buffer[cmd_buffer_p++] = key;
  scrn_putchar(key);
}

void keypress_handler(unsigned char key) {
  switch(key)
    {
      case '\b':
        shell_handle_backspace();
        break;
      case '\n':
        shell_process_cmd_buffer();
        break;
      default:
        shell_handle_keypress(key);
    }
}

Program_t shell_run() {
  Program_t this;
  this.keypress_handler = keypress_handler;
  this.name = "shell";
  shell_set_prompt();
  return this;
}