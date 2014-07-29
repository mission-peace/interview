package com.interview.tree;

import java.util.Deque;
import java.util.LinkedList;

/**
 * http://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree/
 * Assumption that both a and b are unique in tree.
 * Test cases:
 * Empty tree
 * Tree with only root
 * Tree and input with a and b as cousin node
 * Tree and input with a and b not cousin node
 */
public class CousinNodes {

	public boolean areCousins(Node root,int a, int b){
		Deque<Node> queue = new LinkedList<Node>();
		queue.offerFirst(root);
		int levelSize=1;
		int tempLevelSize = 1;
		boolean foundFirst = false;
		while(!queue.isEmpty()){
			levelSize = 0;
			while(tempLevelSize > 0){
				Node node = queue.pollLast();
				if(node.data == a || node.data == b){
					if(foundFirst){
						return true;
					}
					foundFirst = true;
				}
				if(node.left!=null){
					queue.offerFirst(node.left);
					levelSize++;
				}
				if(node.right != null){
					queue.offerFirst(node.right);
					levelSize++;
				}
				tempLevelSize--;
			}
			if(foundFirst){
				return false;
			}
			tempLevelSize = levelSize;
		}
		return false;
	}
	
	public static void main(String args[]){
		BinaryTree bt = new BinaryTree();
		Node head = null;
		head = bt.addNode(10, head);
		head = bt.addNode(15, head);
		head = bt.addNode(5, head);
		head = bt.addNode(7, head);
		head = bt.addNode(19, head);
		head = bt.addNode(20, head);
		head = bt.addNode(-1, head);
		head = bt.addNode(21, head);
		head = bt.addNode(-6, head);
		CousinNodes cn = new CousinNodes();
		System.out.println(cn.areCousins(head, 10, 19));
		System.out.println(cn.areCousins(head, 19, 7));
		System.out.println(cn.areCousins(head, 19, -1));
		System.out.println(cn.areCousins(head, 19, -6));
	}
}
