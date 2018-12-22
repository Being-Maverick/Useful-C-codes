#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 11
int *CountingSort(int *arr,int n,int k)
{
	int *B;
	B=(int *)malloc(sizeof(int)*SIZE);
	int C[k];
	int i;
	for(i=0;i<k;i++)
	C[i]=0;
	for(i=1;i<n;i++)
	C[arr[i]]++;
	
	for(i=1;i<k;i++)
	C[i]+=C[i-1];
	
	for(i=n-1;i>=1;i--)
	{
    	B[C[arr[i]]]=arr[i];
	    C[arr[i]]=C[arr[i]]-1;
	}
	return B;
}

void Display(int *arr,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		printf("%d ",arr[i]);
    }
    printf("\n");
}

void main()
{
	int *arr;
	arr=(int *)malloc(sizeof(int)*SIZE);
	int i;
	printf("Enter the range of array elements\n");
	int range;
	scanf("%d",&range);
	printf("Enter ten array elements\n");
	for(i=1;i<=SIZE;i++)
	scanf("%d",&arr[i]);
	
	printf("The initial array is \n");
	Display(arr,SIZE);
	printf("Sorting the array using Counting Sort\n");
	int *X=CountingSort(arr,SIZE,range);
	
	printf("The sorted array is\n");
	Display(X,SIZE);
	getch();
}
