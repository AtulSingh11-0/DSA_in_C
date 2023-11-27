#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct Queue {
  int val[max];
  int rear, front;
}
qu;

void enque(qu * , int);
int deque(qu * );
int peek(qu);
int isempty(qu);
int isfull(qu);
void disp(qu);

void main() {
  qu q;
  int g, v;
  q.rear = q.front = -1;
  while (1) {
    printf("\n1) Insert\n2) Delete\n3) Peek\n4) Display\n5) Exit");
    printf("\n Enter your choice :");
    scanf("%d", & g);
    switch (g) {
    case 1:
      printf("\n Enter the value");
      scanf("%d", & v);
      if (!isfull(q))
        enque( & q, v);
      else
        printf("\nNo more space");
      break;
    case 2:
      if (!isempty(q))
        printf("\nDeleted element is %d", deque( & q));
      else
        printf("\nNothing to delete");
      break;
    case 3:
      if (!isempty(q))
        printf("\n value at front %d", peek(q));
      else
        printf("\n Nothing in the front");
      break;
    case 4:
      if (!isempty(q)) {
        printf("\nValues int queue : ");
        disp(q);
      } else
        printf("\nNothing to display");
      break;
    case 5:
      exit(0);
    default:
      printf("\n wrong choice");
    }
  }
}

void enque(qu * q, int p) {
  if (q -> rear == -1)
    q -> rear = q -> front = 0;
  else if (q -> rear == max - 1)
    q -> rear = 0;
  else
    q -> rear++;
  q -> val[q -> rear] = p;
}

int deque(qu * q) {
  int g;
  g = q -> val[q -> front];
  if (q -> front == q -> rear)
    q -> rear = q -> front = -1;
  else if (q -> front == max - 1)
    q -> front = 0;
  else
    q -> front++;
  return g;
}

int peek(qu q) {
  return q.val[q.front];
}

int isempty(qu q) {
  if ((q.front == -1 && q.rear == -1))
    return 1;
  else
    return 0;
}

int isfull(qu q) {
  if ((q.front == 0 && q.rear == max - 1) || q.front == q.rear + 1)
    return 1;
  else
    return 0;
}

void disp(qu q) {
  int i;
  if (q.front > q.rear) {
    for (i = q.front; i <= max - 1; i++)
      printf("%d,", q.val[i]);

    for (i = 0; i <= q.rear; i++)
      printf("%d,", q.val[i]);
  } else
    for (i = q.front; i <= q.rear; i++)
      printf("%d,", q.val[i]);
}