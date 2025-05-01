#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 15
int a[max],top=-1;
char expn[20];
void push(int);
int pop();
void postfix_evaluate();
void main()
{
printf("enter a postfix expression \t");
scanf("%s",expn);
postfix_evaluate();
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
void postfix_evaluate()
{
int i,n1,n2,n3,n;
for(i=0;expn[i]!='\0';i++)
{
 if(isdigit(expn[i]))
  {
  n=expn[i]-'0';
  push(n);
  }
 else
  {
  n1=pop();
  n2=pop();
  switch(expn[i])
   {
   case '+':n3=n2+n1;
            break;
   case '-':n3=n2-n1;
            break;
   case '*':n3=n2*n1;
            break;
   case '/':n3=n2/n1;
            break;                  
   default:printf("wrong operator");
           exit(0);
   }
   push(n3);
  } 
 }
n3=pop();
printf("the value is %d",n3);
}





