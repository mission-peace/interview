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

struct node *AlternateBlockReversal(struct node **refHead,int size,bool reversal = true)
{
	if(*refHead==NULL)
		return NULL;

	int count = 1;
	struct node *cur = *refHead;

	if(reversal)
	{
		reversal = false;
		struct node *prev = NULL;		
		struct node *rest = NULL;

		while(count++ <= size && cur!=NULL)
		{
			rest = cur->next;
			cur->next = prev;
			prev = cur;
			cur = rest;
		}

		if(rest!=NULL)
		{
			AlternateBlockReversal(&rest,size,reversal);		
			(*refHead)->next = rest;
		}

		*refHead = prev;
	}
	else
	{
		reversal = true;

		while(count++ <= size-1 && cur!=NULL)
			cur = cur->next;

		if(cur!=NULL && cur->next!=NULL)
			AlternateBlockReversal(&cur->next,size,reversal);
		else
			return NULL;
	}

	return NULL;

}

void main()
{
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i-- )
		Push(&LL,num[i]);
	printLL(LL);

	AlternateBlockReversal(&LL,3,true);
	printLL(LL);

	cin.get();
}