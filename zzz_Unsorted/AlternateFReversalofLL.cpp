#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int a)
{
	struct node *temp=new struct node();

	temp->data = a;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **refHead,int num)
{
	struct node *temp=CreateNode(num);

	if(*refHead!=NULL)
		temp->next = *refHead;

	*refHead = temp;
	return *refHead;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\n The LL is empty\n";
		return;
	}

	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

struct node *_AlternateBlockReversal(struct node **refHead,int blocksize,bool reverse = true)
{
	if(*refHead==NULL)
		return NULL;

	struct node *prev = NULL;
	struct node *cur = *refHead;
	struct node *later = NULL;
	int count = 0;

	while(cur!=NULL && count < blocksize)
	{
		later = cur->next;
		if(reverse)
			cur->next = prev;
		prev = cur;
		cur = later;
		count++;
	}

	if(reverse)
	{
		(*refHead)->next = _AlternateBlockReversal(&cur,blocksize,!reverse);
		return prev;
	}
	else
	{
		prev->next = _AlternateBlockReversal(&cur,blocksize,!reverse);
		return *refHead;
	}
}

void AlternateBlockReversal(struct node **refHead,int blocksize)
{
	*refHead = _AlternateBlockReversal(refHead,3,true);
}


void main()
{
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i-- )
		Push(&LL,num[i]);
	printLL(LL);

	AlternateBlockReversal(&LL,3);
	printLL(LL);

	cin.get();
}