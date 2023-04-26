#include <stdio.h>
#include <stdlib.h>

int main() {
  int price, cnt, money;
  int total;
  
  scanf("%d %d %d", &price, &cnt, &money);

  total = price * cnt;

  if(total > money) {
    printf("모자란 금액 : %d\n", total - money);
  } else {
    printf("금액이 모자라지 않습니다.\n");
  }

  return 0;
}