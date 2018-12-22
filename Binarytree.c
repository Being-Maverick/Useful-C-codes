#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
}Btree;
typedef struct nodetype
{
	Btree *info;
	struct nodetype *next;
}SQ;
SQ *top=NULL,*front=NULL,*rear=NULL;
Btree *root=NULL;
void push(SQ **top,Btree *ptr)
{
	SQ *newptr=(SQ*)malloc(sizeof(SQ));
	newptr->info=ptr;
	if((*top)==NULL)
	{
    newptr->next=NULL;
	(*top)=newptr;
	}else
	{
		newptr->next=(*top);
		(*top)=newptr;
	}
}
Btree *pop(SQ **top)
{
	if((*top==NULL))
	return NULL;
	Btree *q=(*top)->info;
	SQ *ptr=(*top);
	(*top)=(*top)->next;
	free(ptr);
	return q;
}

void enqueue(SQ **front,SQ **rear,Btree *ptr)
{
	SQ *newptr=(SQ*)malloc(sizeof(SQ));
	newptr->info=ptr;
	newptr->next=NULL;
	if((*front)==NULL)
	(*front)=(*rear)=newptr;
	
	else
	{
		(*rear)->next=newptr;
		(*rear)=newptr;
	}
}
Btree *dequeue(SQ **front,SQ **rear)
{
	Btree *q=(*front)->info;
	SQ *old=(*front);
	(*front)=(*front)->next;
	if((*front)==NULL)
	(*rear)=NULL;
	
	free(old);
	return q;
}
void deleteStack(SQ **top)
{
	SQ *ptr;
	while((*top)!=NULL)
	{
		ptr=(*top);
		(*top)=(*top)->next;
		free(ptr);
	}
}
void deleteQueue(SQ **front,SQ **rear)
{
	SQ *ptr;
	while((*front)!=NULL)
	{
		ptr=(*front);
		(*front)=(*front)->next;
		free(ptr);
	}
	(*rear)=NULL;
}
int isemptyStack(SQ *top)
{
	return (top==NULL);
}
int isemptyQueue(SQ *front,SQ *rear)
{
	return (front==NULL);
}
void insert(Btree **root,int val)
{
	Btree *newptr=(Btree *)malloc(sizeof(Btree));
	if(newptr==NULL)
	{
		printf("Insufficient Memory\n");
		return;
	}
	(newptr->left)=(newptr->right)=NULL;
	newptr->info=val;
	if((*root)==NULL)
	{
		(*root)=newptr;
		return;
	}
	enqueue(&front,&rear,(*root));
	while(!(isemptyQueue(front,rear)))
	{
		Btree *ptr=dequeue(&front,&rear);
		if(ptr->left!=NULL)
		enqueue(&front,&rear,ptr->left);
		else
		{
			ptr->left=newptr;
			deleteQueue(&front,&rear);
			return;
	    }
	    if(ptr->right!=NULL)
	    enqueue(&front,&rear,ptr->right);
	    else
	    {
		 ptr->right=newptr;
		 deleteQueue(&front,&rear);
		 return;
        }
	}
	deleteQueue(&front,&rear);
}
void PreOrder(Btree *root)
{
	while(1)
	{
		while(root!=NULL)
		{
			printf("%d ",root->info);
			push(&top,root);
			
			root=root->left;
		}
		if(isemptyStack(top))
		break;
		
		root=pop(&top);
		root=root->right;
	}
	deleteStack(&top);
}
void InOrder(Btree *root)
{
	while(1)
	{
    	while(root!=NULL)
		{
			push(&top,root);
			root=root->left;
		}
		if(isemptyStack(top))
		break;
		
		root=pop(&top);
		printf("%d ",root->info);
		root=root->right;
	}
	deleteStack(&top);
}
Btree *peek(SQ *top)
{   
	if(top==NULL)
	return NULL;
	return top->info;
}
void PostOrder(Btree *root)
{
	if(root==NULL)
	return;
	
	do
	{
	while(root!=NULL)
	{
		if(root->right!=NULL)
		push(&top,root->right);
		
		push(&top,root);
		root=root->left;
	}
	root=pop(&top);
	if(root->right && peek(top)==root->right)
	{
		pop(&top);
		push(&top,root);
		
		root=root->right;
	}
	else
	{
		printf("%d ",root->info);
		root=NULL;
	}
    }while(!isemptyStack(top));
}
void LevelOrder(Btree  *root)
{
	Btree *ptr;
	if(root==NULL)
	return;
	enqueue(&front,&rear,root);
	while(!(isemptyQueue(front,rear)))
	{
		ptr=dequeue(&front,&rear);
		printf("%d ",ptr->info);
		if(ptr->left)
		enqueue(&front,&rear,ptr->left);
		if(ptr->right)
		enqueue(&front,&rear,ptr->right);
	}
	deleteQueue(&front,&rear);
}
void deleteBinaryTree(Btree **root)
{
	if((*root)==NULL)
	return;
	
	deleteBinaryTree((&(*root)->left));
	deleteBinaryTree((&(*root)->right));
	free(root);
}
void main()
{
	int n;
	printf("Enter the number of elements to be inserted in the binary tree\n");
	scanf("%d",&n);
	
	int i=0,val;
	printf("Enter the elements of the binary tree\n");
	for(;i<n;i++)
	{
		scanf("%d",&val);
		insert(&root,val);
	}
	printf("The preorder traversal is \n");
	PreOrder(root);
	printf("\nThe InOrder traversal is\n");
	InOrder(root);
	printf("\nThe PostOrder traversal is\n");
	PostOrder(root);
	printf("\nThe LevelOrder traversal is\n");
	LevelOrder(root);
	deleteBinaryTree(&root);
	getch();
}
