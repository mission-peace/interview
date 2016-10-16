#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int  a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void createLL(struct node **refHead,int x)
{
	struct node *temp = newNode(x);
	if(*refHead!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

void printLL(struct node *head)
{
	if(head==NULL)
		cout<<"LL is empty\n";
	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

struct node *MergeLLs(struct node *LL1,struct node *LL2)
{
	struct node *LL3 = NULL;
	if(LL1==NULL)
	{
		LL3 = LL2;
		return LL3;
	}
	if(LL2==NULL)
	{
		LL3 = LL1;
		return LL3;
	}
	if(LL1->data <= LL2->data)
	{
		LL3 = LL1;
		LL3->next = MergeLLs(LL1->next,LL2);
	}
	else
	{
		LL3 = LL2;
		LL3->next = MergeLLs(LL1,LL2->next);
	}
	return LL3;
}

void SplittoHalves(struct node **LL,struct node **LL1,struct node **LL2)
{
	if(*LL==NULL || (*LL)->next == NULL)
	{
		*LL1 = *LL;
		*LL2 = NULL;
	}
	struct node *slow = *LL;
	struct node *fast = (*LL)->next;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	*LL1 = *LL;
	*LL2 = slow->next;
	slow->next = NULL;
}



void MergeSort(struct node **LL)
{
	if((*LL)->next!=NULL)
	{
		struct node *left = NULL;
		struct node *right = NULL;
		SplittoHalves(LL,&left,&right);
		MergeSort(&left);
		MergeSort(&right);
		*LL = MergeLLs(left,right);
	}
}

int main()
{
	int arr[] = {2,6,4,8,9,1,5,7,3,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL,arr[i]);

	printLL(LL);
	MergeSort(&LL);
	printLL(LL);

	cin.get();
	cin.get();
	return 0;
}