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

void BlockReverse(struct node **refHead,int size)
{
	if(*refHead==NULL)
		return ;

	int count = 0;
	struct node *prev = NULL;
	struct node *cur = *refHead;
	struct node *rest = NULL;

	while(count++ < size && cur!=NULL)
	{
		rest = cur->next;
		cur->next = prev;
		prev = cur;
		cur = rest;
	}		
	
	if(rest!=NULL)
	{
		BlockReverse(&rest,size);
		(*refHead)->next = rest;
	}

	*refHead = prev;

}


void main()
{
	int num[]={1,2,3,4,5,6,7,8,9,10};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	BlockReverse(&LL,5);
	printLL(LL);
	cin.get();
}