package com.interview.linklist;

/**
 * Find if there is loop in linklist
 * Test cases
 * 0, 1 or more elements in linklist
 * even or odd size loops
 * @author tusroy
 */
public class LoopInLinkList {

    public boolean loopExists(Node head){
        if(head == null){
            return false;
        }
        Node slow = head;
        Node fast = head.next;
        while(slow != fast && fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        if(slow == fast){
            return true;
        }
        else{
            return false;
        }
    }
    
    public static void main(String args[]){
        LinkList ll = new LinkList();
        Node head = null;
        head = ll.addNode(1, head);
        head = ll.addNode(2, head);
        head = ll.addNode(3, head);
        head = ll.addNode(4, head);
        head = ll.addNode(5, head);
        head = ll.addNode(6, head);
        head = ll.addNode(7, head);
        head = ll.addNode(8, head);
        Node node1 = ll.find(head, 8);
        Node node2 = ll.find(head, 4);
        node1.next = node2;
        LoopInLinkList lll = new LoopInLinkList();
        System.out.println(lll.loopExists(head));
        
        node2.next = null;
        System.out.println(lll.loopExists(head));
    
        node1 = ll.find(head, 3);
        node2.next = node1;
        System.out.println(lll.loopExists(head));
    }
}
