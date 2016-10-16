#include<iostream>
#include<map>
#define CHECKSUM 60
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

bool checkPatheqSum(int *path,int len)
{
	int sum = 0;
	for(int i=0 ; i<=len-1 ; i++)
		sum +=path[i];
	return sum==CHECKSUM;
}

void getRoottoLeafPath(struct node *root,int *path,int len)
{
	if(root==NULL)
		return;
	path[len++] = root->data;
	if(root->left==NULL && root->right==NULL)
	{
		if(checkPatheqSum(path,len))
			cout<<"Yes, there is a path with Sum "<<endl;
	}
	getRoottoLeafPath(root->left,path,len);
	getRoottoLeafPath(root->right,path,len);
}

void printRoottoLeaf(struct node *tree,int n)
{
	int *path = new int[n];
	bool checksum = false;
	getRoottoLeafPath(tree,path,0);
}

int main()
{
	int arr[] = {10,5,1,7,20,30,40};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;
	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);
	printTree_IN(Tree);
	cout<<endl;

	printRoottoLeaf(Tree,n);

	cin.get();
	cin.get();
	return 0;
}