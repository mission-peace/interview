#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void createLL(struct node **refHead,int a)
{
	struct node *temp = newNode(a);

	if((*refHead)!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

void printLL(struct node *head)
{
	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void SegregateOddnEven(struct node **refHead)
{
	struct node *cur = *refHead;
	if(cur==NULL)
		return;

	struct node *odd = NULL;
	struct node *even = NULL;
	struct node *lodd = NULL;
	struct node *leven = NULL;

	while(cur!=NULL)
	{
		if(cur->data%2)
		{
			if(odd)
			{
				lodd->next = cur;
				lodd = lodd->next;
			}
			else
			{
				odd = cur;
				lodd = cur;
			}
			cur = cur->next;
			lodd->next = NULL;
		}
		else
		{
			if(even)
			{
				leven->next = cur;
				leven = leven->next;
			}
			else
			{
				even = cur;
				leven = cur;
			}
			cur = cur->next;
			leven->next = NULL;
		}
	}

	leven->next = odd;
	*refHead = even;
	
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;

	struct node *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL,arr[i]);

	printLL(LL);
	SegregateOddnEven(&LL);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}