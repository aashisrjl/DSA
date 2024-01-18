#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

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

int main() {
    q queue;
    int ch;
    int choice;
    int x, y;
    
    //initialize
    queue.front = queue.rear = N - 1;

    do {
        printf("\n 1. Enqueue \n");
        printf("\n 2. Dequeue \n");
        printf("\n 3. Exit \n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\n Enter a number to push: \n");
                scanf("%d", &x);
                enqueue(&queue, x);
                break;

            case 2:
                y = dequeue(&queue);
                printf("\n\n Dequeued item is : %d", y);
                break;

            case 3:
                exit(1);
                break;

            default:
                printf("\n Enter 0 for a repeat the task \n");
                scanf("%d", &choice);
        }
    } while (choice == 0);

    return 0;
}

int empty(q *queue) {
    return (queue->front == queue->rear);
}

int full(q *queue) {
    return ((queue->rear + 1) % N == queue->front);
}

void enqueue(q *queue, int item) {
    if (full(queue)) {
        printf("\nQueue is full, cannot enqueue.\n");
    } else {
        queue->rear = (queue->rear + 1) % N;
        queue->items[queue->rear] = item;
    }
}

int dequeue(q *queue) {
    int item;
    if (empty(queue)) {
        printf("\nQueue is empty, cannot dequeue.\n");
        return -1;
    } else {
        queue->front = (queue->front + 1) % N;
        item = queue->items[queue->front];
        return item;
    }
}

