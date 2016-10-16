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
	
	if(*head == NULL)
		*head = temp;
	else
	{
		temp->next = *head;
		*head = temp;
	}

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

struct node *intersectLL(struct node *head1, struct node *head2)
{
	if(head1==NULL || head2==NULL)
		return NULL;

	if(head1->data < head2->data)
		return intersectLL(head1->next,head2);
	if(head1->data > head2->data)
		return intersectLL(head1,head2->next);

	struct node *head = new struct node();
	head->data = head1->data;
	head->next = intersectLL(head1->next,head2->next);

	return head;
}



void main()
{
	int num1[]={2,7,7,16,18,20,20,20,27,29};
	int num2[]={1,3,5,6,7,7,7,20,20,20};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	struct node *LL2 = NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	printLL(LL2);

	struct node *intersection = intersectLL(LL1,LL2);
	cout<<"\nIntersection result : ";
	(intersection) ? printLL(intersection) : cout<<"\n\tNo Intersection exists btwn LL1 and LL2\n" ;

	cin.get();
}