#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<=n-1 ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int getFirstOccur(int arr[],int l,int r,int key)
{
	if(r >= l)
	{
		int mid = l + (r-l)/2;
		if( (mid==0 || arr[mid-1]<key) && arr[mid]==key)
			return mid;
		else if(key < arr[mid])
			return getFirstOccur(arr,l,mid-1,key);
		else
			return getFirstOccur(arr,mid+1,r,key);
	}
	else
		return -1;
}

int getLastOccur(int arr[],int l,int r,int key,int last)
{
	if(r >= l)
	{
		int mid = l + (r-l)/2;
		if((mid==last || key<arr[mid+1]) && arr[mid]==key)
			return mid;
		else if(key < arr[mid])
			return getLastOccur(arr,l,mid-1,key,last);
		else
			return getLastOccur(arr,mid+1,r,key,last);
	}
	else
		return -1;
}

int compare(const void *a,const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	return x-y;
}

void SortbyOrder(int arr1[],int m,int arr2[],int n)
{
	int *temp = new int[m];
	bool *visited = new bool[m]();
	for(int i=0 ; i<=m-1 ; i++)
		temp[i]=arr1[i];
	qsort(temp,m,sizeof(temp[0]),compare);
	cout<<"\n Sorted temp array is : \n";
	printArray(temp,m);
	
	int copyindex=0;
	for(int i=0 ; i<=n-1 ; i++)
	{
		int key = arr2[i];
		int index = getFirstOccur(temp,0,m-1,key);

		if(index==-1)
			continue;
		else
		{
			visited[index] = 1;
			arr1[copyindex++] = key;
			if(index<=m-1 && temp[index+1]==key)
			{
				int lindex = getLastOccur(temp,0,m-1,key,m-1);
				for(int i=0 ; i<=lindex-index ; i++)
				{
					visited[++index] = 1;
					arr1[copyindex++] = key;
				}
			}
		}

	}

	for(int i=0 ; i<=m-1 ; i++)
	{
		if(visited[i]==0)
			temp[i] = arr1[copyindex++];
	}

}

int main()
{
	int arr1[] = {2, 1, 2, 5, 7, 1, 3, 6, 8, 8};
	int m = sizeof(arr1)/sizeof(arr1[0]);

	int arr2[] = {2, 1, 8, 3};
	int n = sizeof(arr2)/sizeof(arr2[0]);

	printArray(arr1,m);
	printArray(arr2,n);
	SortbyOrder(arr1,m,arr2,n);
	cout<<"\nOutput array is  : \n";
	printArray(arr1,m);

	cin.get();
	cin.get();
	return 0;
}