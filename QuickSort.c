#include<stdio.h>
#include<conio.h>
#define SIZE 20
int Partition(int *arr,int start,int end)
{
	int pivot=arr[end-1];
	int i=start-1;
	int j,temp,temp1;
	for(j=start;j<end-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	i++;
	temp=arr[i];
	arr[i]=arr[end-1];
	arr[end-1]=temp;
	return i;
}

void QuickSort(int *arr,int start,int end)
{
	if(start<end)
	{
		int mid=Partition(arr,start,end);
		QuickSort(arr,start,mid);
		QuickSort(arr,mid+1,end);
	}
}

void Display(int *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[SIZE];
	int arr2[SIZE];
	int n;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	int i,j;
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("The initial array is\n");
	Display(arr,n);
	QuickSort(arr,0,n);
	printf("Array after sorting is\n");
	Display(arr,n);
	getch();
}
