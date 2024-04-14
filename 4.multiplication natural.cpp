#include <stdio.h>

// Function prototype
int multiply(int n);

int main() {
    int n;

    // Asking the user to input a number
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Checking if the entered number is positive
    if (n < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Calling the function to find the multiplication of natural numbers
    int result = multiply(n);
    printf("Multiplication of first %d natural numbers is: %d\n", n, result);

    return 0;
}

// Function to find the multiplication of natural numbers using recursion
int multiply(int n) {
    // Base case: if n is 0 or 1, return 1
    if (n == 0 || n == 1)
        return 1;
    // Recursive case: multiply n with result of (n-1)
    else
        return n * multiply(n - 1);
}

