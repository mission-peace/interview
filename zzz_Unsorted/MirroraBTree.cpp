#include<iostream>
#include<vector>
using namespace std;


struct lnode
{
	int data;
	struct lnode *next;
};

struct lnode *newlnode(int a)
{
	struct lnode *temp = new struct lnode();

	temp->data = a;
	temp->next = NULL;

	return temp;
}

void enQ(struct lnode **front,struct lnode **rear,int x)
{
	struct lnode *temp = newlnode(x);

	if(*rear!=NULL)
		(*rear)->next = temp;
	else
		*front = temp;
	*rear = temp;

}

void deQ(struct lnode **front)
{
	struct lnode *temp = *front;
	*front = temp->next;
	temp->next = NULL;
	delete(temp);
}

int frontofQ(struct lnode *front)
{
	if(front!=NULL)
		return front->data;
	else
		return -1;
}

void printQtilln(struct lnode *front,int n)
{
	if(front==NULL)
		return;
	else
	{
		while(front!=NULL)
		{
			cout<<front->data<<" ";
			front = front->next;
		}
	}
}

void printnemptyQ(struct lnode *front)
{
	if(front==NULL)
	{
		cout<<"Queue is empty.."<<endl;
		delete(front);
	}
	else
	{
		while(front!=NULL)
		{
			cout<<front->data<<" ";
			struct lnode *delnode = front;
			front = front->next;
			delnode->next = NULL;
			delete(delnode);
		}
	}

}

struct tnode
{
	struct tnode *left;
	int data;
	struct tnode *right;
};

struct tnode *newtNode(int a)
{
	struct tnode *temp = new struct tnode();

	temp->left = NULL;
	temp->data = a;
	temp->right = NULL;

	return temp;
}

void createtNode(struct tnode **root,int x)
{
	if(*root!=NULL)
	{
		if(x < (*root)->data)
			createtNode(&(*root)->left,x);
		else
			createtNode(&(*root)->right,x);
	}
	else
		*root = newtNode(x);
}

void printTree_IN(struct tnode *root)
{
	if(root!=NULL)
	{
		printTree_IN(root->left);
		cout<<root->data<<" ";
		printTree_IN(root->right);
	}
}


void mirrorTree(struct tnode *root)
{
	if(root==NULL)
		return;

	mirrorTree(root->left);
	mirrorTree(root->right);

	struct tnode *temp = root->left;
	root->left = root->right;
	root->right = temp;

}

int main()
{
	int arr[] = {10,5,1,7,40,37};
	int n=sizeof(arr)/sizeof(arr[0]);

	struct tnode *Tree=NULL;

	for(int i=0 ; i<=n-1 ; i++)
		createtNode(&Tree,arr[i]);

	printTree_IN(Tree);
	cout<<endl<<"The Mirror of the above tree is : \n";
	mirrorTree(Tree);
	printTree_IN(Tree);

	cin.get();
	return 0;
}