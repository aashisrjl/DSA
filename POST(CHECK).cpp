#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int precedence(char);

void reverseString(char *);

void infixToPrefix(char *, char *);

void infixToPostfix(char *, char *);

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}

void infixToPrefix(char *infix, char *prefix) {
    char reversedInfix[MAX_SIZE], postfix[MAX_SIZE];
    
    // Reverse the infix expression
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    // Convert reversed infix to postfix
    infixToPostfix(reversedInfix, postfix);

    // Reverse the postfix expression to get prefix expression
    strcpy(prefix, postfix);
    reverseString(prefix);
}

void infixToPostfix(char *infix, char *postfix) {
    int i, l;
    int op_stack_top = -1;
    int post_stack_top = -1;
    char opstack[MAX_SIZE], temp[MAX_SIZE];
    
    l = strlen(infix);

    for (i = 0; i < l; i++) {
        if (infix[i] == '(') {
            opstack[++op_stack_top] = infix[i];
        } else if (isalnum(infix[i])) {
            temp[++post_stack_top] = infix[i];
        } else if (infix[i] == ')') {
            while (opstack[op_stack_top] != '(') {
                temp[++post_stack_top] = opstack[op_stack_top--];
            }
            op_stack_top--;
        } else {
            while (op_stack_top != -1 && precedence(opstack[op_stack_top]) >= precedence(infix[i])) {
                temp[++post_stack_top] = opstack[op_stack_top--];
            }
            opstack[++op_stack_top] = infix[i];
        }
    }

    // Pop remaining operators from opstack to temp
    while (op_stack_top != -1) {
        temp[++post_stack_top] = opstack[op_stack_top--];
    }

    // Reverse the postfix expression
    reverseString(temp);

    strcpy(postfix, temp);
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

void reverseString(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

