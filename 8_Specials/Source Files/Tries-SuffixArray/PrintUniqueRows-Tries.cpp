#include<iostream>
#define BINARY 2
using namespace std;

struct trienode 
{
	bool isLeaf;
	struct trienode *child[BINARY];
};

struct trie
{
	int count;
	struct trienode *PointertoRootofTrie;
};

struct trienode *newNode()
{
	struct trienode *temp = new struct trienode();

	temp->isLeaf = 0;
	for(int i=0 ; i<=BINARY-1 ; i++)
		temp->child[i] = NULL;

	return temp;
}

void InitializeTrie(struct trie *root)
{
	root->count = 0;
	root->PointertoRootofTrie = newNode();
}

void Insert(struct trie *root,int row[],int len,int rowindex)
{
	root->count++;
	struct trienode *temp = root->PointertoRootofTrie;

	for(int i=0 ; i<=len-1 ; i++)
	{
		if(temp->child[row[i]]==NULL)
			temp->child[row[i]] = newNode();

		temp = temp->child[row[i]];
	}

	if(temp->isLeaf)
	{
		cout<<endl<<"Row : "<<rowindex<<" is NOT unique in the matrix!\n";
		return;
	}
	else
	{
		cout<<endl;
		for(int i=0 ; i<=len-1; i++)
			cout<<row[i]<<" ";
		cout<<" Row : "<<rowindex<<" is unique in the matrix!\n";
	}
	temp->isLeaf = 1;
}

int main()
{
	int arr[][5] = {	{1,0,0,1,1},
						{1,1,0,1,0},
						{1,0,0,1,0},
						{1,0,0,1,1},
						{1,0,0,1,0}	};

	struct trie TRIE;
	InitializeTrie(&TRIE);

	int ROW = sizeof(arr)/sizeof(arr[0]);
	int COL = sizeof(arr[0])/sizeof(arr[0][0]);

	for(int i=0 ; i<=ROW-1 ; i++ )
		Insert(&TRIE,arr[i],COL,i);

	cin.get();
	cin.get();
	return 0;

}