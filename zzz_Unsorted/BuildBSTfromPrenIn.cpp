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

	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;
	return temp;
}

int getPivot(int In[],int si,int ei,int key)
{
	int i;
	for(i=si ; i<= ei ; i++)
	{
		if(In[i]==key)
			return i;
	}
	return -1;
}

struct node *_BuildBST(int In[],int Post[],int si,int ei,int *postindex)
{
	if(si <= ei && *postindex!= -1)
	{
		struct node *root = newNode(Post[*postindex]);
		(*postindex)--;

		if(si==ei)
			return root;
		else
		{
			int pivot = getPivot(In,si,ei,root->data);
			
			root->right = _BuildBST(In,Post,pivot+1,ei,postindex);
			root->left = _BuildBST(In,Post,si,pivot-1,postindex);
			return root;
		}
	}
	else
		return NULL;
}

struct node *BuildBST(int In[],int Post[],int si,int ei)
{
	struct node *root = NULL;
	int postindex = ei;

	root = _BuildBST(In,Post,si,ei,&postindex);
	return root;
}

void printInorder(struct node *root)
{
	if(root==NULL)
		return ;

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main()
{
	int In[] = {1,5,7,10,40,50};
	int Post[] = {1,7,5,50,40,10};

	int n = sizeof(In)/sizeof(In[0]);

	struct node *tree = BuildBST(In,Post,0,n-1);

	printInorder(tree);

	cin.get();
	cin.get();
	return 0;
}