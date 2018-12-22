#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 40
void CountingSort(int *arr,int n,int exp)
{
	int *B;
	B=(int *)malloc(sizeof(int)*SIZE);
	int C[10];
	int i;
	for(i=0;i<10;i++)
	C[i]=0;
	for(i=1;i<n;i++)
	C[(arr[i]/exp)%10]++;
	
	for(i=1;i<10;i++)
	C[i]+=C[i-1];
	
	for(i=n-1;i>=1;i--)
	{
    	B[C[(arr[i]/exp)%10]]=arr[i];
	    C[(arr[i]/exp)%10]=C[(arr[i]/exp)%10]-1;
	}
	for(i=1;i<n;i++)
	arr[i]=B[i];
	free(B);
}

int Maximum(int *arr,int n)
{
	int i,max;
	max=arr[1];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}
	return max;
}

void RadixSort(int *arr,int n)
{
	int Max;
	Max=Maximum(arr,n);
	int exp;
	for(exp=1;Max/exp>0;exp*=10)
	CountingSort(arr,n,exp);
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
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int i;
	for(i=1;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The initial array is\n");
	Display(arr,n);
	printf("Sorting the array\n");
	RadixSort(arr,n);
	printf("The sorted array is\n");
	Display(arr,n);
	getch();
}
