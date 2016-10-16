#include<iostream> 
using namespace std;

int abs(int n)
{
  if(n < 0)
    return -1*n ;
  else
    return n;
}
 
int main()
{
    int n, A[100001][2], B[100001], i, j;
	cin>>n;
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
			cin>>A[j][i];
    }
	
    B[0] = abs(A[0][0] - A[0][1]);
    B[1] = max( B[0] + abs(A[1][0]-A[1][1]) , abs(A[1][0]-A[0][0])+abs(A[1][1]-A[0][1]) );
    for(i=2;i<n;i++)
        B[i] = max( B[i-1] + abs(A[i][0]-A[i][1]) , B[i-2] + abs(A[i][0]-A[i-1][0]) + abs(A[i][1]-A[i-1][1]) );
		
	cout<<B[n-1]<<endl;
    return 0;
}