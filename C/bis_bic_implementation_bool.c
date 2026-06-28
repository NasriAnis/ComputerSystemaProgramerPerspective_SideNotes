#include <stdio.h>

int bis(int x, int m){
  return x | m;
}
int bic(int x, int m){
  m = ~m;
  return x & m;
}

int bool_or(int x, int y) {
  int result = bis(x, y);
  return result;
}

int bool_xor(int x, int y) {
  int result = bis(bic(x, y), bic(y, x));
    return result;
}

int main(){
  int y = 0b1100;
  int x = 0b1010;
  int result;

  printf("x = %b, y = %b\n", x, y);

  result = bis(x, y);
  printf("Bis result: %b\n", result);

  result = bic(x, y);
  printf("Bic result: %b\n", result);

  result = bool_or(x, y);
  printf("Or result: %b\n", result);

  result = bool_xor(x, y);
  printf("Xor result: %b\n", result);

  return 0;
}
