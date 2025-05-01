#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	int data;
	struct tnode *right;
	struct tnode *left;
};
int cnt=0;
struct tnode *CreateBST(struct tnode*,int);
int Height(struct tnode *);
void Count(struct tnode *);
int main()
{	
	struct tnode *root=NULL;
	int choice,item,n,i,h;
	do
	{	
		printf("\n\nBinary Search Tree Operations\n");
		printf("\n1:Creation of BST");
		printf("\n2:Height of the tree");
		printf("\n3:Count number  of nodes");
		printf("\n4:Exit\n");
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				root=NULL;
				printf("\n\nBST for how many nodes?!!");
				scanf("%d",&n);
				for(i=1;i<=n;i++)
				{
					printf("\n enter data for node %d:",i);
					scanf("%d",&item);
					root=CreateBST(root,item);
				}
				printf("\n BST with %d nodes is ready to use !! \n",n);
				break;
			case 2:
				printf("\nBST Height of the tree\n ");
				h=Height(root);
				printf("Height=%d",h);
				break;
			case 3:
				cnt=0;
				printf("\n\nBST number of nodes\n\n");
				Count(root);
				printf("count=%d",cnt);
				break;	
			case 4:
				printf("\n\nTerminating\n\n");		
				break;
			default:
				printf("\n\nInvalid option!!! Try Again!!\n\n");	
				break;
		}
	}while(choice!=5);
		return 0;
}
struct tnode *CreateBST(struct tnode*root,int item)
{
	if(root==NULL)				
	{
		root=(struct tnode*)malloc(sizeof(struct tnode));	
		root->left=root->right=NULL;
		root->data=item;
		return root;
	}
	else
	{
		if(item<root->data)			
			root->left=CreateBST(root->left,item);	
		else if(item>root->data)		
			root->right=CreateBST(root->right,item);
		else
			printf("Duplicate Element !! Not Allowed!!!");		
			return(root);	
	}			
}				
int Height(struct tnode *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int left_height=Height(root->left);
		int right_height=Height(root->right);
		if(left_height>=right_height)
			return left_height+1;
		else
			return right_height+1;
	}
}

void Count(struct tnode *root)
{
	if(root!=NULL)
	{
		Count(root->left);
		cnt++;
		Count(root->right);
	}
}















