#include <stdio.h>

void sumOfWeghit(int g) {
    int cnt = 0;
    for(int i = 1; i <= 10; i++) {
        for(int k = 1; k <= 10; k++) {
            for(int j = 1; j <= 10; j++) {
                if((2 * i + 3 * k + 5 * j) == g) {
                    printf("%d %d %d \n", i, k, j);
                    cnt++;
                }
            }
        }
    }

    if(cnt == 0) 
        printf("0\n");
    
    else 
        printf("%d\n", cnt);
    
}

int main(void) {
    int G;
    int result;
    scanf("%d", &G);
    sumOfWeghit(G);
    return 0;
}