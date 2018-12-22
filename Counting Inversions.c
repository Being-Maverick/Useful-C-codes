#include<stdio.h>
#include<conio.h>
#define SIZE 20
int mergesort(int arr[],int start,int end)
{
	int inversions=0;
	if(start<end)
	{
		int mid=(start+end)/2;
		inversions+=mergesort(arr,start,mid);
		inversions+=mergesort(arr,mid+1,end);
		inversions+=merge(arr,start,mid,end);
	}
	return inversions;
}

int merge(int arr[],int start,int mid,int end)
{
	int temp[end-start+1];
	int p=start,q=mid+1;
	int inversions,k;
	k=inversions=0;
	int i;
	for(i=start;i<=end;i++)
	{
		if(p>mid)
		temp[k++]=arr[q++];
		else if(q>end)
		temp[k++]=arr[p++];
		else if(arr[p]>arr[q])
		{
			inversions+=(mid-p+1);
			temp[k++]=arr[q++];
		}
		else
		temp[k++]=arr[p++];
	}k=0;
	for(p=start;p<=end;p++)
	{
		arr[p]=temp[k++];
	}
	return inversions;
}

void main()
{
	int arr[SIZE];
	int n;
	printf("Enter the number of elements present\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("The number of inversions required are %d\n",mergesort(arr,0,n-1));
	getch();
}
