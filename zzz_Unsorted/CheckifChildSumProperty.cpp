#include<iostream>
#include<queue>
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

	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;

	return temp;
}

void createTree(struct node **root,int x)
{
	if(*root!=NULL)
	{
		if(x < (*root)->data)
			createTree(&(*root)->left,x);
		else
			createTree(&(*root)->right,x);
	}
	else
		*root = newNode(x);
}

void _checkChildSum(struct node *root,bool *prop)
{
	if(root==NULL)
		return;

	if(root->left==NULL && root->right!=NULL)
	{
		if(root->data != root->right->data )
			*prop = false;
	}
	else if(root->right==NULL && root->left!=NULL)
	{
		if(root->data != root->left->data )
			*prop = false;
	}
	else if(root->right!=NULL && root->left!=NULL)
	{
		if(root->data != root->left->data+root->right->data)
			*prop = false;
	}

	_checkChildSum(root->left,prop);
	_checkChildSum(root->right,prop);

}

bool checkChildSum(struct node *root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))	// The leaf nodes,NULL nodes always satisfy CHILD SUM
		return true;
	
	int l=0 ; int r=0;

	if(root->left!=NULL)
		l = root->left->data;
	if(root->right!=NULL)
		r = root->right->data;

	// Prefer checking using if conditions rather than separtely checking like if(l+r==root->data) { checkCHildSUm(left); checkchildSUm(right);}
	if(l+r == root->data && checkChildSum(root->left) && checkChildSum(root->right))
		return true;
	else
		return false;

}

int main()
{

	struct node *Tree = NULL;

	Tree = newNode(10);
	Tree->left = newNode(8);
	Tree->left->left = newNode(5);
	Tree->left->right = newNode(3);
	Tree->right = newNode(2);
	Tree->right->left = newNode(1);

	cout<<"\nFor every subtree, parent = left + right children: "<<checkChildSum(Tree);

	cin.get();
	return 0;
}