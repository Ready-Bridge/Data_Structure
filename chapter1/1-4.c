#include <stdio.h>

int main(void) {
  int num;
  scanf("%d", &num);
  while(num != 0) {
    printf("%d\n", num % 10);
    num /= 10;
  }
  return 0;
}