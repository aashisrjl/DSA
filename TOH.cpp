#include <stdio.h>

// Function prototype
void towerOfHanoi(int n, char source, char auxiliary, char destination);

int main() {
    int numDisks;

    // Asking the user to input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Calling the function to solve Tower of Hanoi problem
    printf("Steps to solve Tower of Hanoi with %d disks:\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}

// Function to solve Tower of Hanoi problem using recursion
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: If there's only one disk, move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the remaining disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

