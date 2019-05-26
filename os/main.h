#ifndef MAIN_H
#define MAIN_H

typedef struct
{
  char *name;
  void (*keypress_handler)(unsigned char);
} Program_t;

void os_start();
void os_proxy_keypress(unsigned char key);

#endif