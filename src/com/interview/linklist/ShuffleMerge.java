package com.interview.linklist;

/**
 * Given two linklist shuffle merge them.
 * e.g head1 = {1->3->5}
 * head2 = {2->4}
 * result = {1->2->3->4->5}
 * Test cases
 * head1 is null and head2 is not
 * head2 is null and head1 is not
 * both are null
 * more nodes in head1 than head2
 * more nodes in head2 than head1
 * @author tusroy
 *
 */
public class ShuffleMerge {

    public Node shuffleMerge(Node head1, Node head2){
        if(head1 == null){
            return head2;
        }
        
        if(head2 == null){
            return head1;
        }
        
        Node recur = null;
        recur = shuffleMerge(head1.next, head2.next);
        
        head1.next = head2;
        head2.next = recur;
        return head1;
    }
    
    public static void main(String args[]){
        LinkList ll = new LinkList();
        Node head1 = null;
        Node head2 = null;
        head1 = ll.addNode(1, head1);
        head1 = ll.addNode(3, head1);
        head1 = ll.addNode(5, head1);
        head1 = ll.addNode(7, head1);
        head1 = ll.addNode(9, head1);
        head2 = ll.addNode(2, head2);
        head2 = ll.addNode(4, head2);
        head2 = ll.addNode(6, head2);
        head2 = ll.addNode(8, head2);
        head2 = ll.addNode(10, head2);
        head2 = ll.addNode(12, head2);
        head2 = ll.addNode(14, head2);
        ShuffleMerge sm = new ShuffleMerge();
        Node result = sm.shuffleMerge(head1, head2);
        ll.printList(result);
    }
}
