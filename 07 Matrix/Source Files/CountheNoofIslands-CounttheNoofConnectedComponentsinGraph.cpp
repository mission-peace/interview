#include<iostream>
#define ROW 5
#define COL 5
using namespace std;

int travROW[8] = {-1,-1,-1,0,0,1,1,1};
int travCOL[8] = {-1,0,1,-1,1,-1,0,1};

bool isSafe(int M[][COL],bool **visited,int i,int j)
{
	return (i>=0 && i<=ROW-1 && j>=0 && j<=COL-1 && M[i][j] && !visited[i][j]);
}

void DFS(int M[][COL],bool **visited,int i,int j)
{
	visited[i][j] = true;

	for(int K=0 ; K<=7 ; K++)
	{
		if(isSafe(M,visited,i+travROW[K],j+travCOL[K]))
			DFS(M,visited,i+travROW[K],j+travCOL[K]);
	}
}

int CountIslands(int M[][COL])
{
	bool **visited = new bool*[ROW]();
	for(int i=0 ; i<=ROW-1 ; i++)
		visited[i] = new bool[COL]();

	int islandscount = 0;

	for(int i=0 ; i<=ROW-1 ; i++)
	{
		for(int j=0 ; j<=COL-1 ; j++)
		{
			if(M[i][j] && !visited[i][j])
			{
				DFS(M,visited,i,j);
				islandscount++;
			}
		}
	}
	return islandscount;

}

int main()
{
	int M[][COL]= {  {1, 1, 0, 0, 0},
					 {0, 1, 0, 0, 1},
					 {1, 0, 0, 1, 1},
				     {0, 0, 0, 0, 0},
					 {1, 0, 1, 0, 1}
    };

	cout<<"The No.of Islands/No.of Connected Components : "<<CountIslands(M);

	cin.get();
	cin.get();
	return 0;
}