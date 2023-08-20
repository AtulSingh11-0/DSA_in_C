#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct stack {
	char ar[SIZE];
	int top;
} St;

char push (St *, char);
char pop (St *);
char peek (St);
char getMatchSymbol (char);
int isFull (St);
int isEmpty (St);
int paranthesisCheck (char []);

void main () {
	char equation[100];
	
	printf("Enter the Equation >> ");
	fgets(equation, 100, stdin);
	
	if(paranthesisCheck(equation)) 
		printf("Paranthesis are OK");
	else
		printf("Paranthesis are not OK");
}

char push (St *s, char value) {
	s -> ar[ ++s -> top] = value;
}

char pop (St *s) {
	return s -> ar[s ->  top--];
}

char peek (St s) {
	return s.ar[s.top];
}

char getMatchSymbol(char ch) {
	switch (ch) {
		case '(': return ')';
		case '{': return '}';
		case '[': return ']';
		case ')': return '(';
		case '}': return '{';
		case ']': return '[';
	}
}

int isFull (St s) {
	if(s.top == SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty (St s) {
	if(s.top == -1) 
		return 1;
	else 
		return 0;
}

int paranthesisCheck (char equation[]) {
	St s;
	s.top = -1;
	int i;
	
	for(i = 0; equation[i]; i++) {
		if( equation[i] == '(' || equation[i] == '{' || equation[i] == '[' )
			push(&s, equation[i]);
		else if ( equation[i] == ')' || equation[i] == '}' || equation[i] == ']' ) {
			if( peek(s) == getMatchSymbol(equation[i]) ) {
				pop(&s);
			} else {
				return 0;
			}
		}
	}
	if( !isEmpty(s))
		return 0;
	else
		return 1;
}