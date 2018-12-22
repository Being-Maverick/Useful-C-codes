#include<stdio.h>
#include<conio.h>
typedef struct node
{
        int at;
        int bt;
        int ct,tat,wt;
        struct node *next;
}Process;
Process *head,*tail;
void insert()
{
     int x,y;
     printf("Enter arrival time and burst Time\n");
     scanf("%d",&x);
     scanf("%d",&y);
     Process *new=(Process *)malloc(sizeof(Process));
     new->at=x;
     new->bt=y;
     new->next=NULL;
     if(head==NULL)
     {
     head=new;
     tail=new;
     return;
     }
     tail->next=new;
     tail=tail->next;
}
void FCFS()
{
     int x=head->at;
     int y=head->at;
     Process *ptr=head;
     while(ptr!=NULL)
     {
        ptr->wt=x-(ptr->at);
        y+=(ptr->bt);
        x=y;
        ptr->ct=y;
        ptr->tat=(ptr->bt)+(ptr->wt);
        ptr=ptr->next;
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
           if((ptr1->at)<(ptr->at))
           {
              int x=ptr->at;
              ptr->at=ptr1->at;
              ptr1->at=x;
              
              x=ptr->bt;
              ptr->bt=ptr1->bt;
              ptr1->bt=x;
           }
           ptr1=ptr1->next;
        }
        ptr=ptr->next;
     }
}
            
void display()
{
     printf("PNo\tAT\tBT\tCT\tTAT\tWT\n");
     int count=0,sum=0,sum1=0;
     Process *ptr;
     while(head!=NULL)
     {
     sum+=(head->wt);
     sum1+=(head->tat);
     count++;
     printf("%d\t%d\t%d\t%d\t%d\t%d\n",count,head->at,head->bt,head->ct,head->tat,head->wt);
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
     int n;
     printf("Enter the number of processes\n");
     scanf("%d",&n);
     int i;
     for(i=1;i<=n;i++)
     insert();
     sort();
     FCFS();
     display();
     getch();
}
     
     
      
