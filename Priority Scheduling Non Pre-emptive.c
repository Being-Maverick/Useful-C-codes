#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
        int at;
        int bt,pt;
        int ct,tat,wt;
        int flag;
        struct node *next;
}Process;
Process *head,*tail;
int n;
void insert()
{
     int x,y,z;
     printf("Enter arrival time,burst Time and the priority\n");
     scanf("%d",&x);
     scanf("%d",&y);
     scanf("%d",&z);
     Process *new=(Process *)malloc(sizeof(Process));
     new->at=x;
     new->bt=y;
     new->pt=z;
     new->wt=new->ct=new->tat=0;
     new->next=NULL;
     new->flag=0;
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
	int min=ptr->bt;
	Process *ptr1=NULL;
	while(ptr!=NULL)
	{
		
	    if(ptr->flag!=1 && ptr->at<=t)
	    {
		ptr1=ptr;
		break;
	    }
	    ptr=ptr->next;
	}
	if(ptr1!=NULL)
	ptr1->flag=1;
	return ptr1;
}
void PriorityNP()
{
     int t=0;
     int x=0,y=0;
     int count=0;
     Process *ptr=NULL;
     printf("PNo\tPT\tAT\tBT\tCT\tTAT\tWT\n");
     while(count!=n)
     {
		ptr=small(t);
		if(ptr==NULL)
		{
			t++;
			continue;
		}
		count++;
		ptr->wt=t-(ptr->at);
		ptr->tat=ptr->wt+ptr->bt;
		t+=ptr->bt;
		ptr->ct=t;
		x+=ptr->wt;
		y+=ptr->tat;
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",count,ptr->pt,ptr->at,ptr->bt,ptr->ct,ptr->tat,ptr->wt);
	 }  
	 printf("Average waiting time is %f\n",((float)x/(float)count));
     printf("Average turnaround time is %f\n",((float)y/(float)count));
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
              
              x=ptr->pt;
              ptr->pt=ptr1->pt;
              ptr1->pt=x;
           }
           else if(ptr1->pt==ptr->pt)
           {
				if(ptr1->at<ptr->at)
				{
					int x=ptr->at;
                    ptr->at=ptr1->at;
                    ptr1->at=x;
              
                    x=ptr->bt;
                    ptr->bt=ptr1->bt;
                    ptr1->bt=x;
                    
                    x=ptr->pt;
                    ptr->pt=ptr1->pt;
                    ptr1->pt=x;
				}
		   }
           ptr1=ptr1->next;
        }
        ptr=ptr->next;
     }
}           
void display()
{
     Process *ptr;
     while(head!=NULL)
     {
     ptr=head;
     head=head->next;
     free(ptr);
     }
}
void main()
{
     head=tail=NULL;
     printf("Enter the number of processes\n");
     scanf("%d",&n);
     int i;
     for(i=1;i<=n;i++)
     insert();
     sort();
     PriorityNP();
     display();
     getch();
}
     
     
      
