#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode {
  element data;
  struct DListNode *prev;
  struct DListNode *next;
}DListNode;

typedef struct {
  DListNode *H;
  DListNode *T;
  int N;
}DListType;

DListNode* getNode() {
  DListNode *node = (DListNode*)malloc(sizeof(DListNode));
  node -> next = node -> prev = NULL;
  return node;
}

void init(DListType *DL) {
  DL -> H = getNode();
  DL -> T = getNode();
  //처음 만들때 H와 T 가 서로를 가리키게 만듬, 양끝은 Null 이라는거 잊지 말기(head 의 prev 와 tail 의 next)
  DL -> H -> next = DL -> T; 
  DL -> T -> prev = DL -> H;
  DL -> N = 0;
}

void insertFrist(DListType *DL, element e)
{
  DListNode * node = getNode(); //비어있는 node가 하나 만들어짐
  DListNode *p = DL -> H; //이중 연결리스트에서는 head 를 가리킬 수 있음

  node -> data = e;

  node -> prev = p;
  node -> next = p -> next;

  p -> next -> prev = node;
  p -> next = node;

  DL -> N++;
}

void insertLast(DListType *DL, element e)
{
  DListNode * node = getNode(); //비어있는 node가 하나 만들어짐
  DListNode *p = DL -> T; //이중 연결리스트에서는 tail 를 가리킬 수 있음

  node -> data = e;

  node -> next = p;
  node -> prev = p -> prev;

  p -> prev -> next = node;
  p -> prev = node;

  DL -> N++;
}

void insert(DListType *DL, int pos, element e)
{  
  if(pos < 1 || pos > DL -> N + 1)
    printf("invaild position!\n");

  else if(pos == 1)
    insertFrist(DL, e);

  else if(pos == DL -> N + 1)
    insertLast(DL, e);
  
  else {
    DListNode *node = getNode(); //비어있는 node가 하나 만들어짐
    DListNode *p = DL -> H;
    for(int i = 1; i < pos; i++)
      p = p -> next;
    
    node -> data = e;

    node -> prev = p;
    node -> next = p -> next;

    p -> next -> prev = node;
    p -> next = node;
  }
}

element delete(DListType *DL, int pos) {
    element e = -1;

    if(pos < 1 || pos > DL -> N)
      printf("invaild position!\n");
    
    else {
      DListNode * p = DL -> H;

      for(int i = 0; i < pos; i++)
        p = p -> next;
      
      e = p -> data;

      p -> prev -> next = p -> next;
      p -> next -> prev = p -> prev;

      free(p);
      DL -> N--;
    }
    return e;
}

//head 의 다음노드 즉, 첫번째 노드부터 Tail을 만나기 전까지 출력
void print(DListType *DL) {
  DListNode *p;
  p = DL -> H;
  for(p = p -> next; p != DL -> T; p = p -> next)
    printf("[%c] <=> ", p -> data);
  
  printf("\b\b\b\b   \n");


}

int main() {
  DListType DL;
  init(&DL); // head 와 tail 의 관리가 한군데서 이뤄진다는 장점 그렇지 않으면 H, T 를 각각 malloc 를 사용해서 main 에서 선언한뒤에 함수들에 H, T 의 값 두개를 계속 넣어줘야함
  insertFrist(&DL, 'A'); print(&DL);
  insertFrist(&DL, 'B'); print(&DL); 

  insertLast(&DL, 'C'); print(&DL);
  insert(&DL, 2, 'D'); print(&DL);

  printf("[%c] is deleted\n" , delete(&DL, 3)); print(&DL);

  return 0;
}