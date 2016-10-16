// C++ program to find largest pair sum in a given array
#include<iostream>
#define max(a,b) a>b ? a:b
#define min(a,b) a<b ? a:b
using namespace std;


int findLargestSumPair(int arr[], int n)
{
    int maxnum1 = max(arr[0],arr[1]);
    int maxnum2 = min(arr[0],arr[1]);
    
	// This can be easily extended for largest triplet sum! 
	// 1st check maxsum1 nd update maxsum2,3 else if check maxsum2 and update maxsum3 else if set for maxsum3
    for(int i=2 ; i<=n-1 ; i++)
    {
		if(arr[i] > maxnum1)
		{
			maxnum2 = maxnum1;
			maxnum1 = arr[i];
		}
		else if(arr[i] > maxnum2)
			maxnum2 = arr[i];
    }
    return maxnum1+maxnum2;
}


/* Driver program to test above function */
int main()
{
	int arr[] = {12, 34, 10, 6, 40};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Max Pair Sum is " << findLargestSumPair(arr, n);
	cin.get();
	cin.get();
	return 0;
}