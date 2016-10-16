#include<iostream>
using namespace std;

struct node
{
    int data;
    int row;
    int next;
};

class MinHeap
{
    struct node *heaparr;
    int heapsize;
    int cursize;
    
public :  
    MinHeap(int n);
    int getParent(int i);
    int getLeft(int i);
    int getRight(int i);
    
    void insertKey(struct node a);
    struct node getMin();
    void Heapify(int i);
    struct node replaceMin(struct node a);
    
};


MinHeap::MinHeap(int n)
{
    heaparr = new struct node[n];
    heapsize = n;
    cursize = 0;
}

int MinHeap::getParent(int i)
{
    return (i-1)/2;
}

int MinHeap::getLeft(int i)
{
    return 2*i+1;
}

int MinHeap::getRight(int i)
{
    return 2*i+2;
}

void MinHeap::insertKey(struct node temp)
{
    if(cursize==heapsize)
    {
        cout<<"\n Heap is full! \n";
        return;
    }
    
    heaparr[cursize] = temp;
    cursize++;
    Heapify(0);
    return;
}

struct node MinHeap::getMin()
{
    struct node temp;
    temp.data = -1;
    temp.row = -1;
    temp.next = -1;
    
    if(cursize==0)
        return temp;
    
    return heaparr[0];
}

struct node MinHeap::replaceMin(struct node x)
{
    struct node root = heaparr[0];
    heaparr[0] = x;
	Heapify(0);
    return root;
}

void Swap(struct node *a,struct node *b)
{
    if(a!=b)
    {
        struct node temp = *a;
        *a = *b;
        *b = temp;
    }
}

void MinHeap::Heapify(int i)
{
    int small = i;
    int left = getLeft(i);
    int right = getRight(i);
    
    if(left < cursize && heaparr[left].data < heaparr[small].data)
        small = left;
    if (right < cursize && heaparr[right].data < heaparr[small].data)
        small = right;
    if(small!=i)
    {
        Swap(&heaparr[small],&heaparr[i]);
        Heapify(small);
    }
}

int main()
{
    int arr[][4] = {    {1,3,5,7},
                        {2,4,6,8},
                        {0,9,10,11}  };
    
    int R=sizeof(arr)/sizeof(arr[0]); 
    int C=sizeof(arr[0])/sizeof(arr[0][0]);
    
    //cout<<"Rows : "<<R<<" Cols : "<<C<<endl;
    
    MinHeap heap(R);
    
    for(int i=0 ; i<=R-1 ; i++)
    {
        struct node temp = {arr[i][0],i,1};
        heap.insertKey(temp);
    }
    
    for(int i=0 ; i<=R*C-1 ; i++)
    {
		// 1. Get the min node and print it
        struct node cur = heap.getMin();
        cout<<cur.data<<" ";
        
        struct node nextnode;
        
		// 2. Create a temporary node which is the next node to be inserted into the heap
        if(cur.next <= C-1)
            nextnode.data = arr[cur.row][cur.next];
        else
            nextnode.data = 99999;
            
        nextnode.row = cur.row;
        nextnode.next = cur.next+1;
        
		// 3. Replace the top node with the temp node created in step 2! Dont forget to Heapify()!
        heap.replaceMin(nextnode);
    }
    
    cin.get();
    return 0;
}

