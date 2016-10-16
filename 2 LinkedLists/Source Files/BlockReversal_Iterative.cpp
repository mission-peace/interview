#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **headref,int num)
{
	struct node *temp = CreateNode(num);

	if(*headref!=NULL)
		temp->next = *headref;

	*headref = temp;
	return temp;

}

void printLL(struct node *temp)
{
	if(temp==NULL)
	{
		cout<<"\n The LL is empty!\n";
		return;
	}

	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	cout<<endl;
}

struct node *BlockReverse(struct node **refHead,int size)
{
	if(*refHead==NULL)
		return NULL;

	struct node *subhead = *refHead;
	bool firstheadchange = true;
	int count = 1;
	struct node *prev = NULL;
	struct node *cur  = *refHead;
	struct node *rest = NULL;

	int top=0;


	while(cur!=NULL)
	{	
		subhead = cur;

		while(++count <= size && cur!=NULL)
		{
			rest = cur->next;
			cur->next = prev;
			prev= cur;
			cur =rest;
		}

		if(firstheadchange && cur!=NULL)
		{
			(*refHead)->next = rest;
			*refHead = cur;
			subhead = rest;
			firstheadchange = false;
		}
		else
		{
			if(cur!=NULL)
				cur->next = rest;
		}
		//subhead = rest
		count = 1;
		prev = NULL;
		rest = NULL;

	}
	
}


void main()
{
	int num[]={1,2,3,4,5,6,7,8,9,10};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	BlockReverse(&LL,4);
	printLL(LL);

	cin.get();
}