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

void createLL(struct node **head,int x)
{
	struct node *temp = newNode(x);

	if(*head!=NULL)
		temp->next = *head;
	*head = temp;
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

struct node *findLLmedian(struct node *slow)
{
	if(slow==NULL)
		return NULL;

	struct node *fast = slow->next;

	while(fast!=NULL && fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

void SplitLLintoHalves(struct node *head,struct node **refHalf1,struct node **refHalf2)
{
	struct node *median = findLLmedian(head);

	*refHalf1 = head;
	*refHalf2 = median->next;
	median->next = NULL;
}

struct node *MergetwoLLHalves(struct node *L,struct node *R)
{
	struct node *LL = NULL;

	if(L==NULL)
		return R;
	if(R==NULL)
		return L;

	if(L->data < R->data)
	{
		LL = L;
		LL->next = MergetwoLLHalves(L->next,R);
	}
	else
	{
		LL = R;
		LL->next = MergetwoLLHalves(L,R->next);
	}

	return LL;
}

void MergeSort(struct node **refHead)
{
	struct node *head = *refHead;
	struct node *half1 = NULL;
	struct node *half2 = NULL;

	if(head==NULL || head->next==NULL)
		return;

	SplitLLintoHalves(head,&half1,&half2);
	MergeSort(&half1);
	MergeSort(&half2);
	*refHead = MergetwoLLHalves(half1,half2);

}

struct node *UnionofLLs(struct node *L,struct node *R)
{

	struct node *Union = NULL;

	while(L && R)
	{

		if(L->data==R->data)
		{
			createLL(&Union,L->data);
			L = L->next;
			R = R->next;
		}
		else
		{
			if(L->data < R->data)
			{
				createLL(&Union,L->data);
				L = L->next;
			}
			else
			{
				createLL(&Union,R->data);
				R = R->next;
			}
		}

	}

	while(L)
	{
		createLL(&Union,L->data);
		L = L->next;
	}

	while(R)
	{
		createLL(&Union,R->data);
		R = R->next;
	}

	return Union;
}

struct node *IntersectionofLLs(struct node *L,struct node *R)
{
	struct node *Inter = NULL;

	while(L && R)
	{

		if(L->data==R->data)
		{
			createLL(&Inter,L->data);
			L = L->next;
			R = R->next;
		}
		else
		{
			if(L->data < R->data)
			{
				L = L->next;
			}
			else
			{
				R = R->next;
			}
		}

	}

	return Inter;
}

int main()
{
	int arr1[] = {4,8,3,6,8,1,9};

	int arr2[] = {1,5,6,2,4,7};

	struct node *LL1 = NULL;
	for(int i=sizeof(arr1)/sizeof(arr1[0])-1 ; i>= 0 ; i--)
		createLL(&LL1,arr1[i]);

	struct node *LL2 = NULL;
	for(int i=sizeof(arr2)/sizeof(arr2[0])-1 ; i>= 0 ; i--)
		createLL(&LL2,arr2[i]);

	cout<<"\n the two LLs are : "<<endl;
	printLL(LL1);
	printLL(LL2);
	MergeSort(&LL1);
	MergeSort(&LL2);
	cout<<"\n After sorting the two LLs : "<<endl;
	printLL(LL1);
	printLL(LL2);

	struct node *U = UnionofLLs(LL1,LL2);
	struct node *I = IntersectionofLLs(LL1,LL2);
	
	cout<<"\n The Union of the two LLs are : "<<endl;
	MergeSort(&U);
	printLL(U);
	cout<<"\n The Intersection of two LLs are : "<<endl;
	MergeSort(&I);
	printLL(I);

	cin.get();
	return 0;
}