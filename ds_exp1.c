#include<stdio.h>
#define max 3
int a[max],top=-1;
void push(int);
int pop();
void display();
void main()
{
int item,i;
do{
	printf("enter your choice\n");
	printf("\n 1:PUSH 2:POP 3:DISPLAY 0:EXIT\t");
	scanf("%d",&i);
	
switch(i)
{
case 1:
	printf("\n enter the item to be pushed");
	scanf("%d",&item);
	push(item);
	break;
case 2:
	item=pop();
	if(item!=-999)
		printf("\n the popped item is %d",item);
	break;
case 3:
	display();
	break;
}
}
while(i!=0);	
}
void push(int item)
{
if(top==max-1)
	printf("\n the stack is full");
else
{
top=top+1;
a[top]=item;	
}
}
int pop()
{	
int p;
if(top==-1)	
	{
	printf("\n stack is empty");
	return-999;
	}
else
	{
	p=a[top];
	top=top-1;
	return p;
	}
}	
void display()	
{	
int i;	
if(top==-1)
	{
	printf("\n the stack is empty\n");
	}
	else
	{
	printf("\n the stack is \n");
	for(i=top;i>=0;i--)
	printf("%d\t",a[i]);
	}
}
	
	

