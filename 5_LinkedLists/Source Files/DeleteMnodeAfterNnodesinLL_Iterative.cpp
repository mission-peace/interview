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

void DeleteMnodesafterNnodes(struct node *head,int sizeM,int sizeN)
{
	if(head==NULL)
		return;

	int count = 1;
	struct node *cur = head;
	struct node *delnode = cur;

	while(cur!=NULL)
	{
		while(count++ < sizeN && cur!=NULL)
			cur = cur->next;

		count = 1;
		while(count++ <= sizeM && cur!=NULL)
		{
			delnode = cur->next;
			if(delnode!=NULL)
			{
				cur->next = delnode->next;
				delnode->next = NULL;
				delete delnode;
			}
			else
				cur->next = NULL;
		}
		cur = cur->next;
		count = 1;
	}

}

void main()
{
	int num[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i-- )
		Push(&LL,num[i]);
	printLL(LL);

	DeleteMnodesafterNnodes(LL,2,3);
	printLL(LL);

	cin.get();
}