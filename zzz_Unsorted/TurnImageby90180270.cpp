#include<iostream>
#define ROW 3
#define COL 4
using namespace std;

void RotateMatrixby90(int arr[][COL],int M90[][ROW])
{
	for(int i=0 ; i<=ROW-1 ; i++)
	{
		for(int j=0 ; j<=COL-1 ; j++)
		{
			*(*(M90+COL-1-j)+i) = arr[i][j];
		}
	}
}

void RotateMatrixby180(int arr[][COL],int M180[][COL])
{
	for(int i=0 ; i<=ROW-1 ; i++)
	{
		for(int j=0 ; j<=COL-1 ; j++)
		{
			*(*(M180+ROW-1-i)+j) = arr[i][j];
		}
	}
}

void printMatrix(int arr[][COL])
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

void printRotatedMatrix(int arr[][ROW])
{
	for(int i=0 ; i<=COL-1 ; i++)
	{
		for(int j=0 ; j<=ROW-1 ; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int arr[][COL] = {	{13,15,18,12},
						{22,27,24,29},
						{34,31,38,35} };

	
	int M90[COL][ROW];
	RotateMatrixby90(arr,M90);
	cout<<"Rotated by 90 degrees, it is : "<<endl;
	printRotatedMatrix(M90);

	int M180[ROW][COL];
	RotateMatrixby180(arr,M180);
	cout<<"Rotated by 180 degrees, it is : "<<endl;
	printMatrix(M180);

	/*
	int M90[COL][ROW];
	RotateMatrixby90(arr,M90);
	cout<<"Rotated by 90 degrees, it is : "<<endl;
	printRotatedMatrix(M90);

	int M90[COL][ROW];
	RotateMatrixby90(arr,M90);
	cout<<"Rotated by 90 degrees, it is : "<<endl;
	printMatrix(M90);
	*/
	cout<<"The normal, unshifted matrix : "<<endl;
	printMatrix(arr);

	cin.get();
	cin.get();
	return 0;

}

