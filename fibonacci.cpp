#include <stdio.h>

// Function to calculate the nth Fibonacci number recursively
int fibonacci(int n) {
    // Base cases: Fibonacci of 0 and 1 are 0 and 1 respectively
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Enter the value of n for Fibonacci sequence: ");
    scanf("%d", &n);

    // Display Fibonacci sequence
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

