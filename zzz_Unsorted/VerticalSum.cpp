#include<iostream>
#include<map>
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

void createTree(struct node **root,int a)
{
	if(*root==NULL)
		*root = newNode(a);
	else if(a < (*root)->data)
		createTree(&(*root)->left,a);
	else if(a > (*root)->data)
		createTree(&(*root)->right,a);
}

void PrintInorder(struct node *root)
{
	if(root==NULL)
		return;
	PrintInorder(root->left);
	cout<<root->data<<" ";
	PrintInorder(root->right);
}

void getVerticalSum(struct node *root,int HD,map<int,int> &M)
{
	if(root==NULL)
		return;
	getVerticalSum(root->left,HD-1,M);
	if(M[HD]==NULL)
	{
		M[HD] = 0;
		M[HD] += root->data;
	}
	else
		M[HD] +=root->data;
	getVerticalSum(root->right,HD+1,M);
}

void printVerticalSum(struct node *root)
{
	map<int,int> M;
	getVerticalSum(root,0,M);

	map<int,int>::iterator i;
	for(i = M.begin() ; i!=M.end() ; i++)
		cout<<"Distance "<<i->first<<" sum = "<<i->second<<endl;
	
}

int main()
{
	int arr[] = {10,5,1,7,20,30,40};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *tree = NULL;
	for(int i=0 ; i<=n-1 ; i++)
		createTree(&tree,arr[i]);
	
	PrintInorder(tree);
	cout<<"\n\n";
	printVerticalSum(tree);

	cin.get();
	cin.get();
	return 0;
}