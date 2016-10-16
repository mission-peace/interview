#include<iostream>
#define M 6
#define N 6
using namespace std;

bool isRowSafe(int mat[][N],int i,int j)
{
	bool x=false,y=false;
	for(int k=0 ; k<=N-1 ; k++)
	{
		if(k<j-1 && mat[i][k])
			x = true;
		if(k>j+1 && mat[i][k])
			y = true;
	}
	return x && y;
}

bool isColSafe(int mat[][N],int i,int j)
{
	bool x=false,y=false;
	for(int k=0 ; k<=N-1 ; k++)
	{
		if(k<i-1 && mat[k][j])
			x = true;
		if(k>i+1 && mat[k][j])
			y = true;
	}
	return x && y;
}

bool isDiagSafe(int mat[][N],int i,int j)
{
	bool a=0,b=0,c=0,d=0;

	for(int k=j-1 ; k>=0 ; k--)
		if(k < j-1 && mat[k][k])
			a = true;
	for(int k=j+1 ; k<=N-1 ; k++)
		if(k > j+1 && mat[k][k])
			b = true;
	for(int k=)
}

bool isSafe(int mat[][N],int i,int j)
{
	return isRowSafe(mat,i,j) && isColSafe(mat,i,j) && isDiagSafe(mat,i,j);
}