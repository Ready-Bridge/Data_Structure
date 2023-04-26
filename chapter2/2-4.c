#include <stdio.h>
#include <stdlib.h>

int maxOfItem(int a, int b) {
  if(a > b) {
    return a;
  } 
  else {
    return b;
  }
}

int printMax(int arr[], int n) {
  if(n == 1) {  
    return arr[0];
  }
  else {
    return maxOfItem(arr[n - 1], printMax(arr, n - 1)); 
  }
  
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("%d", printMax(arr, n));

  return 0;
}