#include<iostream>
using namespace std;

struct node
{
	char data;
	struct node *next;
};

struct node *newNode(char a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void createLL(struct node **refHead,char x)
{
	struct node *temp = newNode(x);
	if(*refHead!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

int compareLL(struct node *LL1,struct node *LL2)
{
	while(LL1!=NULL && LL2!=NULL && LL1->data==LL2->data)
	{
		LL1 = LL1->next;
		LL2 = LL2->next;
	}

	if(LL1!=NULL)
	{
		if(LL2!=NULL)
			return LL1->data-LL2->data < 0 ? -1 : 1;
		else
			return -1;
	}
	else
	{
		if(LL2==NULL)
			return 0;
		else
			return 1;
	}
}

int main()
{
	char arr1[] = {'g','e','e','k','s','b'};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);

	char arr2[] = {'g','e','e','k','s','a'};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

	struct node *LL1 = NULL;
	for(int i=n1-1 ; i>=0 ; i--)
		createLL(&LL1,arr1[i]);
	struct node *LL2 = NULL;
	for(int i=n2-1 ; i>=0 ; i--)
		createLL(&LL2,arr2[i]);

	cout<<"The compareLL() result is : "<<compareLL(LL1,LL2);


	cin.get();
	cin.get();
	return 0;
}