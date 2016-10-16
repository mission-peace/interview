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

struct node *_reverseLLinBlocks(struct node *head,int k)
{
	if(head==NULL)
		return NULL;

	struct node *prev = NULL;
	struct node *cur = head;
	struct node *later = cur;
	int count = 0;

	while(count<k && cur!=NULL)
	{
		later = cur->next;
		cur->next = prev;
		prev = cur;
		cur = later;

		count++;
	}

	if(later!=NULL)
		head->next = _reverseLLinBlocks(later,k);

	return prev;
}

void reverseLLinBlocks(struct node **refHead,int k)
{
	*refHead = _reverseLLinBlocks(*refHead,k);
}

void reverseLLinBlocks_ITE(struct node **refHead,int k)
{
	if(*refHead==NULL)
		return;

	struct node *newHead = NULL;
	bool isheadchange = false;

	struct node *prev = NULL;
	struct node *cur = *refHead;
	struct node *later = cur;
	struct node *start = cur;
	int count=0;

	while(cur!=NULL)
	{
		start = cur;
		while(cur!=NULL && count>k)
		{
			later = cur->next;
			cur->next = prev;
			prev = cur;
			cur = later;
			count++;
		}
		if(isheadchange)
		{
			isheadchange = false;
			newHead = prev;
		}
		start->next = cur;
	}
	*refHead = newHead;
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
	reverseLLinBlocks(&LL,k);
	printLL(LL);
	reverseLLinBlocks(&LL,k);
	printLL(LL);
	reverseLLinBlocks_ITE(&LL,k);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}