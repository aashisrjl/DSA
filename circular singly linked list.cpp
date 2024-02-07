#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head=NULL;
typedef struct node nodetype;

void insrtfirst()
{
	int x;
	nodetype *newnode;
	newnode=(nodetype*)malloc(sizeof(nodetype));
	printf("Enter data:");
	scanf("%d",&x);
	newnode->data=x;
	if(head==NULL)
	{
		newnode->next=newnode;
		head=newnode;
	}
	else
	{
		nodetype *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		newnode->next=head;
		temp->next=newnode;
		head=newnode;
	}
}

void insrtlast()
{
	nodetype *newnode,*temp;
	newnode=(nodetype*)malloc(sizeof(nodetype));
	printf("\nEnter nodal value:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=head;
	}
}

void display()
{
	nodetype *temp;
	temp=head;
	if(head==NULL)
	{
		printf("List empty :( ");return;
	}
	else
	{
		do
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
}

void del()
{
	nodetype *temp,*prev;
	if(head==NULL)
	{
		printf("List Empty.");return;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		free(head);
		head=temp->next;
	}
}

void dellast()
{
	nodetype *temp,*prev;
	if(head==NULL)
	{
		printf("List empty");
		return;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==head)
		{
			head=NULL;
		}
		else
		{
			prev->next=head;
		}
		free(temp);
	}
}

void insertAtPosition(int pos)
{
    int x, i;
    nodetype *newnode, *temp = head;
    newnode = (nodetype*)malloc(sizeof(nodetype));
    if(newnode == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }
    printf("Enter data:");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    if (pos == 1) {
        insrtfirst();
        return;
    }
    for(i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nPosition out of range!");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtPosition(int pos)
{
    int i;
    nodetype *temp = head, *prev = NULL;
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    if (pos == 1) {
        del();
        return;
    }
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nPosition out of range!");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main()
{
	int ch, pos;
	while(1)
	{
		printf("\n\t1.Insert at First\n\t2.Insert at last\n\t3.Display\n\t4.Delete\n\t5.Delete last\n\t6.Insert at position\n\t7.Delete at position\n\t8.Exit\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insrtfirst();
				break;
			case 2:
				insrtlast();
				break;
			case 3:
				display();
				break;
			case 4:
				del();
				break;
			case 5:
				dellast();
				break;
			case 6:
				printf("Enter position to insert:");
				scanf("%d", &pos);
				insertAtPosition(pos);
				break;
			case 7:
				printf("Enter position to delete:");
				scanf("%d", &pos);
				deleteAtPosition(pos);
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

