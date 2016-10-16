#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *adjList;
	bool undirGraph;

public:
	Graph(int V,bool graphtype=false) {this->V = V; this->undirGraph = graphtype ; this->adjList= new list<int>[V];}
	void addEdge(int u,int v);
	void printGraph(Graph);
	void BFS(int i);
	void ShortestPath(int vertex,int parent[]);
};

void Graph::addEdge(int u,int v)
{
	adjList[u].push_back(v);
	
	if(undirGraph)
		adjList[v].push_back(u);
}

void Graph::printGraph(Graph G)
{
	int v;
	list<int>::iterator vCrawl;
	list<int>::iterator lCrawl;

	for(v=0 ; v<=G.V-1 ; v++)
	{
		cout<<"\nExploring the vertex : "<<v;
		cout<<"\nThe neighbouring vertices are : ";

		for(vCrawl = G.adjList[v].begin() ; vCrawl != G.adjList[v].end() ; vCrawl++)
			cout<<*vCrawl<<" ";
	}
	
}

void Graph::BFS(int i)
{
	bool *visited = new bool[V];
	int *parent = new int[V];

	for(int j=0;j<=V-1 ;j++)
	{
		visited[j]=false;
		parent[j] = -1;
	}
	list<int> queue;

	visited[i] = true;
	queue.push_back(i);
		
	//cout<<"\n\nBFS of "<<i<<" is : ";
	int vertex;
	list<int>::iterator vCrawl;

	while(!queue.empty())
	{
		vertex = queue.front();
		//cout<<vertex<<" ";
		queue.pop_front();
				
		for(vCrawl = adjList[vertex].begin() ; vCrawl!=adjList[vertex].end() ; vCrawl++)
		{
			if(visited[*vCrawl]==false)
			{
				visited[*vCrawl]=true;
				parent[*vCrawl]=vertex;
				queue.push_back(*vCrawl);

			}
		}
	}
	
	// vertex variable is passed since it is the last node visited
	ShortestPath(vertex,parent);
}

void Graph::ShortestPath(int vertex,int parent[])
{
	//cout<<"\n The Shortest Path found using BFS is : ";
	list<int> shortestpath;
	int hops = 0;
	int tracePath = vertex;
	while(1)
	{
		shortestpath.push_front(tracePath);
		tracePath=parent[tracePath];

		if(tracePath==-1)
			break;

	}
	for(list<int>::iterator pCrawl=shortestpath.begin() ; ; )
	{
		cout<<*pCrawl++;
		//*pCrawl++;
		hops++;
		if( pCrawl==shortestpath.end() )
			break;
		else
			cout<<" -> ";
		
	}
	cout<<"\n The no. of Hops made = "<<--hops;
	//cout<<--hops<<endl;
}

int main()
{
	int M,N;
	cin>>M;
	cin>>N;

	Graph g(M*N);

	
	int Rr[10][10] =
	{
		{1,1,3,4,1,5,2,1,5,1},
		{1,3,4,2,1,4,3,4,5,1},
		{3,4,4,3,3,1,1,2,2,3},
		{4,2,3,2,4,3,5,4,4,3},
		{1,1,3,4,1,3,1,1,3,5},
		{5,4,1,3,3,2,5,5,4,2},
		{2,3,1,5,1,5,2,1,4,4},
		{1,4,2,4,1,5,1,1,2,4},
		{5,5,2,4,3,4,4,2,5,5},
		{1,1,3,3,5,2,4,4,5,2}

	};

	int Dd[10][10]=
	{
		{1,1,3,4,1,5,2,1,5,1},
		{1,3,4,2,1,4,3,4,5,1},
		{3,4,4,3,3,1,1,2,2,3},
		{4,2,3,2,4,3,5,4,4,3},
		{1,1,3,4,1,3,1,1,3,5},
		{5,4,1,3,3,2,5,5,4,2},
		{2,3,1,5,1,5,2,1,4,4},
		{1,4,2,4,1,5,1,1,2,4},
		{5,5,2,4,3,4,4,2,5,5},
		{1,1,3,3,5,2,4,4,5,2}
	};

	for(int i=0 ; i<= M-1 ; ++i)
	{
		for(int j=0 ; j<= N-1 ; ++j)
		{
			int temp = Rr[i][j];

			for(int k=temp ; k>=1 ; --k)
			{
				if( N > j+k )
					g.addEdge((i*N)+j,(i*N)+j+k);
			}	
		}
	}

	for(int i=0 ; i<=M-1 ; ++i)
	{
		for(int j=0 ; j<=N-1 ; ++j)
		{
			int temp = Dd[i][j];

			for(int k=temp ; k>= 1 ; --k)
			{
				if( M-i > k )
					g.addEdge((i*N)+j,j+(k+i)*N );
			}	
		}
	}
	



	/*
	int Rr[40][20] = 
	{
		{4,5,5,5,3,3,6,3,4,6,5,2,7,5,8,6,8,8,6,4},
		{5,2,2,8,5,3,8,1,6,8,5,4,7,8,7,1,5,1,8,3},
		{5,2,6,7,7,1,6,6,6,6,7,2,6,7,3,1,2,2,2,1},
		{5,8,7,2,4,4,6,6,3,7,5,7,1,8,4,5,3,8,5,5},
		{3,5,7,4,8,5,4,5,7,3,7,6,1,8,6,7,2,5,3,1},
		{3,3,1,4,5,4,1,7,8,3,8,8,6,3,2,1,3,3,2,7},
		{6,8,6,6,4,1,1,2,7,2,2,7,2,2,1,4,3,1,3,4},
		{3,1,6,6,5,7,2,7,6,8,4,4,7,3,6,2,8,2,6,6},
		{4,6,6,3,7,8,7,6,4,2,4,5,2,4,2,2,4,7,1,4},
		{6,8,6,7,3,3,2,8,2,7,8,2,6,8,6,6,1,2,5,8},
		{5,5,7,5,7,8,2,4,4,8,5,1,6,8,8,5,7,7,5,3},
		{2,4,2,7,6,8,7,4,5,2,1,4,7,4,8,1,3,7,5,3},
		{7,7,6,1,1,6,2,7,2,6,6,7,4,6,8,5,8,8,8,5},
		{5,8,7,8,8,3,2,3,4,8,8,4,6,3,5,8,3,5,4,3},
		{8,7,3,4,6,2,1,6,2,6,8,8,8,5,5,7,8,6,6,5},
		{6,1,1,5,7,1,4,2,2,6,5,1,5,8,7,7,5,4,1,1},
		{8,5,2,3,2,3,3,8,4,1,7,3,8,3,8,5,3,6,4,5},
		{8,1,2,8,5,3,1,2,7,2,7,7,8,5,6,4,6,8,2,6},
		{6,8,2,5,3,2,3,6,1,5,5,5,8,4,6,1,4,2,3,3},
		{4,3,1,5,1,7,4,6,4,8,3,3,5,3,5,1,5,6,3,2},
		{4,5,5,5,3,3,6,3,4,6,5,2,7,5,8,6,8,8,6,4},
		{5,2,2,8,5,3,8,1,6,8,5,4,7,8,7,1,5,1,8,3},
		{5,2,6,7,7,1,6,6,6,6,7,2,6,7,3,1,2,2,2,1},
		{5,8,7,2,4,4,6,6,3,7,5,7,1,8,4,5,3,8,5,5},
		{3,5,7,4,8,5,4,5,7,3,7,6,1,8,6,7,2,5,3,1},
		{3,3,1,4,5,4,1,7,8,3,8,8,6,3,2,1,3,3,2,7},
		{6,8,6,6,4,1,1,2,7,2,2,7,2,2,1,4,3,1,3,4},
		{3,1,6,6,5,7,2,7,6,8,4,4,7,3,6,2,8,2,6,6},
		{4,6,6,3,7,8,7,6,4,2,4,5,2,4,2,2,4,7,1,4},
		{6,8,6,7,3,3,2,8,2,7,8,2,6,8,6,6,1,2,5,8},
		{5,5,7,5,7,8,2,4,4,8,5,1,6,8,8,5,7,7,5,3},
		{2,4,2,7,6,8,7,4,5,2,1,4,7,4,8,1,3,7,5,3},
		{7,7,6,1,1,6,2,7,2,6,6,7,4,6,8,5,8,8,8,5},
		{5,8,7,8,8,3,2,3,4,8,8,4,6,3,5,8,3,5,4,3},
		{8,7,3,4,6,2,1,6,2,6,8,8,8,5,5,7,8,6,6,5},
		{6,1,1,5,7,1,4,2,2,6,5,1,5,8,7,7,5,4,1,1},
		{8,5,2,3,2,3,3,8,4,1,7,3,8,3,8,5,3,6,4,5},
		{8,1,2,8,5,3,1,2,7,2,7,7,8,5,6,4,6,8,2,6},
		{6,8,2,5,3,2,3,6,1,5,5,5,8,4,6,1,4,2,3,3},
		{4,3,1,5,1,7,4,6,4,8,3,3,5,3,5,1,5,6,3,2}
	};

	for(int i=0 ; i<= M-1 ; ++i)
	{
		for(int j=0 ; j<= N-1 ; ++j)
		{
			int temp = Rr[i][j];

			for(int k=temp ; k>=1 ; --k)
			{
				if( (i+1)*N > (i*N)+(j+k) )
					g.addEdge((i*N)+j,(i*N)+j+k);
			}	
		}
	}

	for(int i=20 ; i<=M-1 ; ++i)
	{
		for(int j=20 ; j<=N-1 ; ++j)
		{
			int temp = Rr[i][j];

			for(int k=temp ; k>= 1 ; --k)
			{
				if( M-i > k )
					g.addEdge((i*N)+j-20,j-20+(k*(i+1)*N));
			}	
		}
	}
	*/

	/*
	int **R = new int*[M];
	for(int i=0 ; i<= M-1 ; ++i)
	{
		R[i] = new int[N];
		for(int j=0 ; j<= N-1 ; ++j)
		{
			cin>>R[i][j];
			int temp = R[i][j];

			for(int k=temp ; k>=1 ; --k)
			{
				if( (i+1)*N > (i*N)+(j+k) )
					g.addEdge((i*N)+j,(i*N)+j+k);
			}	
		}
	}

	int **D = new int*[M];
	for(int i=0 ; i<=M-1 ; ++i)
	{
		D[i] = new int[N];
		for(int j=0 ; j<=N-1 ; ++j)
		{
			cin>>D[i][j];
			int temp = D[i][j];

			for(int k=temp ; k>= 1 ; --k)
			{
				if( M-i > k )
					g.addEdge((i*N)+j,j+(k*(i+1)*N));
			}	
		}
	}

	*/

	//g.printGraph(g);
	g.BFS(0);

	cin.get();
	cin.get();
	return 0;
	
}

