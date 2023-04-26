#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char from, char tmp, char to) {
  if(n == 1) {
    printf("%c %c\n",from ,to);
  }
  else {
    Hanoi(n - 1, from, to, tmp);
    printf("%c %c\n",from ,to);
    Hanoi(n - 1, tmp, from, to);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  Hanoi(n, 'A', 'B', 'C');
  
  return 0;
}
