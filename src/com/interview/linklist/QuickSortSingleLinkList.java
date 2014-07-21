package com.interview.linklist;

/**
 * http://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
 * Test cases
 * 0 1 or more nodes
 * sorted reverse sorted nodes
 */
public class QuickSortSingleLinkList {

	public Node quickSort(Node head){
		if(head == null || head.next == null){
			return head;
		}
		Node smaller = null;
		Node larger = null;
		Node pivot = head;
		Node temp = head.next;
		pivot.next = null;
		LinkList ll = new LinkList();
		while(temp != null){
			Node next = temp.next;
			temp.next = null;
			if(temp.data < pivot.data){
				smaller = ll.addAtFront(temp, smaller);
			}else{
				larger = ll.addAtFront(temp, larger);
			}
			temp = next;
		}
		
		smaller = quickSort(smaller);
		larger = quickSort(larger);
		
		Node tail1 = smaller;
		
		while(tail1 != null && tail1.next != null){
			tail1 = tail1.next;
		}
		
		if(smaller != null){
			tail1.next = pivot;
			pivot.next = larger;
			return smaller;
		}else{
			pivot.next = larger;
			return pivot;
		}
	}
	
	public static void main(String args[]){
		QuickSortSingleLinkList qss = new QuickSortSingleLinkList();
		LinkList ll = new LinkList();
		Node head = null;
		head = ll.addNode(11, head);
		head = ll.addNode(2, head);
		head = ll.addNode(-1, head);
		head = ll.addNode(50, head);
		head = ll.addNode(13, head);
		head = ll.addNode(-5, head);
		head = ll.addNode(10, head);
		head = ll.addNode(8, head);
	
		head = qss.quickSort(head);
		ll.printList(head);
	}
}
