#include <stdio.h>

// Function to calculate factorial recursively
unsigned long long factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive case: factorial of n is n times factorial of (n-1)
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    
    // Input
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    
    // Error check: factorial is not defined for negative numbers
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1; // Exit with error code 1
    }
    
    // Calculate and output factorial
    unsigned long long fact = factorial(n);
    printf("Factorial of %d is: %llu\n", n, fact);
    
    return 0;
}

