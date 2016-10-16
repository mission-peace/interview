#include<iostream>
using namespace std;

struct node{
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
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void reverseLL(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->next==NULL)
		return;
	struct node *prev = NULL;
	struct node *cur = *refHead;
	struct node *next = NULL;

	while(cur!=NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*refHead = prev;
}

void reverseLL_RecurUtil(struct node *cur,struct node *prev,struct node **refHead)
{
	if(cur->next==NULL)
	{
		cur->next = prev;
		*refHead = cur;
		return;
	}

	struct node *next = cur->next;
	cur->next = prev;

	reverseLL_RecurUtil(next,cur,refHead);
}

void reverseLL_Recur(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->next==NULL)
		return;
	reverseLL_RecurUtil(*refHead,NULL,refHead);
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL,arr[i]);

	printLL(LL);
	reverseLL(&LL);
	printLL(LL);
	reverseLL_Recur(&LL);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}
