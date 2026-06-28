// int uadd_ok(unsigned x, unsigned y){
//   unsigned result = x + y;
//   if (result < x || result < y) {
//     return 0;
//   } else {
//     return 1;
//   }
// }

int uadd_ok(unsigned x, unsigned y) {
    unsigned result = x + y;
    return result >= x; // Returns 1 if safe, 0 if it overflowed
}
