#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
typedef struct node nodetype;

void insrt()
{
	int x;
	struct node *newnode;
	newnode=(nodetype*)malloc(sizeof(nodetype));
	printf("Enter data:");
	scanf("%d",&x);
	newnode->data=x;
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}

void del()
{
	nodetype *temp;
	if(head==NULL)
	{
		printf("List Empty.");return;
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	printf("Delete item is:%d\n",head->data);
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
		while(temp->next!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}

int main()
{
		int ch,c;
		do{
			system("CLS");
			printf("\n\t1.Insert at First\n\t2.Delete\n\t3.Display\n\t4.Exit\n");
			printf("Enter the choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
						system("CLS");
				insrt();
				break;
				
				case 2:
						system("CLS");
				del();
				break;
				
				case 3:
						system("CLS");
				display();
				break;
				
				case 4:
				exit(1);
				break;
				
				default: printf("invalid choice..");
			}
			 printf("Enter 0 to return to the main menu \n other number to exit: ");
        scanf("%d", &c);
		}while(c==0);
		getch();
}
