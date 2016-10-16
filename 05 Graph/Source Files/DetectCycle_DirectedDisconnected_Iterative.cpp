#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *adjList;
	bool undigraph;

	public : 

	Graph(int V,bool Graphtype);
	void addEdge(int u,int v);
	void printGraph();
	void detectCyclebyDFS();
	void _detectCycle(int i,bool visited[],bool stack[],int parent[]);

};

Graph::Graph(int V,bool Graphtype=false)
{
	this->V = V;
	this->undigraph = Graphtype;
	this->adjList = new list<int>[V];
}

void Graph::addEdge(int u,int v)
{
	this->adjList[u].push_back(v);

	if(this->undigraph)
		this->adjList[v].push_back(u);
}

void Graph::printGraph()
{
	cout<<endl;
	for(int vertex=0 ; vertex<=this->V-1; vertex++)
	{
		cout<<"\nExploring the neighbours of vertex "<<vertex<<" : ";
		for(list<int>::iterator vCrawl=this->adjList[vertex].begin() ; vCrawl!=this->adjList[vertex].end() ; vCrawl++)
			cout<<*vCrawl<<" ";
	}
	cout<<endl;
}

void Graph::_detectCycle(int i,bool visited[],bool stack[],int parent[])
{
	visited[i]=true;
	stack[i]=true;

	for(list<int>::iterator vCrawl=adjList[i].begin() ; vCrawl!=adjList[i].end() ; vCrawl++)
	{
		if(!visited[*vCrawl])
		{
			visited[*vCrawl]=true;
		}
	}
}

void Graph::detectCyclebyDFS()
{
	bool *visited = new bool[this->V];
	int *parent = new int[this->V];
	bool *stack = new bool[this->V];

	for(int i=0 ; i<=this->V-1 ; i++)
	{
		visited[i]=false;
		stack[i]=false;
		parent[i]=-1;
	}

	for(int vertex=0 ; vertex<=this->V-1 ; vertex++)
	{
		_detectCycle(vertex,visited,stack,parent);
	}

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

	cin.get();
}