#include <stdio.h>

int main(void) {
    int arr[3][4] = {0, 1, 2, 3,
    10, 11, 12, 13,
    20, 21, 22 ,23};

    for(int i = 0; i < 3; i++) {
        for(int k = 0; k < 4; k++) {
            printf("%2d ", arr[i][k]);
        }
        printf("\n");
    }

    return 0;
}