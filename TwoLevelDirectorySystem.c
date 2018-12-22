#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct nodeType
{
	int x;
	struct nodeType *next;
}file;
typedef struct userType
{
	char name[50];
	struct userType *next;
	file *head;
}user;
user *userHead;
int searchUser(char name[50])
{
	user *ptr=userHead;
	int flag=0;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->name,name)==0)
		{
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	return flag;
}
void addUser()
{
	user *ptr=(user *)malloc(sizeof(user));
	if(ptr==NULL)
	{
		printf("Memory insufficient\n");
		return;
	}
	ptr->head=NULL;
	ptr->next=NULL;
	printf("\nEnter the new username\n");
	scanf("%s",ptr->name);
	if(searchUser(ptr->name)==1)
	{
		printf("\nGiven user already exists\n");
		free(ptr);
		return;
	}
	if(userHead==NULL)
	{
		userHead=ptr;
		return;
	}
	else
	{
		ptr->next=userHead;
		userHead=ptr;
	}
} 
int searchFile(char name[50],int fno)
{
	user *ptr=userHead;
	file *nptr;
	int flag=0;
	while(ptr!=NULL)
	{
	   if(strcmp(ptr->name,name)==0)
	   {
	   nptr=ptr->head;
	   while(nptr!=NULL)
	   {
			if(nptr->x==fno)
			{
				flag=1;
				break;
			}
			nptr=nptr->next;
	   }
	   }
	   if(flag==1)
	   break;
	   ptr=ptr->next;
	}
	return flag;
}
void addFile(char s[50])
{
	user *ptr=userHead;
	if(userHead==NULL)
	{
		printf("\nCreate user first\n");
		return;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(strcmp(s,ptr->name)==0)
			break;
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("\nNo such user exists\n");
			return;
		}
		
		file *newFile=(file *)malloc(sizeof(file));
		if(newFile==NULL)
		{
			printf("\nInsufficient Memory\n");
			return;
		}
		printf("\nEnter the new file number\n");
		scanf("%d",&(newFile->x));
		if(searchFile(s,newFile->x)==1)
		{
			printf("\nFile with file number %d already exists\n",newFile->x);
			free(newFile);
			return;
		}
		if(ptr->head==NULL)
		{
			ptr->head=newFile;
			newFile->next=NULL;
		}
		else
		{
			newFile->next=ptr->head;
			ptr->head=newFile;
		}
		printf("\nFile created\n");
	}
}
void display()
{
	user *ptr=userHead;
	file *nptr;
	while(ptr!=NULL)
	{
		printf("UserName:\t%s\n",ptr->name);
		nptr=ptr->head;
		printf("\nThe files along with their memory addresses are\n");
		while(nptr!=NULL)
		{
			printf("File Number:\t%d\tMemory Address\t%d\n",nptr->x,&(nptr->x));
			nptr=nptr->next;
		}
		ptr=ptr->next;
	}
}
void access(int fno,char name[50])
{
	user *ptr=userHead;
	file *nptr;
	int flagNotAccess=1;
	while(ptr!=NULL)
	{
		nptr=ptr->head;
		while(nptr!=NULL)
		{
			if(nptr->x==fno && (strcmp(ptr->name,name)==0))
			{
				printf("\nFile is present its memory address is %d\n",&(nptr->x));
				return;
			}
			else if(nptr->x==fno)
			{
				flagNotAccess=1;
			}
			nptr=nptr->next;
		}
		ptr=ptr->next;
	}
	if(flagNotAccess==1)
	printf("\nSorry, you don't have the required permissions to access the file\n");
}

void deleteFile(int fno,char name[50])
{
	user *ptr=userHead;
	file *nptr,*ptr1,*ptr2;
	int flagNotAvailable=1;
	while(ptr!=NULL)
	{
		nptr=ptr->head;
		ptr1=NULL;
		while(nptr!=NULL)
		{
			if(strcmp(ptr->name,name)==0 && (nptr->x==fno))
			{
				if(ptr1==NULL)
				{
					ptr->head=nptr->next;
					free(nptr);
					return;
				}
				else if(nptr->next==NULL)
				{
					ptr1->next=NULL;
					free(nptr);
					return;
				}
				else
				{
					ptr1->next=nptr->next;
					free(nptr);
					return;
				}
			}
			ptr1=nptr;
			nptr=nptr->next;
		}
		ptr=ptr->next;
	}
	printf("\nFile not found in current user directory\n");
}
void deleteUser(char name[50])
{
	user *ptr2,*ptr=userHead;
	file *nptr,*ptr1;
	ptr2=NULL;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->name,name)==0)
		{
			nptr=ptr->head;
			while(nptr!=NULL)
			{
				ptr1=nptr;
				nptr=nptr->next;
				free(ptr1);
			}
			if(ptr2==NULL)
			{
				userHead=ptr->next;
				free(ptr);
				return;
			}
			else if(ptr->next==NULL)
			{
				ptr2->next=NULL;
				free(ptr);
				return;
			}
			else
			{
				ptr2->next=ptr->next;
				free(ptr);
				return;
			}
		}
		ptr2=ptr;
		ptr=ptr->next;
	}
	printf("\nNo such user exists\n");
}

void main()
{
	int choice,x;
	printf("Creating Users\n");
	do
	{
		addUser();
		printf("Want to create more users(1-Yes\\0-No)\n");
		scanf("%d",&choice);
	}while(choice!=0);
	char name[50];
	printf("Enter the username to login(\"null\" to exit)\n");
	scanf("%s",name);
	do
	{	
	if(searchUser(name)==1)
	{
	do
	{
		printf("Choose the facility you want to perform\n");
		printf("1.Create a file\n");
		printf("2.Access a file\n");
		printf("3.Delete a file\n");
		printf("4.Display the directory structure\n");
		printf("5.Remove my Account\n");
		printf("6.LogOff\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:addFile(name);
			       break;
			case 2:printf("Enter the number of the file you want to access\n");
			       scanf("%d",&x);
			       access(x,name);
			       break;
			case 3:printf("Enter the number of the file you want to delete\n");
			       scanf("%d",&x);
			       deleteFile(x,name);
			       break;
			case 4:printf("The directory structure is\n");
				   display();
			       break;
			case 5:deleteUser(name);
			       printf("The current directory is\n");
			       display();
			       choice=6;
			       break;
			case 6:printf("Logging Off....\n");
			       break;
			default:printf("Wrong Choice\n");
		}
	}while(choice!=6);
    }
    else
    printf("Invalid Username\n");
	printf("Enter the username to login(\"null\") to exit\n");
	scanf("%s",name);
}while(strcmp(name,"null")!=0);
}
