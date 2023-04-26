#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef char element;

typedef struct {
  element data[N];
  int front, rear;
}QueueType;

void init(QueueType *Q) {
  Q -> front = Q -> rear = -1;
}

int isFUll(QueueType *Q) {
  return Q -> rear == N - 1;
}

int isEmpty(QueueType *Q) {
  return Q -> front == Q -> rear;
}

void enqueue(QueueType *Q, element e) {
  if(isFUll(Q))
    printf("Full\n");
  else {
    Q -> rear++;
    Q -> data[Q -> rear] = e;
  }
}

element dequeue(QueueType *Q) {
  if(isEmpty(Q)) {
    printf("Empty\n");
    return 0;
  } 
  Q -> front++;
  return Q -> data[Q -> front];
}


void print(QueueType * Q) {
  printf("Front : %d - Rear : %d", Q -> front, Q -> rear);
  printf("\n");

  for(int i = Q -> front + 1; i <= Q -> rear; i++) {
    printf("[%c] ", Q -> data[i]);
  }

  printf("\n");
}

int main() {
  QueueType Q;
  init(&Q);
  srand(time(NULL));

  for(int i = 0; i < 7; i++) {
    enqueue(&Q, rand() % 26 + 65); // 알파벳 대문자 A ~ Z 의 아스키코드
  }

  print(&Q);

  for(int i = 0; i < 4; i++) 
    printf("[%c] ", dequeue(&Q));
  
  printf("\n");

  print(&Q);
  
  return 0;
}