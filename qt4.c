#include <stdio.h>
#include <stdlib.h>

int main(){
	char expression[1000];
	while (scanf("%s",expression)!=EOF){
		int i;
		int count = 0;
		int isValid = 1;
		for(i=0;expression[i]!='\0' && expression[i] != '\n' && isValid;i++){
			if(expression[i] == '('){
				count ++;
			}else if(expression[i] == ')'){
				if(count == 0){
					isValid = 0;
				}else{
					count --;
				}
			}
		}
		if(isValid){
			if(count == 0){
				printf("correct\n");
			}else{
				printf("incorrect\n");
			}
		}else{
			printf("incorrect\n");
		}
	}
	
	return 0;
}
