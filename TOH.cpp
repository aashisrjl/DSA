#include <stdio.h>

// Function to move a disk from source to destination
void moveDisk(int disk, char source, char destination) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

// Function to implement Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    moveDisk(n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Number of disks must be at least 1.\n");
        return 1;
    }

    // Towers are labeled as A, B, and C
    towerOfHanoi(n, 'A', 'B', 'C');
    
    return 0;
}

