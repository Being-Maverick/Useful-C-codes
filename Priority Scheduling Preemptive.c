#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
        int at;
        int bt,pt;
        int ct,tat,wt;
        int rt;
        struct node *next;
}Process;
Process *head,*tail;
int n=0;
void insert()
{
     int x,y,z;
     printf("Enter arrival time,burst Time and Priority\n");
     scanf("%d",&x);
     scanf("%d",&y);
     scanf("%d",&z);
     Process *new=(Process *)malloc(sizeof(Process));
     new->at=x;
     new->bt=new->rt=y;
     new->pt=z;
     new->wt=new->ct=new->tat=0;
     new->next=NULL;
     n+=new->bt;
     if(head==NULL)
     {
     head=new;
     tail=new;
     return;
     }
     tail->next=new;
     tail=tail->next;
}
Process *small(int t)
{
	Process *ptr=head;
	int min=INT_MAX;
	Process *ptr1=NULL;
	while(ptr!=NULL)
	{
		if(ptr->rt==0)
		{
			ptr=ptr->next;
			continue;
		}
	    if(ptr->at<=t)
	    {
		ptr1=ptr;
		break;
	    }
	    ptr=ptr->next;
	}
	return ptr1;
}
void PriorityP()
{
     int t=0;
     int x=0,y=0;
     int count=0;
     Process *ptr=NULL;
     while(count!=n)
     {
		ptr=small(t);
		if(ptr==NULL)
		{
			t++;
			continue;
		}
		count++;
		ptr->rt--;
		t++;
		if(ptr->rt==0)
		{
		ptr->ct=t;
		ptr->tat=ptr->ct-ptr->at;
		ptr->wt=ptr->tat-ptr->bt;
	    }
	 }  
}
void sort()
{
     Process *ptr,*ptr1;
     ptr=head;
     while(ptr!=NULL)
     {
     ptr1=ptr->next;			
     while(ptr1!=NULL)
        {
           if((ptr1->pt)<(ptr->pt))
           {
              int x=ptr->at;
              ptr->at=ptr1->at;
              ptr1->at=x;
              
              x=ptr->bt;
              ptr->bt=ptr1->bt;
              ptr1->bt=x;
              
              x=ptr->rt;
              ptr->rt=ptr1->rt;
              ptr1->rt=x;
              
              x=ptr->pt;
              ptr->pt=ptr1->pt;
              ptr1->pt=x;
           }
           else if(ptr->pt==ptr1->pt && ptr->at>ptr1->at)
           {
			  int x=ptr->at;
              ptr->at=ptr1->at;
              ptr1->at=x;
              
              x=ptr->bt;
              ptr->bt=ptr1->bt;
              ptr1->bt=x;
              
              x=ptr->rt;
              ptr->rt=ptr1->rt;
              ptr1->rt=x;
			  
			  x=ptr->pt;
              ptr->pt=ptr1->pt;
              ptr1->pt=x;	
		   }
           ptr1=ptr1->next;
        }
        ptr=ptr->next;
     }
}

void display()
{
      printf("PNo\tPT\tAT\tBT\tCT\tTAT\tWT\n");
     int count=0,sum=0,sum1=0;
     Process *ptr;
     while(head!=NULL)
     {
     sum+=(head->wt);
     sum1+=(head->tat);
     count++;
     printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",count,head->pt,head->at,head->bt,head->ct,head->tat,head->wt);
     ptr=head;
     head=head->next;
     free(ptr);
     }
     printf("Average waiting time is %f\n",((float)sum/(float)count));
     printf("Average turnaround time is %f\n",((float)sum1/(float)count));
}
void main()
{
     head=tail=NULL;
     int m;
     printf("Enter the number of processes\n");
     scanf("%d",&m);
     int i;
     for(i=1;i<=m;i++)
     insert();
     sort();
     PriorityP();
     display();
     getch();
}
