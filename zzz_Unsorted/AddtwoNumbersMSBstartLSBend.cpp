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

void createLL(struct node **refEnd,int x)
{
	struct node *temp = newNode(x);

	if(*refEnd!=NULL)
		temp->next = *refEnd;	
	*refEnd = temp;
}


void printLL(struct node *head)
{
	if(head==NULL)
		return ;

	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int getLLsize(struct node *head)
{
	if(head==NULL)
		return -1;

	int size = 0;

	while(head!=NULL)
	{
		size++;
		head = head->next;
	}
	return size;
}

struct node *Add2eqLLs(struct node **refHead,struct node *LL1,struct node *LL2,int *carry)
{
	if(LL1==NULL)
		return LL1;

	Add2eqLLs(refHead,LL1->next,LL2->next,carry);

	int sum = *carry + LL1->data + LL2->data;
	createLL(refHead,sum%10);
	sum/10 ? *carry=1 : *carry=0 ;

	return *refHead;
}

struct node *AddwithBigLL(struct node **refHead,struct node *LL1,int extra,int *carry)
{
	if(!extra || LL1==NULL)
		return LL1;

	AddwithBigLL(refHead,LL1->next,--extra,carry);

	int sum = *carry + LL1->data;
	createLL(refHead,sum%10);
	sum/10 ? *carry=1 : *carry=0;
	//*refHead = temp;

	return *refHead;
}

void Add2LLs(struct node **refHead,struct node *LL1,struct node *LL2)
{
	if(LL1==NULL || LL2==NULL)
	{
		if(LL1==NULL)
			*refHead = LL2;
		if(LL2==NULL)
			*refHead = LL1;
		return;
	}

	int n1 = getLLsize(LL1);
	int n2 = getLLsize(LL2);

	if(n2 > n1)
	{
		struct node *temp = LL1;
		LL1 = LL2;
		LL2 = temp;
	}

	if(n1!=n2)
	{
		int extra = abs(n1-n2);
		struct node *tempLL1 = LL1;
		while(extra--)
			tempLL1 = tempLL1->next;
		int carry = 0;
		Add2eqLLs(refHead,tempLL1,LL2,&carry);
		AddwithBigLL(refHead,LL1,abs(n1-n2),&carry);
	}
	else
	{
		int carry = 0;
		Add2eqLLs(refHead,LL1,LL2,&carry);
		if(carry)
			createLL(refHead,1);

	}

}


int main()
{
	int arr1[] = {4,6,5};
	int n = sizeof(arr1)/sizeof(arr1[0]);

	struct node *LL1 = NULL;

	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL1,arr1[i]);

	printLL(LL1);

	int arr2[] = {2,1,8,0,7};
	n = sizeof(arr2)/sizeof(arr2[0]);

	struct node *LL2 = NULL;

	for(int i=n-1 ; i>=0 ; i--)
		createLL(&LL2,arr2[i]);

	printLL(LL2);

	struct node *SumLL = NULL;
	Add2LLs(&SumLL,LL1,LL2);
	printLL(SumLL);

	cin.get();
	cin.get();
	return 0;

}