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

void createTree(struct node **root,int a)
{
    if(*root==NULL)
        *root = newNode(a);
    else
    {
        if(a < (*root)->data)
            createTree(&(*root)->left,a);
        else
            createTree(&(*root)->right,a);
    }
}

void Inorder(struct node *tree)
{
    if(tree==NULL)
        return;
    Inorder(tree->left);
    cout<<tree->data<<" ";
    Inorder(tree->right);
}

void increment(struct node *temp,int diff)
{
	if(temp->left!=NULL)
	{
		temp->left->data = temp->left->data + diff;
		increment(temp->left,diff);
	}
	else if(temp->right!=NULL)
	{
		temp->right->data = temp->right->data + diff;
		increment(temp->right,diff);
	}
}

void ConverttoChildSum(struct node *root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;
	ConverttoChildSum(root->left);
	ConverttoChildSum(root->right);

	int leftdata=0;
	int rightdata=0;

	if(root->left)
		leftdata = root->left->data;
	if(root->right)
		rightdata = root->right->data;
	int diff = leftdata+rightdata-root->data;

	if(diff>0)
	{
		root->data += diff;
	}
	else if(diff < 0)
	{
		increment(root,-diff);
	}
}



int main()
{
   int arr[] = {10,5,1,7,20,30,40};
   int n=sizeof(arr)/sizeof(arr[0]);
   
   struct node *tree = NULL;
   for(int i=0 ; i<=n-1 ; i++)
        createTree(&tree,arr[i]);
   
    Inorder(tree);
    cout<<endl;
    ConverttoChildSum(tree);
	Inorder(tree);
   
   cin.get();
   cin.get();
   return 0;
}