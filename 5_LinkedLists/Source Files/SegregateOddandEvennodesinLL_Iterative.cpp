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

void SwapData(int *a,int *b)
{
	if(a==NULL||b==NULL)
		return;
	int temp = *a;
	*a = *b;
	*b = temp;
}


void SegregateOddnEven(struct node *head)
{
	if(head==NULL || head->next==NULL)
		return;

	struct node *even = head;
	head=head->next;

	while(head!=NULL)
	{
		if(head->data%2!=0 && even->data%2==0)	// Why we check for (even->data)%2==0 ? Because when the list of full of odd/even numbers, we need not do any swap
		{
			SwapData(&even->data,&head->data);
			even = even->next;

			if(even->next && even->next->data%2==0)
			{
				struct node *evenstart = even;
				while(head->next && even->data!=head->next->data)	// Why it is even->next->data ? because we need to swap INCLUSIVE of head
																	// Similar is the case for MaximumSumPath, we need to add the COMMON NODE also to the MaxSumPath LL
				{
					SwapData(&even->data,&head->data);
					even=even->next;
				}
				even = evenstart;	// Reset the start of beginning of Even pointer which is 16 instead of 28
			}
		}
		head = head->next;
	}

}


void main()
{
	struct node *LL = NULL;

	int num[] = {16,15,23,28,24,13,19,25,18,29,20}; // 
	for(int i=(sizeof(num)/sizeof(num[0])-1) ; i>=0 ; i--)
		Push(&LL,num[i]);

	printLL(LL);
	SegregateOddnEven(LL);
	printLL(LL);

	cin.get();
}