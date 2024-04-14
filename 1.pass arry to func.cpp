#include <stdio.h>

// Function prototype
void printArray(int arr[], int size);

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    // Calling the function and passing the array
    printArray(myArray, size);

    return 0;
}

// Function to print elements of an array
void printArray(int arr[], int size) {
    printf("Elements of the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

