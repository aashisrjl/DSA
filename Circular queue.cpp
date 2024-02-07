#include <stdio.h>
#include <stdlib.h>

#define N 5

struct cqueue {
    int items[N];
    int front;
    int rear;
};

typedef struct cqueue q;

int empty(q*);
int full(q*);
void enqueue(q*, int);
int dequeue(q*);
void display(q*);

int main() {
    q queue;
    int ch, c;
    int x, y;

    // Initialize queue
    queue.front = -1;
    queue.rear = -1;

    do {
        system("CLS");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                system("CLS");
                printf("\nEnter a number to push: ");
                scanf("%d", &x);
                enqueue(&queue, x);
                break;

            case 2:
                system("CLS");
                y = dequeue(&queue);
                if (y != -1)
                    printf("\nDequeued item is: %d\n", y);
                break;

            case 3:
                system("CLS");
                printf("\nCurrent queue contents:\n");
                display(&queue);
                break;

            case 4:
                exit(0);
                break;

            default:
                system("CLS");
                printf("\nInvalid choice! Please enter a valid option.\n");
                break;
        }
        printf("Enter 0 to return to the main menu \n other number to exit: ");
        scanf("%d", &c);
    } while (c == 0);

    return 0;
}

int empty(q *queue) {
    return (queue->front == -1);
}

int full(q *queue) {
    return ((queue->rear + 1) % N == queue->front);
}

void enqueue(q *queue, int item) {
    if (full(queue)) {
        printf("\nQueue is full, cannot enqueue.\n");
    } else {
        if (empty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % N;
        }
        queue->items[queue->rear] = item;
    }
}

int dequeue(q *queue) {
    int item;
    if (empty(queue)) {
        printf("\nQueue is empty, cannot dequeue.\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Queue becomes empty after dequeue
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % N;
        }
        return item;
    }
}

void display(q *queue) {
    if (empty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % N) {
            printf("%d ", queue->items[i]);
        }
        printf("%d\n", queue->items[i]); // Print the last element
    }
}

