package com.interview.tree;

import java.util.LinkedList;
import java.util.Queue;

class NodeRef{
	Node node;
}

class Node{
	Node left;
	Node right;
	Node next;
	int data;
	int lis;
	int height;
	int size;
	
	public static Node newNode(int data){
		Node n = new Node();
		n.left = null;
		n.right = null;
		n.data = data;
		n.lis = -1;
		n.height = 1;
		n.size = 1;
		return n;
	}
}

public class BinaryTree {
	public Node addNode(int data, Node head){
		Node tempHead = head;
		Node n = Node.newNode(data);
		if(head == null){
			head = n;
			return head;
		}
		Node prev = null;
		while(head != null){
			prev = head;
			if(head.data < data){
				head = head.right;
			}else{
				head = head.left;
			}
		}
		if(prev.data < data){
			prev.right = n;
		}else{
			prev.left = n;
		}
		return tempHead;
	}
	
	class IntegerRef{
		int height;
	}
	
	public int height(Node root){
		IntegerRef ir = new IntegerRef();
		heightOfTree(root,ir);
		return ir.height;
	}
	
	private void heightOfTree(Node root,IntegerRef max){
		if(root == null){
			max.height = 0;
			return;
		}
		IntegerRef irl = new IntegerRef();
		IntegerRef irr = new IntegerRef();
		heightOfTree(root.left,irl);
		heightOfTree(root.right,irr);
		max.height = Math.max(irl.height, irr.height) + 1;
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
	}
}
