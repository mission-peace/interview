#include<iostream>
using namespace std;

struct dataset
{
	int key;
	int count;
};

void printStruct(struct dataset arr[],int n)
{
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i].key<<" "<<arr[i].count<<endl;
}

int main()
{
	int n=5;
	struct dataset *arr = new struct dataset[n];

	for(int i=0 ; i<=n-1 ; i++)
	{
		arr[i].key = i;
		arr[i].count = 15+i;
	}

	printStruct(arr,n);

	cin.get();
	return 0;
}