#include <stdio.h>
#include <stdlib.h>

int sumOfInt(int N) {
  if(N == 1) {
    return 1;
  } 
  else {
    return N + sumOfInt(N - 1);
  }
}

int main() {
  int N;
  scanf("%d", &N);
  printf("%d", sumOfInt(N));

  return 0;
}