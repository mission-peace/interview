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
int sizeofLL(struct node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1 + sizeofLL(head->next);
}

struct node *getAddress(struct node *head, int searchnum)
{
	if(head == NULL)
		return NULL;

	while(head!=NULL)
	{
		if(head->data == searchnum)
			return head;

		head=head->next;
	}
	cout<<"\nThe number you mentioned is not present in LL!\n";
}

struct node *LLIntersection(struct node *head1, struct node *head2)
{
	struct node *res = NULL;
	struct node **lastptr = &res;

	if(head1==NULL || head2==NULL)
		return res;

	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data==head2->data)
		{
			Push(lastptr,head1->data);
			lastptr = &((*lastptr)->next);
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (head1->data > head2->data)
			head2 = head2->next;
		else if (head1->data < head2->data)
			head1 = head1->next;
	}
	cout<<"\nIntersection result : ";
	return res;	
}



void main()
{
	int num1[]={1,5,7,7,8,10,13,16,18,18,18,19,20,23,24,27};
	int num2[]={2,7,7,16,18,18,18,20,27};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	printLL(LL2);

	struct node *intersection = LLIntersection(LL1,LL2);
	(intersection) ? printLL(intersection) : cout<<"\n\tNo Intersection exists btwn LL1 and LL2\n" ;

	cin.get();
}