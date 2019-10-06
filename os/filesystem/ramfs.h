typedef struct
{
  char name[128]; // 128 max filename lentgh
  int start_addr;
  int end_addr;
} File_t;

File_t ramfs_create_file(unsigned char * filename);
File_t* ramfs_list_files();
int ramfs_get_tip_file_idx();