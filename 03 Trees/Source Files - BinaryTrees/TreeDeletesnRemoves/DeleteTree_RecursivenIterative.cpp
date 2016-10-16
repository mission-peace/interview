/*

Time Complexity : 

1. Creating links using Q = O(n)
2. Printing the levels using adj pointer = O(n)
3. Creating Tree = O(nlogn) if created directly, then O(n)

OVERALL TIME = O(n)

Space Complexity :

1. Queue - O(n)
2. Queue to print - (On)

OVERALL SPACE = O(n)

Time Complexity : 

1. Creating links using Q = O(n)
2. Printing the levels using adj pointer = O(n)
3. Creating Tree = O(nlogn) if created directly, then O(n)

OVERALL TIME = O(n)

Space Complexity :



OVERALL SPACE = O(n)



*/


#include<iostream>
#include<stack>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
	struct node *adj;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();

	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;
	temp->adj = NULL;

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

void DeleteTree(struct node *tree)
{
}

void DeleteTree_ITE(struct node **tree)
{
	struct node *root = *tree;
	stack<node *> S;

	do
	{
		while(root!=NULL)
		{
			if(root->right!=NULL)
				S.push(root->right);
			if(root!=NULL)
				S.push(root);
			root = root->left;
		}

		root = S.top();
		S.pop();

		if(!S.empty()&& root->right!=NULL && root->right==S.top())
		{
			S.pop();
			S.push(root);
			root = root->right;
		}
		else if(root->left==NULL)
		{
			cout<<"Deleting the node : "<<root->data<<endl;
			root = NULL;
			delete root;
		}

	}while(!S.empty());

	*tree = NULL;
}


int main()
{
	int arr[] = {10,5,1,7,40,50};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *tree = NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createTree(&tree,arr[i]);

	cout<<"\n\nREC - Tree Deletion : ";
	DeleteTree(tree);
	cout<<"\n\nITE - Tree Deletion : ";
	DeleteTree_ITE(&tree);


	cin.get();
	return 0;
}