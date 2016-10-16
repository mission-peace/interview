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

	if(cur->data < cur->next->data)
	{
		struct node *temp = cur->next;

		if(temp->next!=NULL)
			cur->next = temp->next;
		else
			cur->next = NULL;

		temp->next = NULL;
		delete temp;

		DeleteNodeshavingHighRight(cur);
	}
	else
		DeleteNodeshavingHighRight(cur->next);

}

void main()
{
	int num[] = {9,45,8,8,65,8,7,45,7,7,6,92,6,6};

	struct node *LL=NULL;
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i-- )
		Push(&LL,num[i]);
	printLL(LL);

	DeleteNodeshavingHighRight(LL);
	printLL(LL);

	cin.get();
}