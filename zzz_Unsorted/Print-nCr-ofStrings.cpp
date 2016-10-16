#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0 ; i<=n-1 ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printCombinationsUtil(int arr[],int n,int nindex,int comb[],int r,int rindex)
{
    if(rindex==r)
    {
        printArray(comb,r);
        return;
    }
    if(nindex >= n)
        return;
        
    comb[rindex] = arr[nindex];
    printCombinationsUtil(arr,n,nindex+1,comb,r,rindex+1);
	int k=nindex;
	while(k<=n-1 && arr[k]==arr[k+1])
	{
		k++;
	}
    printCombinationsUtil(arr,n,k+1,comb,r,rindex);
    
}

void printCombinations(int arr[],int n,int r)
{
    int *comb = new int[r];
    printCombinationsUtil(arr,n,0,comb,r,0);
}

int main()
{
   int arr[] = {1,2,3,4,4};
   int n=sizeof(arr)/sizeof(arr[0]);
   int r=3;
   
   //for(int i=1 ; i<=n ; i++)
	printCombinations(arr,n,r);
   
   cin.get();
   cin.get();
   return 0;
}