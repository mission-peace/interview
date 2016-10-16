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
	temp->left= NULL;
	temp->data = a;
	temp->right = NULL;
	return temp;
}

int searchIndex(int arr[],int si,int ei,int key)
{
	for(int i=si ; i<=ei-1 ; i++)
	{
		if(arr[i]==key)
			return i;
	}
	return -1;

}

int *extractKeys(int In[],int Lev[],int len,int size)
{
	int *temp = new int[size];

	for(int i=0,j=0 ; i<=len-1 ; i++)
	{
		if(searchIndex(In,0,size,Lev[i])!=-1)
			temp[j++] = Lev[i];
	}
	return temp;
}

struct node *BuildTree(int In[],int Lev[],int si,int ei,int len)
{
	if(si > ei)
		return NULL;

	struct node *root = newNode(Lev[0]);

	if(si==ei)
		return root;
	else
	{
		int pivot = searchIndex(In,si,ei,root->data);		
		// In Level Order, not necessarily, lev[si] can be root!
		// This is because, the traversal order is not consecutive
		// compared to Pre or Post order traversal
		// Hence, we extract the keys for left and right subtree and 
		// store them in arrays!

		int *left = extractKeys(In,Lev,len,pivot);
		
		int *right = extractKeys(In+pivot+1,Lev,len,len-1-pivot);
											

		root->left = BuildTree(In,left,si,pivot-1,len);
		root->right = BuildTree(In,right,pivot+1,ei,len);

		delete []left;
		delete []right;
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

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int In[] = {4, 8, 10, 12, 14, 20, 22};
	int Lev[] = {20, 8, 22, 4, 12, 10, 14};
	int n = sizeof(In)/sizeof(In[0]);

	struct node *tree = NULL;

	tree = BuildTree(In,Lev,0,n-1,n);
	cout<<"\nThe inorder Array is : "<<endl;
	printArray(In,n);
	cout<<"\nThe inorder Tree Traversal is : "<<endl;
	Inorder(tree);

	cin.get();
	cin.get();
	return 0;

}