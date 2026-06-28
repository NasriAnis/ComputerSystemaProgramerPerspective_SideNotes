#include <stdio.h>

int tadd_ok(int x, int y){

  int sum = x+y;
  int neg_over = x < 0 && y < 0 && sum >= 0;
  int pos_over = x >= 0 && y >= 0 && sum < 0;
  return !neg_over && !pos_over;

  // if (x < 0 && y < 0) {
  //   int result = x + y;
  //   if (result >= 0) {
  //     return 0;
  //   }
  // }
  // else if (x >= 0 && y >= 0) {
  //   int result = x + y;
  //   if (result < 0) {
  //     return 0;
  //   }
  // }
  // return 1;
}

int main(){
  int x = -1530494977;
  int y = -1530494977;


  if (tadd_ok(x, y)){
    printf("Possible\n");
  } else {printf("Unpossible\n");};

  printf("%d + %d = %d\n", x, y, x+y);
  printf("(%d+%d) - %d = %d\n", x, y, x+y, (x+y)-x);
  return 0;
}
