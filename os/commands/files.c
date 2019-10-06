#include "../../kernel/gpu/text_mode/display.h"
#include "../filesystem/ramfs.h"

void cmd_cf(char *args) {
  // todo check args, filname length etc
  ramfs_create_file(args);
  scrn_print("created file: ");
  scrn_println(args);
}

void cmd_lf(char *args) {
  scrn_println("files:");
  File_t* files = ramfs_list_files();

  for(int i = 0; i <= ramfs_get_tip_file_idx(); i++) {
    scrn_print(files[i].name);
    scrn_print(" ");
  } 
  scrn_newline();
}
