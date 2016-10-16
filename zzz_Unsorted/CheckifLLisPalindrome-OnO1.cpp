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

void Push(struct node **refHead,char x)
{
	struct node *temp = newNode(x);

	if(*refHead!=NULL)
		temp-> next = *refHead;

	*refHead = temp;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		cout<<"\nThe LL is empty\n";
		return;
	}
	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

struct node *getMedian(struct node *slow)
{
	if(slow==NULL || slow->next==NULL)
		return slow;

	struct node *fast = slow->next;

	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

struct node *reverseLL(struct node **refHead)
{
	if(*refHead==NULL || (*refHead)->next==NULL)
		return *refHead;

	struct node *first = *refHead;
	struct node *rest = first->next;

	reverseLL(&rest);
	first->next->next = first;
	first->next = NULL;
	*refHead = rest;
}

void reverseafterMedian(struct node **median)
{
	struct node *half2= (*median)->next;
	(*median)->next = NULL;
	 reverseLL(&half2);
	(*median)->next = half2;

}

bool isPalindrome(struct node *head)
{
	struct node *median = getMedian(head);
	cout<<"\nThe Median is : "<<median->data<<endl;
	
	reverseafterMedian(&median);
	printLL(head);

	 struct node *half1 = head;
	 struct node *half2 = median->next;
	 bool res = true;

	 while(half2!=NULL)
	 {
		 if(half1->data != half2->data)
		 { 
			 res = false;
			 break;
		 }

		 half1 = half1->next;
		 half2 = half2->next;
	 }

	reverseafterMedian(&median);
	printLL(head);

	return res;
}

int main()
{

	char arr[] = {'R','A','D','A','R'};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct node *LL = NULL;

	for(int i=n-1 ; i>=0 ; i--)
		Push(&LL,arr[i]);

	printLL(LL);
	isPalindrome(LL) ? cout<<"\nLL is Palindrome!" : cout<<"\nLL is not a palindrome!";


	cin.get();
	cin.get();
	return 0;
}