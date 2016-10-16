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

struct node *insertNode(struct node *root,int a)
{
	if(root==NULL)
		return newNode(a);
	if(a < root->data)
		root->left = insertNode(root->left,a);
	if(a > root->data)
		root->right = insertNode(root->right,a);
	return root;
}

void printTree(struct node *tree)
{
	if(tree==NULL)
		return;
	printTree(tree->left);
	cout<<tree->data<<" ";
	printTree(tree->right);
}

bool searchTree(struct node *root,int key)
{
	if(root==NULL)
		return 0;
	else if(root->data == key)
		return 1;
	else if(key < root->data)
		searchTree(root->left,key);
	else
		searchTree(root->right,key);
}

struct node *getInorderSuccessor(struct node *root)
{
	if(root==NULL)
		return root;
	while(root->left!=NULL)
		root = root->left;
	return root;
}

struct node *deleteNode(struct node *root,int key)
{
	if(root==NULL)
		return root;
	else if(key < root->data)
		root->left = deleteNode(root->left,key);
	else if(key > root->data)
		root->right = deleteNode(root->right,key);
	else
	{
		if(root->left == NULL)
		{
			struct node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL)
		{
			struct node *temp = root->left;
			delete root;
			return temp;
		}
		struct node *temp = getInorderSuccessor(root->right);
		root->data = temp->data;
		// The ultimate smartness of BST delete lies in the below line! :D
		root->right = deleteNode(root->right,temp->data);
	}
	return root;
}

int main()
{
	int arr[] = {10,5,1,7,30,40,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *tree = NULL;
	tree = insertNode(tree,arr[0]);
	for(int i=1 ; i<=n-1 ; i++)
		insertNode(tree,arr[i]);		// Time = O(n^2)

	printTree(tree);	// Time = O(n)
	cout<<"\n\n";

	for(int i=0 ; i<=n-1 ; i++)
		searchTree(tree,arr[i])==1 ? cout<<arr[i]<<" is found!\n" : cout<<arr[i]<<" is not found! SORRY!\n";

	searchTree(tree,0)==1 ? cout<<" 0 is found!\n" : cout<<"0 is not found! SORRY!\n";
	searchTree(tree,-1)==1 ? cout<<"-1 is found!\n" : cout<<"-1 is not found! SORRY!\n";
	searchTree(tree,1234)==1 ? cout<<" 1234 is found!\n" : cout<<"1234 is not found! SORRY!\n";

	cout<<"\n\n";
	deleteNode(tree,5);
	printTree(tree);	
	cout<<"\n\n";

	cout<<"\n\n";
	deleteNode(tree,10);
	printTree(tree);	
	cout<<"\n\n";


	cin.get();
	cin.get();
	return 0;
}