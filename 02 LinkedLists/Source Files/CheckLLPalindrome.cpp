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

void createLL(struct node **refHead,char a)
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

void reverseLL(struct node **refHead)
{
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

struct node *getTwoHalves(struct node *LL,struct node **half1,struct node **half2)
{
    *half1 = LL;
    struct node *slow = LL;
    struct node *fast = LL->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *half2 = slow->next;
    slow->next = NULL;
    return slow;
}

bool checkEqualHalves(struct node *LL1,struct node *LL2)
{
    while(LL2!=NULL)
    {
        if(LL2->data!=LL1->data)
            return 0;
        LL2 = LL2->next;
        LL1 = LL1->next;
    }
    return 1;
}

bool checkPalindrome(struct node *LL)
{
    struct node *half1 = NULL;
    struct node *half2 = NULL;
    struct node *half1End = getTwoHalves(LL,&half1,&half2);

    reverseLL(&half2);
    bool res = checkEqualHalves(half1,half2);
    reverseLL(&half2);

    half1End->next = half2;
    return res;
}



int main()
{
	char arr[] = {'r','a','d','a','r'};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	struct node *LL = NULL;
	for(int i=n-1 ; i>=0 ; i--)
	    createLL(&LL,arr[i]);
	printLL(LL)  ;
	cout<<checkPalindrome(LL);
	printLL(LL);
	

	cin.get();
	cin.get();
	return 0;
}