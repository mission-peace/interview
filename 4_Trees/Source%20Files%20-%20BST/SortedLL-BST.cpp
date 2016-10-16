#include<iostream>
using namespace std;

struct lnode 
{
	int data;
	struct lnode *next;
};

struct lnode *newNodeLL(int a)
{
	struct lnode *temp = new struct lnode();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void createLL(struct lnode **refHead,int a)
{
	struct lnode *temp = newNodeLL(a);
	if(*refHead!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

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

void createTree(struct node **root,int a)
{
	if(*root==NULL)
		*root = newNode(a);
	else if(a < (*root)->data)
		createTree(&(*root)->left,a);
	else if(a > (*root)->data)
		createTree(&(*root)->right,a);
}

int countNodes(struct lnode *head)
{
	int count = 0;
	while(head!=NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}


struct node *LLtoBST(struct lnode **refHead,int n)
{
	if(*refHead==NULL)
		return NULL;
	if(n <= 0)
		return NULL;

	struct node *templeft = LLtoBST(&(*refHead),n/2);
	struct node *root = newNode((*refHead)->data);
	root->left = templeft;

	*refHead = (*refHead)->next;

	struct node *tempright = LLtoBST(&(*refHead),n-(n/2)-1);
	root->right = tempright;

	return root;
}

struct node *convertLLtoBST(struct lnode **refHead,struct node *&root)
{
	return LLtoBST(refHead,countNodes(*refHead));
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}



int main()
{
	int arr[] = {1,5,7,10,20,25,30};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct lnode *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL,arr[i]);

	struct node *tree = NULL;
	tree = convertLLtoBST(&LL,tree);
	inorder(tree);

	cin.get();
	cin.get();
	return 0;
}