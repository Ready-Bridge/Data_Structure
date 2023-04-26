#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // C언어에서 난수를 발생시키기 위해 필요한 헤더파일 time.h

#define N 10            // 배열의 크기를 '기호상수'를 통해 전역 상수로 선언해 놓는다.

/*
해당 실습의 내용은 앞으로도 많이 쓰일 것이기에 중요하게 유념한다.
- 난수 발생하는 방법
- define으로 기호상수 선언하는 방법
- srand(time(NULL)) : C언어에서 난수를 발생시키는 함수 rand()를 사용하기 전에 seed 값을 선언하기 위해 먼저 호출되어야 하는 함수. 이를 사용하지 않으면 난수는 seed값이 일치해서 동일한 값만을 출력하게 되는 오류가 있다.
- rand() : 랜덤 숫자를 출력하는 함수
*/

void makeArray(int A[]) {
    for (int i = 0; i < N; i++) 
        A[i] = rand() % 100 + 1;     // rand() % 100 -> 0 ~ 99 까지 출력된다.
}

void printArray(int A[]) {  
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");                   // 반드시 반복문 이후, 줄바꿈을 해서 추가적으로 있을 출력을 알아보기 쉽게 만든다.
}

int findMax(int A[]) {              // max값을 구하는 함수
    int max = A[0];                 // 배열에서 최대 값을 구할 때 항상 max는 index 0번의 원소를 의미하게 한다.
    for (int i = 1; i < N; i++) {
        if (A[i] > max)
            max = A[i];
    }

    return max;
}

int main() {
    int A[N];          // 배열을 선언할 때에는 자료형 (int), index 수 (N=기호상수=10)을 지정해서 선언해야 한다.

    // srand = seed rand -> 계수로 time(NULL)을 통해 현재 시간값을 기초로 난수를 생성한다.
    srand(time(NULL));  // '반드시' 랜덤 변수를 선언하기 위해 앞에 선언해야 하는 중첩함수 (time.h에 들어가 있다)

    // 배열의 이름 A는 배열의 index 0번의 주소값을 의미하므로 포인터를 굳이 사용할 필요가 없다.
    // 주소를 전달해 주면서 외부 함수에서도 배열A의 값을 수정 가능하다. (Call by Reference 방식. 주소를 전달하므로써 공유되는 것)
    makeArray(A);
    printArray(A);

    printf("Max : %d\n", findMax(A));

    return 0;
}