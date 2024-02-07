//WAP to insert at beginning and insert at last,delete at beginning and delete at last and display the stack using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
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
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insrtn()
{
	int x,position;
	nodetype *newnode,*left,*right;
	right=head;
	int i=1;
	printf("\nEnter a position:");
	scanf("%d",&position);
	if(position==1)
	{
		insrtfirst();
	}
	else
	{
		while(i!=position)
		{
			i++;
			left=right;
			right=right->next;
		}
		newnode=(nodetype*)malloc(sizeof(nodetype));
		printf("\nEnter the data:");
		scanf("%d",&x);
		newnode->data=x;
		newnode->next=right;
		left->next=newnode;
		return;
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
		return;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->next=NULL;
		temp->next=newnode;
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
		while(temp->next!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
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
}
void delany()
{
	int position;
	nodetype *left,*right,*temp;
	printf("\nEnter position:");
	scanf("%d",&position);
	right=head;
	if(position==1)
	{
		del();
	}
	int i=1;
	while(i!=position)
	{
		i++;
		left=right;
		right=right->next;
	}
	if(right->next==NULL)
	{
		left->next=NULL;
		free(right);
	}
	else
	{
		temp=right->next;
		left->next=temp;
		free(right);
	}
	return;
}
void dellast()
{
	nodetype *temp;
	if(head==NULL)
	{
		printf("List empty");
		return;
	}
	else
	{
		if(head->next==NULL)
		{
			temp=head;
			head=NULL;
			free(temp);
			return;
		}
		else
		{
			temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			free(temp->next);
			temp->next=NULL;
		}
	}
	
}
int main()
{
		int ch,c;
		do{
			system("CLS");
			printf("\n\t1.Insert at First\n\t2.Insert at any position\n\t3.Insert at last\n\t4.Display\n\t5.Delete\n\t6.Delete at any position\n\t7.Delete at last\n\t8.Exit\n");
			printf("Enter the choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:insrtfirst();break;
				case 2:insrtn();break;
				case 3:insrtlast();break;
				case 4:display();break;
				case 5:del();break;
				case 6:delany();break;
				case 7:dellast();break;
				case 8:exit(1);break;
				default: printf("invalid choice..");
			}
		 printf("Enter 0 to return to the main menu \n other number to exit: ");
        scanf("%d", &c);
		}while(c==0);
		getch();
}
