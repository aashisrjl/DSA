#include <stdio.h>

// Function to find the GCD of two numbers recursively using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;

    printf("Enter two integers to find their GCD: ");
    scanf("%d %d", &a, &b);

    // Error check: GCD is not defined for negative numbers
    if (a < 0 || b < 0) {
        printf("GCD is not defined for negative numbers.\n");
        return 1; // Exit with error code 1
    }

    // Calculate and display GCD
    printf("GCD of %d and %d is: %d\n", a, b, gcd(a, b));

    return 0;
}

