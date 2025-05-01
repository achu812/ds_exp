#include<stdio.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
struct Node
{
	int data;
	struct Node *next;
}*head=NULL;
void main()
{
	int item,i;
	do{
		printf("\nEnter your choice:");
		printf("\n1.Push 2.Pop 3.Display 0.Exit");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter the item to be pushed:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;	
		}
	}while(i!=0);
}
void push(int value)
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
	printf("\nOne item is inserted");
}
void pop()
{	
	int p;
	if(head==NULL)
		printf("\nStack is empty");
	else
	{
		struct Node *temp=head;
		if(head->next==NULL)
		{
			head=NULL;
			p=temp->data;
			free(temp);
		}
		else
		{
			head=temp->next;
			p=temp->data;
			free(temp);
		}
		printf("The poped item is %d",p);
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\nStack is Empty");
	}
	else
	{
		struct Node *temp=head;
		printf("\nStack elements are-\n");
		while(temp->next!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("%d--->NULL",temp->data);
	}
}
