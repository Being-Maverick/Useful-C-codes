#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct nodetype
{
	int arr[SIZE];
	int front;
	int rear; 
}Queue;
void EnqueueAtFront(Queue **ptr,int n,int val)
{
	if((*ptr)->front==0 && (*ptr)->rear==n-1)
	{
		printf("Queue is full\n");
		return;
	}
	if((*ptr)->front==-1)
	(*ptr)->front=(*ptr)->rear=0;
	else
	{
		(*ptr)->front=((*ptr)->front-1+n)%n;
	}
	(*ptr)->arr[(*ptr)->front]=val;
}
void EnqueueAtRear(Queue **ptr,int n,int val)
{
	if((*ptr)->front==0 && (*ptr)->rear==n-1)
	{
		printf("Queue is full\n");
		return;
	}
	if((*ptr)->front==-1)
	(*ptr)->front=(*ptr)->rear=0;
	else
	{
		(*ptr)->rear=((*ptr)->rear+1)%n;
		(*ptr)->arr[(*ptr)->rear]=val;
	}
	(*ptr)->arr[(*ptr)->rear]=val;
}
int DeleteAtFront(Queue **ptr,int n)
{
	if((*ptr)->front==-1)
	 {
		return -1;
	 }   
    int temp=(*ptr)->arr[(*ptr)->front];
	 if((*ptr)->front==(*ptr)->rear)
	{
		
		(*ptr)->front=(*ptr)->rear=-1;
	}
	else
	{
		(*ptr)->front=((*ptr)->front+1)%n;
	}
	return temp;
}
int DeleteAtRear(Queue **ptr,int n)
{
	if((*ptr)->front==-1)
	 {
		return -1;
	 }   
    int temp=(*ptr)->arr[(*ptr)->rear];
	if((*ptr)->front==(*ptr)->rear)
	{
		
		(*ptr)->front=(*ptr)->rear=-1;
	}
	else
	{
		(*ptr)->rear=((*ptr)->rear-1)%n;
	}
	return temp;
}
void display(Queue *ptr,int n)
{
	int i=ptr->front;
	for(;i!=ptr->rear+1;i=(i+1)%n)
	printf("%d ",ptr->arr[i]);
	
	printf("\n");
}
void main()
{
	Queue *ptr;
	ptr=(Queue *)malloc(sizeof(Queue));
	ptr->front=ptr->rear=-1;
	unsigned int ch;
	printf("Enter the queue length\n");
	int n;
	scanf("%d",&n);
	printf("Enter ur choice\n");
	printf("1.Insert at front\n");
	printf("2.Insert at rear\n");
	printf("3.Delete at front\n");
	printf("4.Delete at rear\n");
	printf("5.Display the queue\n\n");
	scanf("%d",&ch);
	int val;
	do
	{
		switch(ch)
		{
			case 1:printf("Enter the value\n");
			       scanf("%d",&val);
			       EnqueueAtFront(&ptr,n,val);
			       break;
			case 2:printf("Enter the value\n");
			       scanf("%d",&val);
			       EnqueueAtRear(&ptr,n,val);
			       break;
			case 3:printf("The value dequeued is \n");
			       int x=DeleteAtFront(&ptr,n);
			       if(x!=-1)
			       printf("%d\n",x);
			       else
			       printf("Underflow\n");
			       break;
			case 4:printf("The value dequeued is \n");
			       x=DeleteAtRear(&ptr,n);
			       if(x!=-1)
			       printf("%d\n",x);
			       else
			       printf("Underflow\n");
				   break;
			case 5:printf("The queue is\n");
			       display(ptr,n);
			       break;		
		 }
			printf("Enter ur choice\n");
			scanf("%d",&ch);
	}while(ch<=5);
	printf("Terminating...\n");
	getch();
}
