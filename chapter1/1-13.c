#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct Bank{
    int number;
    char name[MAX_NAME_LENGTH];
    int cash;
} Bank;

int main(void) {
    Bank st;
    int nu, ca;
    char na[MAX_NAME_LENGTH];

    scanf("%d %s %d", &nu, na, &ca);
    st.number = nu;
    strcpy(st.name, na);
    st.cash = ca;

    printf("%s의 %d계좌의 잔액은 %d원", st.name, st.number, st.cash);
    return 0;
}