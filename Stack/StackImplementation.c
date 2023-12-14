#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Stack{
  int ar[MAX];
  int top;
} Stack;

void push(Stack *, int);
int pop(Stack *);
int peek(Stack);
int isEmpty(Stack);
int isFull(Stack);
void display(Stack);

int main(void) {
  Stack s;
  s.top = -1;
  int choice, val;

  while(1){
    printf("\n1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit\n");
    printf("\nEnter your option > ");
    scanf("%d", &choice);

    switch (choice){
      case 1:
        if(!isFull(s)) {
          printf("\nInput the value > ");
          scanf("%d", &val);
          push(&s, val);
          break;
        } else {
          printf("\nNo more Space\n");
          break;
        }
      case 2:
        if(!isEmpty(s)) {
          printf("\nPopped value > %d\n", pop(&s));
          break;
        } else {
          printf("\nThere is nothing to Display\n");
          break;
        }
      case 3:
        if(!isEmpty(s)) {
          printf("\nTopmost value is > %d\n", peek(s));
          break;
        } else {
          printf("\nThere is nothing to Display\n");
          break;
        }
      case 4:
        if(!isEmpty(s)) {
          printf("\nValues in the Stack are :\n");
          display(s);
          break;
        } else {
          printf("\nThere is nothing to Display\n");
          break;
        }
      case 5:
        exit(0);
      default:
        printf("Invalid Choice");
    }
  }
  return 0;
}

void push(Stack *s, int val) {
  s->ar[++s->top] = val;
}
int pop(Stack *s) {
  return s->ar[s->top--];
}
int peek(Stack s) {
  return s.ar[s.top];
}
int isEmpty(Stack s) {
  if(s.top == -1)
    return 1;
  else
    return 0;
}
int isFull(Stack s) {
  if(s.top == MAX-1)
    return 1;
  else
    return 0;
}
void display(Stack s) {
  printf("-----\n");
  int temp = s.top;
  while(temp >= 0) {
    printf("| %d |\n", s.ar[temp--]);
    printf("-----\n");
  }
}