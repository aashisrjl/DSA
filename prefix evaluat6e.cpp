#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 100

int vstack[MAX_SIZE];
int top = -1;

void push(int);
int pop();

void push(int item) {
    if(top >= MAX_SIZE - 1) {
        printf("\nStack Overflow.");
        exit(1);
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
    char prefix[MAX_SIZE], ch;

    printf("Enter a valid prefix expression: ");
    fgets(prefix, MAX_SIZE, stdin);
    prefix[strcspn(prefix, "\n")] = 0;
    l = strlen(prefix);

    for(i = l - 1; i >= 0; i--) { // Start from the end of the string
        if(isalpha(prefix[i])) {
            printf("Enter value of %c: ", prefix[i]);
            scanf("%d", &value);
            push(value);
        } else if (isdigit(prefix[i])) {
            int num = 0;
            while (isdigit(prefix[i])) {
                num = num * 10 + (prefix[i] - '0');
                i--;
            }
            i++; // Move back to the last digit of the number
            push(num);
        } else {
            ch = prefix[i];
            op1 = pop();
            op2 = pop();
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

