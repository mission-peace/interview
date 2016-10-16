#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
	int LISet;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();
	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;
	temp->LISet = -1;
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

int LISet(struct node *root)
{
	if(root==NULL)
		return 0;
	if(root->LISet!=-1)
		return root->LISet;

	int excl_curnode = LISet(root->left) + LISet(root->right);

	int incl_curnode = 1;
	if(root->left)
		incl_curnode += LISet(root->left->left) + LISet(root->left->right);
	if(root->right)
		incl_curnode += LISet(root->right->left) + LISet(root->right->right);

	root->LISet = max(excl_curnode,incl_curnode);
	return root->LISet;
}


int main()
{
	int arr[] = {10,5,1,7,30,40,50,60};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl;

	cout<<LISet(Tree);


	cin.get();
	return 0;
}