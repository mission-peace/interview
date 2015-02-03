package com.interview.linklist;

/**
 * http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
 * Empty list
 * 1 or more nodes list
 */
public class CopyLinkListWIthArbitPointer {

    public Node copy(Node head){
        if(head == null){
            return null;
        }
        
        Node current = head;
        //create new node with same value as current and insert it after current
        while(current != null){
            Node newNode = Node.newNode(current.data);
            newNode.next = current.next;
            newNode.child = current.child;
            current.next = newNode;
            current = newNode.next;
        }
        //copy arbit position of current for the copy
        current = head;
        while(current != null){
            current.next.child = current.child.next;
            current = current.next.next;
        }
        
        //now separate copy from the main list
        Node newHead = null;
        Node newCurrent = null;
        current = head;
        while(current != null){
            if(newHead == null){
                newHead = current.next;
                current.next = current.next.next;
                newCurrent = newHead;
            }else{
                newCurrent.next = current.next;
                current.next = current.next.next;
                newCurrent = newCurrent.next;
            }
            current = current.next;
        }
        return newHead;
    }
    
    public void printList(Node head){
        while(head != null){
            System.out.println(head.data + " " + head.child.data);
            head = head.next;
        }
    }
    
    public static void main(String args[]){
        LinkList ll = new LinkList();
        Node head = null;
        head = ll.addNode(1, head);
        head = ll.addNode(2, head);
        head = ll.addNode(3, head);
        head = ll.addNode(4, head);
        Node n1 = ll.find(head,1);
        Node n2 = ll.find(head,2);
        Node n3 = ll.find(head,3);
        Node n4 = ll.find(head,4);
        
        n1.child = n2;
        n2.child = n4;
        n3.child = n1;
        n4.child = n1;
        
        CopyLinkListWIthArbitPointer cll = new CopyLinkListWIthArbitPointer();
        Node newHead = cll.copy(head);
        cll.printList(head);
        cll.printList(newHead);
    }
}
