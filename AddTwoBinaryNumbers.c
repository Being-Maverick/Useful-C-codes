#include<stdio.h>
#include<conio.h>
#define SIZE 20
void addBinNum(int *a,int *b,int *c,int n)
{
	int rem=0,i,j=n;
	for(i=n-1;i>=0;i--,j--)
	{
		c[j]=(a[i]+b[i]+rem)%2;
		rem=(a[i]+b[i]+rem)/2;
	}
	c[j]=rem;
}
void printarray(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d",arr[i]);
	printf("\n");
}
void main()
{
	int a[SIZE],b[SIZE],c[SIZE];
	int n;
	printf("Enter the number of bits in the binary integer\n");
	scanf("%d",&n);
	int i=0;
	printf("Enter the n-bit binary number\n");
	for(;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the n-bit binary number\n");
    for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	printf("The numbers are\n");
	printarray(a,n);
	printarray(b,n);
	addBinNum(a,b,c,n);
	printf("The sum of two binary numbers is\n");
	printarray(c,n+1);	
	getch();
}
