#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 300

struct Stack{
	char v[STACK_SIZE];
	int top;
};

void push(struct Stack* s, char c);
char pop(struct Stack* s);
void clear(struct Stack* s);

int main (void) {
	
	
}

void push(struct Stack* s, char c){
	if (s->top < (STACK_SIZE)){
		s->top++;
		s->v[s->top] = c;
	}else{
		exit(1);
	}
}

char pop(struct Stack* s){
	if (s->top >= 0){
		char tmp = s->v[s->top];
		s->top--;
		return tmp;
	}else{
		
		return NULL;
	}
}

void clear(struct Stack* s){
	do{
		
	}while(pop(s) != NULL);
}
