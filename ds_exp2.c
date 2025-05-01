#include<stdio.h>
#define max 12
int a[max],top=-1;
void push(int);
void display();
void main()
{
int n,r;
printf("enter the element");
scanf("%d",&n);
while(n!=0)
{
r=n%2;
push(r);
n=n/2;
}
display();
}
void push(int n)
{
if(top==max-1)
	printf("\n the stack is full");
else
{
top=top+1;
a[top]=n;	
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



