//Program to implement Binary search tree with creation of tree,traversal(pre,in,post),searching and deletion of node
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
	struct tree *left;
	int info;
	struct tree *right;
}*rt;
void insrt()
{	
	int x;
	struct tree *temp,*root;
	root=rt;
	temp=(struct tree *)malloc(sizeof(struct tree));
	printf("Enter data:");
	scanf("%d",&x);
	temp->left=NULL;
	temp->right=NULL;
	temp->info=x;
	if(root==NULL)
	{
		root=temp;
		rt=root;
		return;
	}
	while(root!=NULL)
	{
		if(temp->info>root->info)
		{
			if(root->right==NULL)
			{
				root->right=temp;
				return;
			}
			else 
			{
				root=root->right;
				continue;
			}
			if(root->left==NULL)
			{
				root->left=temp;
				return;
			} 
			else 
			{
				root=root->left;
				continue;
			}
		}
		else
		{
			return;
		}
	}
}
void inorder(struct tree *root)
{
	
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\t%d",root->info);
		inorder(root->right);
	}
	return;
}
void preorder(struct tree *root)
{
	
	if(root!=NULL)
	{
		printf("\t%d",root->info);
		preorder(root->left);
		preorder(root->right);
	}
	return;
}
void postorder(struct tree *root)
{
	
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t%d",root->info);
	}
	return;
}
void delnode()
{
	int key;
	struct tree *current,*prev;
	int found;
	current=rt;
	while(current!=NULL)
	{
		printf("Enter the key:");
		scanf("%d",&key);
		if(current->info==key)
		{
			found=1;
			break;
		}
		else
		{
			prev=current;
			if(current->info>=key)
				current=current->left;
			else
				current=current->right;
		}
	}
	if(current->left==NULL && current->right!=NULL)
	{
		if(prev->left==current)
			prev->left=NULL;
		else
			prev->right=NULL;
			free(current);
	}
	if(current->right==NULL && current->left!=NULL)
	{
		if(prev->left==current)
			prev->left=current->left;
		else
			prev->right=current->left;
			free(current);
	}	
	if(current->left!=NULL && current->right!=NULL)
	{
		struct tree *temp=current->right;
		if(temp->left==NULL && temp->right==NULL)
		{
			current->info=temp->info;
			free(temp);
			current->right=NULL;
		}
	}
	if(current->right->left!=NULL)
	{
		struct tree *left_current=current->right;
		struct tree *left_current_prev=current->right->left;
		while(left_current->left!=NULL)
		{
			left_current_prev=left_current;
			left_current=left_current->left;
		}
		current->info=left_current->info;
		free(left_current);
		left_current_prev->left=NULL;
	}
	else
	{
		struct tree *temp;
		temp=current->right;
		current->info=temp->info;
		current->right=temp->right;
		free(temp);
	}
}

int main()
{
	int ch;
	rt=NULL;
	while(1)
	{
		printf("\n\t1.Insert a node\n\t2.Pre-order traversal\n\t3.In-order traversal\n\t4.Post-order traversal\n\t5.Search a node\n\t6.Delete a node\n\t7.Exit\n");
		printf("Enter a choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insrt();break;
			case 2:preorder(rt);break;
			case 3:inorder(rt);break;
			case 4:postorder(rt);break;
			case 6:delnode();break;
			case 7:exit(1);break;
			default: printf("Invalid choice....");
		}
		
	}getch();
}
