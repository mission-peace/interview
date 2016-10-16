#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int x)
{
	struct node *temp = new struct node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **head,int num)
{
	struct node *temp = CreateNode(num);
	
	if(! (*head)==NULL)
	{
		temp->next = *head;
		*head = temp;
	}
	else
		*head = temp;

	return *head;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\n EMPTY LL!\n";
		return;
	}
	cout<<endl;
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

struct node *PairwiseSwap(struct node *temp)
{
	if(temp==NULL || temp->next==NULL)
		return NULL;

	while(temp!=NULL && temp->next!=NULL)
	{
		Swap(&temp->data,&temp->next->data);
		temp=temp->next->next;
	}
}

void main()
{
	int num[]={1,2,3,4,5};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	printLL(LL1);
	PairwiseSwap(LL1);
	cout<<"\nAfter Pair wise Swapping, the LL is :\n  ";
	printLL(LL1);

	cin.get();
}