package com.interview.graph;

import java.util.HashMap;
import java.util.Map;

/**
 http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
 */
public class PathCompressionAndRank {

	private Map<Long,Node> nodeMap = new HashMap<Long,Node>();
	
	void addNode(long id){
		Node node = new Node();
		node.id = id;
		node.rank = 1;
		node.parentNode = null;
		nodeMap.put(id,node);
	}
	
	class Node {
		Node parentNode;
		long id;
		int rank;
	}
	
	public void union(long id1, long id2){
		union(nodeMap.get(id1),nodeMap.get(id2));
	}
	
	public long find(long id){
		Node root = find(nodeMap.get(id));
		return root.id;
	}

	private void union(Node node1, Node node2) {
		Node root1 = findRoot(node1);
		Node root2 = findRoot(node2);

		if (root1.id != root2.id) {
			if (root1.rank > root2.rank) {
				root2.parentNode = root1;
				root1.rank += root2.rank;
				root2.rank = 1;
			} else {
				root1.parentNode = root2;
				root2.rank += root1.rank;
				root1.rank = 1;
			}
		}
	}

	private Node find(Node node) {
		Node root = findRoot(node);
		if (root.id != node.id) {
			node.parentNode = root;
		}
		return root;
	}

	private Node findRoot(Node node) {
		while (node.parentNode != null) {
			node = node.parentNode;
		}
		return node;
	}
}
