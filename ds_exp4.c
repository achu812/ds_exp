#include<stdio.h>
#define max 4
int q[max],front=-1,rear=-1;
void enqueue(int);
int dequeue();
void display();
void main()
{
	int i,item;
	do{
	printf("\nEnter your choice:");
	printf("\n1.Enqueue\t2.dequeue\t3.Display\t0.exit\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
		printf("enter the item to be inserted:");
		scanf("%d",&item);
		enqueue(item);
		break;
	case 2:
		item=dequeue();
		if(item!=-999)
		{
		printf("\nthe deleted item is %d",item);
		}
		break;
	case 3:
		display();
		break;
}
}
while(i!=0);
}
void enqueue(int item)
{
	if(rear==max-1)
	{
	printf("\nthe queue is full.\n");
	}
	else
	{
		if((rear==-1)&&(front==-1))
		{
		front=0;
		}
		rear=rear+1;
		q[rear]=item;
		}
		
}
int dequeue()
{
	int item;
	if(front==-1)
	{
	printf("\nthe queue is empty\n");
	return-999;
	}
	else
	{
		item=q[front];
		if(front=rear)
		{
			front=rear-1;
		}
		else
		{
			front=front+1;
		}
		return item;
		}
}
void display()
{
	int i;	
	if((front==-1)&&(rear==-1))
	{
		printf("\nthe queue is empty\n");
	}
	else
	{
		printf("\nthe queue is \n");
		for(i=front;i<=rear;i++)
		printf("%d\t",q[i]);
	}
}
		
	
