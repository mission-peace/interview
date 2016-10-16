/*
Algorithm :

1. Do a postorder traversal till a node before leaf
2. Now check if imbalance = root->left + root->right - root >0 or <10 if ==0, just return
3. If >0 , then just do root = root + imbalance
4. If <0, then try to increment the node by adding the imbalance
5. Have a separate funtion to increment the imbalance starting at the left from the node!
6. if root->left , then root->left + = imbalance and recur with diff Increment(root->left,imbalance) 
7. if root->right, then root->right += imbalance and recur
*/

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

void printTree_IN(struct node *root)
{
	if(root!=NULL)
	{
		printTree_IN(root->left);
		cout<<root->data<<" ";
		printTree_IN(root->right);
	}
		
}

void incrementNodes(struct node *root,int diff)
{
    if(root->left!=NULL)
    {
        root->left->data += diff;
        incrementNodes(root->left,diff);
    }
    else if(root->right!=NULL)
    {
        root->right->data += diff;
        incrementNodes(root->right,diff);
    }
        
}

void ConvertTreetoSumTree(struct node *root)
{
    if(root==NULL || root->left==NULL && root->right==NULL)
        return;
    else
    {
        ConvertTreetoSumTree(root->left);
        ConvertTreetoSumTree(root->right);
        
        int lsum = 0;
        if(root->left)
            lsum = root->left->data;
        int rsum = 0;
        if(root->right)
            rsum = root->right->data;
            
        int diff = lsum+rsum - root->data;
        
        if(diff > 0)
            root->data += diff;
        else if(diff<0)
            incrementNodes(root,-diff);
        else
            return;
            
    }
}

int main()
{
	int arr[] = {10,5,1,7,20,30,40};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl;
    ConvertTreetoSumTree(Tree);
	printTree_IN(Tree);
	cout<<endl;    
	cout<<endl;

	cin.get();
	return 0;
}