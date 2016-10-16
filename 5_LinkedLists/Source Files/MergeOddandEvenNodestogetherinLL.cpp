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
	if(*refHead!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

void printLL(struct node *head)
{
	cout<<endl;
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void mergeOddEven(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->next==NULL)	// To handle 0 node and 1 node LLs
		return;

	struct node *odd = *refHead;
	struct node *even = odd->next;
	struct node *evenhead = even;
	struct node *prevodd = NULL;
	while(1)
	{
		prevodd = odd;		// Track the previous Odd node, see other comments for reason

		if(even!=NULL)
		{
			odd->next = even->next;
			odd = odd->next;
		}
		else
			break;

		if(odd!=NULL)
		{
			even->next = odd->next;
			even = even->next;
		}
		else
			break;
	}

	if(odd)				
		odd->next = evenhead;
	else				// If odd is NULL, then assign the evenhead to previous odd node we have been tracking
		prevodd->next = evenhead;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL,arr[i]);

	printLL(LL);
	mergeOddEven(&LL);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}