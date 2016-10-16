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
	temp->left= NULL;
	temp->data = a;
	temp->right = NULL;
	return temp;
}

int getPivot(int arr[],int si,int ei)
{
	for(int i=si+1 ; i<=ei ; i++)
	{
		if(arr[i] >= arr[si])
			return i-1;
	}
}

struct node *BuildTree(int Pre[],int si,int ei)
{
	if(si > ei)
		return NULL;

	struct node *root = newNode(Pre[si]);	// si = root, for a given subtree
	
	if(si==ei)
		return root;
	else
	{
		int pivot = getPivot(Pre,si,ei);	// Pivot = Marks the end of Left Subtree

		root->left = BuildTree(Pre,si+1,pivot);
		root->right = BuildTree(Pre,pivot+1,ei);
	}
	return root;

}

void Inorder(struct node *root)
{
	if(root==NULL)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int	Pre[] = {10, 5, 1, 7, 40, 50};
	int n = sizeof(Pre)/sizeof(Pre[0]);

	struct node *BST = NULL;

	BST = BuildTree(Pre,0,n-1);

	cout<<"\n The Pre order traversal Array is : "<<endl;
	printArray(Pre,n);
	cout<<"\n The Inorder BSTree Traversal is : "<<endl;
	Inorder(BST);

	cin.get();
	cin.get();
	return 0;

}