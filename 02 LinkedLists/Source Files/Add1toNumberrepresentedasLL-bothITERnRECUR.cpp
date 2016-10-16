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

void addNumUtil(struct node *head,int n,int &carry)
{
	if(head==NULL)
		return;

	struct node *cur = head;
	addNumUtil(head->next,n,carry);

	int temp = 0;
	if(cur->next==NULL)
		temp = head->data + n;
	else
		temp = head->data + carry;

	head->data = temp%10;
	if(temp/10)
		carry = temp/10;
	else
		carry = 0;	

}

void addNumber(struct node **refHead,int n)
{
	int carry = 0;
	addNumUtil(*refHead,n,carry);

	if(carry)
		createLL(refHead,carry);
}

int main()
{
	int arr[] = {9,9,9,9,9,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL,arr[i]);

	printLL(LL);
	addNumber(&LL,9);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}