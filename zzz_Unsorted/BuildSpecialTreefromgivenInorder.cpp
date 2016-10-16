#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	char data;
	struct node *right;
};

struct node *newNode(char a)
{
	struct node *temp = new struct node();
	temp->left= NULL;
	temp->data = a;
	temp->right = NULL;
	return temp;
}

int searchIndex(char arr[],int si,int ei)
{
	int maxi = si;
	for(int i=si+1 ; i<=ei ; i++)
	{
		if(arr[i]-'A' > arr[maxi]-'A')
			maxi = i;

	}
	return maxi;
}

struct node *BuildTree(char In[],int si,int ei)
{
	if(si > ei)
		return NULL;

	int pivot = searchIndex(In,si,ei);

	struct node *root = newNode(In[pivot]);

	if(si==ei)
		return root;
	else
	{
		root->left = BuildTree(In,si,pivot-1);
		root->right = BuildTree(In,pivot+1,ei);
		
	}
	return root;

}

void Inorder(struct node *root)
{
	if(root==NULL)
		return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void printArray(char arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	char In[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	int n = sizeof(In)/sizeof(In[0]);

	struct node *tree = NULL;

	tree = BuildTree(In,0,n-1);
	printArray(In,n);
	cout<<"\n The Inorder Tree Traversal is : "<<endl;
	Inorder(tree);

	cin.get();
	cin.get();
	return 0;

}