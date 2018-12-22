#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define SIZE 100
int frames[20];
int pageString[SIZE];
int n,m;
int Faults()
{
	int i,j;
	int flag=0;
	int count=0;
	for(i=0;i<m;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(frames[j] == INT_MIN)
			{
				frames[j]=pageString[i];
				flag=1;
				count++;
				break;
			}
		}
		if(flag==1)
		continue;
		for(j=0;j<n;j++)
		{
			if(frames[j]==pageString[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		continue;
		for(j=1;j<n;j++)
		frames[j-1]=frames[j];
		frames[j-1]=pageString[i];
		count++;
	}
	return count;
}
void main()
{
	printf("Enter the number of frames available\n");
	scanf("%d",&n);
	printf("Enter the size of the page string\n");
	scanf("%d",&m);
	int i;
	for(i=0;i<n;i++)
	{
		frames[i]=INT_MIN;
	}
	printf("Enter the page string\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&pageString[i]);
	}
	printf("Calculating the number of page faults...\n");
	printf("The number of page faults are \n");
	int pagefaults=Faults();
	printf("%d\n",pagefaults);
	getch();
}
