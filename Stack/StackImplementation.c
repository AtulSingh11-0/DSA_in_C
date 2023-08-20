#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct stack {
	int ar[SIZE];
	int top;
}st;

void push (st *, int);
int pop (st *);
int peek (st);
int isEmpty (st);
int isFull (st);
void display (st);

void main () {
	st s;
	s.top = -1;
	
	int choice, value, poppedValue;
	
	while(1) {
		printf("\n1) Push \n2) Pop \n3) Peek \n4) Display \n5) Exit");
		printf("\nEnter your Choice >> ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				if( !isFull(s) ) {
					printf("\nInput the value >> ");
					scanf("%d", &value);
					push(&s, value);
					break;
				} else {
					printf("\nNo more Space \n");
					break;
				}
			case 2:
				if( !isEmpty(s) ) {
					poppedValue = pop(&s);
					printf("\nPopped value is >> %d \n", poppedValue);
					break;
				} else {
					printf("\nThere is nothing to Display \n");
					break;
				}
			case 3:
				if( !isEmpty(s) ) {
					printf("\nTopmost value is >> %d \n", peek(s));
					break;
				} else {
					printf("\nThere is nothing to Display \n");
					break;
				}
			case 4:
				if( !isEmpty(s) ) {
					printf("\nValues in the Stack are : \n");
					display(s);
					break;
				} else {
					printf("\nThere is nothing to Display \n");
					break;
				}
			case 5:
				exit(0);
			default:
				printf("\nWrong Choice \n");
		}
	}
}

void push (st *s, int value) {
	s->ar[++s->top] = value;
}

int pop (st *s) {
	return s->ar[s->top--];
}

int peek (st s) {
	return s.ar[s.top];
}

int isFull (st s) {
	if( s.top == SIZE-1)
		return 1;
	else
		return 0;
}

int isEmpty (st s) {
	if(s.top == -1)
		return 1;
	else
		return 0;
}

void display(st s) {
	int index = s.top;
	printf("-----\n");
	while(index >= 0) {
		printf("| %d | \n", s.ar[index--]);
		printf("-----\n");
	}
}