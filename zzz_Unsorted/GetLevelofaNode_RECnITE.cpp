#include<iostream>
#include<queue>
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

void _getLevelofNode(struct node *root,int key,int level,int *res)
{
	if(root==NULL)
		return;

	if(root->data==key)
		*res = level;
	if( (root->left && root->left->data==key) || (root->right && root->right->data==key) )
		*res = level+1;
	_getLevelofNode(root->left,key,level+1,res);
	_getLevelofNode(root->right,key,level+1,res);
}

int getLevelofNode(struct node *root,int key)
{
	int keylevel = -1;
	_getLevelofNode(root,key,1,&keylevel);
	return keylevel;
}

int getLevelofNode_ITE(struct node *root,int key)
{
	int nodelevel = -1;
	if(root==NULL)
		return nodelevel;
	if(root->data==key)
		return nodelevel+2;

	queue<struct node *> Q;
	Q.push(root);

	while(!Q.empty())
	{
		int levelnodescount = Q.size();
		nodelevel++;

		while(levelnodescount)
		{
			struct node *front = Q.front();
			Q.pop();

			if(front->data==key)
				return ++nodelevel;

			if( (root->left && root->left->data==key) || (root->right && root->right->data==key) )
				return nodelevel+2;

			if(front->left)
				Q.push(front->left);
			if(front->right)
				Q.push(front->right);

			levelnodescount--;
		}
	}
	nodelevel = -1;
	return nodelevel;
}




int main()
{
	int arr[] = {10,5,1,7,40,50,60};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *tree = NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createTree(&tree,arr[i]);

	for(int i=0 ; i<=n-1 ; i++)
	{
		int key = arr[i];
		cout<<"\n\nThe level of the node "<<key<<" is (RECURSION) : "<<getLevelofNode(tree,key);
		cout<<"\nThe level of the node "<<key<<" is (ITERATION)  : "<<getLevelofNode_ITE(tree,key);

	}

	//cout<<"\n\nThe Difference between Odd and Even Levels is : "<<getDifferenceofLevels(tree);

	cin.get();
	return 0;
}