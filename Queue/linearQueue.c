#include<stdio.h>
#include<stdlib.h>

#define max 50

typedef struct Queue {
  int val[max];
  int front, rear;
}
qu;

void enqueu(qu * , int);
int dequeu(qu * );
int peek(qu);

int isempty(qu);
int isfull(qu);

void disp(qu);

int main() {
  int ch, v;
  qu q;
  q.front = q.rear = -1;
  while (1) {
    printf("\n1) Insert \n2) Delete \n3) Front value\n4) Display\n5) Exit");
    printf("\n\nEnter the choice : ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      if (!isfull(q)) {
        printf("\n Enter the value : ");
        scanf("%d", & v);
        enqueu( & q, v);
      } else
        printf("\nNo more space");
      break;
    case 2:
      if (!isempty(q)) {
        v = dequeu( & q);
        printf("\nThe deleted value from the front is %d", v);
      } else
        printf("\nNothing to delete");
      break;
    case 3:
      if (!isempty(q)) {
        printf("\nThe Value at the front is %d", peek(q));
      } else
        printf("\nNothing in the queue");
      break;
    case 4:
      if (!isempty(q)) {
        printf("\nValues are");
        disp(q);
      } else
        printf("\nNothing in the queue");
      break;
    case 5:
      exit(1);
    default:
      printf("\nNot in the menu");
    }
  }
}

void enqueu(qu * q, int f) {
  int i;
  if (q -> front == -1)
    q -> front = q -> rear = 0;
  else if (q -> rear == max - 1) {
    for (i = q -> front; i <= q -> rear; i++)
      q -> val[i - (q -> front)] = q -> val[i];
    q -> rear = i - (q -> front);
    q -> front = 0;
  } else
    q -> rear++;
  q -> val[q -> rear] = f;
}

int dequeu(qu * q) {
  int g;
  g = q -> val[q -> front];
  if (q -> front == q -> rear)
    q -> front = q -> rear = -1;
  else
    q -> front++;
  return g;
}

int peek(qu p) {
  return p.val[p.front];
}

int isempty(qu p) {
  if (p.front == -1)
    return 1;
  else
    return 0;
}

int isfull(qu q) {
  if (q.front == 0 && q.rear == max - 1)
    return 1;
  else
    return 0;
}

void disp(qu q) {
  int g;
  g = q.front;
  for (; g <= q.rear; g++)
    printf("\n%d", q.val[g]);
}