#include<iostream>
#define ENGLISH 26
#define getIndex(c) (int)(c-'a')
#define getChar(i) (char)(i+'a')
using namespace std;

struct trienode
{
	bool isLeaf;
	struct trienode *child[ENGLISH];
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
	for(int i=0 ; i<=ENGLISH-1 ; i++)
		temp->child[i] = NULL;
	return temp;
}

void InitializeTrie(struct trie *root)
{
	root->count = 0;
	root->PointertoRootofTrie = newNode();
}

void Insert(struct trie *root,char key[],int *maxwordsize)
{
	int len = strlen(key);
	if(len==0)
		return;

	struct trienode *temp = root->PointertoRootofTrie;

	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getIndex(key[i]);

		if(temp->child[index]==NULL)
			temp->child[index] = newNode();

		temp = temp->child[index];
	}
	temp->isLeaf = 1;
	root->count++;

	*maxwordsize = max(*maxwordsize,len);
}

void findLongestPrefixWord(struct trie *root,char key[],int len)
{
	char longestprefix[50] = "";
	char tempword[50] = "";

	struct trienode *temp = root->PointertoRootofTrie;

	for(int i=0,len = strlen(key) ; i<=len-1 ; i++)
	{
		int index = getIndex(key[i]);

		if(temp->isLeaf)
			strcpy(longestprefix,tempword);
		
		if(temp->child[index]==NULL)
			break;
		else
			tempword[i] = getChar(index);

		temp = temp->child[index];
	}

	if(strlen(longestprefix))
		cout<<"\n For the key '"<<key<<"' , the longest prefix is = "<<longestprefix<<endl;
	else
		cout<<"\n For the key '"<<key<<"' , there is NO longest prefix in the Dictionary!"<<endl;

}

int main()
{
	char *keys[] = {"are", "area", "base", "cat", "cater", "children", "basement"};

	struct trie TRIE;
	InitializeTrie(&TRIE);

	int maxwordsize = 0;
	int keyscount = sizeof(keys)/sizeof(keys[0]);
	for(int i=0 ; i<=keyscount-1 ; i++)
		Insert(&TRIE,keys[i],&maxwordsize);

	char *testkeys[] = {"chare","caterers","child","basemexy","cater"};

	keyscount = sizeof(testkeys)/sizeof(testkeys[0]);

	for(int i=0; i<=keyscount-1 ; i++)
		findLongestPrefixWord(&TRIE,testkeys[i],maxwordsize);

	cin.get();
	cin.get();
	return 0;
}