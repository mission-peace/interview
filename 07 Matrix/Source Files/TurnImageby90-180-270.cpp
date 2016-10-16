#include<iostream>
#define ROW 3
#define COL 4
using namespace std;

template<class T>
void printMatrix(T mat,int r=ROW,int c=COL)
{
	cout<<endl; //<<"Printing Standard wise Matrix : \n";
	for(int i=0 ; i<=r-1 ; i++)
	{
		for(int j=0 ; j<=c-1 ; j++)
			cout<< *(*(mat+i)+j)<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void TurnMatrixbyDegrees(int mat[][COL])
{
	int **mat90 = new int*[COL]();
	for(int i=0 ; i<=COL-1 ; i++)
		mat90[i] = new int[ROW]();

	for(int i=0 ; i<=ROW-1 ; i++)
		for(int j=0 ; j<=COL-1 ; j++)
			mat90[j][ROW-1-i] = mat[i][j];

	cout<<"Turning by 90 degrees\n";
	printMatrix(mat90,COL,ROW);
	delete []mat90;

	int **mat180 = new int*[ROW]();
	for(int i=0 ; i<=ROW-1 ; i++)
		mat180[i] = new int[COL]();

	for(int i=0 ; i<=ROW-1 ; i++)
		for(int j=0 ; j<=COL-1 ; j++)
			mat180[ROW-1-i][COL-1-j] = mat[i][j];

	cout<<"Turning by 180 degrees\n";
	printMatrix(mat180);
	delete []mat180;

	int **mat270 = new int*[COL]();
	for(int i=0 ; i<=COL-1 ; i++)
		mat270[i] = new int[ROW]();

	for(int i=0 ; i<=ROW-1 ; i++)
		for(int j=0 ; j<=COL-1 ; j++)
			mat270[COL-1-j][i] = mat[i][j];

	cout<<"Turning by 270 degrees\n";
	printMatrix(mat270,COL,ROW);
	delete []mat270;
}

int main()
{
	int mat[][COL]		= {	{34,36,31,39},
							{12,19,13,17},
							{28,24,26,23},	};


	/*
	cout<<"\n No. of Rows : "<<sizeof(mat)/sizeof(mat[0])<<endl;
	cout<<"\n No. of Cols : "<<sizeof(mat[0])/sizeof(mat[0][0])<<endl;
	cout<<"\n No. of Eles : "<<sizeof(mat)/sizeof(mat[0][0])<<endl;
	cout<<"\n Sizeof Matrix : "<<sizeof(mat)<<endl;
	*/

	cout<<" Original Matrix : \n";
	printMatrix(mat);
	TurnMatrixbyDegrees(mat);

	cin.get();
	cin.get();
	return 0;
}