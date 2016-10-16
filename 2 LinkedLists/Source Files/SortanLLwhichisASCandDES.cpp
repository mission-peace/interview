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
    if(*refHead)
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
    if(*refHead==NULL || (*refHead)->next==NULL)
        return;
        
    struct node *prev = NULL;
    struct node *cur = *refHead;
    struct node *later = NULL;
    
    while(cur!=NULL)
    {
        later = cur->next;
        cur->next = prev;
        prev = cur;
        cur = later;
    }
    *refHead = prev;
}

void splitLL(struct node **refLL,struct node **AscLL,struct node **DesLL)
{
    struct node *LL = *refLL;
    if(LL==NULL)
        return;
        
    struct node *AscLLHead = LL;
    struct node *DesLLHead = LL->next;
    
    bool flip = 1;
    while(LL)
    {
        struct node *temp = LL;
		LL = LL->next;
        temp->next = NULL;
        
        if(flip)
        {
            if(*AscLL)
                (*AscLL)->next = temp;
            *AscLL = temp;
        }
        else
        {
            if(*DesLL)
                (*DesLL)->next = temp;
            *DesLL = temp;
        }
        
        flip = !flip;
    }
    
    *AscLL = AscLLHead;
    *DesLL = DesLLHead;
}

struct node *mergeLL(struct node *LL1,struct node *LL2)
{
    struct node *LL = NULL;
    if(LL1==NULL)
        return LL2;
    if(LL2==NULL)
        return LL1;
    
    if(LL1->data < LL2->data)
    {
        LL = LL1;
        LL->next = mergeLL(LL1->next,LL2);
    }
    else
    {
        LL = LL2;
        LL->next = mergeLL(LL1,LL2->next);
    }
    return LL;
}

void sortLL(struct node **refHead)
{
    struct node *asc = NULL;
    struct node *des = NULL;
    splitLL(refHead,&asc,&des);
	printLL(asc);
	printLL(des);
    reverseLL(&des);
    *refHead = mergeLL(asc,des);
}


int main()
{
    int arr[] = {10,40,53,30,67,12,89};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    struct node *LL = NULL;
    for(int i=n-1 ; i>=0 ; i--)
        createLL(&LL,arr[i]);
    printLL(LL);
    
    sortLL(&LL);
    printLL(LL);
    
    cin.get();
    cin.get();
    return 0;
}
