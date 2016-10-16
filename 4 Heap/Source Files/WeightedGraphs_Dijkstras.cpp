#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <list>
using namespace std;

class Edge
{
	int v;
	int weight;

public:
	Edge(int w,int v) {this->v = v; this->weight=w;}
	int getV() {return this->v;}
	int getW() {return this->weight;}
};

class Graph
{
	int V;
	list<Edge> *adj;
	bool undirGraph;

public:
	Graph(int V,bool graphtype = false) {this->V = V; this->adj = new list<Edge>[V]; this->undirGraph=graphtype;}
	void addEdge(int u, int weight, int v);
	int minWeight(bool visited[], int distances[]);
	void Dijkstras(int src,int dest,bool breakondest);
	void printGraph();
};

void Graph::addEdge(int u,int weight, int v)
{
	Edge node(weight,v);
	adj[u].push_back(node);

	if(undirGraph)
	{
		Edge node2(weight,u);
		adj[v].push_back(node2);
	}
}

void Graph::printGraph()
{
	list<Edge>::iterator vCrawl;
	list<Edge>::iterator lCrawl;

	for(int v=0 ; v<=V-1 ; ++v)
	{
		cout<<"\nExploring the vertex : "<<v;
		cout<<"\nThe neighbouring vertices are : ";

		for(vCrawl = adj[v].begin() ; vCrawl != adj[v].end() ; vCrawl++)
		{
			cout<<"{w:"<<vCrawl->getW()<<"}  ";
			cout<<vCrawl->getV()<<"   ";

		}
	}
}

int Graph::minWeight(bool visit[], int dist[])
{
	int least = INT_MAX;
	int index = 0;

	for(int v=0 ; v<=V-1 ; ++v)
		if(!visit[v] && dist[v] < least)
			least=dist[v],index =v;

	return index;
}

void Graph::Dijkstras(int src,int dest=0,bool breakondest=false)
{
	
	if(breakondest)
	{
		bool destfound = false;
		for(int v=0 ; v<=V-1 ; v++)
		{
			if(dest==v)
				destfound=true;
		}
		if(!destfound)
		{
			cout<<"\n\n\n Destination Vertex not found! No pointing in bugging Dijsktra...\n";
			//cout<<"NO";
			return;
		}
	}
	//cout<<"YES"<<endl;

	// STEP 1 : Initialization - set up arrays
	bool *visited = new bool[V];
	int *distances = new int[V];

	for(int v=0 ; v<=V-1 ; ++v)
	{
		visited[v] = false;
		distances[v] = INT_MAX;
	}

	// STEP 2 : Mark the source as visited and distance as 0, UPDATE THE NEIGHBOURS of source otherwise the code fails
	visited[src] = true;
	distances[src] = 0;

	list<Edge>::iterator lCrawl;
	for(lCrawl=adj[src].begin() ; lCrawl!=adj[src].end(); ++lCrawl)
	{
		if(!visited[lCrawl->getV()] && distances[lCrawl->getV()] > distances[src]+lCrawl->getW())
			distances[lCrawl->getV()] = distances[src]+lCrawl->getW();
	}

	// STEP 3 : Visit every other vertex and Update the cost
	for(int v=0 ; v<=V-1 ; ++v)
	{
		int j = minWeight(visited,distances);
		visited[j] = true;

		for(list<Edge>::iterator k = adj[j].begin() ; k!=adj[j].end() ; ++k)
		{
			if(!visited[k->getV()] && distances[k->getV()] > distances[j]+k->getW())
				distances[k->getV()] = distances[j]+k->getW() ;
		}

		if(breakondest && distances[dest]!=INT_MAX && visited[dest])
			break;
	}

	// STEP 4 : Print distances[] which has the Single Source Shortest Path (or) Print the shortest distance btwn src and dest
	if(!breakondest)
	{
		cout<<"\n\nVertex\t\t\t"<<"Distance\n";
		for(int v=0 ; v<=V-1 ; ++v)
		{	
			cout<<v<<"\t\t\t"<<distances[v]<<endl;
		}
	}
	else
	{
		cout<<"\n\n\nThe shortest distance between betwn src "<<src<<" and dest "<<dest<<" is : "<<distances[dest]<<endl;
		//cout<<distances[dest];
	}

}

int main()
{
	Graph g(9,true);

	g.addEdge(0,4,1);
	g.addEdge(0,8,7);
	g.addEdge(1,8,2);
	g.addEdge(1,11,7);
	g.addEdge(2,7,3);
	g.addEdge(2,2,8);
	g.addEdge(7,7,8);
	g.addEdge(7,1,6);
	g.addEdge(8,6,6);
	g.addEdge(6,2,5);
	g.addEdge(2,4,5);
	g.addEdge(3,14,5);
	g.addEdge(5,10,4);
	g.addEdge(3,9,4);

	g.printGraph();

	int src  = 0;
	int dest = 7;
	g.Dijkstras(src,dest);

	cin.get();
	return 0;
}
