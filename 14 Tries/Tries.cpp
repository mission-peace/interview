#include<iostream>
#define ENGLISH 26
#define getTrieIndex(a) ((int)a-(int)'a')

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

struct trienode *createNode()
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
	root->PointertoRootofTrie = createNode();
}

void Insert(struct trie *root,char word[])
{
	int len = strlen(word);
	if(len==0)
		return;

	struct trienode *temp = root->PointertoRootofTrie;
	root->count++;

	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getTrieIndex(word[i]);
		if(temp->child[index]==NULL)
			temp->child[index] = createNode();

		temp = temp->child[index];
	}
	temp->isLeaf = 1;

}

bool Search(struct trie *root,char word[])
{
	struct trienode *temp = root->PointertoRootofTrie;

	int len = strlen(word);
	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getTrieIndex(word[i]);
		if(temp->child[index]==NULL)
			return false;

		temp = temp->child[index];
	}
	return (temp && temp->isLeaf);
}

int main()
{
	char *keys[] = {"let","the","bygones","be","bygones","before","fore"};

	struct trie TRIE;
	InitializeTrie(&TRIE);

	int noofwords = sizeof(keys)/sizeof(keys[0]);

	for(int i=0 ; i<=noofwords-1 ; i++)
		Insert(&TRIE,keys[i]);

	char res[2][30] = {" is not found in Trie..\n"," is present in Trie!\n"};
	char *testkeys[] = {"let","the","bygones","by","bygones","before","fore","f","bygoness","","bygo","bef",""};
	int nooftestkeys = sizeof(testkeys)/sizeof(testkeys[0]);

	for(int i=0 ; i<=nooftestkeys-1 ; i++)
		cout<<"The word '"<<testkeys[i]<<"' "<<res[Search(&TRIE,testkeys[i])];
	
	cin.get();
	cin.get();
	return 0;
}