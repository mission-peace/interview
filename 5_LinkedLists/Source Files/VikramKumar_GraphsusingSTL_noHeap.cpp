#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class Edge
{
		int v;
		int weight;

	public:
		Edge(int _v, int _w) 
		{ 
			v = _v	; 
			weight = _w ;
		}
		int getV() { return v; }
		int getWeight() { return weight; }
};

class Graph
{
		int V; // No. of vertices'
		// Pointer to an array containing adjacency lists
		list<Edge> *adj;

	public:
		Graph(int V); // Constructor

		// function to add an edge to graph
		void addEdge(int u, int v, int weight);
		void Dijkstras(int src);
		int min_dist(int dist[],bool sptSet[]);

};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<Edge>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
	Edge node(v, weight);
	adj[u].push_back(node); // Add v to u's list
}

int Graph::min_dist(int dist[],bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void Graph::Dijkstras(int src)
{
	int *dist = new int[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool *sptSet = new bool[V]; // sptSet[i] will true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;
	sptSet[src] = true;
	list<Edge>::iterator i;

	
	for(i=adj[src].begin();i!=adj[src].end();i++)
	{
		if(!sptSet[i->getV()] && (dist[i->getV()] > dist[src]+i->getWeight()))
			dist[i->getV()] = dist[src]+i->getWeight();
	}

	for(int count = 0; count < V-1; count++)
	{
		int u=min_dist(dist,sptSet);
		sptSet[u] = true;
		list<Edge>::iterator i;

		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			if(!sptSet[i->getV()] && dist[u]!=INT_MAX && (dist[i->getV()] > dist[u]+i->getWeight()))
				dist[i->getV()] = dist[u]+i->getWeight();
		}
	} 

	cout<<"Vertex\t\tDistance"<<endl;
	for(int i=0;i<V;i++)
	{
		cout<<i<<"\t\t"<<dist[i]<<"\t\t";
		cout<<endl;
	}
}

int main()
{

	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(1, 0, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(7, 0, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(2, 1, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(7, 1, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 2, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(8, 2, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(5, 2, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(4, 3, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(5, 3, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 4, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 5, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(7, 6, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(8, 6, 6);
	g.addEdge(7, 8, 7);
	g.addEdge(8, 7, 7);

	int s=0;
	cout <<"Following are shortest distances from source " << s <<"\n";
	g.Dijkstras(s);

	cin.get();
	return 0;
} 