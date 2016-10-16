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

void convertBSTtoDLL(struct node *root,struct node **tail,struct node **head)
{
	if(root==NULL)
		return;
	convertBSTtoDLL(root->left,tail,head);

	root->left = *tail;
	if(*tail!=NULL)
		(*tail)->right = root;
	else
		*head = root;
	*tail = root;

	convertBSTtoDLL(root->right,tail,head);
}

void printDLL(struct node *head)
{
	if(head==NULL)
		return;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->right;
	}
}

int main()
{
	int arr[] = {6,3,8,2,9,1,7,5,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;
	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl;
	struct node *prev = NULL;
	struct node *head = NULL;
	convertBSTtoDLL(Tree,&prev,&head);
	printDLL(head);
	cout<<endl;

	cin.get();
	return 0;
}