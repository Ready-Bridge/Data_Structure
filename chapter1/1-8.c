#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0};
    srand(time(NULL));

    for(int i = 0; i < 10000; i++) {
        arr[rand() % 6 + 1] += 1;
    }

    for(int i = 1; i < 7; i++) {
        printf("%d 이(가) 나온 횟수 : %d \n", i, arr[i]);
    }

    return 0;
}