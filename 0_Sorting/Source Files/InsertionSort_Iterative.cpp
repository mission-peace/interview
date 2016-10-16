#include<iostream>
using namespace std;

void Swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b = temp;

}

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0 ; i<=len-1 ; i++)
		cout<<arr[i]<<" ";
}

void InsertionSort(int arr[],int e)
{
	//int s;

	int key;
	int j;

	for(key=1 ; key <= e ; key++)
	{

		if(arr[key] < arr[key-1] )
		{
			j=key;
			int keyvalue = arr[key];

			// Move from backward, i.e, from the arr[key] location till the point where keyvalue is lesser, 
			// ie, the point where the keyvalue needs to be
			while(j-1>=0 && arr[j-1] > keyvalue)
			{
				Swap(&arr[j-1],&arr[j]);
				j--;
			}

			/* Below is a Bad method
			// Traverse till the point where we want to insert the element arr[key]
			// s points to the exact location where the new element needs to inserted
			for(s=0 ; arr[s] <= arr[key] ; s++) {}

			// Move elements one position ahead so that sortedness is maintained
			while(s!=key)
			{
				Swap(&arr[s],&arr[key]);
				s++;
			}
			*/
		}

	}

}

void main()
{
	int arr[] = {13,6,23,15,8,12,3};
	int len = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,len);
	InsertionSort(arr,len-1);
	printArray(arr,len);

	cin.get();
}