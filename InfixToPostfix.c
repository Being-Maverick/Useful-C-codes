#include<stdio.h>
#include<conio.h>
typedef struct nodetype
{
char ch;
struct nodetype *next;
}stack;
void push(stack **,char);
char pop(stack **);
char peek(stack **);
int isempty(stack **);
void main()
{
char exp[50];
char pos[50];
stack *top=NULL;
printf("Enter the infix expression\n");
scanf("%s",exp);
char x;
int i,j=0;
int index=0;
for(i=0;exp[i]!='\0';i++)
{
x=exp[i];
switch(x)
{
case '(':push(&top,x);
break;
case ')':
         for(;(!(isempty(&top))) && peek(&top)!='(';)
         {
         pos[index]=pop(&top);
         index++;
         }
         pop(&top);
         break;
case '+':
case '-':
         for(;((!isempty(&top))) && (peek(&top)=='*' || peek(&top)=='/');)
         {
         pos[index]=pop(&top);
         index++;
         }
         push(&top,x);
         break;
case '*':
case '/':push(&top,x);
break;
default:pos[index]=x;
        index++;
        }
        }
        if(!(isempty(&top)))
        {
        while(top!=NULL)
        {
        pos[index]=pop(&top);
        index++;
        }
        }
        printf("The postfix expression is \n");
        for(;j<index;j++)
        printf("%c",pos[j]);
        getch();
        }        
        void push(stack **top,char val)
        {
        stack *ptr=(stack *)malloc(sizeof(stack));
        ptr->ch=val;
        if((*top)==NULL)
        {
        ptr->next=NULL;
        (*top)=ptr;
        }
        else
        {
        ptr->next=(*top);
        (*top)=ptr;
        }
        }
        char pop(stack **top)
        {
        char x;
        stack *ptr=(*top);
        x=ptr->ch;
        (*top)=(*top)->next;
        free(ptr);
        return x;
        }
        char peek(stack **top)
        {
        return ((*top)->ch);
        }
        int isempty(stack **top)
        {
        if((*top)==NULL)
        return 1;
        return 0;
        }
        
