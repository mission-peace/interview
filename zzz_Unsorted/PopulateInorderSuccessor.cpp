#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
	struct node *next;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();
	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;
	temp->next = NULL;
	return temp;
}

void createNode(struct node **root,int x)
{
	if(*root!=NULL)
	{
		if(x < (*root)->data)
			createNode(&(*root)->left,x);
		else
			createNode(&(*root)->right,x);
	}
	else
		*root = newNode(x);
}

void printTree_IN(struct node *root)
{
	if(root!=NULL)
	{
		printTree_IN(root->left);
		cout<<root->data<<" ";
		printTree_IN(root->right);
	}
		
}

void getInorderLinks(struct node *root,struct node *&prev)
{
	if(root==NULL)
		return;
	getInorderLinks(root->right,prev);
	root->next = prev;
	prev = root;
	getInorderLinks(root->left,prev);
}

void LinkInorderSuccessors(struct node *root)
{
	struct node *prev = NULL;
	getInorderLinks(root,prev);
}

void printInorderLinks(struct node *root)
{
	while(root->left!=NULL)
		root = root->left;
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root = root->next;
	}
}

int main()
{
	int arr[] = {10,5,1,7,20,30,40,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl;
	LinkInorderSuccessors(Tree);
	printInorderLinks(Tree);
	cout<<endl;

	cin.get();
	return 0;
}