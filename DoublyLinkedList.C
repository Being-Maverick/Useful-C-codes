#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodetype
{
	int info;
	struct nodetype *prev;
	struct nodetype *next;
}node;
void inorder(node *head)
{
	if(head!=NULL)
	{
		inorder(head->prev);
		printf("%d ",head->info);
		inorder(head->next);
	}
}
node *findmid(node *head)
{
	node *p,*q;
	p=head;
	q=head;
	while(p!=NULL || p->next!=NULL)
	{
		q=q->next;
		p=(p->next)->next;
	}
	return q;
}
node *dlltobst(node *head)
{
	node *temp,*p,*q;
	if(head!=NULL && head->next!=NULL)
	return head;
	
	temp=findmid(head);
	p=head;
	while(p->next!=temp)
	{
		p=p->next;
	}
	p->next=NULL;
	q=temp->next;
	temp->prev=dlltobst(head);
	temp->next=dlltobst(q);
	return temp;
}

void add(node **head,node **tail,int value,int pos)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->info=value;
	
	if(pos==1)
	{
	ptr->prev=NULL;
	if((*head)==NULL)
	{
	ptr->next=NULL;
	}
	else
	{
	ptr->next=(*head);
	(*head)->prev=ptr;
	}
	(*head)=ptr;
	return;
    }
	node *temp=(*head);
	int k=1;
	while(k<(pos-1) && temp!=NULL)
	{
	temp=temp->next;
	k++;
	}
	if(k!=(pos-1))
	{
	printf("Desired position doesn't exist\n");
	return;
    }
	ptr->next=temp->next;
	ptr->prev=temp;
	if((temp->next)!=NULL)
	(temp->next)->prev=ptr;
	else
	(*tail)=ptr;
	
	temp->next=ptr;
	}
	void traverse(node *head)
	{
	node *temp=head;
	while(temp!=NULL)
	{
	printf("%d\n",temp->info);
	temp=temp->next;
	}	
	}
	void reversetraverse(node *tail)
	{
	node *temp=tail;
	while(temp!=NULL)
	{
	printf("%d\n",temp->info);
	temp=temp->prev;
	}
	}
	
	void del(node **head,node **tail,int pos)
	{
	node *temp,*ptr;
	temp=(*head);
	if((*head)==NULL)
	{
	printf("List is empty\n");
	return;
	}
	if(pos==1)
	{
	(*head)=(*head)->next;
	if((*head)==NULL)
	(*tail)=NULL;
	else
	(*head)->prev=NULL;
	free(temp);
	return;
	}
	int k=1;
	while(k<pos && (temp->next)!=NULL)
	{
	k++;
	temp=temp->next;
	}
	if(k!=pos)
	printf("Desired position doesn't exist\n");
    
    ptr=temp->prev;
    ptr->next=temp->next;
    
    if((temp->next) != NULL)
	temp->next->prev=ptr;
	
	else
	(*tail)=(*tail)->prev;
	
	free(temp);
	}
	void dispose(node **head,node **tail)
	{
	node *temp;
	while((*head)!=NULL)
	{
	temp=(*head);
	(*head)=(*head)->next;
	free(temp);
	}	
	(*tail)=NULL;
	}
	int main()
	{
	int choice;
	node *head,*tail;
	head=tail=NULL;
	printf("Enter ur choice \n1:To add an element \n2:To delete an element\n 3:Forward traversal \n4:Reverse traversal\n 5:Exit\n");	
	scanf("%d",&choice);
	do
	{
	switch(choice)
	{
	case 1:printf("Enter the element and position\n");
	       int val,pos;
	       scanf("%d%d",&val,&pos);
	       add(&head,&tail,val,pos);
	       break;
	case 2:printf("Enter the position\n");
	       scanf("%d",&pos);
	       del(&head,&tail,pos);
	       break;
	case 3:printf("Forward traversal is\n");
	       traverse(head);
	       break;
	case 4:printf("Reverse order traversal is\n");
	       reversetraverse(tail);
	       break;
	}	
	scanf("%d",&choice);
	}while(choice!=5);
	printf("Convert the doubly linked list into BST\n");
	printf("The inorder traversal is\n");
	node *ptr=dlltobst(head);
	inorder(ptr);
	dispose(&head,&tail);
	getch();
	return 0;
	}
	
