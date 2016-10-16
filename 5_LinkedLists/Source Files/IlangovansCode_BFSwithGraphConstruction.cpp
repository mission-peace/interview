#include<stdio.h>
int x,y,rear=-1,front=-1;
int q[62500][2];
void insertQ(int i,int j)
{
  if(front==-1)
    front=0;
  rear=rear+1;
  q[rear][0]=i;
  q[rear][1]=j;
}
void extractQ()
{
  x=q[front][0];
  y=q[front][1];
  front=front+1;
}
int emptyQ()
{
  if(front>rear)
    return 1;
  else 
    return 0;
}
int main()
{
  int M,N,i,j,k,l,c,a,b;
  int R[250][250],D[250][250],E[498][2],level[250][250],count=0;
  scanf("%d%d",&M,&N);
  for(i=0;i<M;i++)
    for(j=0;j<N;j++)
    {
	 scanf("%d",&R[i][j]);
    }
  for(i=0;i<M;i++)
    for(j=0;j<N;j++)
	scanf("%d",&D[i][j]);
  /*Input end*/

  //BFS
  for(i=0;i<M;i++)
  {
    for(j=0;j<N;j++)
    {
      level[i][j]=-1;
    }
  }
  level[0][0]=0;
  insertQ(0,0);
  while(!(emptyQ()))
  {
    extractQ();
    count=0;
    for(k=0,c=y;k<R[x][y] && k<(N-y)-1;k++,c++)
			{
			E[k][0]=x;
			E[k][1]=c+1;
                        count++;
			}
	for(l=k,c=x;l<k+D[x][y] && l<k+(M-x)-1;l++,c++)
			{
			E[l][0]=c+1;
			E[l][1]=y;
	                count++;
			}
    for(k=0;k<count;k++)
    {
      a=E[k][0];
      b=E[k][1];
      if(level[a][b]==-1)
      {
       level[a][b]=1+level[x][y];
       insertQ(a,b);
      }
    }
  }
  printf("%d\n",level[M-1][N-1]);
  return 0;
}
