#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

void enqueue(PriorityQueue* pq) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }
    
    Element newElement;
    printf("Enter data to enqueue: ");
    scanf("%d", &newElement.data);
    printf("Enter priority of the data: ");
    scanf("%d", &newElement.priority);
    
    int i = pq->size - 1;
    while (i >= 0 && pq->elements[i].priority > newElement.priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }
    pq->elements[i + 1] = newElement;
    pq->size++;
}

Element dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    
    Element dequeuedElement = pq->elements[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;
    
    return dequeuedElement;
}

void displayPriorityQueue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    
    printf("Priority Queue elements (data, priority):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, %d) ", pq->elements[i].data, pq->elements[i].priority);    }
    printf("\n");
}

int main() {
    PriorityQueue* pq = createPriorityQueue();
    int choice;
    
    do {
        printf("\nPriority Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue(pq);
                break;
            case 2:
                if (pq->size > 0) {
                    Element elem = dequeue(pq);
                    printf("Dequeued: (%d, %d)\n", elem.data, elem.priority);
                } else {
                    printf("Priority Queue is empty. Cannot dequeue.\n");
                }
                break;
            case 3:
                displayPriorityQueue(pq);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    
    free(pq);
    
    return 0;
}

