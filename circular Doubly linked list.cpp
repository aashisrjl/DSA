#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node NodeType;

NodeType* head = NULL;

void insertFirst(int data) {
    NodeType* newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int data) {
    NodeType* newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        NodeType* temp = head->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NodeType* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
    }
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NodeType* temp = head->prev;
    if (head->next == head) {
        head = NULL;
    } else {
        temp->prev->next = head;
        head->prev = temp->prev;
    }
    free(temp);
}

void insertAtPosition(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    NodeType* newNode = (NodeType*)malloc(sizeof(NodeType));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        if (pos == 1) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            printf("Invalid position\n");
            return;
        }
    } else {
        NodeType* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count != pos - 1) {
            printf("Invalid position\n");
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteAtPosition(int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position or list is empty\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    NodeType* temp = head;
    int count = 1;
    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NodeType* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position;

    while (1) {
    	
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Insert at position\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertFirst(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertLast(data);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

