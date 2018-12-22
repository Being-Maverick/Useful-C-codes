#include<stdio.h>
#include<conio.h>
#define SIZE 20
void insertionsort(int a[],int *n,int key)
{
	(*n)--;
	if((*n)==-1 || a[(*n)]<key )
	return;
	else if(a[(*n)]>key)
	{
		a[(*n)+1]=a[(*n)];
		insertionsort(a,n,key);
		a[*n+1]=key;
    }
}

void main()
{
	int arr[SIZE];
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Input array elements\n");
	int i=0;
	for(;i<n;i++)
	scanf("%d",&arr[i]);
	printf("The original array is\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	printf("\nSorting the array\n");
	for(i=1;i<n;i++)
	{
		int j=i;
	    insertionsort(arr,&j,arr[i]);
    }
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	getch();
}
