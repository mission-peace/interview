#include<iostream>
#include<stack>

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

void printLL(struct node *start,bool fromend=false)
{
	if(fromend)
	{
		while(start->right!=NULL)
		{
			start = start->right;
		}
	}

	while(start!=NULL)
	{
		cout<<start->data<<" ";
		if(fromend)
			start = start->left;
		else
			start = start->right;
	}
}

void inorder(struct node *tree)
{
	if(tree==NULL)
		return;

	inorder(tree->left);
	cout<<tree->data<<" ";
	inorder(tree->right);
}

void _ConvertTreetoDLL(struct node *root,struct node **prev,struct node **head)
{
	if(root==NULL)
		return;

	_ConvertTreetoDLL(root->left,prev,head);

	if(*prev!=NULL)
	{
		root->left = *prev;
		(*prev)->right = root;
	}
	else
		*head = root;
	*prev = root;

	_ConvertTreetoDLL(root->right,prev,head);

}

void ConvertTreetoDLL(struct node *root,struct node **head)
{
	struct node *prev = NULL;
	_ConvertTreetoDLL(root,&prev,head);
}

void _ConvertTreetoDLL_ITE(struct node *root,struct node **head,struct node **prev)
{
	stack<node *> S;
	S.push(root);

	while(root!=NULL)
	{
		if(root->left!=NULL)
			S.push(root->left);
		root = root->left;
	}

	while(!S.empty())
	{
		root = S.top();
		S.pop();

		if(root!=NULL)
		{
			if(*prev==NULL)
				*head = root;
			else
			{
				 root->left = *prev;
				(*prev)->right = root;
			}
			*prev = root;
		}

		if(root->right!=NULL)
		{
			S.push(root->right);
			root = root->right;
		}
	}

}

void ConvertTreetoDLL_ITE(struct node *tree,struct node **head)
{
	struct node *prev = NULL;
	_ConvertTreetoDLL_ITE(tree,head,&prev);
}



int main()
{
	int arr[] = {10,5,1,7,40,45,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"\n**** RECURSIVE ****\n";
	struct node *tree = NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createTree(&tree,arr[i]);

	cout<<"\nThe Inorder Traversal via Tree : \n";
	inorder(tree);

	struct node *head = NULL;
	ConvertTreetoDLL(tree,&head);


	cout<<"\nThe Traversal via Doubly Linked list (using right pointer): \n";
	printLL(head,false);
	cout<<"\nThe Traversal via Doubly Linked list (using  left pointer): \n";
	printLL(head,true);
	cout<<"\n";


	cout<<"\n**** ITERATIVE ****\n";
	struct node *tree2 = NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createTree(&tree2,arr[i]);

	cout<<"\nThe Inorder Traversal via Tree : \n";
	inorder(tree2);

	struct node *head2 = NULL;
	ConvertTreetoDLL_ITE(tree2,&head2);

	cout<<"\nThe Traversal via Doubly Linked list (using right pointer): \n";
	printLL(head2,false);
	cout<<"\nThe Traversal via Doubly Linked list (using  left pointer): \n";
	printLL(head2,true);
	cout<<"\n";

	cin.get();
	return 0;
}