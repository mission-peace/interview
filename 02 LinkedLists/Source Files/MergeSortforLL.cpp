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

	if(*head!=NULL)
		temp->next = *head;

	*head = temp;
	return *head;
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

int sizeofLL(struct node *head)
{
	if(head==NULL)
		return 0;
	else
		return 1 + sizeofLL(head->next);
}

struct node *findLLMedian(struct node *head)
{
	struct node *slow = head;

	if(slow==NULL)
		return NULL;

	struct node *fast = slow;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if(sizeofLL(head)%2 == 1)
	{
		if(slow->next==NULL)
			return NULL;
		else
			return slow->next;
	}
	else
		return slow;
}

struct node *SortedLLsMerge(struct node *head1,struct node *head2)
{
	struct node *LL3 = NULL;
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	if(head1->data <= head2->data)
	{
		LL3 = head1;
		LL3->next = SortedLLsMerge(head1->next,head2);
	}
	if(head1->data > head2->data)
	{
		LL3 = head2;
		LL3->next = SortedLLsMerge(head1,head2->next);
	}

	return LL3;
}

void SplitLLintohalf(struct node **half1head,struct node **half2head,struct node *LL)
{
	*half1head = LL;
	*half2head = findLLMedian(LL);
	
	struct node *temp = *half1head;

	if(temp->next!=NULL)
	{
		while(temp->next != *half2head)
		{
			temp = temp->next;
		}
	}
	temp->next = NULL;

}


void MergeSortLL(struct node **refHead)
{
	struct node *head = *refHead;
	struct node *half1 = NULL;
	struct node *half2 = NULL;

	if(head ==NULL || head->next == NULL)
		return;

	SplitLLintohalf(&half1,&half2,head);
	MergeSortLL(&half1);
	MergeSortLL(&half2);
	*refHead = SortedLLsMerge(half1,half2);

}


void main()
{
	int num[] = {10,2,3,3,4,4,4,5};

	struct node *LL1 = NULL;
	for(int i=(sizeof(num)/sizeof(num[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num[i]);

	printLL(LL1);
	MergeSortLL(&LL1);
	printLL(LL1);

	cin.get();
	cin.get();
}