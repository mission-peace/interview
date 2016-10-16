#include<iostream>
#define URLSET 26+1
#define getIndex(a) a=='.' ? 26 : a-'a'
using namespace std;

struct trienode
{
	bool isLeaf;
	char *ip;
	struct trienode *child[URLSET];
};
struct trie
{
	int count;
	struct trienode *PointertoRootofTrie;
};

struct trienode *newNode()
{
	struct trienode *temp = new struct trienode();
	temp->isLeaf = false;
	temp->ip = NULL;
	for(int i=0 ; i<=URLSET-1 ; i++)
		temp->child[i] = NULL;
	return temp;
}

void InitializeTrie(struct trie *root)
{
	root->count = 0;
	root->PointertoRootofTrie = newNode();
}

void Insert(struct trie *root,char *url,char *ip)
{
	struct trienode *temp = root->PointertoRootofTrie;
	
	int len = strlen(url);
	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getIndex(url[i]);
		if(temp->child[index]==NULL)
			temp->child[index] = newNode();
		temp = temp->child[index];
	}
	temp->isLeaf = true;
	temp->ip = new char[strlen(ip)];
	temp->ip = ip;

	root->count++;
}

void getForwardDNSLookup(struct trie *root,char *url)
{
	struct trienode *temp = root->PointertoRootofTrie;
	int len = strlen(url);
	for(int i=0 ; i<=len-1 ; i++)
	{
		int index = getIndex(url[i]);
		if(temp->child[index]!=NULL)
			temp = temp->child[index];
		else
			break;
	}
	if(temp->isLeaf && temp->ip)
		cout<<"\n From the Forward DNS Lookup Table, URL '"<<url<<"' --> '"<<temp->ip<<"'\n";
	else
		cout<<"\n No entry in the Forward DNS Lookup table for URL '"<<url<<"' !\n";
}

int main()
{
	char IP[][16] = {"107.108.11.123", "107.109.123.255", "74.125.200.106","76.125.200.106"};
	char URL[][50] = {"www.samsung.com", "www.samsung.net","www.google.in","www.google.co.in"};

	// Forward DNS Lookup = Type in the Website URL -> then get the IP address
	// Thus, the Trie must maintain URLs in the Trie DS and must have IPs along with leaf flag

	int urlscount = sizeof(URL)/sizeof(URL[0]);
	struct trie TRIE;
	InitializeTrie(&TRIE);

	for(int i=0 ; i<=urlscount-1 ; i++)
		Insert(&TRIE,URL[i],IP[i]);

	char testkeys[][50] = {"www.samsung.com","www.samsung.co","www.samsung.net","www.amazon.com","www.google.","www.google.co.in"};
	int testkeyscount = sizeof(testkeys)/sizeof(testkeys[0]);

	for(int i=0 ; i<=testkeyscount-1 ; i++)
		getForwardDNSLookup(&TRIE,testkeys[i]);

	cin.get();
	cin.get();
	return 0;
}