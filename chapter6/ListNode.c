#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode {
  element data;
  struct ListNode *next;
}ListNode;

typedef struct ListType {
  ListNode *head;
  int size;
}ListType;

void init(ListType *L) {
  L->head = NULL; //아직 아무 node 도 가리키지 않고 있음
  L->size = 0;
}

void insertFirst(ListType *L, element e) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // ListNode 의 size 만큼의 공간을 할당해서 ListNode 형태의 주소로 보내달라는 의미 -> node 에 주소 저장
  node->data = e;
  node->next = L->head;
  L->head = node;
  L->size++;
}

void insertLast(ListType *L, element e) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  node -> data = e;
  node -> next= NULL; // 단순연결리스트에서 마지막 link 는 무조건 null임

  //이 부분을 통해 Last 를 먼저 썼을때의 오류를 방지
  if(L -> size == 0) {
    L->head = node;
  } 
  
  else {
    ListNode *p;
    for(p = L -> head; p -> next != NULL; p = p -> next);  // 다음 노드의 next 가 null 이라면 자신의 previous 노드를 알아야함
    p -> next = node;
  }

  L -> size++;

}

void insert(ListType *L, int pos, element e) {
  if(pos == 1) 
    insertFirst(L, e);
  
  else if(pos == L->size + 1)
    insertLast(L, e);
  
  else {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = L -> head;

    for(int i = 1; i < pos - 1; i++) //pos 위치 전까지 움직여야 됨
      p = p -> next;
    
    node -> data = e;
    node -> next = p -> next;
    p -> next = node;
  }

  L->size++;
}

element deleteFirst(ListType *L) {
  if(L -> size == 0) {
    printf("No element.\n");
    return -1;
  }

  ListNode *p = L -> head;
  element e = p -> data;
  L -> head = p -> next;
  free(p);
  L -> size--;

  return e;
}

element delete(ListType *L, int pos) {
  if(L -> size == 0) {
    printf("No element.\n");
    return -1;
  }

  if(pos < 1 || pos > L -> size) {
      if(L -> size == 0) {
    printf("Invalid Pos.\n");
    return -1;
  } else {
    ListNode *p = L -> head;
    ListNode *q;
    element e;

    if(pos == 1)
      e = deleteFirst(L);
    else {
      for(int i = 1; i < pos; i++)  {
        q = p;
        p = p -> next;
      }
      e = p -> data;
      q -> next = p -> next;
      free(p);
      L -> size--;
    }
    return e;
  }
  }
}


void print(ListType *L) {
  ListNode *p;

  for(p = L -> head; p != NULL; p = p -> next) 
    printf("%c => ", p->data);
  printf("\b\b\b  \n");
}



int main() {
  ListType L;
  init(&L);

  insertLast(&L, 'E'); print(&L); //------> insertLast 를 먼저하면 오류가 발생 ----> null 을 가리키고 있는데 그거의 next 에 node 를 설정하라는 것이므로

  insertFirst(&L, 'A'); print(&L);
  insertFirst(&L, 'B'); print(&L);
  

  insertLast(&L, 'C'); print(&L);
  insertLast(&L, 'D'); print(&L);

  insert(&L, 1, 'F'); print(&L);
  insert(&L, 4, 'G'); print(&L);
  insert(&L, 8, 'H'); print(&L);

  printf("[%c] is deleted.\n", deleteFirst(&L)); print(&L);
  printf("[%c] is deleted.\n", delete(&L, 3)); print(&L);

  return 0;
}