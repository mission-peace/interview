#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
	//struct node *parent;
};

struct node *newNode(int x)
{
	struct node *temp = new struct node();

	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	//temp->parent = NULL;

	return temp;
}

void createNode(struct node **root,int x)
{
	if(*root!=NULL)
	{
		if(x >= (*root)->data)
			createNode(&(*root)->right,x);
		else
			createNode(&(*root)->left,x);
	}
	else
		*root = newNode(x);
}

int heightTree(struct node *root)
{
	if(root==NULL)
		return 0;

	return 1+max(heightTree(root->left),heightTree(root->right));

}

int heightBalancedTree(struct node *root)
{
	if(root==NULL)
		return 1;

	int lh = heightTree(root->left);
	int rh = heightTree(root->right);
	int h = lh-rh;

	if((-1<=h && h<=1) && heightBalancedTree(root->left) && heightBalancedTree(root->right))
		return 1;

	return 2;
}

int main()
{
	int arr[] = {10,5,1,7,40,60,50,70};	//  {1,7,5,50,40,10};

	struct node *Tree=NULL;

	for(int i=0 ; i<=(sizeof(arr)/sizeof(arr[0]))-1 ; i++)
		createNode(&Tree,arr[i]);

	int n = 0;
	cout<<"\nIs the tree height balanced? 1=TRUE 2=FALSE : "<<heightBalancedTree(Tree);

	cin.get();
	return 0;
}