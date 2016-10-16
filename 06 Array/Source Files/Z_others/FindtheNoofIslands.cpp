#include<iostream>
using namespace std;

bool isSafe(int lands[][5],int i,int j,int **visited)
{
	return i>=0 && i<=4 && j>=0 && j<=4 && lands[i][j] && !visited[i][j];
}

void DFS(int lands[][5],int i,int j,int **visited)
{
	int row[8] = {-1,-1,-1,0,0,1,1,1};
	int col[8] = {-1,0,1,-1,1,-1,0,1};

	visited[i][j] = 1;

	for(int k=0 ; k<=7 ; k++)
	{
		if(isSafe(lands,i+row[k],j+col[k],visited))
		{
			DFS(lands,i+row[k],j+col[k],visited);
		}
	}
}


int countIslands(int lands[][5])
{
	int **visited = new int*[5]();
	for(int i=0 ; i<=4 ; i++)
		visited[i] = new int[5]();

	int count = 0;

	for(int i=0 ; i<=4 ; i++)
	{
		for(int j=0 ; j<=4 ; j++)
		{
			if(lands[i][j] && !visited[i][j])
			{
				DFS(lands,i,j,visited);
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int lands[][5]=    { {1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
						{1, 0, 1, 0, 1} };

	cout<<"The no. of Islands are : "<<countIslands(lands);

	cin.get();
	cin.get();
	return 0;
}