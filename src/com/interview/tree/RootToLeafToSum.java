package com.interview.tree;

import java.util.ArrayList;
import java.util.List;

/**
 * http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
 * Test cases
 * Negative number , 0 and postive number for sum
 * 0,1 or more nodes
 */
public class RootToLeafToSum {

	public void printPath(Node root, int sum){
		List<Node> path = new ArrayList<Node>();
		printPath(root,path,sum);
	}
	
	private void printPath(Node root, List<Node> path,int sum){
		if(root == null){
			return;
		}

		if(sum == root.data && root.left == null && root.right == null){
			path.add(root);
			for(Node node: path){
				System.out.println(node.data + " ");
			}
			path.remove(path.size()-1);
		}
		path.add(root);
		printPath(root.left, path,sum-root.data);
		printPath(root.right, path,sum-root.data);
		path.remove(path.size()-1);
	}
	
	public static void main(String args[]){
		RootToLeafToSum rtl = new RootToLeafToSum();
		BinaryTree bt = new BinaryTree();
		Node head = null;
		head = bt.addNode(10, head);
		head = bt.addNode(15, head);
		head = bt.addNode(5, head);
		head = bt.addNode(7, head);
		head = bt.addNode(19, head);
		head = bt.addNode(20, head);
		head = bt.addNode(-1, head);
		rtl.printPath(head, 22);
	}
}
