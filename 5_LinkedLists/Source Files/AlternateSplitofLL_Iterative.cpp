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

struct node *AlternateLLSplit(struct node *head1,struct node **head2)
{
	if(head1==NULL)
		return NULL;
	if(head1->next==NULL)
		return head1;

	struct node *delnode=head1;
	while(head1!=NULL && delnode!=NULL)
	{
		delnode = head1->next;
		if(delnode!=NULL)
			head1->next = delnode->next;
		else
			break;

		Push(head2,delnode->data);
		head2 = &((*head2)->next);
		
		delete delnode;
		head1 = head1->next;
	}

}

void main()
{
	int num[]={1,2,3,4,5,6,7,8,9,10};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	struct node *LL2 = NULL;
	struct node **lastref = &LL2;

	printLL(LL1);
	AlternateLLSplit(LL1,lastref);
	cout<<"\n The two separate LLs are :\n";
	printLL(LL1);
	printLL(LL2);

	cin.get();
}