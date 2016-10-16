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
		
	int vertex;
	list<int>::iterator vCrawl;

	while(!queue.empty())
	{
		vertex = queue.front();
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
		*pCrawl++;
		hops++;
		if( pCrawl==shortestpath.end() )
			break;
		
	}
	cout<<--hops<<endl;
}

int main()
{
	int M,N;
	cin>>M;
	cin>>N;

	if(M*N<=4)
	{
		cout<<(M*N)/2<<endl;
	}
	else
	{
		Graph g(M*N,true);

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
					if( N > j+k )
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
						g.addEdge((i*N)+j,j+(k+i)*N) ;
				}
			

			}
		}
	
		g.BFS(0);
	}
	return 0;
	
}

