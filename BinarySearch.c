#include<stdio.h>
#include<conio.h>
#define SIZE 50
int binarysearch(int *,int,int);
void main()
{
  int arr[SIZE];
  int n;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  int i;
  printf("Enter the elements of the array\n");
  for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
  int item;
  printf("Enter the item to be searched(0 to exit)\n");
  scanf("%d",&item);
  do
  {
    int loc=binarysearch(arr,n,item);
    if(loc==-1) 
      printf("Element is not present");
    else
      printf("Element is present at position %d",(loc+1));
      printf("Enter the item to be searched(0 to exit)\n");
  scanf("%d",&item);
  }while(item!=0);
  getch();
}
int binarysearch(int *arr,int n,int item)
{
  int beg,end,mid; 
  beg=0;
  end=n-1;
  do
  {
   mid=(beg+end)/2;
   if(arr[mid]<item)
   beg=mid+1; 
   else
   end=mid-1;
  }while(beg<=end && arr[mid]!=item);
  if(arr[mid]==item)
  return mid;
  return -1;
}  
