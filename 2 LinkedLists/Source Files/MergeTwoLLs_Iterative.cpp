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

struct node *Push(struct node **head,int num)
{
	struct node *temp = CreateNode(num);
	
	if(temp!=NULL)
		temp->next = *head;

	*head = temp;
	return *head;
}

void printLL(struct node *temp)
{
	if(temp==NULL)
	{
		cout<<"\nThe LL is empty!\n";
		return;
	}

	cout<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

struct node *SortedLLsMerge(struct node *head1,struct node *head2)
{
	struct node *LL3 = NULL;
	struct node **headref = &LL3;

	if(head1==NULL)
	{
	LL3=head2;
	return LL3;
	}

	if(head2==NULL)
	{
	LL3=head1;
	return LL3;
	}

	struct node *endofLL = NULL;

	while(1)
	{

		if(head1==NULL && head2!= NULL)
		{
		endofLL = head2;
		break;
		}

		else if(head1!=NULL && head2==NULL)
		{
		endofLL = head1;
		break;
		}

		else if(head1==NULL && head2==NULL)
		break;

		if(head1->data <= head2->data)
		{
		Push(headref,head1->data);
		head1=head1->next;
		}

		else if(head1->data > head2->data)
		{
		Push(headref,head2->data);
		head2=head2->next;
		}

		headref = &((*headref)->next);
	}

	while(endofLL!=NULL)
	{
		Push(headref,endofLL->data);
		headref = &((*headref)->next);
		endofLL = endofLL->next;
	}

	return LL3;
}

void main()
{
	int num1[]={1,3,5,7};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	int num2[]={2,4,6,8,10};

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	printLL(LL2);
	printLL(SortedLLsMerge(LL1,LL2));


	cin.get();
}