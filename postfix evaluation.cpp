#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

void push(int);
int pop();

int vstack[100];
int top = -1;

void push(int item) {
    if(top >= 99) {
        printf("\nStack Overflow.");
        return;
    }
    vstack[++top] = item;
}

int pop() {
    if(top < 0) {
        printf("\nStack Underflow.");
        exit(1);
    }
    return vstack[top--];
}

int main() {
    int i, value, res, l, op1, op2;
    char postfix[100], ch, input[10];

    printf("Enter a valid postfix expression: ");
    fgets(postfix, 100, stdin); // Use fgets instead of gets
    postfix[strcspn(postfix, "\n")] = 0; // Remove the newline character
    l = strlen(postfix);

    for(i = 0; i < l; i++) {
        if(isalpha(postfix[i])) {
            printf("Enter value of %c: ", postfix[i]);
            scanf("%d", &value);
            while(getchar() != '\n'); // Clear the input buffer
            push(value);
        } else {
            ch = postfix[i];
            op2 = pop();
            op1 = pop();
            switch(ch) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if(op2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    push(op1 / op2);
                    break;
                case '$':
                    push((int)pow((double)op1, (double)op2));
                    break;
                case '%':
                    push(op1 % op2);
                    break;
            }
        }
    }
    printf("The result is: ");
    res = pop();
    printf("%d\n", res);

    return 0;
}

