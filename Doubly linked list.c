#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

typedef struct node nodetype;

nodetype *front = NULL;
nodetype *rear = NULL;

void dpush() {
    nodetype *newnode;
    newnode = (nodetype*)malloc(sizeof(nodetype));
    printf("\nEnter data:");
    scanf("%d", &newnode->data);
    newnode->next = front;
    newnode->prev = NULL;
    if (front != NULL) {
        front->prev = newnode;
    }
    front = newnode;
    if (rear == NULL) {
        rear = newnode;
    }
}

void dpop() {
    int x;
    nodetype *temp;
    if (front == NULL) {
        printf("\nList Empty!!");
        return;
    }
    x = front->data;
    temp = front;
    front = front->next;
    if (front != NULL) {
        front->prev = NULL;
    } else {
        rear = NULL; // If the list becomes empty after popping
    }
    free(temp);
    printf("\n%d is the deleted item.", x);
}

void dinject() {
    int x;
    nodetype *temp;
    printf("\nEnter data:");
    scanf("%d", &x);
    temp = (nodetype*)malloc(sizeof(nodetype));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL) {
        temp->prev = NULL;
        front = rear = temp;
    } else {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
}

void deject() {
    int x;
    nodetype *temp;
    if (front == NULL) {
        printf("\nList Empty!!");
        return;
    }
    x = rear->data;
    temp = rear;
    rear = rear->prev;
    if (rear != NULL) {
        rear->next = NULL;
    } else {
        front = NULL; // If the list becomes empty after dejecting
    }
    free(temp);
    printf("\n%d is the deleted item.", x);
}

void insertAtPosition(int pos) {
    int i, x;
    nodetype *temp, *newnode;
    if (pos < 1) {
        printf("\nInvalid position!");
        return;
    }
    if (pos == 1) {
        dpush(); // Inserting at the front is the same as pushing
        return;
    }
    temp = front;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nPosition out of range!");
        return;
    }
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if (newnode == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }
    printf("\nEnter data:");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    } else {
        rear = newnode;
    }
    temp->next = newnode;
}

void deleteAtPosition(int pos) {
    int i, x;
    nodetype *temp, *del;
    if (pos < 1 || front == NULL) {
        printf("\nInvalid position or list is empty!");
        return;
    }
    if (pos == 1) {
        dpop(); // Deleting from the front is the same as popping
        return;
    }
    temp = front;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("\nPosition out of range!");
        return;
    }
    del = temp->next;
    x = del->data;
    temp->next = del->next;
    if (del->next != NULL) {
        del->next->prev = temp;
    } else {
        rear = temp;
    }
    free(del);
    printf("\n%d is the deleted item.", x);
}

void display() {
    nodetype *temp;
    temp = front;
    if (temp == NULL) {
        printf("\nList empty..");
        return;
    }
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int ch, pos;
    while (1) {
        printf("\n\t1.Push\n\t2.Pop\n\t3.Inject\n\t4.Deject\n\t5.Insert at Position\n\t6.Delete at Position\n\t7.Display\n\t8.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                dpush();
                break;
            case 2:
                dpop();
                break;
            case 3:
                dinject();
                break;
            case 4:
                deject();
                break;
            case 5:
                printf("\nEnter position to insert:");
                scanf("%d", &pos);
                insertAtPosition(pos);
                break;
            case 6:
                printf("\nEnter position to delete:");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(1);
                break;
            default:
                printf("Invalid choice..");
        }
    }
    getch();
}

