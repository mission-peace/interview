#include<iostream>
#define ROW 3
#define COL 4
using namespace std;

void printMatrix(int **mat)
{
	cout<<"\n Printing Matrix : \n";
	for(int i=0 ; i<=ROW-1 ; i++)
	{
		for(int j=0 ; j<=COL-1 ; j++)
			cout<< *(*(mat+i)+j)<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	// Method 1 - Creation of 2D Matrix using Square Braces
	int mat1[][COL]	= {	{34,36,31,39},
						{12,19,13,17},
						{28,24,26,23},	};

	// Method 2 - Creation of 2D Matrix using new operator
	int **mat2 = new int*[ROW]();
	for(int i=0 ; i<=ROW-1 ; i++)
		mat2[i] = new int[COL]();

	//printMatrix((int **)mat1);  // Uncommenting this line throws exception "Access Violation while reading location!"
	printMatrix(mat2);

	cin.get();
	return 0;
}