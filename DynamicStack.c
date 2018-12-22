#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct DynArrayStack
{
	int top;
	int capacity;
	
	int *array;
}DStack;
DStack *createstack()
{
	DStack *ptr=(DStack *)malloc(sizeof(DStack));
	if(ptr==NULL)
	return NULL;
	
	ptr->top=-1;
	ptr->capacity=1;
	ptr->array=malloc((ptr->capacity)*sizeof(int));
	if((ptr->array)==NULL)
	return NULL;
	return ptr;
}
int isFull(DStack *ptr)
{
	return ((ptr->top)==((ptr->capacity)-1));
}
void DoubleStack(DStack *ptr)
{
	(ptr->capacity)*=2;
	(ptr->array)=realloc(ptr->array,ptr->capacity);
}
void Push(DStack *ptr,int x)
{
	if((isFull(ptr)))
	DoubleStack(ptr);
	ptr->array[++(ptr->top)]=x;
}
int isEmpty(DStack *ptr)
{
	return(ptr->top==-1);
}
int peek(DStack *ptr)
{
	if(isEmpty(ptr))
	return -1;
	return ptr->array[ptr->top];
}
int Pop(DStack *ptr)
{
	if(isEmpty(ptr))
	return -1;
	return ptr->array[(ptr->top)--];
}
void delete(DStack *ptr)
{
	if(ptr)
	{
	if(ptr->array)
	free(ptr->array);
	free(ptr);	
	}
}
void InsertAtBottom(DStack *ptr,int data)
{
	int temp;
	if(isEmpty(ptr))
	{
		Push(ptr,data);
		return;
	}
	temp=Pop(ptr);
	InsertAtBottom(ptr,data);
	Push(ptr,temp);
}
void reverseStack(DStack *ptr)
{
	int data;
	
	if(isEmpty(ptr))
	return;
	
	data=Pop(ptr);
	reverseStack(ptr);
	InsertAtBottom(ptr,data);	
}
void display(DStack *ptr)
{
	int i=ptr->top;
	for(i=ptr->top;i>=0;i--)
	printf("%d  ",ptr->array[i]);
    printf("\n");
}
void main()
{
	DStack *stack=createstack();
	if(!stack)
	{
		printf("memory is full\n");
		exit(0);
	}
	stack->capacity=2;
	printf("Enter the number of elements to be entered into stack\n");
	int n;
	scanf("%d",&n);
	int i,x;
	for(i=0;i<n;i++)
	{
		printf("Enter the element to be inserted\n");
		scanf("%d",&x);
		Push(stack,x);
	}
	printf("Original stack is\n");
	display(stack);
	printf("Reversing the stack.....\n");
	printf("Reversed stack is\n");
	reverseStack(stack);
	display(stack);
	delete(stack);
	getch();
}
