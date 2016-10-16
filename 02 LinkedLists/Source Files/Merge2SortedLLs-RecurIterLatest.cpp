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
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

struct node *mergeSortedLLs(struct node *LL1,struct node *LL2)
{
	struct node *head = NULL;
	struct node **refHead = NULL;
	*refHead = head;
	struct node *tail = NULL;
	struct node *temp = NULL;

	while(LL1!=NULL && LL2!=NULL)
	{
		if(LL1->data < LL2->data)
		{
			if(head)
			{
				temp = LL1->next;
				LL1->next = NULL;
				LL1 = temp;
				tail->next = LL1;
			}
			else
			{
				head = LL1;
				tail = LL1;
				LL1 = LL1->next;
			}
		}
		else
		{
			if(head)
			{
				temp = LL2->next;
				LL2->next = NULL;
				LL2 = temp;
				tail->next = LL2;
			}
			else
			{
				head = LL2;
				tail = LL2;
				LL2 = LL2->next;
			}
		}
	}

	if(LL1==NULL)
		tail->next = LL2;
	if(LL2==NULL)
		tail->next = LL1;
	return head;


}

struct node *mergeSortedLLs_Iter(struct node *LL1,struct node *LL2)
{
	struct node *LL = NULL;
	struct node **refHead = &LL;

	while(1)
	{
		if(LL1==NULL)
		{
			*refHead = LL2;
			break;
		}
		if(LL2==NULL)
		{
			*refHead = LL1;
			break;
		}

		if(LL1->data < LL2->data)
		{
			struct node *temp = LL1;
			LL1 = LL1->next;
			temp->next = *refHead;
			*refHead = temp;
			//refHead = &(*refHead)->next;

		}
		else
		{
			struct node *temp = LL2;
			LL2 = LL2->next;
			temp->next = *refHead;
			*refHead = temp;
			//refHead = &(*refHead)->next;
		}

	}
	return LL;


}

struct node *mergeSortedLLs_Recur(struct node *LL1,struct node *LL2)
{
	struct node *LL3 = NULL;
	if(LL1==NULL)
		return LL2;
	if(LL2==NULL)
		return LL1;

	if(LL1->data < LL2->data)
	{
		LL3 = LL1;
		LL3->next = mergeSortedLLs_Recur(LL1->next,LL2);
	}
	else
	{
		LL3 = LL2;
		LL3->next = mergeSortedLLs_Recur(LL1,LL2->next);
	}
	return LL3;

}

int main()
{
	int arr1[] = {1,3,5,7,9,11,13};
	int n = sizeof(arr1)/sizeof(arr1[0]);

	struct node *LL1 = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL1,arr1[i]);

	int arr2[] = {2,4,6,8};
	n = sizeof(arr2)/sizeof(arr2[0]);

	struct node *LL2 = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL2,arr2[i]);

	printLL(LL1);
	printLL(LL2);

	struct node *LL = NULL;
	//LL = mergeSortedLLs(LL1,LL2);
	//printLL(LL);
	//LL = mergeSortedLLs_Iter(LL1,LL2);
	//printLL(LL);
	LL = mergeSortedLLs_Recur(LL1,LL2);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}