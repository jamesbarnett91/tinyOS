struct idt_entry
{
  unsigned short int offset_lowerbits;
  unsigned short int selector;
  unsigned char zero;
  unsigned char type_attr;
  unsigned short int offset_higherbits;
} __attribute__((packed));