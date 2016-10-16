#include<iostream>
#include<algorithm>
#include<list>
#include<deque>
#include<map>
#include<vector>
#include <limits>
using namespace std;

long MAXWEALTHDIFF = numeric_limits<long>::min();
class Graph
{
	long V;
	list<long> *adjList;
	bool undiGraph;

	public :

		long *WEALTHINFO;
		bool *isMgr;
		long N;
		Graph(long n,bool undiGraph);
		void addEdge(long u,long v);
		void printGraph();
		void DFS(long i);
		long _DFSutil(long i,bool visited[],int parent[],bool isFirstNode,int prevnode);
		void LongestPath(int i,int parent[]);
		void getWealthDetails(long *wealtharr,bool *ismgrarr,long count);
};
void Graph::getWealthDetails(long *wealtharr,bool *ismgrarr,long count)
{
	this->WEALTHINFO = wealtharr;
	this->isMgr = ismgrarr;
	this->N = count;
}

Graph::Graph(long n,bool Graphtype=false)
{
	this->V = n;
	this->undiGraph = Graphtype;
	adjList = new list<long>[n];
}

void Graph::addEdge(long u,long v)
{
	adjList[u].push_back(v);

	if(undiGraph)
		adjList[v].push_back(u);

}

void Graph::printGraph()
{
	for(long vertex=0 ; vertex<= V-1 ; vertex++)
	{
		cout<<"\nExploring the neighbours of vertex "<<vertex<<" : ";
		for(list<long>::iterator vCrawl = adjList[vertex].begin() ; vCrawl!=adjList[vertex].end() ; vCrawl++)
		{
			cout<<*vCrawl<<" " ;
		}
	}
}


void Graph::DFS(long i)
{
	bool *visited = new bool[V];
	int *parent = new int[V];

	for(int j=0 ; j<=V-1 ; j++)
	{
		visited[j] = false;
		parent[j] = -1;
	}

	int hojonode = i;
	int lastnodevisited = _DFSutil(i,visited,parent,true,hojonode);
}

long Graph::_DFSutil(long i,bool visited[],int parent[],bool isFirstnode,int hojonode)
{
	MAXWEALTHDIFF = max(MAXWEALTHDIFF,WEALTHINFO[hojonode]-WEALTHINFO[i]);

	visited[i]=true;
	//cout<<i<<" ";
	int lastnodevisited = i;

	for(list<long>::iterator vCrawl=adjList[i].begin() ; vCrawl!=adjList[i].end() ; vCrawl++)
	{
		if(!visited[*vCrawl])
		{
			parent[*vCrawl]=i;
			lastnodevisited = _DFSutil(*vCrawl,visited,parent,isFirstnode,hojonode);
		}
	}
	return lastnodevisited;
}

void printManagers(bool *isMgr,int N)
{
	cout<<endl;
	for(int i=0 ; i<=N-1 ; i++)
	{
		if(isMgr[i])
			cout<<i<<" is a Manager\n";
		else
			cout<<i<<" is just a reportee\n";
	}
	cout<<endl;
}

int main()
{
	long N=0;
	cin>>N;

	long *WEALTH = new long[N]();
	bool *isMgr = new bool[N]();
	int CEOid = 0;
	long temp = 0;
	map<int,int> mgr2reportee;

	for(long i=0 ; i<=N-1 ; i++)
		cin>>WEALTH[i];

	Graph g(N,false);
	for(long i=0 ; i<=N-1 ; i++)
	{
		cin>>temp;

		// Get the CEO 
		if(temp==-1)
        {
			CEOid = i;
			mgr2reportee[temp] = CEOid;
          	continue;
        }

		// Subtract 1 from ManagerID to setup Graph and Map
		--temp;
		isMgr[temp] = true;
		mgr2reportee[temp] = i;
		g.addEdge(temp,i);
		MAXWEALTHDIFF = max(MAXWEALTHDIFF,WEALTH[temp]-WEALTH[i]);
	}

	g.getWealthDetails(WEALTH,isMgr,N);
	g.DFS(CEOid);
	/*
	for(long i=0 ; i<=N-1 ; i++)
	{
		if(isMgr[i])
			g.DFS(i);
	}*/

	cout<<MAXWEALTHDIFF;
	cin.get();
	cin.get();
	return 0;
}