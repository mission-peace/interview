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

void printInorderREVERSE(struct node *root)
{
	if(root==NULL)
		return;
	printInorderREVERSE(root->right);
	cout<<root->data<<" ";
	printInorderREVERSE(root->left);
}

bool getPrednSucc(struct node *tree,int key,struct node *&pred,struct node *&succ)
{
	struct node *root = tree;
	if(root==NULL)
		return false;
	if(root->data==key)
	{
		// This part is for when the left or right subtree is not NULL, and we need to find the max or min
		if(root->right!=NULL)
		{
			struct node *minleft = root->right;
			while(minleft->left!=NULL)
				minleft = minleft->left;
			succ = minleft;
		}
		if(root->left!=NULL)
		{
			struct node *maxright = root->left;
			while(maxright->right!=NULL)
				maxright = maxright->right;
			pred = maxright;
		}
		return true;
	}
	else
	{
		// This part is smart! While Traversal, we are indeed visiting the 
		// Predecessor and Successor. Thus, why not we track them while
		// Traversal itself ?!
		if(key < root->data)
		{
			succ = root;
			return getPrednSucc(root->left,key,pred,succ);
		}
		else if(key > root->data)
		{
			pred = root;
			return getPrednSucc(root->right,key,pred,succ);
		}
	}

}

struct node *getLCA(struct node *root,int n1,int n2)
{
	if(root==NULL || n1 < root->data && root->data < n2)
		return root;
	else if(n1 < root->data && n2 < root->data)
		getLCA(root->left,n1,n2);
	else if(n1 > root->data && n2 > root->data)
		getLCA(root->right,n1,n2);
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
	cout<<"\n\n";
	printInorderREVERSE(tree);

	struct node *pred = NULL;
	struct node *succ = NULL;
	int key = 1;
	
	cout<<"\n\n";
	if(getPrednSucc(tree,key,pred,succ))
	{
		if(pred==NULL)
			cout<<"\nNo Predecessor for "<<key<<endl;
		else
			cout<<"\nThe Predecessor for "<<key<<" is : "<<pred->data<<endl;
		if(succ==NULL)
			cout<<"\nNo successor for "<<key<<endl;
		else
			cout<<"\nThe successor for "<<key<<" is : "<<succ->data<<endl;
	}
	else
		cout<<"The key "<<key<<" is not found in the tree!"<<endl;

	cout<<"\n\n";
	int n1 = 1,n2 = 35;
	struct node *resLCA = getLCA(tree,n1,n2);
	if(resLCA!=NULL)
		cout<<"The LCA of "<<n1<<" and "<<n2<<" is : "<<resLCA->data<<"\n";
	else
		cout<<"LCA doesnt exist for "<<n1<<" and "<<n2;


	cin.get();
	cin.get();
	return 0;
}