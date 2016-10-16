#include<iostream>
#define IPSET 11
#define getIndex(a) a=='.' ? 10 : (int)(a-'0')
using namespace std;

struct trienode
{
	bool isLeaf;
	char *url;
	struct trienode *child[IPSET];
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
	temp->url = "";
	for(int i=0 ; i<=IPSET-1 ; i++)
		temp->child[i] = NULL;

	return temp;
}

void InitializeTrie(struct trie *root)
{
	root->count = 0;
	root->PointertoRootofTrie = newNode();
}

void Insert(struct trie *root, char ip[],char *url)
{
	int len = strlen(ip);
	if(len==0)
		return;

	struct trienode *temp = root->PointertoRootofTrie;

	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getIndex(ip[i]);

		if(temp->child[index]==NULL)
			temp->child[index] = newNode();

		temp = temp->child[index];
	}

	temp->isLeaf = 1;
	temp->url = new char[strlen(url)+1];
	strcpy(temp->url,url);

	root->count++;
}

void Search(struct trie *root,char ip[])
{
	int len = strlen(ip);
	if(len==0)
		return;

	struct trienode *temp = root->PointertoRootofTrie;
	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getIndex(ip[i]);

		if(temp->child[index]==NULL)
			break;
		else
			temp = temp->child[index];
	}

	if(temp && temp->isLeaf && temp->url)
		cout<<"\n For IP '"<<ip<<"' , the URL from Reverse DNS Cache is '"<<temp->url<<"'\n";
	else
		cout<<"\n Sorry, there is no URL present in Reverser DNS cache for IP, "<<ip<<endl;

}

int main()
{
	char IP[][16] = {"107.108.11.123", "107.109.123.255", "74.125.200.106"};
	char URL[][50] = {"www.samsung.com", "www.samsung.net","www.google.in"};

	int ipcount = sizeof(IP)/sizeof(IP[0]);

	struct trie TRIE;
	InitializeTrie(&TRIE);

	for(int i=0 ; i<=ipcount-1 ; i++)
		Insert(&TRIE,IP[i],URL[i]);

	char testips[][16] = {"107.108.11.123", "107.109.123.255", "74.125.200.106","124.567.32.57","107.109.123.254",""};
	int testkeyscount = sizeof(testips)/sizeof(testips[0]);
	for(int i=0 ; i<=testkeyscount-1 ; i++)
		Search(&TRIE,testips[i]);
	 
	cin.get();
	cin.get();
	return 0;
}