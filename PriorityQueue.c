#include<stdio.h>
#include<conio.h>
#define SIZE 50
void MaxHeapify(int arr[],int n,int i)
{
	int l=2*i+1;
	int r=l+1;
	int max=i;
	if(l<=n && arr[l]>arr[i])
	max=l;
	if(r<=n && arr[r]>arr[max])
	max=r;
	if(max!=i)
	{		
	   int temp=arr[i];
	   arr[i]=arr[max];
	   arr[max]=temp;
	   MaxHeapify(arr,n,max);
    }
}

void BuildMaxHeap(int arr[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	MaxHeapify(arr,i,n);
}

int HeapMaximum(int arr[],int n)
{
	if (n<0)
	return -1;
	else 
	return arr[0];
}

int HeapExtractMax(int arr[],int *n)
{
	if((*n)<0)
	return -1;
	
	int max=arr[0];
	arr[0]=arr[(*n)];
	(*n)--;
	int y=(*n);
	MaxHeapify(arr,y,0);
	return max;
}

void HeapIncreaseKey(int arr[],int i,int key)
{
	if(key<arr[i])
	{
		printf("Error new key is less than current key\n");
		return;
	}
	arr[i]=key;
	int temp;
	while(i>0 && arr[i/2]<arr[i])
	{
		 temp=arr[i];
		 arr[i]=arr[i/2];
		 arr[i/2]=temp;
		 i/=2;
	}
}

void MaxHeapInsert(int arr[],int *n,int key)
{
	(*n)++;
	arr[*n]=-100;
	HeapIncreaseKey(arr,(*n),key);
}

void display(int arr[],int n)
{
	int i;
	for(i=0;i<=n;i++)
	printf("%d ",arr[i]);
	printf("\n");
}

void main()
{
	int arr[SIZE];
	int count=-1,ch,x,y;
	do
	{
		printf("Enter ur choice\n");
		printf("1.Insert an element\n");
		printf("2.Increase key of an element\n");
		printf("3.Extract maximum element\n");
		printf("4.Display the priority queue\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter an element\n");
			       scanf("%d",&x);
			       MaxHeapInsert(arr,&count,x);
			       break;
			case 2:printf("Enter the index and new key\n");
			       scanf("%d%d",&y,&x);
			       HeapIncreaseKey(arr,y,x);
			       break;
			case 3:y=HeapExtractMax(arr,&count);
			       printf("Extractec element is %d\n",y);
			       break;
			case 4:display(arr,count);
		}
	}while(ch>=1 && ch<=4);
	getch();
}
