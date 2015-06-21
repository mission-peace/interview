package com.interview.graph;

import java.util.HashMap;
import java.util.Map;

/**
 * @author tusroy
 * Date 06/20/2015
 *  
 * Disjoint sets using path compression and union by rank
 * Supports 3 operations
 * 1) makeSet
 * 2) union
 * 3) findSet
 * 
 * For m operations and total n elements time complexity is O(m*f(n)) where f(n) is 
 * very slowly growing function. For most cases f(n) <= 4 so effectively
 * total time will be O(m). Proof in Coreman book.
 */
public class DisjointSet {

    private Map<Long, Node> map = new HashMap<>();
    
    class Node{
        long id;
        Node parent;
        int rank;
    }
    
    /**
     * Create a set with only one element.
     */
    public void makeSet(long id){
        Node node = new Node();
        node.id = id;
        node.parent = node;
        node.rank = 0;
        map.put(id,  node);
    }
    
    /**
     * Combines two sets together to one.
     * Does union by rank
     */
    public void union(long id1, long id2){
        Node node1 = map.get(id1);
        Node node2 = map.get(id2);
        
        Node parent1 = findSet(node1);
        Node parent2 = findSet(node2);
        
        //if they are part of same set do nothing
        if(parent1.id == parent2.id){
            return;
        }
        
        //else whoever's rank is higher becomes parent of other
        if(parent1.rank >= parent2.rank){
            parent1.rank += 1;
            parent2.parent = parent1;
        } else{
            parent2.rank += 1;
            parent1.parent = parent2;
        }
    }
    
    /**
     * Finds the representative of this set
     */
    public long findSet(long id){
        return findSet(map.get(id)).id;
    }
    
    /**
     * Find the representative recursively and does path
     * compression as well.
     */
    private Node findSet(Node node){
        Node parent = node.parent;
        if(parent == node){
            return parent;
        }
        node.parent = findSet(node.parent);
        return node.parent;
    }
    
    public static void main(String args[]){
       long id1 = 1;
       long id2 = 2;
       long id3 = 3;
       long id4 = 4;
       long id5 = 5;
       long id6 = 6;
       long id7 = 7;
       
       DisjointSet ds = new DisjointSet();
       ds.makeSet(id1);
       ds.makeSet(id2);
       ds.makeSet(id3);
       ds.makeSet(id4);
       ds.makeSet(id5);
       ds.makeSet(id6);
       ds.makeSet(id7);
          
       ds.union(id1, id2);
       ds.union(id3, id4);
       ds.union(id3, id5);
       ds.union(id6, id7);
        
       ds.union(id5, id7);
       ds.union(id2, id6);
       
       System.out.println(ds.findSet(id1));
       System.out.println(ds.findSet(id2));
       System.out.println(ds.findSet(id3));
       System.out.println(ds.findSet(id4));
       System.out.println(ds.findSet(id5));
       System.out.println(ds.findSet(id6));
       System.out.println(ds.findSet(id7));
       
  }
}
