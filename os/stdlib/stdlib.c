char* int_to_str(int i)
{
  // Room for 4 byte int, -ve sign and null terminator
  static char buf[12];
  char *p = buf + 11;	// points to null terminator
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  }
  else {
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}