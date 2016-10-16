#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
    if(a!=b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}


void printArray(int arr[],int n)
{
    cout<<endl;
    for(int i=0 ; i<=n-1 ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void MergeSubArrays(int arr[],int si,int mid, int ei,int *inverts)
{
    int count = 0;
    int *l = new int[mid-si+1];
    int *r = new int[ei-mid];
    int lsize = mid-si+1;
    int rsize = ei-mid;
    
    for(int i=0 ; i<=lsize-1 ; i++)
        l[i] = arr[i+si];
    for(int i=0 ; i<=rsize-1 ; i++)
        r[i] = arr[i+mid+1];
    
    int i=0,j=0,k=si;
    
    while(i<=lsize-1 && j<=rsize-1)
    {
        if(l[i] <= r[j])
            arr[k++] = l[i++];
        else
        {
            arr[k++] = r[j++];
            count += lsize-i;
        }
    }
    
    while(i<=lsize-1)
        arr[k++] = l[i++];
    while(j<=rsize-1)
        arr[k++] = r[j++];
    
    *inverts += count;
    
    
}

void MergeSort(int arr[],int si,int ei,int *inverts)
{
    if(si<ei)
    {
        int mid = si  + (ei-si)/2;
        MergeSort(arr,si,mid,inverts);
        MergeSort(arr,mid+1,ei,inverts);
        MergeSubArrays(arr,si,mid,ei,inverts);
        
    }
    
}


int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int inversions = 0;
    MergeSort(arr,0,n-1,&inversions);
    printArray(arr,n);
    cout<<"The number of inversions : "<<inversions;
    cin.get();
    return 0;
}

