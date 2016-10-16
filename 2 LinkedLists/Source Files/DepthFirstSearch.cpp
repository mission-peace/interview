#include<iostream>
#include<algorithm>
#include<list>
#include<deque>
using namespace std;

class Graph
{
	int V;
	list<int> *adjList;
	bool undiGraph;

	public :

		Graph(int n,bool undiGraph);
		void addEdge(int u,int v);
		void printGraph();
		void DFS(int i);
		int _DFSutil(int i,bool visited[],int parent[]);
		void LongestPath(int i,int parent[]);
};

Graph::Graph(int n,bool Graphtype=false)
{
	this->V = n;
	this->undiGraph = Graphtype;
	adjList = new list<int>[n];
}

void Graph::addEdge(int u,int v)
{
	adjList[u].push_back(v);

	if(undiGraph)
		adjList[v].push_back(u);

}

void Graph::printGraph()
{
	for(int vertex=0 ; vertex<= V-1 ; vertex++)
	{
		cout<<"\nExploring the neighbours of vertex "<<vertex<<" : ";
		for(list<int>::iterator vCrawl = adjList[vertex].begin() ; vCrawl!=adjList[vertex].end() ; vCrawl++)
		{
			cout<<*vCrawl<<" " ;
		}
	}
}


void Graph::DFS(int i)
{
	bool *visited = new bool[V];
	int *parent = new int[V];

	for(int j=0;j<=V-1 ; j++)
	{
		visited[j] = false;
		parent[j] = -1;
	}

	int lastnodevisited = _DFSutil(i,visited,parent);
	cout<<"\nThe Last node visited is : "<<lastnodevisited;
	//LongestPath(lastnodevisited,parent);
}

int Graph::_DFSutil(int i,bool visited[],int parent[])
{
	visited[i]=true;
	cout<<i<<" ";
	int lastnodevisited = i;

	for(list<int>::iterator vCrawl=adjList[i].begin() ; vCrawl!=adjList[i].end() ; vCrawl++)
	{
		if(!visited[*vCrawl])
		{
			parent[*vCrawl]=i;
			lastnodevisited = _DFSutil(*vCrawl,visited,parent);
		}
	}

	return lastnodevisited;
}

void main()
{
	Graph g1(4);

	g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(3, 3);
 
	g1.printGraph();
	cout<<endl;
	cout<<"\nDFS of "<<0<<" is : ";
	g1.DFS(0);
	cout<<"\nDFS of "<<1<<" is : ";
	g1.DFS(1);
	cout<<"\nDFS of "<<2<<" is : ";
	g1.DFS(2);
	cout<<"\nDFS of "<<3<<" is : ";
	g1.DFS(3);

	cout<<"\n\n\n NEXT GRAPH";

	Graph g2(5,true);

    g2.addEdge(0, 1);
    g2.addEdge(0, 4);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);
    g2.addEdge(1, 4);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
 
	g2.printGraph();
	cout<<endl;
	cout<<"\nDFS of "<<0<<" is : ";
	g2.DFS(0);
	cout<<"\nDFS of "<<1<<" is : ";
	g2.DFS(1);
	cout<<"\nDFS of "<<2<<" is : ";
	g2.DFS(2);
	cout<<"\nDFS of "<<3<<" is : ";
	g2.DFS(3);
	cout<<"\nDFS of "<<4<<" is : ";
	g2.DFS(4);

	cin.get();
}