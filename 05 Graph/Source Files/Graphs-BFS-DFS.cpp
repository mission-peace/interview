#include<iostream>
#include<list>
using namespace std;

class Graph
{
    bool undigraph;
    list<int> *adjList;
    int V;
    
public :   
    Graph(int a,bool type);
    void addEdge(int u,int v);
    void printGraph();
    //int BFS(int v);
    //void ShortestPath();
};

Graph::Graph(int n,bool type)
{
    adjList = new list<int>[n];
    this->V = n;
    this->undigraph = type;
}

void Graph::addEdge(int u,int v)
{
    adjList[u].push_back(v);
    if(undigraph)
        adjList[v].push_back(u);
}

void Graph::printGraph()
{
    for(int i=0 ; i<=V-1 ; i++)
    {
        cout<<"\nExploring the vertices of "<<i<<endl;
        list<int>::iterator lcrawl;
        
        for(lcrawl=adjList[i].begin() ; lcrawl!=adjList[i].end() ; lcrawl++)
            cout<<*lcrawl<<" ";
    }
}

int main()
{
    Graph g(5,true);
    
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.addEdge(1,3);
    g.addEdge(4,1);
    g.printGraph();
    
    
    cin.get();
    return 0;
}
