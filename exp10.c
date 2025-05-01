#include<stdio.h>
#include<stdlib.h>
int n,adj[20][20],visited[20];
void readgraph();
void displaygraph();
void bfs();
void dfs();
void main()
{
	int n,ch;
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1.Create graph\n2.Display graph\n3.BFS\n4.DFS\n5.EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:readgraph();
				break;
			case 2:displaygraph();
				break;
			case 3:bfs();
				break;	
			case 4:dfs();
				break;
			case 5:exit(0);
				break;
		}		
	}		
}			
void readgraph()
{
	int i,j;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacent matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}	
}
void displaygraph()	
{
	int i,j;
	printf("The graph is:\n");
	for(i=1;i<=n;i++)	
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}	
void dfs()
{
	int v,stack[20],i,top=-1;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	top++;
	stack[top]=1;
	while(top>=0)	
	{
		v=stack[top];
		top--;
		if(visited[v]==0)
		{
			printf("%d   ",v);
			visited[v]=1;
			for(i=n;i>=1;i--)
			{
				if((adj[v][i]==1) && (visited[i]==0))
				{
					top++;
					stack[top]=i;
				}
			}
		}	
	}		
}			
void bfs()
{
	int i,v,front=-1,rear=-1,queue[20];
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	printf("1    ");
	visited[1]=1;
	rear++;
	front++;
	queue[rear]=1;
	while(front<=rear)
	{
		v=queue[front];
		front++;
		for(i=1;i<=n;i++)
		{
			if((adj[v][i]==1) && (visited[i]==0))
			{
				printf("%d   ",i);
				visited[i]=1;
				rear++;
				queue[rear]=i;
			}
		}
	}	
}		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	

















