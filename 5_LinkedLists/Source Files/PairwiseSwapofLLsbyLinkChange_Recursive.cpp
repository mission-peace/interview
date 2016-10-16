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

struct node *Push(struct node **refHead, int num)
{
	struct node *temp = CreateNode(num);

	if(*refHead!=NULL)
		temp->next = *refHead;

	*refHead = temp;
	return *refHead;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		 cout<<"\n The LL is empty!\n";
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

void PairwiseSwapChangeLinks(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->next==NULL)
		return;

	struct node *node1 = *refHead;
	struct node *node2 = node1->next;
	struct node *rest = NULL;

	if(node2!=NULL)
	{
		rest = node2->next;
		node2->next = node1;
		PairwiseSwapChangeLinks(&rest);
		node1->next = rest;
		*refHead = node2;
	}
	else
		*refHead = node1;

}


void main()
{
	int num1[] = {1,2,3,4,5,6,7,8,9};

	struct node *LL1=NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	printLL(LL1);
	PairwiseSwapChangeLinks(&LL1);
	printLL(LL1);

	cin.get();

}