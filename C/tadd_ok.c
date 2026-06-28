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
  if (tadd_ok(-1530494977, -1530494977)){
    printf("Possible");
  } else {printf("Unpossible");};
  return 0;
}
