#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef char element;

typedef struct
{
    element data[N];
    int front, rear;
}DequeType;

void init(DequeType *D)
{
    D->front = D->rear = 0;
}

int isEmpty(DequeType *D)
{
    return D->rear == D->front;
}

int isFull(DequeType *D)
{
    return D->front == (D->rear + 1) % N;
}

void addFront(DequeType *D, element e) {
  if(isFull(D))
    printf("Full\n");
  else {
    D->data[D->front] = e;
    D->front = (D->front - 1 + N) % N;
  }
}

void addRear(DequeType *D, element e)
{
    if(isFull(D))
        printf("Full\n");
    else
    {
        D->rear = (D->rear + 1) % N;
        D->data[D->rear] = e;
    }
}
element deleteFront(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }
    
    D->front = (D -> front + 1) % N;
    return D->data[D->front];
}

element deleteRear(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }
    
    int pos = D -> rear; //마지막 포지션을 저장
    D -> rear = (D -> rear -1 + N) % N;
    return D -> data[pos];
}


element getFront(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }
    
    return D->data[(D->front+1) % N];
}

element getRear(DequeType *D) {
  if(isEmpty(D))
    {
        printf("Empty.\n");
        return 0;
    }
    
    return D -> data[D -> rear];
}

void print(DequeType *D)
{
    printf("F : %d, R : %d\n", D->front, D->rear);
    
    int i = D->front;
    while(i != D->rear)
    {
        i = (i + 1) % N;
        printf("%c ", D->data[i]);
    }
    printf("\n");    
}

int main()
{
    DequeType D;
    init(&D);
    srand(time(NULL));
    
    for(int i = 0; i < 6; i++)
        addRear(&D, rand() % 26 + 65);
    
    print(&D);
    
    
    for(int i = 0; i < 3; i++)
        addFront(&D, rand() % 26 + 65);
    
    

    printf("\n\n");
    
    print(&D); 
    
    

    for(int i = 0; i < 6; i++)
        deleteRear(&D);
    
    printf("\n\n");

    print(&D);

    

    for(int i = 0; i < 3; i++)
        deleteFront(&D);
    
    printf("\n\n");
    
    print(&D);
      
    
    return 0;
}
