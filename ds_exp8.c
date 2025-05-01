#include<stdio.h>
#include<stdlib.h>
struct tnode{
	int data;
	struct tnode *right;
	struct tnode *left;
	
};

struct tnode *CreateBst(struct tnode*,int);
void Inorder(struct tnode*);
void Preorder(struct tnode*);
void Postorder(struct tnode*);

int main()
{
	struct tnode *root=NULL;
	int choice,item,n,i;
	do
	{
		printf("\n\nBinary search tree opertaions");
		printf("\n 1.Creation of BST");
		printf("\n 2.Transverse in Inorder");
		printf("\n 3.Transverse in Preorder");
		printf("\n 4.Transverse in Postorder");
		printf("\n 5.Exit");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				root=NULL;
				printf("\n\nBst for how many nodes");
				scanf("%d",&n);
				for(i=1;i<=n;i++)
				{
					printf("\n Enter data for node %d",i);
					scanf("%d",&item);
					root=CreateBst(root,item);
				}
				printf("\n Bst with %d nodes is ready to use\n",n);
				break;
			case 2:
				printf("\n Bst trversal in inorder");
				Inorder(root);
				break;
			case 3:
				printf("\n Bst traversal in preorder");
				Preorder(root);
				break;
			case 4:
				printf("\n Bst traversal in postorder ");
				Postorder(root);
				break;
			case 5:
				printf("\n\n Terminating\n\n");
				break;
			default:
				printf("\n\ninvalid option\n\n");
				break;						
		}
	
	}
	while(choice!=5);
	return 0;

}

struct tnode *CreateBst(struct tnode *root,int item)
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
			root->left=CreateBst(root->left,item);
		else if(item>root->data)
			root->right=CreateBst(root->right,item);
		else
			printf("Duplicate element not allowed!!");
			return(root);	
	}
}

void Inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		Inorder(root->left);
		printf("%d",root->data);
		Inorder(root->right);
	}
}
void Preorder(struct tnode *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}
void Postorder(struct tnode *root)
{
	if(root!=NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("%d",root->data);
	}
}

