#include <stdio.h>

int is_equal(int x, int y) { return !(x ^ y); }

int main() {
  int x = 0x54;
  int y = 0x54;

  printf("euqal: %d", is_equal(x, y));
  return 0;
}
