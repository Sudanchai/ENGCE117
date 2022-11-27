#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void main() {
  int i, n;
  int t = 9;
  int x = 0;

  printf("Enter the number : ");
  scanf("%d", & n);
  for (i = 0; i < n; i++) {
    x += t; //x = x+t;
    printf("%d ", t);
    t = t * 10 + 9;
    if (i < n - 1) {
      printf("+ ");
    }
  }
  printf("\nAnswer = %d ", x);
}