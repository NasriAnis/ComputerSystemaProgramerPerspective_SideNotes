#include <stdint.h>
#include <stdio.h>

int div(int32_t x){
  int k = 4
  int32_t bias = ( x >> 31 ) & ((1 << k) - 1); // or 0xF;
  // the first is the general pattern we shift then & it:
  // x >= 0:  00000000 00000000 00000000 00000000
  // x <  0:  11111111 11111111 11111111 11111111
  // 0xF   :  00000000 00000000 00000000 00001111
  printf("Bias : %d\n", bias);

  return (x + bias) >> k;
}

int main(){
  printf("Result: %d", div(-12340));
}
