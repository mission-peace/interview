#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int arr[] = {20,8,-1,-1,22,-1,-1};
	int n = sizeof(arr)/sizeof(arr[0]);

	// (variable to file)
	ofstream fileobj_v2f;

	fileobj_v2f.open();

	for(int i=0 ; i<=n-1 ; i++)
	{
		fprintf(fileobj_v2f,"%d",arr[i]);
	}


	cin.get();
	cin.get();
	return 0;
}