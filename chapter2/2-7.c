#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int Count(char arr[], char compare, int n) {
  if(arr[n] == '\0') {
    return 0;
  }
  else {
      return (arr[n] == compare) + Count(arr, compare, n + 1); 
 }   
}

int main() {
  char arr[MAX];
  char compare;
  int n;

  scanf("%s ", arr);
  scanf("%c", &compare);
  
  printf("%d", Count(arr, compare, n));
  return 0;
}