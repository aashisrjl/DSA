#include <stdio.h>

// Function prototype
int fibonacci(int n);

int main() {
    int n;

    // Asking the user to input the value of n
    printf("Enter the value of n (n >= 0): ");
    scanf("%d", &n);

    // Checking if the entered value is non-negative
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Calling the function to calculate the nth Fibonacci number
    int result = fibonacci(n);
    printf("The %dth Fibonacci number is: %d\n", n, result);

    return 0;
}

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    // Base case: if n is 0 or 1, return n
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

