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

void DeleteNodeshavingHighRight(struct node *head)
{
	if(head==NULL || head->next==NULL)
		return;

	struct node *cur = head;
	struct node *rest = cur->next;
	while(rest!=NULL)
	{
		if(cur->data < rest->data)
		{
			if(rest->next!=NULL)
				cur->next = rest->next;
			else
				cur->next = NULL;

			rest->next = NULL;
			delete rest;

			rest = cur->next;
		}
		else
		{
			cur = cur->next;
			rest = cur->next;
		}
	}

}

void main()
{
	int num[] = {5,5,5,65,4,35,3,45,2,65,2,87,1};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i-- )
		Push(&LL,num[i]);
	printLL(LL);

	DeleteNodeshavingHighRight(LL);
	printLL(LL);

	cin.get();
}