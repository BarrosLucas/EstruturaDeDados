#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 27

struct Stack{
	char v[STACK_SIZE];
	int top;
};

void push(struct Stack* s, char c);
char pop(struct Stack* s);
void clear(struct Stack* s);

int main(){
	char firstSequence[STACK_SIZE];
	char secondSequence[STACK_SIZE];
	
	char firstInput[STACK_SIZE*2];
	char secondInput[STACK_SIZE*2];
	
	
	
	long amount;
	
	long counterFirstSequence, counterSecondSequence;
	
	struct Stack stack = {stack.top = -1};
	
	scanf("%d%*c",&amount);
	while(amount != 0){
		counterFirstSequence = 0;
		counterSecondSequence = 0;
		
		fgets(firstInput,STACK_SIZE,stdin);
		fgets(secondInput,STACK_SIZE,stdin);
		
		long i;
		for(i = 0; firstInput[i]!='\0' && firstInput[i]!='\n';i++){
			if(firstInput[i]!=' '){
				firstSequence[counterFirstSequence] = firstInput[i];
				counterFirstSequence++;
			}
			if(secondInput[i]!=' '){
				secondSequence[counterSecondSequence] = secondInput[i];
				counterSecondSequence++;
			}
		}
		
		
		counterFirstSequence = 0;
		for(counterSecondSequence=0; counterSecondSequence < amount; counterSecondSequence++){
			char ultimateCharacter = pop(&stack);
			if(ultimateCharacter != NULL){
				if(ultimateCharacter == secondSequence[counterSecondSequence]){
					printf("R");
					continue;
				}else{
					push(&stack,ultimateCharacter);
				}
			}
			
			while(firstSequence[counterFirstSequence] != secondSequence[counterSecondSequence] && counterFirstSequence < amount){
				push(&stack,firstSequence[counterFirstSequence]);
				printf("I");
				counterFirstSequence ++;
			}
			
			if(counterFirstSequence == amount){
				printf(" Impossible");
				break;
			}else{
				counterFirstSequence++;
				printf("IR");
			}
			
		}
		printf("\n");
		clear(&stack);
		scanf("%d%*c",&amount);
	}
	
	
	
	return 0;
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
