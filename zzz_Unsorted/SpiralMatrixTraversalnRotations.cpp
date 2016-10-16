#include<iostream>
#define ROW 4
#define COL 5
using namespace std;

void printSpirally(int arr[][COL])
{
	int sr=0;
	int er = ROW-1;
	int sc = 0;
	int ec = COL-1;

	while(sr <= er && sc<=ec )
	{
		for(int i=sr ; i<=er ; i++)
			cout<<arr[i][sc]<<" ";
		sc++;

		for(int i=sc ; i<=ec ; i++)
			cout<<arr[er][i]<<" ";
		er--;

		for(int i=er ; i>=sr ; i--)
			cout<<arr[i][ec]<<" ";
		ec--;

		for(int i=ec ; i>=sc ; i--)
			cout<<arr[sr][i]<<" ";
		sr++;
	}

}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	* b = temp;
}

void rotateMatrix(int arr[][COL])
{
	int sr=0;
	int er = ROW-1;
	int sc = 0;
	int ec = COL-1;

	int prev,cur;

	while(sr <= er && sc<=ec )
	{

		if(sr+1 <=er && sc+1<=ec)
			prev = arr[sr+1][ec];
		else
			break;

		for(int i=ec ; i>=sc ; i--)
		{
			cur = arr[sr][i];
			arr[sr][i] = prev;
			prev = cur;
		}
		sr++;

		for(int i=sr ; i<=er ; i++)
		{
			cur = arr[i][sc];
			arr[i][sc] = prev;
			prev = cur;
		}
		sc++;

		for(int i=sc ; i<=ec ; i++)
		{
			cur = arr[er][i];
			arr[er][i] = prev;
			prev = cur;
		}
		er--;

		for(int i=er ; i>=sr ; i--)
		{
			cur = arr[i][ec];
			arr[i][ec] = prev;
			prev = cur;
		}
		ec--;


	}

}

void printMatrix(int arr[ROW][COL])
{
	for(int i=0 ; i<=ROW-1 ; i++)
	{
		for(int j=0 ; j<=COL-1 ; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int arr[ROW][COL] = {	{11,12,13,14,15},
							{16,17,18,19,20},
							{21,22,23,24,25},
							{26,27,28,29,30}	};

	printSpirally(arr);

	cout<<"\n\nThe actual matrix : "<<endl;
	printMatrix(arr);

	rotateMatrix(arr);
	cout<<"\nThe Rotated Matrix : "<<endl;
	printMatrix(arr);

	cin.get();
	return 0;
}