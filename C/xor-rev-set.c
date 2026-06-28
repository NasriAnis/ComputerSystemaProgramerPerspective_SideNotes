#include <stdio.h>
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y; /* Step 1 */
  *x = *x ^ *y; /* Step 2 */
  *y = *x ^ *y; /* Step 3 */
}

int* reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1; first <= last; first++,last--){
    if (first == last){ break; }
    inplace_swap(&a[first], &a[last]);
  }
  return a;
}

int main(){
  int arr[] = {0, 1, 2, 3, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int* a = reverse_array(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

