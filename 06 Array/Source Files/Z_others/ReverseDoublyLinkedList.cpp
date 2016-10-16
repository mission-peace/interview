#include<iostream>
using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *newNode(int a)
{
	struct node *temp = new struct node();

	temp->prev = NULL;
	temp->data = a;
	temp->next = NULL;

	return temp;
}

void Push(struct node **refHead,int a)
{
	struct node *temp = newNode(a);

	if(*refHead!=NULL)
	{
		temp->next = *refHead;
		(*refHead)->prev = temp;
	}

	*refHead = temp;
}


void printDLL(struct node *head)
{
	cout<<"\nTraversal using \"next\" pointer: ";
	while(head->next!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<head->data<<"\n";

	cout<<"\nTraversal using \"prev\" pointer: ";
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->prev;
	}
	cout<<endl;
}

void reverseDLL_ITE(struct node **refHead)
{
	struct node *temp = NULL;
	struct node *head = *refHead;

	while(head!=NULL)
	{
		temp = head->next ;
		head->next = head->prev;
		head->prev = temp;

		temp = head;
		head = head->prev;
	}
	*refHead = temp;

}

void _reverseDLL_REC(struct node *head,struct node **refHead)
{
	if(head==NULL)
		return;

	struct node *temp = head->next;
	head->next = head->prev;
	head->prev = temp;

	if(head->prev==NULL)
		*refHead = head;
	else
		_reverseDLL_REC(head->prev,refHead);
}

void reverseDLL_REC(struct node **refHead)
{
	_reverseDLL_REC(*refHead,&(*refHead));
}


int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *DLL = NULL;

	for(int i=n-1 ; i>=0 ; i--)
		Push(&DLL,arr[i]);

	printDLL(DLL);

	cout<<"\n    ++++ Reversal of DLL using ITERATION ++++"<<endl;
	reverseDLL_ITE(&DLL);
	printDLL(DLL);

	cout<<"\n    ++++ Reversal of DLL using RECURSION ++++"<<endl;
	reverseDLL_REC(&DLL);
	printDLL(DLL);

	cin.get();
	return 0;
}