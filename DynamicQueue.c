#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct DynamicQueue
{
	int front,rear;
	int capacity;
	int *array;
}DQueue;
DQueue *createdynamicqueue()
{
	DQueue *ptr=(DQueue*)malloc(sizeof(DQueue));
	if(!ptr)
	return NULL;
	
	ptr->capacity=1;
	ptr->front=ptr->rear=-1;
	ptr->array=malloc((ptr->capacity)*sizeof(int));
	if(!(ptr->array))
	return NULL;
	return ptr;
}
int isEmptyQueue(DQueue *ptr)
{
	return((ptr->front)==-1);
}
int isFullQueue(DQueue *ptr)
{
	return ((ptr->rear+1)%(ptr->capacity)==ptr->front);
}
int QueueSize(DQueue *ptr)
{
	return ((ptr->capacity-ptr->rear+ptr->front+1)%(ptr->capacity));
}
void Enqueue(DQueue *ptr,int data)
{
	if(isFullQueue(ptr))
	ResizeQueue(ptr);
	
	ptr->rear=(ptr->rear+1)%(ptr->capacity);
	ptr->array[ptr->rear]=data;
	
	if(ptr->front==-1)
	ptr->front=ptr->rear;
}

void ResizeQueue(DQueue *ptr)
{
	int size=ptr->capacity;
	ptr->capacity=(ptr->capacity)*2;
	
	ptr->array=realloc(ptr->array,ptr->capacity);
	
	if(!(ptr->array))
	{
		printf("Memory Error\n");
		return;
	}
	if((ptr->front)>(ptr->rear))
    {
		int i=0;
		for(;i<(ptr->front);i++)
		ptr->array[i+size]=ptr->array[i];
		ptr->rear=(ptr->rear)+size;
	}
}
int Dequeue(DQueue *ptr)
{
	int data=0;
	if(isEmptyQueue(ptr))
	{
		printf("Queue is empty\n");
		return 0;
	}
	else
	{
		data=ptr->array[ptr->front];
		if(ptr->front==ptr->rear)
		ptr->front=ptr->rear=-1;
		
		else
		ptr->front=(ptr->front+1)%(ptr->capacity);
	}
	return data;
}
void DeleteQueue(DQueue *ptr)
{
	if(ptr!=NULL)
	{
		if((ptr->array)!=NULL)
		free(ptr->array);
		free(ptr);
	}
}
void reverseQueue(DQueue *ptr)
{
	int data;
	
	if(isEmptyQueue(ptr))
	return;
	
	data=Dequeue(ptr);
	reverseQueue(ptr);
	Enqueue(ptr,data);	
}
void display(DQueue *ptr)
{
	int i,j;
	i=ptr->front;
	j=ptr->rear;
	
	if(i<=j)
	{
		for(;i<=j;i++)
		printf("%d ",ptr->array[i]);
	}
	else
	{
		for(;i<(ptr->capacity);i++)
	    printf("%d ",ptr->array[i]);
		
		for(i=0;i<=j;i++)
		printf("%d ",ptr->array[i]);	
	}
	printf("\n");
}
void main()
{
	int n;
	DQueue *ptr=createdynamicqueue();
	printf("Enter the no of elements to be inserted\n");
	scanf("%d",&n);
	int i=0,x;
	printf("Enter the elements of the queue\n");
	for(;i<n;i++)
	{
		scanf("%d",&x);
		Enqueue(ptr,x);
	}
	printf("The original Queue is\n");
	display(ptr);
	printf("Reversing the Queue\n");
	reverseQueue(ptr);
	printf("The reversed Queue is\n");
	display(ptr);
	
	getch();
	
}
