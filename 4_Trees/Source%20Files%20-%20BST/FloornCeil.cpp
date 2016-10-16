#include<iostream>
#define INTMIN -9999
#define INTMAX 9999
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

int getCeilValue(struct node *root,int key)
{
	if(root==NULL)
		return -1;
	if(root->data == key)
		return root->data;
	if(key > root->data)
		return getCeilValue(root->right,key);

	int ceil = getCeilValue(root->left,key);
	return ((ceil >= key) ? ceil : root->data);
}

int getFloorValue(struct node *root,int key)
{
	if(root==NULL)
		return INTMAX;
	if(root->data == key)
		return root->data;

	if(key < root->data)
		return getFloorValue(root->left,key);
	int temp = getFloorValue(root->right,key);
	return (temp <= key ? temp : root->data); 
}



int main()
{
	int arr[] = {10,5,1,7,20,30};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl;
	
	for(int i=0 ; i<=15 ; i++)
		cout<<i<<" -> "<<getCeilValue(Tree,i)<<endl;

	for(int i=0 ; i<=15 ; i++)
		cout<<i<<" -> "<<getFloorValue(Tree,i)<<endl;

	cout<<endl;

	cin.get();
	return 0;
}