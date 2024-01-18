// didn't run ! ok 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<math.h>
void push(int);
int pop();
int vstack[100];
int top=-1;
int main(){

	int i,value[100];
	int res,l,op1,op2;
	char postfix[100],ch;
	
	printf("Enter a valid postfix\n");
	gets(postfix);
	l=strlen(postfix);
		for(i=0;i<=l-1;i++)
		{
			if(isalpha(postfix[i]))
			{
				printf("Enter value of %c",postfix[i]);
				scanf("%d", &value[i]);
				push(value[i]);

			}else{
					ch=postfix[i];
					op2=pop();
					op1=pop();
					switch(ch){
						case '+':
							push(op1+op2);
							break;
							case'-':
								push(op1-op2);
								break;
								case'*':
									push(op1*op2);
									break;
									case'/':
										push(op1/op2);
										break;
										case'$':
											push(pow(op1,op2));
											break;
											case'%':
												push(op1%op2);
												break;

				}
			 }
		}
				printf("The reault is:"); res=pop();
				printf("%d", res);
				
	}
