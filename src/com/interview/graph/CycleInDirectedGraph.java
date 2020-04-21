package com.interview.graph;

import java.util.HashSet;
import java.util.Set;

/**
 * http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 */
public class CycleInDirectedGraph {

    public boolean hasCycle(Graph<Integer> graph) {
        Set<Vertex<Integer>> whiteSet = new HashSet<>();
        Set<Vertex<Integer>> graySet = new HashSet<>();
        Set<Vertex<Integer>> blackSet = new HashSet<>();

        for (Vertex<Integer> vertex : graph.getAllVertex()) {
            whiteSet.add(vertex);
        }

        while (whiteSet.size() > 0) {
            Vertex<Integer> current = whiteSet.iterator().next();
            if(dfs(current, whiteSet, graySet, blackSet)) {
                return true;
            }
        }
        return false;
    }

    private boolean dfs(Vertex<Integer> current, Set<Vertex<Integer>> whiteSet,
                        Set<Vertex<Integer>> graySet, Set<Vertex<Integer>> blackSet ) {
        //move current to gray set from white set and then explore it.
        moveVertex(current, whiteSet, graySet);
        for(Vertex<Integer> neighbor : current.getAdjacentVertexes()) {
            //if in black set means already explored so continue.
            if (blackSet.contains(neighbor)) {
                continue;
            }
            //if in gray set then cycle found.
            if (graySet.contains(neighbor)) {
                return true;
            }
            if(dfs(neighbor, whiteSet, graySet, blackSet)) {
                return true;
            }
        }
        //move vertex from gray set to black set when done exploring.
        moveVertex(current, graySet, blackSet);
        return false;
    }

    private void moveVertex(Vertex<Integer> vertex, Set<Vertex<Integer>> sourceSet,
                            Set<Vertex<Integer>> destinationSet) {
        sourceSet.remove(vertex);
        destinationSet.add(vertex);
    }

    public static void main(String args[]){
        Graph<Integer> graph = new Graph<>(true);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 3);
        graph.addEdge(4, 1);
        graph.addEdge(4, 5);
        graph.addEdge(5, 6);
        graph.addEdge(6, 4);
        CycleInDirectedGraph cdg = new CycleInDirectedGraph();
        System.out.println(cdg.hasCycle(graph));
    }
}

Python Code : 

def moveVertex(current,frm,to):
    
    frm.remove(current)
    to.append(current)

def dfs(current,white,grey,black):
    
    moveVertex(current,white,grey)
    neighbours=graph[current]
        
    for vertex in neighbours:
        
        if vertex in black:
            continue
        
        if vertex in grey:
            return True
        
        if dfs(vertex,white,grey,black):
            return True
        
    moveVertex(current,grey,black)
    return False
    
def isCyclic(n, graph):
   
    black=[]
    grey=[]
    white=[i for i in range(n)]
    
               
    while len(white)>0:
        current=white[-1]
        
        if dfs(current,white,grey,black):
            return True
    return False
    
#driver Code
#to create graph by taking input from user
def createGraph(n,arr,graph):
    i=0
    while(i<2*e):
        graph[arr[i]].append(arr[i+1])
        i+=2
 
from collections import defaultdict
if __name__ = '__main__':
    t=int(input())
    for i in range(t):
        n,e = list(map(int,input().strip().split()))
        arr = list(map(int,input().strip().split()))
        
        graph(defaultdict(list))
        
        createGraph(e,arr,graph)
        
        if isCyclic(n, graph):
            print(1)
        else:
            print(0)


