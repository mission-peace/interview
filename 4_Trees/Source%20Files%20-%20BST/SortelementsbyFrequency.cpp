#include<iostream>
using namespace std;

struct node
{
	struct node *left;
	int data;
	unsigned int freq;
	struct node *right;
};

struct bucket
{
	int data;
	unsigned int freq;
};

struct node *createNode(int a)
{
	struct node *temp = new struct node();
	temp->left = NULL;
	temp->data = a;
	temp->freq = 1;
	temp->right = NULL;
	return temp;
}

void createTree(struct node **root,int x)
{
	if(*(root)!=NULL)
	{
		if((*root)->data==x)
			((*root)->freq)++;
		if(x < (*root)->data)
			createTree(&((*root)->left),x);
		else if(x > (*root)->data)
			createTree(&((*root)->right),x);
	}
	else
		*root = createNode(x);
}

int compare(const void *a,const void *b)
{
	return (*(const struct bucket *)b).freq-(*(const struct bucket *)a).freq;
}

void Inorder(struct node *BST,int *index,struct bucket count[])
{
	if(BST==NULL)
		return;

	Inorder(BST->left,index,count);
	count[*index].data = BST->data;
	count[*index].freq = BST->freq;
	(*index)++;
	Inorder(BST->right,index,count);
}

void printStruct(struct bucket count[],int index)
{
	cout<<endl;
	for(int i=0 ; i<=index-1 ; i++)
	{
		int freqcount = count[i].freq;
		while(freqcount>0)
		{
			cout<<count[i].data<<" ";
			freqcount--;
		}
	}
	cout<<endl;
}


void sortbyFrequency(int arr[],int n)
{
	struct node *BST = NULL;
	for(int i=0 ; i<=n-1 ; i++)
		createTree(&BST,arr[i]);

	struct bucket *count = new struct bucket[n];
	int index = 0;
	Inorder(BST,&index,count);

	qsort(count,index,sizeof(count[0]),compare);
	printStruct(count,index);
}

int main()
{
	int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
	int n = sizeof(arr)/sizeof(arr[0]);

	sortbyFrequency(arr,n);

	cin.get();
	cin.get();
	return 0;
}