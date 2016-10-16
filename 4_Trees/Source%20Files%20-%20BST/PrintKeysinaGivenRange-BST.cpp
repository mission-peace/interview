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

struct node *createTree(struct node *root,int a)
{
	if(root==NULL)
		return newNode(a);
	else if(a < root->data)
		root->left = createTree(root->left,a);
	else if(a > root->data)
		root->right = createTree(root->right,a);
	return root;
}

void printInorder(struct node *root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printRange(struct node *root,int L1,int L2)
{
	if(root==NULL)
		return;
	if(L1 < root->data)
		printRange(root->left,L1,L2);
	if(L1 <= root->data && root->data <= L2)
		cout<<root->data<<" ";
	if(root->data < L2)
		printRange(root->right,L1,L2);
}

int main()
{
	int arr[] = {10,5,1,7,15,20,25,30};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *tree = NULL;
	tree = createTree(tree,arr[0]);
	for(int i=1 ; i<=n-1 ; i++)
		createTree(tree,arr[i]);

	printInorder(tree);
	int L1 = 6;
	int L2 = 21;

	cout<<"\n\nThe nodes between "<<L1<<" and "<<L2<<" are : \n";
	printRange(tree,min(L1,L2),max(L1,L2));


	cin.get();
	cin.get();
	return 0;
}