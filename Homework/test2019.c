#include <stdio.h>

int main() {
  int *b[] = {1, 3, 5, 7, 9};
  int a[5], *num[5] = {&a[0], &a[1], &a[2], &a[3], &a[4]};
  // int a[] = {1, 3, 5, 7, 9}; int *num[5] = {a[0], a[1], a[2], a[3], a[4]};
  int a[3][4], (*num)[4];
  num[1] = &a[1][3];
}
