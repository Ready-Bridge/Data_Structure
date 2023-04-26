#include <stdio.h>

int main(void) {
  int score;
  scanf("%d", &score);
  if (score < 0 || score > 100) {
    printf("Wrong Input");
  } else {
      switch (score / 10) 
      {
        case 10:
        case 9:
          printf("A");
          break;
        case 8:
          printf("B");
          break;
        case 7:
          printf("C");
          break;
        default: //switch 문에서 else의 역할을 수행
          printf("D or F");
          break;
      }
  }
  return 0;
}