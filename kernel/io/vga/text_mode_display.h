void vga_clear_screen();
void vga_print(char *msg);
void vga_print_ln(char *msg);
void vga_set_text_colour(int foreground, int background);
void vga_print_raw(unsigned char byte);
void vga_backspace();
void vga_newline();