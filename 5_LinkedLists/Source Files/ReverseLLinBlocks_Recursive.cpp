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

struct node *BlockReversal(struct node **refHead,int size)
{
	if(*refHead==NULL)
		return NULL;

	int count = 1;
	struct node *prev = NULL;
	struct node *cur = *refHead;
	struct node *rest = NULL;

	while(count++ <=size && cur!=NULL)
	{
		rest = cur->next;
		cur->next = prev;
		prev = cur;
		cur = rest;
	}
	
	if(rest!=NULL)
	{
		BlockReversal(&rest,size);
		(*refHead)->next = rest;
	}

	*refHead = prev;
}

void main()
{
	int num[] = {1,2,3,4,5,6,7,8,9,10};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i-- )
		Push(&LL,num[i]);
	printLL(LL);

	BlockReversal(&LL,3);
	printLL(LL);

	cin.get();
}