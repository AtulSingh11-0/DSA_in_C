#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct Queue {
  int arr[MAX];
  int front, rear;
} qu;

void enqueu(qu *, int);
int dequeu(qu *);
int peek(qu);
int isFull(qu);
int isEmpty(qu);
void display(qu);

void main() {
  qu q;
  q.front = q.rear = -1;

  int choice;
  while(1) {
    printf("\n1) Insert \n2) Delete \n3) Front value\n4) Display\n5) Exit");
    printf("\n\nEnter the choice : ");
    scanf("%d", &choice);

    switch (choice){
    case 1:
      if(!isFull(q)) {
        int value;
        printf("\nInput the value > ");
        scanf("%d", &value);
        enqueu(&q, value);
        break;
      } else {
        printf("\nNot enough space\n");
        break;
      }

    case 2:
      if(!isEmpty(q)) {
        printf("\nDeleted value form the front is > %d\n", dequeu(&q));
        break;
      } else {
        printf("\nQueue is Empty\n");
        break;
      }

    case 3:
      if(!isEmpty(q)) {
        printf("\nValue at front is > %d\n", peek(q));
        break;
      } else {
        printf("\nQueue is Empty\n");
        break;
      }

    case 4:
      if(!isEmpty(q)) {
        printf("\nValues in the Queue are :\n");
        display(q);
        break;
      } else {
        printf("\nNothing to Display\n");
        break;  
      }

    case 5:
      exit(1);
      break;

    default:
      printf("\nInvalid Choice\n");
    }
  }
}

void enqueu(qu *q, int value) {
  int i;

  if(q -> front == -1)
    q -> front = q -> rear = 0;
  else if(q -> rear == MAX - 1){
    for(i = q -> front; i <= q -> rear; i++)
      q -> arr[i - (q -> front)] = q -> arr[i];
    q -> rear = i - (q -> front);
  } else
    q -> rear++;

  q -> arr[q -> rear] = value;
}

int dequeu(qu *q) {
  int v = q -> arr[ q -> front];
  if( q -> front == q -> rear)
    q -> front = q -> rear = -1;
  else
    q -> front++;
  return v;
}

int peek(qu q) {
  return q.arr[q.front];
}

int isFull(qu q) {
  if(q.front == 0 && q.rear == MAX-1)
    return 1;
  else
    return 0;
}

int isEmpty(qu q) {
  if(q.front == -1) 
    return 1;
  else 
    return 0;
}

void display(qu q) {
  int i = q.front;
  printf("\n|");
  for(;i <=  q.rear; i++) {
    printf(" %d |", q.arr[i]);
  }
  printf("\n");
}