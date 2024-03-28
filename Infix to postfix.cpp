#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_SIZE 100

int precedence(char);

int main() {
    int i, l;
    int op_stack_top = -1;
    int post_stack_top = -1;
    char infix[MAX_SIZE], poststack[MAX_SIZE], opstack[MAX_SIZE];
    
    printf("\nEnter an infix expression:\n");
    gets(infix);
    l = strlen(infix);
    
    for (i = 0; i < l; i++) {
        if (infix[i] == '(') {
            opstack[++op_stack_top] = infix[i];
        } else if (isalnum(infix[i])) {
            poststack[++post_stack_top] = infix[i];
        } else if (infix[i] == ')') {
            while (opstack[op_stack_top] != '(') {
                poststack[++post_stack_top] = opstack[op_stack_top];
                op_stack_top--;
            }
            op_stack_top--;
        } else {
            while (op_stack_top != -1 && precedence(opstack[op_stack_top]) >= precedence(infix[i])) {
                poststack[++post_stack_top] = opstack[op_stack_top--];
            }
            opstack[++op_stack_top] = infix[i];
        }
    }

    // Pop remaining operators from opstack to poststack
    while (op_stack_top != -1) {
        poststack[++post_stack_top] = opstack[op_stack_top--];
    }

    // Displaying the postfix expression
    printf("\nThe postfix expression is:\n");
    for (i = 0; i <= post_stack_top; i++) {
        printf("%c", poststack[i]);
    }
    printf("\n");

    return 0;
}

int precedence(char ch) {
    switch (ch) {
        case '$':
        case '^':
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 1;
    }
}

