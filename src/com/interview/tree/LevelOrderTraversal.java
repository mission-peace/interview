package com.interview.tree;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
 * Test cases
 * Empty tree
 * Tree with only left side
 * Tree with only right side
 * Mixed size tree
 * Full tree
 * complete tree
 */
public class LevelOrderTraversal {

	public void levelOrder(Node root){
		Queue<Node> queue = new LinkedList<Node>();
		queue.offer(root);
		System.out.println();
		while(queue.size() > 0){
			root = queue.poll();
			System.out.print(root.data + " ");
			if(root.left != null){
				queue.add(root.left);
			}
			if(root.right != null){
				queue.add(root.right);
			}
		}
	}

	public void levelOrderSpiral(Node root){
		if(root == null){
			return;
		}
		
		Deque<Node> stack1 = new LinkedList<Node>();
		Deque<Node> stack2 = new LinkedList<Node>();
		stack1.addFirst(root);
		while(!stack1.isEmpty() || !stack2.isEmpty()){
			while(!stack1.isEmpty()){
				Node node = stack1.pollFirst();
				System.out.println(node.data);
				if(node.left != null){
					stack2.addFirst(node.left);
				}
				if(node.right != null){
					stack2.addFirst(node.right);
				}
			}
			while(!stack2.isEmpty()){
				Node node = stack2.pollFirst();
				System.out.println(node.data);
				if(node.right != null){
					stack1.addFirst(node.right);
				}
				if(node.left != null){
					stack1.addFirst(node.left);
				}
			}
		}
	}
	
	public static void main(String args[]){
		LevelOrderTraversal loi = new LevelOrderTraversal();
		BinaryTree bt = new BinaryTree();
		Node head = null;
		head = bt.addNode(10, head);
		head = bt.addNode(15, head);
		head = bt.addNode(5, head);
		head = bt.addNode(7, head);
		head = bt.addNode(19, head);
		head = bt.addNode(20, head);
		head = bt.addNode(-1, head);
		loi.levelOrderSpiral(head);
	}
}
