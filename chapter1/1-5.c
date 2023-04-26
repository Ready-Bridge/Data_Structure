#include <stdio.h>

int main(void) {
  int N;
  int even = 0;
  int odd = 0;

  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0) {
      even += i;
    } else {
      odd += i;
    }
  }

  printf("짝수의 합 : %d \n", even);
  printf("홀수의 합 : %d \n", odd);
  return 0;
}



/* 

int i = 1;

while(i <= N)
{
  if(i % 2 == 0)
    even += i;
  
  else 
    odd += i;
}

*/