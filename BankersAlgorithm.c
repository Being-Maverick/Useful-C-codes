#include<stdio.h>
#include<conio.h> 
int current[10][10], maximum_claim[10][10], available[10];
int allocation[10] = {0, 0, 0, 0, 0};
int maxres[10], running[10], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;
void safety()
{
while (counter != 0) 
{
safe = 0;
for (i = 0; i < processes; i++) 
{
if (running[i]) 
{
exec = 1;
for (j = 0; j < resources; j++) 
{
if (maximum_claim[i][j] - current[i][j] > available[j]) 
{
exec = 0;
break;
}
}
if (exec) 
{
printf("\nProcess%d is executing\n", i + 1);
running[i] = 0;
counter--;
safe = 1;
 
for (j = 0; j < resources; j++) 
{
available[j] += current[i][j];
}
break;
}
}
}
if (!safe) 
{
printf("\nThe processes are in unsafe state.\n");
break;
} 
else 
{
printf("\nThe process is in safe state");
printf("\nAvailable vector:");
for (i = 0; i < resources; i++) 
{
printf("\t%d", available[i]);
}
printf("\n");
}
}
}
void resourcealloc()
{
	int req[10];
	int pno;
	printf("Enter the process number\n");
	scanf("%d",&pno);
	printf("Enter the request vector\n");
	int i,j;
	for(i=0;i<resources;i++)
	scanf("%d",&req[i]);
	int flag=1;
	for(i=0;i<resources;i++)
	{
		if(req[i]>(maximum_claim[pno-1][i]-current[pno-1][i]))
		{
			flag=0;
			break;
		}
	}
	if(!flag)
	{
		printf("Resources cannot be allocated, as the need is less than the request\n");
		return;
	}
	else
	{
		for(i=0;i<resources;i++)
	    {
		if(req[i]>available[i])
		{
			printf("More than availble resources are requested, the process must wait\n");
			return;
		}
	    }
	    for(i=0;i<resources;i++)
	    {
			available[i]-=req[i];
			current[pno-1][i]+=req[i];
		}
		safety();
	}
	}
int main()
{
printf("Enter number of processes: ");
scanf("%d", &processes); 
for (i = 0; i < processes; i++) 
{
running[i] = 1;
counter++;
} 
printf("\nEnter number of resources: ");
scanf("%d", &resources);
printf("\nEnter Claim Vector:");
for (i = 0; i < resources; i++) 
{ 
scanf("%d", &maxres[i]);
} 
printf("\nEnter Allocated Resource Table:\n");
for (i = 0; i < processes; i++) 
{
for(j = 0; j < resources; j++) 
{
scanf("%d", &current[i][j]);
}
} 
printf("\nEnter Maximum Claim Table:\n");
for (i = 0; i < processes; i++) 
{
for(j = 0; j < resources; j++) 
{
scanf("%d", &maximum_claim[i][j]);
}
} 
printf("\nThe Claim Vector is: ");
for (i = 0; i < resources; i++) 
{
printf("\t%d", maxres[i]);
} 
printf("\nThe Allocated Resource Table:\n");
for (i = 0; i < processes; i++) 
{
for (j = 0; j < resources; j++) 
{
printf("\t%d", current[i][j]);
}
printf("\n");
}
printf("\nThe Maximum Claim Table:\n");
for (i = 0; i < processes; i++) 
{
for (j = 0; j < resources; j++) 
{
printf("\t%d", maximum_claim[i][j]);
}
printf("\n");
}
 
for (i = 0; i < processes; i++) 
{
for (j = 0; j < resources; j++) 
{
allocation[j] += current[i][j];
}
} 
printf("\nAllocated resources:");
for (i = 0; i < resources; i++) 
{
printf("\t%d", allocation[i]);
}
 
for (i = 0; i < resources; i++) 
{
available[i] = maxres[i] - allocation[i];
}
printf("\nAvailable resources:");
for (i = 0; i < resources; i++) 
{
printf("\t%d", available[i]);
}
printf("\n");
resourcealloc();
getch();
return 0;
}
