#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int precedence(char ch);
void reverseString(char *str);
void infixToPrefix(char *infix, char *prefix);
void infixToPostfix(char *infix, char *postfix);
void swapParentheses(char *expr);

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline character if present

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}

void infixToPrefix(char *infix, char *prefix) {
    char reversedInfix[MAX_SIZE], postfix[MAX_SIZE];
    
    // Reverse the infix expression
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);
    // Correct the parentheses
    swapParentheses(reversedInfix);

    // Convert reversed infix to postfix
    infixToPostfix(reversedInfix, postfix);

    // Reverse the postfix expression to get prefix expression
    strcpy(prefix, postfix);
    reverseString(prefix);
}

void infixToPostfix(char *infix, char *postfix) {
    int i, l;
    int op_stack_top = -1;
    char opstack[MAX_SIZE], temp[MAX_SIZE + 1] = {0}; // Initialize temp array
    
    l = strlen(infix);

    for (i = 0; i < l; i++) {
        if (isalnum(infix[i])) {
            strncat(temp, &infix[i], 1); // Append alphanumeric characters directly to temp
        } else if (infix[i] == '(') {
            opstack[++op_stack_top] = infix[i];
        } else if (infix[i] == ')') {
            while (op_stack_top != -1 && opstack[op_stack_top] != '(') {
                strncat(temp, &opstack[op_stack_top--], 1); // Append operators to temp
            }
            op_stack_top--; // Pop '(' from the stack
        } else {
            while (op_stack_top != -1 && precedence(opstack[op_stack_top]) >= precedence(infix[i])) {
                strncat(temp, &opstack[op_stack_top--], 1);
            }
            opstack[++op_stack_top] = infix[i];
        }
    }

    while (op_stack_top != -1) { // Pop any remaining operators from the stack
        strncat(temp, &opstack[op_stack_top--], 1);
    }

    strcpy(postfix, temp);
}

void swapParentheses(char *expr) {
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') expr[i] = ')';
        else if (expr[i] == ')') expr[i] = '(';
    }
}

// Implement other functions (reverseString, precedence) as before

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

