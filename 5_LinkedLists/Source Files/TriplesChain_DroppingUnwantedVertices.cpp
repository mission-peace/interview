#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <vector> 
#include <iterator>
using namespace std; 

struct VectorizeRow 
{ 
	const size_t size; 
	VectorizeRow(size_t s) : size(s) {} 
	vector<int> operator()(const int* a) const 
	{ 	return vector<int>(a, a+size);	} 
}; 

struct FirstColumnOnlyCmp
{
    bool operator()(const std::vector<int>& lhs,
                    const std::vector<int>& rhs) const
    {
        return lhs[0] < rhs[0];
    }
};

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
	void Dijkstras(int src,int dest,bool printDijkstra);
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

struct min_heap
{
	bool operator()(int i, int j)
	{return i > j ; }
};



void Graph::Dijkstras(int src,int dest,bool printDijkstra=true)
{
	// STEP 1 : Initialization - set up arrays
	bool *visited = new bool[V];
	int *distances = new int[V];

	map<int,int> hashDistances;
	priority_queue<int,vector<int>,min_heap> minHeapDistances;

	for(int v=0 ; v<=V-1 ; ++v)
	{
		visited[v] = false;
		distances[v] = INT_MAX;
	}
  

	// STEP 2 : Mark the source as visited and distance as 0, UPDATE THE NEIGHBOURS of source otherwise the code fails
	visited[src] = true;
	distances[src] = 0;
	hashDistances[src] = 0;

	list<Edge>::iterator lCrawl;
	for(lCrawl=adj[src].begin() ; lCrawl!=adj[src].end(); ++lCrawl)
	{
		if(!visited[lCrawl->getV()] && distances[lCrawl->getV()] > distances[src]+lCrawl->getW())
		{
			distances[lCrawl->getV()] = distances[src]+lCrawl->getW();
			hashDistances[lCrawl->getV()] = distances[lCrawl->getV()]; 
			minHeapDistances.push(distances[lCrawl->getV()]);
		}
	}

  
	// STEP 3 : Visit every other vertex and Update the cost
	for(int v=0 ; v<=V-1 ; ++v)
	{
		//int j = minWeight(visited,distances);

		int minheaptop = minHeapDistances.top();
		int key=0;

		map<int,int>::iterator it;
		for(it=hashDistances.begin() ; it!=hashDistances.end() ; ++it)
		{
			if(it->second == minheaptop)
			{
				key = it->first;
				hashDistances.erase(it);
				break;
			}
		}

		minHeapDistances.pop();
		visited[key] = true;

		for(list<Edge>::iterator k = adj[key].begin() ; k!=adj[key].end() ; ++k)
		{
			if(!visited[k->getV()] && distances[k->getV()] > distances[key]+k->getW())
			{
				distances[k->getV()] = distances[key]+k->getW() ;
				hashDistances[k->getV()]=distances[k->getV()];
				minHeapDistances.push(distances[k->getV()]);
			}
		}

		if(distances[dest]!=INT_MAX && visited[dest])
			break;
	}

  
	// STEP 4 : Print distances[] which has the Single Source Shortest Path (or) Print the shortest distance btwn src and dest
	if(printDijkstra)
	{
		cout<<"\n\nVertex\t\t\t"<<"Distance\n";
		for(int v=0 ; v<=V-1 ; ++v)
		{	
			cout<<v<<"\t\t\t"<<distances[v]<<endl;
		}
		cout<<"\n\n\nThe shortest distance between betwn src "<<src<<" and dest "<<dest<<" is : "<<distances[dest]<<endl;
	}
	else
		cout<<distances[dest]<<endl;

}

int main()
{
	int chainscount = 0;
	int src = 0;
	int dest = 0;

	cin>>chainscount;
	cin>>src;
	cin>>dest;

	if(chainscount < 1)
		cout<<"NO"<<endl;
	else
	{

		int **chains = new int*[chainscount];
		list<int> vertexList;
		map<int,int> vertexTable;
		int verticescount = 0 ;

		for(int i=0 ; i<=chainscount-1 ; i++)
		{
			chains[i] = new int[3];

			cin>>chains[i][0];
			cin>>chains[i][1];
			cin>>chains[i][2];

			if(vertexTable.empty())
				vertexTable[chains[i][0]] = verticescount++;
			if(vertexTable.find(chains[i][0])==vertexTable.end())
				vertexTable[chains[i][0]] = verticescount++;
			if(vertexTable.find(chains[i][2])==vertexTable.end())
				vertexTable[chains[i][2]] = verticescount++;

		}
		vector<vector<int> > v1; 

		transform(chains, chains+chainscount, back_inserter(v1), VectorizeRow(3)); 

		sort(v1.begin(),v1.end(),FirstColumnOnlyCmp());

		int subtract = 0;

		int i = 1;
		int size = v1.size();

		for(i =1 ; i<= size-1 ; i++)
		{

			if(v1[i][0] == v1[i-1][0] && v1[i][2]== v1[i-1][2])
			{
				if( v1[i-1][1]>= 0 && v1[i][1]>=0  && v1[i-1][1] <= v1[i][1])
				{
					v1[i][1] = -1;
					int temp = v1[i][1];
					v1[i][1] = v1[i-1][1];
					v1[i-1][1] = temp;

					subtract++;
				}
				else if(v1[i-1][1]>= 0 && v1[i][1]>=0 && v1[i][1] <= v1[i-1][1])
				{
					v1[i-1][1] = -1;
					subtract++;
				}
			}
		}

		int noofvertices = verticescount-subtract;
	
		Graph g(noofvertices,true);

		for(int i=0 ; i<=chainscount-1 ; i++)
		{
			if(v1[i][1]!= -1)
				g.addEdge(vertexTable[v1[i][0]],v1[i][1],vertexTable[v1[i][2]]);
		}
     
		g.printGraph();

		if(vertexTable.find(dest)==vertexTable.end() || vertexTable.find(src)==vertexTable.end())
			cout<<"NO"<<endl;
		else
        {
            cout<<"YES"<<endl;
			g.Dijkstras(vertexTable[src],vertexTable[dest],true);
        }
      
	}
	cin.get();
	cin.get();
	return 0;
}


