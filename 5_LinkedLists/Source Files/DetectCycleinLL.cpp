#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void printLL(struct node *head)
{
	cout<<endl;
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node *getAddress(struct node *head,int a)
{

	while(head != NULL)
	{
		if(head->data == a)
			return head;
		head = head->next;
	}
}

struct node *CreateNode(int num)
{
	struct node *temp = new struct node();
	temp->data = num;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **head, int a)
{
	struct node *temp = CreateNode(a);
	
	if(*head != NULL)
	{
		temp->next = *head;
		*head = temp;
	}
	else
		*head = temp;

	return *head;
}

int DetectLoopinLL(struct node *head)
{
	struct node *slow = head;
	struct node *fast = head;

	while(slow!=NULL && fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast)
			return 1;
	}
	return 0;
}


void main()
{
	int num[]={1,2,3,4,5,6,7,8,9};

	struct node *LL=NULL;
	for(int i=sizeof(num)/sizeof(num[0])-1; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);

	for(int i=0 ; i<=sizeof(num)/sizeof(num[0])-1 ; i++)
	{
		(getAddress(LL,9))->next = getAddress(LL,num[i]);
		DetectLoopinLL(LL) ? cout<<"\nLoop is there in LL!\n":cout<<"\nNo Loop in the LL\n";
	}

	//printLL(LL);
	cin.get();
}