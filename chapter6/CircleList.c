#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode {
  element data;
  struct ListNode *next;
}ListNode;

typedef struct ListType {
  ListNode *tail; // L -> tail : Last Node , L -> tail -> next : First Node 임!
  int size;
}ListType;

void init(ListType *L) {
  L->tail = NULL; //아직 아무 node 도 가리키지 않고 있음
  L->size = 0;
}

void insertLast(ListType *L, element e) {
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node -> data = e;

  if(L -> size == 0) {
    L -> tail = node;
    node -> next = L-> tail; // node -> next = node;
  } else {
    node -> next = L -> tail -> next;
    L -> tail -> next = node;
    L -> tail = node;
  }
  L -> size++;
}

void insertFirst(ListType *L, element e) {
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node -> data = e;

  if(L -> size == 0) {
    L -> tail = node;
    node -> next = L-> tail; // node -> next = node;
  } else {
    node -> next = L -> tail -> next;
    L -> tail -> next = node;
  }
  L -> size++;
}

void insert(ListType *L,int pos, element e) {
  if(pos == 1) 
    insertFirst(L, e);
  
  else if(pos == L->size + 1)
    insertLast(L, e);
  
  else {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = L -> tail;

    for(int i = 0; i < pos - 1; i++) //pos 위치 전까지 움직여야 됨
      p = p -> next;
    
    node -> data = e;
    node -> next = p -> next;
    p -> next = node;
    L->size++;
  }
}

element deleteFirst(ListType *L) {
  ListNode *p = L -> tail;
  ListNode *q = p -> next;

  element e = q -> data;
  p -> next = q -> next;

  if(p == q)
    L -> tail = NULL;
  
  free(q);
  L -> size--;

  return e;
}

element deleteLast(ListType *L) {
  ListNode *p = L -> tail;
  ListNode *q = p -> next;

  element e = p -> data;
  
  if(p -> next == L -> tail)
    L -> tail = NULL;
  
  else {
    while(q -> next != p)
      q = q -> next;
    
    q -> next = p -> next;
    L -> tail = q;
  }
  
  free(p);
  L -> size--;

  return e;
}

void print(ListType *L) {
  ListNode *p = L -> tail;
  for(p = p -> next; p != L -> tail; p = p -> next) {
    printf("[%c] => ", p -> data);
  }
  printf("[%c] => ", p -> data); 
  printf("\b\b\b  \n");
}

int main() {
  ListType L;
  init(&L);

  insertLast(&L, 'A'); print(&L);
  insertLast(&L, 'B'); print(&L);
  insertLast(&L, 'C'); print(&L);

  insertFirst(&L, 'D'); print(&L);
  insertFirst(&L, 'E'); print(&L);

  printf("[%c] is deleted\n", deleteFirst(&L)); print(&L);
  printf("[%c] is deleted\n", deleteLast(&L)); print(&L);


  return 0;
}