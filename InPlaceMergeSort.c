#include<stdio.h>
#include<conio.h>
#define SIZE 100
void merge(int arr[],int p,int q,int r)
{
     int i,j,last;
     for(i=r;i>q;i--)
     {
       last=arr[q];
       for(j=q-1;j>=0 && arr[j]>arr[i];j--)
       arr[j+1]=arr[j];
       
       if(j!=q-1 && last>arr[i])
       {
         arr[j+1]=arr[i];
         arr[i]=last;
       }
     }
}
void mergesort(int arr[],int low,int high)
{
     if(low>=high)
     return;
     int mid=(low+high)/2;
     mergesort(arr,low,mid);
     mergesort(arr,mid+1,high);
     merge(arr,low,mid,high);
}
void Display(int arr[],int n)
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
     int n;
     printf("Enter the size of the array\n");
     scanf("%d",&n);
     printf("Initializing the array\n");
     int i;
     for(i=0;i<n;i++)
     arr[i]=rand()%(n+1);
     Display(arr,n);
     printf("Sorting the array\n");
     mergesort(arr,0,n-1);
     Display(arr,n);
     getch();
}
       
