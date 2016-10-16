#include<iostream>
#include<map>
using namespace std;

void printDistinct(int arr[],int n)
{
	map<int,int> HT;

	for(int i=0 ; i<=n-1 ; i++)
	{
		if(HT.find(arr[i])==HT.end())
		{
			cout<<arr[i]<<" ";
			HT.insert(pair<int,int>(arr[i],1));
		}
	}
	HT.clear();
}

int main()
{
	int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
	int n = sizeof(arr)/sizeof(arr[0]);
	printDistinct(arr,n);
	cin.get();
	cin.get();
	return 0;
}

