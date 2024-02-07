#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node nodetype;

nodetype *front = NULL;
nodetype *rear = NULL;

void insrtlast() {
    nodetype *newnode;
    newnode = (nodetype *)malloc(sizeof(nodetype));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nEnter data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void del() {
    nodetype *temp;
    if (front == NULL) {
        printf("Queue Empty.\n");
        return;
    }
    temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

void display() {
    nodetype *temp;
    temp = front;
    if (front == NULL) {
        printf("List empty :(\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int ch, c;
    do {
    	system("CLS");
        printf("\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insrtlast();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice..\n");
                break;
        }
        printf("Enter 0 to return to the main menu \n any other number to exit: ");
        scanf("%d", &c);
    } while (c == 0);
        getch();
    return 0;
}

