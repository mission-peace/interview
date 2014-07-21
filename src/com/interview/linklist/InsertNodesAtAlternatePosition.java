package com.interview.linklist;

/**
 * http://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/
 * Test case
 * Size of list 1 is smaller, equal and larger than list 2
 */
public class InsertNodesAtAlternatePosition {

	public Node insert(Node head1, Node head2){
		if(head1 == null || head2 == null){
			return head2;
		}
		
		while(head1 != null && head2 != null){
			Node temp = head1.next;
			Node temp1 = head2.next;
			head1.next = head2;
			head2.next = temp;
			head2 = temp1;
			head1 = temp;
		}
		return head2;
	}
	
	public static void main(String args[]){
		LinkList ll = new LinkList();
		Node head = null;
		head = ll.addNode(1, head);
		head = ll.addNode(2, head);
		head = ll.addNode(3, head);
	
		Node head1 = null;
		head1 = ll.addNode(4, head1);
		head1 = ll.addNode(5, head1);
	/**	head1 = ll.addNode(6, head1);
		head1 = ll.addNode(7, head1);
		head1 = ll.addNode(8, head1);**/
		
		InsertNodesAtAlternatePosition ina = new InsertNodesAtAlternatePosition();
		head1 = ina.insert(head, head1);
		ll.printList(head);
		System.out.println("\n\n");
		ll.printList(head1);
	}
}
