#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct {
  char data[N];
  int top;
} StackType; 

void init(StackType *S) {
  S -> top = -1;
}

int isEmpty(StackType *S) {
  return S -> top == -1;
}

int isFull(StackType *S) {
  return S -> top == N - 1;
}

void push(StackType *S, char c) {
  if(isFull(S)) {
    printf("Full\n");
  } else {
    S -> top++;
    S -> data[S -> top] = c;
  }
}

char pop(StackType *S) {
  if(isEmpty(S)) {
    printf("Empty \n");
    return -1;
  }

  char c = S -> data[S -> top];
  S -> top--;
  return c;
}

char peek(StackType *S) {
  if(isEmpty(S)) {
    printf("Empty\n");;
    return -1;
  }

  return S -> data[S -> top];
}

// 회문이 아니면 0을, 맞으면 1을 리턴

int isPalindrome(char b[]) {
  StackType S;
  init(&S);
  int pt;
  int n = strlen(b);
  char tag;
  
  for(int i = 0; i < n; i ++) {
    push(&S, b[i]);
    printf("%c\n", b[i]);
  }

  for(int i = 0; i < n; i ++) {
    tag = pop(&S);
    printf("%c", tag);
    printf("??%c\n", b[i]);
    if(tag != b[i])
      return 0;
  }

  return 1;
}

int main() {
  char a[N];
  char b[N];
  int cnt2 = 0;

  //scanf 함수로 공백을 입력받기 위해 [^\n] 을 사용함
  scanf("%[^\n]s", a);

  int cnt = strlen(a);
  
  //a로 문자열을 입력받고 이 문자열에서 스페이스, 구두점, 대문자 등을 무시하고 오로지 소문자로만 만들어진 문자열을 b라는 배열에 넣어줌
  for(int i = 0; i < cnt; i++) {
    if(a[i] >= 'a' && a[i] <= 'z') {
      b[cnt2++] = a[i];
    }
    else if(a[i] >= 'A' && a[i] <= 'Z') {
      b[cnt2++] = a[i] - 'A' + 'a';
    }
  }

  if(isPalindrome(b)) {
    printf("회문이 맞습니다.");
  } else {
    printf("회문이 아닙니다.");
  }

  return 0;
}
