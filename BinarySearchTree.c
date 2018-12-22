#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodetype
{
	int value;
	struct nodetype *left;
	struct nodetype *right;
	struct nodetype *par;
}Btree;
Btree *minimum(Btree *root)
{
	while(root!=NULL && root->left!=NULL)
	root=root->left;
	
	return root;
}
Btree *maximum(Btree *root)
{
	while(root!=NULL && root->right!=NULL)
	root=root->right;
	
	return root;
}
Btree *search(Btree *root,int val)
{
	while(root!=NULL)
	{
		if(root->value==val)
		break;
		else if(val<root->value)
		root=root->left;
		else
		root=root->right;
	}
	return root;
}
void inorder(Btree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->value);
		inorder(root->right);
	}
}
void preorder(Btree *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->value);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Btree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->value);
	}
}
Btree *successor(Btree *root)
{
	if(root->right!=NULL)
	return minimum(root->right);
	
	Btree *ptr=root->par;
	while(ptr!=NULL && root==ptr->right)
	{
		root=ptr;
		ptr=ptr->par;
	}
	return ptr;
}
void insert(Btree **root,int val)
{
	Btree *ptr=(Btree *)malloc(sizeof(Btree));
	ptr->value=val;
	ptr->left=ptr->right=NULL;
	Btree *newptr,*parentptr;
	if((*root)==NULL)
	{
		(*root)=ptr;
		ptr->par=NULL;
	}
	else
	{
		newptr=(*root);
		parentptr=NULL;
		while(newptr!=NULL)
		{
			parentptr=newptr;
			if((newptr->value)>val)
			newptr=newptr->left;
			else
			newptr=newptr->right;
		}
		if((parentptr->value)>val)
		parentptr->left=ptr;
		else
		parentptr->right=ptr;
		ptr->par=parentptr;
	}
}
Btree *predecessor(Btree *root)
{
	if(root->left!=NULL)
	return maximum(root->left);
	
	Btree *ptr=root->par;
	while(ptr!=NULL && root==ptr->left)
	{
		root=ptr;
		ptr=ptr->par;
	}
	return ptr;
}
void transplant(Btree **root,Btree **sub1,Btree **sub2)
{
	if((*sub1)->par==NULL)
	(*root)=(*sub2);
	else if((*sub1)==(((*sub1)->par)->left))
    ((*sub1)->par)->left=(*sub2);
    else
    (((*sub1)->par)->right)=(*sub2);
    if((*sub2)!=NULL)
    (*sub2)->par=(*sub1)->par;
}
void Delete(Btree **root,Btree **node)
{
	if((*node)->left==NULL)
	transplant(root,node,(&(*node)->right));
	else if((*node)->right==NULL)
	transplant(root,node,(&(*node)->left));
	else
	{
		Btree *ptr;
		ptr=minimum(((*node)->right));
		if(ptr->par!=(*node))
		{
			transplant(root,&ptr,&(ptr->right));
			ptr->right=(*node)->right;
			(ptr->right)->par=ptr;
		}
		transplant(root,node,&ptr);
		ptr->left=(*node)->left;
		(ptr->left)->par=ptr;
	}
	free((*node));
}

void main()
{
	Btree *root=NULL;
	int x;
	printf("Enter the value to be inserted into the binary search tree(except 0)\n");
	scanf("%d",&x);
	do
	{
		insert(&root,x);
		printf("Enter the value to be inserted into the binary search tree(except 0)\n");
		scanf("%d",&x);
	}while(x!=0);
	printf("The inorder traversal is\n");
	inorder(root);
	printf("\nThe preorder traversal is\n");
	preorder(root);
	printf("\nThe postorder traversal is\n");
	postorder(root);
	Btree *ptr,*ptr1;
	printf("\nEnter the value to search\n");
	scanf("%d",&x);
	ptr=search(root,x);
	if(ptr==NULL)
	printf("Element not found\n");
	else
	{
		printf("Element is present\n");
		ptr1=successor(ptr);
		if(ptr1!=NULL)
		printf("It's inorder successor is %d\n",ptr1->value);
		ptr1=predecessor(ptr);
		if(ptr1!=NULL)
		printf("It's inorder predecessor is %d\n",ptr1->value);
		Delete(&root,&ptr);
		printf("The inorder traversal after deleting %d is\n",x);
		inorder(root);
	}
	getch();
}
