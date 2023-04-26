#include <stdio.h>

int main(void) {
    int arr[3][4];
    int n;
    int sum = 0;

    for(int i = 0; i < 3; i++) {
        for(int k = 0; k < 4; k++) {
            printf("%d 행 %d 열의 수를 입력해주세요 : ",i + 1, k + 1);
            scanf("%d", &n);
            arr[i][k] = n;        
        }
    }
    for(int i = 0; i < 4; i++) {
        sum += arr[0][i];
    }
    printf("1행의 합 : %d \n", sum);
    sum = 0;

    for(int i = 0; i < 4; i++) {
        sum += arr[1][i];
    }
    printf("2행의 합 : %d \n", sum);
    sum = 0;

    for(int i = 0; i < 4; i++) {
        sum += arr[2][i];
    }
    printf("3행의 합 : %d \n", sum);
    sum = 0;
    
    for(int i = 0; i < 3; i++) {
        sum += arr[i][0];
    }
    printf("1열의 합 : %d \n", sum);
    sum = 0;

    for(int i = 0; i < 3; i++) {
        sum += arr[i][1];
    }
    printf("2열의 합 : %d \n", sum);
    sum = 0;

    for(int i = 0; i < 3; i++) {
        sum += arr[i][2];
    }
    printf("3열의 합 : %d \n", sum);
    sum = 0;

    for(int i = 0; i < 3; i++) {
        sum += arr[i][3];
    }
    printf("4열의 합 : %d \n", sum);
    
    return 0;
}