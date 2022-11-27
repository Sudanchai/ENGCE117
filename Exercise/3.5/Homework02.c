#include <stdio.h>

void main() {
  int i, n = 9, t = 1, sort = 0, mark = 1;
  int count[10], countclone[10], countnum[10];

  printf("Enter the maximum array : ");
  scanf("%d", & n);
  printf("Your array is : %d\n", n);
  //input
  for (i = 0; i <= n - 1; i++) {
    printf("\nEnter the number - %d : ", i + 1);
    scanf("%d", & count[i]);
    printf("Your number is : %d\n", count[i]);
    countclone[i] = count[i];
  }

  //process
  printf("\nYour array is have \n");
  for (i = 0; i < n; i++) {
    for (t = i + 1; t < n; ++t) {
      if (countclone[i] > countclone[t]) {
        sort = countclone[i];
        countclone[i] = countclone[t];
        countclone[t] = sort;
      }
    }
  }
  t = 1;
  for (i = 0; i < n; i++) {
    countnum[i] = t;
    for (t = 0; t < n; t++) {

      if (countclone[i] == countclone[t]) {
        countnum[i] = mark++;
      }
    }
    mark = 1;
    if (countclone[i] != countclone[i - 1]) {
      printf("\n%d -> %d ", countclone[i], countnum[i]);
    }
  }
}