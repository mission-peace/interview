package com.interview.linklist;

import java.util.LinkedList;
import java.util.Queue;

/**
 * http://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/
 * Test cases
 * Zero, One or more nodes in link list
 */
public class LinkListToCompleteBinaryTree {

	public void convert(Node head){
		if(head == null){
			return;
		}
		Queue<Node> queue = new LinkedList<Node>();
		queue.offer(head);
		head = head.next;
		Node current = null;
		while(head != null){
			current = queue.poll();
			current.before = head;
			queue.offer(head);
			Node prev = head;
			head = head.next;
			//dont forget to null the next before you proceed.
			prev.next = null;
			if(head != null){
				current.next = head;
				queue.offer(head);
				prev = head;
				head = head.next;
				//dont forget to null the next before you proceed.
				prev.next = null;
			}
		}
	}
	
	public void inorder(Node head){
		if(head == null){
			return;
		}
		inorder(head.before);
		System.out.print(head.data + " ");
		inorder(head.next);
	}
	
	public static void main(String args[]){
		LinkList ll = new LinkList();
		Node head = null;
		head = ll.addNode(10, head);
		head = ll.addNode(12, head);
		head = ll.addNode(15, head);
		head = ll.addNode(25, head);
		head = ll.addNode(30, head);
		head = ll.addNode(36, head);
		head = ll.addNode(40, head);
		head = ll.addNode(45, head);
		
		LinkListToCompleteBinaryTree llct = new LinkListToCompleteBinaryTree();
		llct.convert(head);
		llct.inorder(head);
	}
}
