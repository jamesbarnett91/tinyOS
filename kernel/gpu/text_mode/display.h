void scrn_enable_cursor(unsigned char start_line, unsigned char end_line);
void scrn_clear();
void scrn_print(char *msg);
void scrn_println(char *msg);
void scrn_set_text_colour(int foreground, int background);
void scrn_putchar(unsigned char byte);
void scrn_backspace();
void scrn_newline();