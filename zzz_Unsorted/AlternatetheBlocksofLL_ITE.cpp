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
	struct node *prev = NULL;
	struct node *cur = *refHead;
	struct node *later = NULL;
	int count = 0;

	struct node *head = NULL;
	bool headchange = true;

	while(cur!=NULL)
	{
		while(cur!=NULL && count < blocksize)
		{
			later = cur->next;
			cur->next = prev;
			prev = cur;
			cur = later;

			count++;
		}
		count = 0;
		if(headchange)
		{
			headchange = false;
			head = prev;
		}

		(*refHead)->next = cur;

		while(cur!=NULL && count <blocksize)
		{
			//later = cur->next;
			prev = cur;
			cur = cur->next;
			//cur = later;
			count++;
		}
		*refHead = prev;
		prev = cur;
		count = 0;
	}
	return head;
}

void AlternateBlockReversal_ITE(struct node **refHead,int blocksize)
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

	AlternateBlockReversal_ITE(&LL,3);
	printLL(LL);

	cin.get();
}