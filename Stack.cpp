#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <math.h>
#define N 10

struct stack {
    int items[N];
    int top;
};
typedef struct stack s;

int Isempty(s stack) {
    return (stack.top == -1);
}

int Isfull(s stack) {
    return (stack.top == N - 1);
}

void push(s *stack, int data) {
    if (Isfull(*stack)) {
        printf("\nThere is overflow\n");
    } else {
        stack->top++;
        stack->items[stack->top] = data;
        printf("\n%d data is pushed to the stack\n",data);
    }
}

void pop(s *stack, int data) {
    if (Isempty(*stack)) {
        printf("\nThere is no data to pop\n");
    } else {
        //stack->top--;
        data = stack->items[stack->top--];
        printf("\nPOP item is: %d \n",data);
        
    }
}

int main() {
    s stack;
    stack.top = -1; //  top to -1

    int n;
    int data;
    int choice;
    char name[10];
    printf("\n ||Enter your name to start action:|| \n");
    scanf("%s",&name);
    do{
    	 system("CLS");
    	 printf(" \n \t\t ****** Dear %s you are welcome **********\n",name);
    	 printf("\n------------------------------------------------\n");
    printf("1. \t Dear %s Enter 1 for push the data:\n",name);
    printf("2. \t Dear %s Enter 2 for pop the data: \n",name);
    printf("3. \t Dear %s Enter 3 to see the stack data: \n",name);
    scanf("%d", &n);
    system("CLS");

    switch (n) {
        case 1:
        	 system("CLS");
        	 printf(" \n \t\t ****** Dear %s you can perform Push Operation **********\n",name);
            printf("\n======= Pushing the data onto the stack =======\n");
            printf("\nEnter data to push: \n");
            scanf("%d", &data);
            push(&stack, data);
            break;
            
        case 2:
        	 system("CLS");
        	printf(" \n \t\t ****** Dear %s you can perform Pop Operation **********\n",name);
            printf("\n======= Popping the data from the stack =======\n");
            pop(&stack,data);
            break;
            
        case 3:
        	 system("CLS");
        	 printf(" \n \t\t ****** Dear %s your stack data are as follow **********\n",name);
        	printf("===Displaying stack data:=====\n");
        	for(int i=0;i<=stack.top;i++){
        		printf("%d. %d \n",i,stack.items[i]);
			}
        	break;
        	
        default:
        	system("CLS");
        	printf(" \n \t\t ****** Dear %s  **********\n",name);
            printf("Please enter a valid instruction:\n");
            break;
    }
        printf(" \n \t\t ****** Mr/Mrs %s Thank You ! **********\n",name);
	printf("\n \n ===== press 0(zero) for main menu:=====\n");
	printf(" ===== press 1(zero) for exit:=====\n");
	scanf("%d",&choice);
//	if(choice == 1){
//		exit(1);
//	}
}while(choice == 0);

    return 0;
}

