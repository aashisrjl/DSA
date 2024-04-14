#include <stdio.h>

// Function prototype
void displayMultiples(int num, int count);

int main() {
    int number;

    // Asking the user to input a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calling the function to display the first four multiples
    printf("First four multiples of %d are: ", number);
    displayMultiples(number, 1);

    return 0;
}

// Function to display the first four multiples of a number using recursion
void displayMultiples(int num, int count) {
    // Base case: stop recursion when count exceeds 4
    if (count > 4)
        return;

    // Displaying the current multiple
    printf("%d ", num * count);

    // Recursively calling the function with the next multiple
    displayMultiples(num, count + 1);
}

