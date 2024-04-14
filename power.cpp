#include <stdio.h>

// Function prototype
double power(double base, int exponent);

int main() {
    double base;
    int exponent;

    // Asking the user to input the number
    printf("Enter a number: ");
    scanf("%lf", &base);

    // Asking the user to input the power
    printf("Enter the power to be calculated: ");
    scanf("%d", &exponent);

    // Calling the power function and displaying the result
    double result = power(base, exponent);
    printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, result);

    return 0;
}

// Function to calculate power
double power(double base, int exponent) {
    double result = 1.0;

    // Calculating power using a loop
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

