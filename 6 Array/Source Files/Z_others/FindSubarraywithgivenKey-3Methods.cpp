#include<iostream>
#include<map>
using namespace std;

/* 
ALL - Subarray = CONTIGUOUS Subarray
1. Find Subarray with given Sum
2. Find Smallest Subarry with Sum > given value
3. Find Subarray whose difference is 0
4. Brute Force Subarray with given sum
5. Brute force Subarray with given difference
6. Brute force print all the "contiguous" subarrays
*/
 


//Q1

void SubArraywithGivenSumLinearTime(int arr[],int n,int key)
{
	int cursum = 0;

	for(int i=0 ; i<=n-1 ; i++)
	{
		cursum += arr[i];

		int start = 0;
		// If cursum is > key, keep reducing it by starting from the tail, i.e index 0!
		while(start<=i-1 && cursum > key)
		{
			cursum -= arr[start];
			start++;
		}

		if(cursum==key)
		{
			cout<<"\n a Contiguous Subarray of sum = "<<key<<" is found!\n";
		}


	}
}

// Q2 

void SmallestSubArrwithSumLinearTime(int arr[],int n,int key)
{
	int cursum = 0;
	int smallestsubarr = n+1;

	for(int i=0 ; i<=n-1 ; i++)
	{
		cursum += arr[i];

		int start = 0;
		int tempsum = cursum;
		// If tempsum is > key, keep reducing it by starting from the tail, i.e index 0!
		while(start<=i-1 && tempsum > key)
		{
			tempsum -= arr[start];
			start++;
		}

		if(tempsum==key)
		{
			cout<<"\n a Contiguous Subarray of sum = "<<tempsum<<" is found!\n";

			//if(start!=0) // This means we found a subarray somewhere in the middle
			smallestsubarr = min(smallestsubarr,i-start+1);
			cout<<"\n The subarrays is found between "<<start<<" and "<<i<<endl;

		}
	}
	cout<<"\n The Smallest subarray is : "<<smallestsubarr;
}

// Q3
int printZeroSumSubarray(int arr[], int n)
{
    int sum=0;
    map<int,int> m;
 
	int count = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
 
        if(arr[i]==0 || sum == 0 || m[sum])
            count++;
 
        m[sum] = 1;
    }
 
    return 0;
}

 
// Q4:Make a diff and check if it is the keydiff
// Q5:Make a count and check if it is the keysum 
// Q6
void printallSubarrays(int arr[],int n)
{
	for(int i=0 ; i<=n-2 ; i++)
	{
		cout<<arr[i]<<endl;
		for(int j=i+1 ; j<=n-1 ; j++)
		{
			for(int k=i ; k<=j ; k++)
				cout<<arr[k]<<" ";
			cout<<endl;
		}
	}
}
 
int main()
{
	int arr[] = {3, 2, 1, 5, 6, 3, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);


	// Q 1
	cout<<"\n\n\n Q1 \n";
	SubArraywithGivenSumLinearTime(arr,n,12);
	cout<<"\n Q1 ends\n\n\n";

	// Q 2
	cout<<"\n\n\n Q2\n";
	SmallestSubArrwithSumLinearTime(arr,n,11);
	cout<<"\n Q2 ends\n\n\n";
	
	// Q 3
	cout<<"\n\n\n Q3 \n";
	if (printZeroSumSubarray(arr, n))
		cout<<"Found a subarray with 0 sum";
	else
		cout<<"No Subarray with 0 sum";
	cout<<"\n Q3 ends\n\n\n";

	// Q 4,5,6
	cout<<"\n\n\n Q456 \n";
	printallSubarrays(arr,n);
	cout<<"\n Q456 ends\n\n\n";

	cin.get();
	cin.get();
	return 0;
}