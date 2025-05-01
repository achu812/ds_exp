#include<stdio.h>
#include<stdlib.h>
void insertAtbegining(int);
void insertAtend(int);
void removeBegining();
void removeEnd();
void display();
void search();
struct Node
{
	int data;
	struct Node *next;
}*head=NULL;
void main()
{
	int i,item;
	do{
		printf("\nEnter your choice:");
		printf("\n1.Insert at begining\t2.Insert at end\t3.Remove from begining\t4.Remove from end\t5.Display\t6.Search\n0:Exit\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			printf("Enter the item to be inserted:");
			scanf("%d",&item);
			insertAtbegining(item);
			break;
		case 2:
			printf("Enter the item to be inserted:");
			scanf("%d",&item);
			insertAtend(item);
			break;
		case 3:
			removeBegining();
			break;
		case 4:
			removeEnd();
			break;
		case 5:
			display();
			break;
		case 6:
			search();
			break;
		}
	}while(i!=0);
}
void insertAtbegining(int value)
{
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	if(head==NULL)
	{
		newNode->next=NULL;
		head=newNode;
	}
	else
	{
		newNode->next=head;
		head=newNode;
	}
	printf("\nOne node inserted\n");
}
void insertAtend(int value)
{
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	if(head==NULL)
		head=newNode;
	else
	{
		struct Node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=newNode;
	}
	printf("\nOne node inserted\n");
}
void removeBegining()
{
	if(head==NULL)
		printf("\nList is empty\n");
	else
	{
		struct Node *temp=head;
		if(head->next==NULL)
		{
			head=NULL;
			free(temp);
		}
		else
		{
			head=temp->next;
			free(temp);
			printf("One node deleted");
		}
	}
}
void removeEnd()
{
	if(head==NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		struct Node *temp1=head,*temp2;
		if(head->next==NULL)
			head=NULL;
		else
		{
			while(temp1->next!=NULL)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			temp2->next=NULL;
		}
		free(temp1);
		printf("\nOne node deleted\n");
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		struct Node *temp=head;
		printf("\nList elements are-\n");
		while(temp->next!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("%d--->NULL",temp->data);
	}
}
void search()
{
	int f=0,s;
	if(head==NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		printf("\nEnter the item to be searched:");
		scanf("%d",&s);
		struct Node *temp=head;
		while(temp->next!=NULL)
		{
			if(s==temp->data)
			{
				f=1;
			}
			temp=temp->next;
		}
		if(s==temp->data)
			{
				f=1;
			}
		if(f==1)
			printf("Searched item is found");
		else
			printf("Item not found");
	}
}
