#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
int precendency(char);

int main(){
	int i,l,l1;
	int op_stack_top = -1;
	int post_stack_top = -1;
	char infix[100], poststack[100], opstack[100];
	
	printf("\n Enter a infix:\n");
	gets(infix);
	l= strlen(infix);
	l1 = l;
	
	for(i=0;i<l-1;i++){
		if(infix[i] == '('){
			opstack[++op_stack_top] = infix[i];
			l1++;
		}
		else if(isalpha(infix[i])){
			poststack[++post_stack_top] = infix[i];
			l1++;
		}
		else if(infix[i] == ')'){
			l1++;
			
			while(opstack[op_stack_top] != '('){
				poststack[++post_stack_top]= opstack[op_stack_top];
				op_stack_top--;
			}
				op_stack_top--;	
		}
		else{
				if(precendency(opstack[	op_stack_top]) >= precendency(infix[i]))
				{
					poststack[post_stack_top] = opstack[op_stack_top--];
					opstack[++op_stack_top]= infix[i];
				}
			}
			while(op_stack_top != -1){
				poststack[++post_stack_top]= opstack[op_stack_top];
				op_stack_top--;
			}
			// dispalying
			for(i=0;i<l1;i++){
				printf(" \nThe post stack is:\n");
				printf("%c",poststack[i]);
			}
		}
		return 0;
	}
	int precendency(char ch){
		switch(ch){
			case '$':
				case '^':
				return 4;
				break;
				
				case '*':
					case '/':
					return 3;
					break;
					
					case '+':
						case '-':
						return 2;
						break;
						
						default:
							return 1;
		}
	}
	
