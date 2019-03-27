#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if (a % 2 == 0) {
    printf("%d is odd number\n", a);
  } else if (b % 2 == 0) {
    printf("%d is odd number\n", b);
  } else if (c % 2 == 0) {
    printf("%d is odd number\n", c);
  }
  return 0;
}
