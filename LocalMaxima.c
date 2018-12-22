#include<stdio.h>
#include<conio.h>
#define SIZE 50
int localMaxima(int arr[],int low,int high)
{
	if(low>high)
	return -1;
	
	int mid=(low+high)/2;
	if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
	return arr[mid];
	else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
	return localMaxima(arr,low,mid-1);
	else
	return localMaxima(arr,mid+1,high);
}
void main()
{
	printf("Enter the size of the array\n");
	int n;
	int arr[SIZE];
	scanf("%d",&n);
	printf("Input array elements\n");
	int i=0;
	for(;i<n;i++)
	scanf("%d",&arr[i]);
	
	printf("The local maxima is\n");
	printf("Local Maxima is %d\n",localMaxima(arr,0,n-1));
	getch();
}
