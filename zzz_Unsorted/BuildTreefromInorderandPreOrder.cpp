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

int searchIndex(char arr[],int si,int ei,char key)
{
	for(int i=si ; i<=ei ; i++)
	{
		if(arr[i]==key)
			return i;
	}
	cout<<"Invalid Traversal!";
	return -1;
}

struct node *BuildTree(char Pre[],char In[],int si,int ei)
{
	static int preindex;

	if(si > ei)
		return NULL;
	
	struct node *root = newNode(Pre[preindex++]);

	if(si==ei)
		return root;

	int pivot = searchIndex(In,si,ei,Pre[preindex-1]);

	root->left = BuildTree(Pre,In,si,pivot-1);
	root->right = BuildTree(Pre,In,pivot+1,ei);

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
	char Pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	char In[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	int n = sizeof(Pre)/sizeof(Pre[0]);

	struct node *tree = NULL;

	tree = BuildTree(Pre,In,0,n-1);
	printArray(In,n);
	Inorder(tree);

	cin.get();
	cin.get();
	return 0;

}