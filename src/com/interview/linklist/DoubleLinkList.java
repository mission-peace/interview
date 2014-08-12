package com.interview.linklist;

public class DoubleLinkList {

	public Node addNode(Node head,int data){
		if(head == null){
			head = Node.newNode(data);
			return head;
		}
		Node newNode = Node.newNode(data);
		Node current = head;
		while(current.next != null){
			current = current.next;
		}
		current.next = newNode;
		newNode.before = current;
		return head;
	}
	
	public void print(Node head){
		while(head != null){
			System.out.print(head.data + " ");
			head = head.next;
		}
	}
	
	public static void main(String args[]){
		DoubleLinkList dll = new DoubleLinkList();
		Node head = null;
		head = dll.addNode(head,1);
		head = dll.addNode(head,2);
		head = dll.addNode(head,3);
		head = dll.addNode(head,4);
		head = dll.addNode(head,5);
		dll.print(head);
	}
}
