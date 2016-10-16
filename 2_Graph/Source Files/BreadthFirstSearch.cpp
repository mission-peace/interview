#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	bool undiGraph;
	list<int> *adjList;

	public:
		Graph(int V,bool undiGraph);
		void addEdge(int u,int v);
		void printGraph(Graph G);
		void BFS(int i);
		void ShortestPath(int vertex,int parent[]);
};

Graph::Graph(int V,bool Graphtype=false)
{
	this->V = V;
	this->undiGraph = Graphtype;
	adjList = new list<int>[V];
}

void Graph::addEdge(int u,int v)
{
	adjList[u].push_back(v);

	if(this->undiGraph)
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
		
	cout<<"\n\nBFS of "<<i<<" is : ";
	int vertex;
	list<int>::iterator vCrawl;

	while(!queue.empty())
	{
		vertex = queue.front();
		cout<<vertex<<" ";
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
	cout<<"\n The Shortest Path found using BFS is : ";
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
		hops++;
		if( pCrawl==shortestpath.end() )
			break;
		else
			cout<<" -> ";
		
	}
	cout<<"\n The no. of Hops made = "<<hops;
}



void main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
	g.printGraph(g);

	g.BFS(0);
	g.BFS(1);
	g.BFS(2);
	g.BFS(3);


	
	cout<<"\n\n\n NEXT GRAPH";

	Graph g2(5,true);
    g2.addEdge(0, 1);
	//g2.addEdge(1, 0);
    g2.addEdge(0, 4);
	//g2.addEdge(4, 0);
    g2.addEdge(1, 2);
	//g2.addEdge(2, 1);
    g2.addEdge(1, 3);
	//g2.addEdge(3, 1);
    g2.addEdge(1, 4);
	//g2.addEdge(4, 1);
    g2.addEdge(2, 3);
	//g2.addEdge(3, 2);
    g2.addEdge(3, 4);
	//g2.addEdge(4, 3);
 
	g2.printGraph(g2);
	g2.BFS(0);
	g2.BFS(1);
	g2.BFS(2);
	g2.BFS(3);
	g2.BFS(4);

	cin.get();
}