#include "ramfs.h"
#include "../../kernel/gpu/text_mode/display.h"

#include "../stdlib/sdtlib.h"

#define RAMDISK_SIZE 102400 // 100 blocks
#define BLOCK_SIZE 1024
#define MAX_FILES 128 // fixed size until mem management done

unsigned char ramdisk[RAMDISK_SIZE];

File_t files[MAX_FILES];
int tip_file_idx = -1;

File_t* ramfs_list_files() {
  return files;
}

int ramfs_get_tip_file_idx() {
  return tip_file_idx;
}

File_t ramfs_create_file(unsigned char *filename) {
  int i = ++tip_file_idx;
  strcpy(filename, files[i].name);
  return files[i];
}
