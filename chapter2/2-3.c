#include <stdio.h>
#include <stdlib.h>

void printResult(int n) {
  if(n / 10 != 0) {
    printf("%d\n", n % 10);
    printResult(n / 10);
  }
  else {
    printf("%d\n", n);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printResult(n);
  return 0;
}