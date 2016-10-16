#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();

	temp->data = a;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void createTree(struct node **root,int x)
{
	if(*root!=NULL)
	{
		if(x < (*root)->data)
			createTree(&(*root)->left,x);
		else if(x >= (*root)->data)
			createTree(&(*root)->right,x);
	}
	else
		*root = newNode(x);
}

void kthSmallestNode(struct node *root,int *k)
{
	if(root==NULL)
		return;

	kthSmallestNode(root->left,k);
	if(!(*k-1))
		cout<<root->data;
	(*k)--;
	kthSmallestNode(root->right,k);
}

int main()
{
	int arr[] = {10,5,7,1,30,50};
	int n = sizeof(arr)/sizeof(arr[0]);


	struct node *tree = NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createTree(&tree,arr[i]);

	for(int i=1 ; i<=n ; i++)
	{
		int k=i;
		cout<<"\nThe "<<k<<"th smallest node is : ";
		kthSmallestNode(tree,&k);
	}



	cin.get();
	cin.get();
	return 0;
}