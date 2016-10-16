#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node *createNode(int a)
{
	struct node *temp = new struct node();

	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;

	return temp;
}

struct node *BuildBST(int arr[],int si,int ei)
{
	if(si <= ei)
	{
		int mid = si + (ei-si)/2 ;

		struct node *root = createNode(arr[mid]);

		root->left = BuildBST(arr,si,mid-1);
		root->right = BuildBST(arr,mid+1,ei);

		return root;
	}
	else
		return NULL;
}

bool _checkifBST(struct node *root,struct node **prev)
{
	//static struct node *prev = NULL;

	if(root==NULL)
		return true;

	if(!_checkifBST(root->left,prev) )
		return false;

	if((*prev)!=NULL && (*prev)->data > root->data)
		return false;
	*prev = root;

	if(!_checkifBST(root->right,prev))
		return false;
}

void getPrednSucc(struct node *root,struct node **prev,int key)
{
	if(root==NULL)
		return;

	getPrednSucc(root->left,prev,key);

	if(root->data==key)
	{
		if(*prev)
			cout<<"\n The Predecessor of "<<key<<" is : "<<(*prev)->data;
		else
			cout<<"\n No Predecessor for "<<key<<" since it is the first node!";
	}
	if(*prev && (*prev)->data==key)
	{
		if(root)
			cout<<"\n The Successor of "<<key<<" is : "<<root->data;
		else
			cout<<"\n No Successor for "<<key<<" since it is the last node!";
	}
	*prev = root;

	getPrednSucc(root->right,prev,key);

}

bool checkifBST(struct node *root)
{
	if(root==NULL)
		return false;

	struct node *prev = NULL;

	return _checkifBST(root,&prev);
}

void Inorder(struct node *root)
{
	if(root==NULL)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int main()
{
	int arr[] = {1,6,11,13,15,18,20,24,28,33};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *tree = BuildBST(arr,0,n-1);

	Inorder(tree);

	cout<<"\n  Is this a valid BST ? "<<checkifBST(tree);

	for(int i=0 ; i<=n-1 ; i++)
	{
		cout<<endl;
		struct node *prev = NULL;
		getPrednSucc(tree,&prev,arr[i]);
	}

	//CorrectTwoNodesofBST(tree);

	cin.get();
	return 0;
}