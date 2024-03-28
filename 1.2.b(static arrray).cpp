#include <stdio.h>

#define MAX_SIZE 100

void addElement(int *arr, int *size, int element) {
    if (*size < MAX_SIZE) {
        *(arr + *size) = element;
        (*size)++;
        printf("Element added successfully.\n");
    } else {
        printf("Array is full. Cannot add more elements.\n");
    }
}

void deleteElement(int *size) {
    if (*size > 0) {
        (*size)--;
        printf("Element deleted successfully.\n");
    } else {
        printf("Array is empty. Cannot delete.\n");
    }
}

void displayArray(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", *(arr + i));
        }
        printf("\n");
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element;

    do {
        printf("\nArray Operations Menu\n");
        printf("1. Add element\n");
        printf("2. Delete element from end\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                addElement(arr, &size, element);
                break;
            case 2:
                deleteElement(&size);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

