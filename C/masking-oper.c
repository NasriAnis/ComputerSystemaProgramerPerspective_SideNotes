#include <stdio.h>

int main() {
  int x = 0x87654321;
  printf("x = %x\n", x);

  // mask least significant byte :
  int masker = 0xFF;
  int result = x & masker;
  printf("Least significant byet of x: %x\n", result);

  // complemente x but not the least significant byte
  int ended_x = ~x;
  ended_x = ended_x & ~0xFF;
  int least_byte = x & 0xFF;
  result = ended_x | least_byte;
  printf("Least significant byet + complement: %x\n", result);

  // The least significant byte set to all ones, and all other bytes of x left un- changed
  result = x | 0xFF;
  printf("result: %x\n", result);

  return 0;
}
