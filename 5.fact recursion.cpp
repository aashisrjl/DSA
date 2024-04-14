#include <stdio.h>

// Function prototype
int factorial(int n);

int main() {
    int number;

    // Asking the user to input a number
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    // Checking if the entered number is non-negative
    if (number < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Calling the function to calculate factorial
    int result = factorial(number);
    printf("Factorial of %d is: %d\n", number, result);

    return 0;
}

// Function to calculate factorial using recursion
int factorial(int n) {
    // Base case: if n is 0 or 1, factorial is 1
    if (n == 0 || n == 1)
        return 1;
    // Recursive case: factorial of n is n * factorial(n-1)
    else
        return n * factorial(n - 1);
}

