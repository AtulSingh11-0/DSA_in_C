#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct stack {
	char ar[SIZE];
	int top;
} St;

void push (St *, char);
char pop (St *);
char peek (St);
int isFull (St);
int isEmpty (St);
void infixToPostfix (char [], char []);
int getPriority (char);

void main () {
	char expression[SIZE], result[SIZE];
	
	printf("\nEnter the Expression : ");
	fgets(expression, SIZE, stdin);
	
	infixToPostfix (expression, result);
	
	printf("\nThe Posfix Expression is : ");
	puts(result);
}

void push (St *s, char value) {
	s -> ar[++s -> top] = value;
}

char pop (St *s) {
	return s -> ar[s -> top--];
}

char peek (St s) {
	return s.ar[s.top];
}

int isFull (St s) {
	if( s.top == SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty (St s) {
	if( s.top == -1)
		return 1;
	else
		return 0;
}

void infixToPostfix (char expression[], char result[]) {
	St s;
	s.top = -1;
	int i,j;
	char ch;
	
	for (i = 0, j = 0; expression[i] != '\0'; i++) {
		if(expression[i] == ' ')
			continue;
		else if ( expression[i] == '(' || expression[i] == '{' || expression[i] == '[' )
			push(&s, expression[i]);
		else if ( (expression[i] >= 48 && expression[i] <= 57) ||
				  (expression[i] >= 65 && expression[i] <= 90) ||
				  (expression[i] >= 97 && expression[i] <= 122) )  {
			result[j++] = expression[i];		  	
		} else if ( expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			while ( !isEmpty(s) &&
					getPriority(expression[i]) <= getPriority(peek(s)) &&
					peek(s) != '(' ) {
					result[j++] = pop(&s);
				}
			push(&s, expression[i]);
		} else if ( expression[i] == ')' || expression[i] == '}' || expression[i] == ']' ) {
			while ( !isEmpty(s) && (ch = pop(&s)) != '(' ) {
				result[j++] = ch;
			}
		} else {
			break;
		}
		
	}
	if( !isEmpty(s) ) {
		while ( !isEmpty(s) && (ch = peek(s)) != '(') {
			result[j++] = pop(&s);
		}
	}
	result[j] = '\0';
}

int getPriority (char ch) {
	switch (ch) {
		case '+':
		case '-': return 0;
		case '*':
		case '/': return 1;
	}
}