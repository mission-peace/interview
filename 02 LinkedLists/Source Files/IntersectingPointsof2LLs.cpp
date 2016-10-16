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
	if(head ==NULL)
		return NULL;

	while(head!=NULL)
	{
		if(head->data == searchnum)
			return head;

		head=head->next;
	}
	cout<<"\nThe number you mentioned is not present in LL!\n";
}

struct node *IntersectingNode(struct node *head1,struct node *head2)
{

	int lendiff = abs(sizeofLL(head1)-sizeofLL(head2));

	struct node *temp1 = head1;
	if(sizeofLL(temp1) >= sizeofLL(head2))
		temp1 = head1;
	else
	{
		temp1 = head2;
		head2 = head1;
	}

	while(lendiff--)
		temp1 = temp1->next;

	while(temp1!=NULL && head2!=NULL)
	{
		if(temp1 == head2)
			return temp1;

		temp1 = temp1->next;
		head2 = head2->next;
	}
	return NULL;
}

void main()
{
	int num1[]={1,2,3,4,5,15,16,17,18};
	int num2[]={33,32,35};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	printLL(LL2);

	for(int i=1 ; i<=(sizeof(num1)/sizeof(num1[0])) ; i++)
	{
		(getAddress(LL2,num2[(sizeof(num2)/sizeof(num2[0]))-1]))->next = getAddress(LL1,num1[i]);

		cout<<"\nThe intersecting LLs are :\n";
		printLL(LL1);
		printLL(LL2);

		(IntersectingNode(LL1,LL2)!=NULL)	? cout<<"\n The intersecting point of LL1 and LL2 is : "<<(IntersectingNode(LL1,LL2))->data<<"\n"
											: cout<<"\n There are no Intersecting points!\n";
	
	}
	cin.get();
}