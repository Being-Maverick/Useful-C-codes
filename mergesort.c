#include<stdio.h>
#include<conio.h>
#define SIZE 50
void merge(int arr[],int low,int mid,int high)
{
	int p,i,j,k;
	i=low;
	j=mid+1;
	k=0;
	int c[SIZE];
	for(p=low;p<=high;p++)
	{
		if(i>mid)
		{
			c[k]=arr[j];
			j++;
		}
		else if(j>high)
		{
			c[k]=arr[i];
			i++;
		}
		else if(arr[i]<arr[j])
		{
			c[k]=arr[i];
			i++;
		}
		else
		{
			c[k]=arr[j];
			j++;
		}
		k++;
	}
	k=0;
	for(p=low;p<=high;p++)
	{
		arr[p]=c[k];
		k++;
	}
}

void mergesort(int arr[],int low,int high)
{
	if(high<=low)
	return;
	int mid=(low+high)/2;
	mergesort(arr,0,mid);
	mergesort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

void display(int arr[],int n)
{
	printf("The array is\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[SIZE];
	int n,i;
	printf("Enter the number\n");
	scanf("%d",&n);
	printf("Enter the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	display(arr,n);
	printf("Sorting the array\n");
	mergesort(arr,0,n-1);
	display(arr,n);
	getch();
}
