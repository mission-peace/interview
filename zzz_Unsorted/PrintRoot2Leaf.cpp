#include<iostream>
#include<vector>
using namespace std;


struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *newtNode(int a)
{
	struct node *temp = new struct node();

	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;

	return temp;
}

void createtNode(struct node **root,int x)
{
	if(*root!=NULL)
	{
		if(x < (*root)->data)
			createtNode(&(*root)->left,x);
		else
			createtNode(&(*root)->right,x);
	}
	else
		*root = newtNode(x);
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

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void _printRoot2LeafPath(struct node *root,int arr[],int size)
{
	if(root==NULL)
		return;

	arr[size++] = root->data;

	if(root->left==NULL && root->right==NULL)
		printArray(arr,size);

	_printRoot2LeafPath(root->left,arr,size);
	_printRoot2LeafPath(root->right,arr,size);
}

void printRoot2LeafPath(struct node *root,int size)
{
	int *arr = new int[size];
	_printRoot2LeafPath(root,arr,0);
}

int main()
{
	int arr[] = {10,5,1,7,40,37,24};
	int n=sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createtNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl<<"The Root to Leaf Path of the above tree is : \n";
	printRoot2LeafPath(Tree,n);

	cin.get();
	return 0;
}