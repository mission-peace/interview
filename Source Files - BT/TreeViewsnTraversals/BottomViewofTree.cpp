#include<iostream>
#include<map>
#include<vector>
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

void printTree_VERTICALORDER(map<int,vector<int>> &TreeMap)
{
	map<int,vector<int>>::iterator i;

	for(i=TreeMap.begin() ; i!=TreeMap.end() ; i++)
	{
		//for(int j=0 ; j<= i->second.size()-1 ; j++)
			cout<<i->second[i->second.size()-1]<<" ";
	}

}

void getVerticalOrderMap(struct node *root,map<int,vector<int>> &TreeMap,int HD)
{
	if(root==NULL)
		return;

	TreeMap[HD].clear();
	TreeMap[HD].push_back(root->data);
	getVerticalOrderMap(root->left,TreeMap,HD-1);
	getVerticalOrderMap(root->right,TreeMap,HD+1);
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

void main()
{
	int arr[] = {6,3,8,2,9,1,7,10,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);

	cout<<"The Inorder Traversal is : ";
	printTree_IN(Tree);
	cout<<endl;

	map<int,vector<int>> TreeMap;
	getVerticalOrderMap(Tree,TreeMap,0);

	cout<<"The Bottom View of Tree  : ";
	printTree_VERTICALORDER(TreeMap);

	cin.get();
}