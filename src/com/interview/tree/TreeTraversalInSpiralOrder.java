package com.interview.tree;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

/**
 * Date 04/16/2015
 * @author tusroy
 *
 * Video link - https://youtu.be/vjt5Y6-1KsQ
 *
 * Given a root of binary tree, print in spiral order. 
 * e.g               1 
 *             2           3 
 *        4       5     6      7
 *      8   9  10    11 
 * should print 1 3 2 4 5 6 7 8 9 10 11
 *
 * Solution 1 : Use two stack. Put root in stack1. While stack1 is not
 * empty take items from stack1 and put its child left,right in stack2.
 * Then once stack1 is empty pop from stack2 and put its child right,
 * left into stack1.
 * 
 * Solution 2 : Use one dequeue. Technique is like above but instead of
 * using two stack use dequeue. Also keep count till which point you read
 * in the dequeue.
 * 
 * Solution 3: Use one dequeue. Use a delimiter to separate between one 
 * stack growing from top and another one growing from bottom.
 *         
 * Time complexity is O(n) 
 * Space complexity is O(n)
 *
 * Reference
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 */
public class TreeTraversalInSpiralOrder {

    /**
     * Two stack to print in spiral way
     */
    public void spiralWithTwoStack(Node root) {
        if (root == null) {
            return;
        }
        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();
        s1.push(root);
        // stack1's children are added to stack2
        while (!s1.isEmpty() || !s2.isEmpty()) {
            while (!s1.isEmpty()) {
                root = s1.pop();
                System.out.print(root.data + " ");
                // stack2 is built leftNode to rightNode
                if (root.left != null) {
                    s2.push(root.left);
                }
                if (root.right != null) {
                    s2.push(root.right);
                }
            }
            // stack2's children are added to stack1
            while (!s2.isEmpty()) {
                root = s2.pop();
                System.out.print(root.data + " ");
                // stack1 is built rightNode to leftNode
                if (root.right != null) {
                    s1.push(root.right);
                }
                if (root.left != null) {
                    s1.push(root.left);
                }
            }
        }
    }

    /**
     * One deque with count method to print tree in spiral order
     * flips between pollFirst, offerLast leftChildNode to rightChildNode &&
     * pollLast, offerFirst rightChildNode to leftChildNode
     */
    public void spiralWithOneDeque(Node root) {
        if (root == null) {
            return;
        }
        Deque<Node> deque = new LinkedList<Node>();
        deque.offerFirst(root);
        int remainingNodes = 1;
        boolean flip = true;
        while (!deque.isEmpty()) {
            int childrenremainingNodes = 0;
            while (remainingNodes > 0) {
                if (flip) {
                    root = deque.pollFirst();
                    System.out.print(root.data + " ");
                    if (root.left != null) {
                        deque.offerLast(root.left);
                        childrenremainingNodes++;
                    }
                    if (root.right != null) {
                        deque.offerLast(root.right);
                        childrenremainingNodes++;
                    }
                } else {
                    root = deque.pollLast();
                    System.out.print(root.data + " ");
                    if (root.right != null) {
                        deque.offerFirst(root.right);
                        childrenremainingNodes++;
                    }
                    if (root.left != null) {
                        deque.offerFirst(root.left);
                        childrenremainingNodes++;
                    }
                }
                remainingNodes--;
            } // remainingNodes == 0
            flip = !flip; // flip direction
            // childrenNodes added this cycle becomes nodes to print
            remainingNodes = childrenremainingNodes; // allows reentry of loop
        }
    }

    /**
     * One deque with delimiter to print tree in spiral order
     */
    public void spiralWithOneDequeDelimiter(Node root)
    {
        if(root == null){
            return;
        }
        Deque<Node> q = new LinkedList<>();
        q.offer(null);
        q.offerFirst(root);
        //if only delimiter(in this case null) is left in queue then break
        while(q.size() > 1){
            // in front of null, queue is built leftNode to rightNode
            root = q.peekFirst();
            while(root != null){
                root = q.pollFirst();
                System.out.print(root.data + " ");
                // build queue behindNull with beforeNull's children
                if(root.left != null){
                    q.offerLast(root.left);
                }
                if(root.right != null){
                    q.offerLast(root.right);
                }
                // continue front loop until null
                root = q.peekFirst();
            } // front node is null, enter back loop
            // behind null's queue is build rightNode to leftNode
            root = q.peekLast();
            while(root != null){
                System.out.print(root.data + " ");
                root = q.pollLast();
                // build queue beforeNull with behindNull's children
                if(root.right != null){
                    q.offerFirst(root.right);
                }
                if(root.left != null){
                    q.offerFirst(root.left);
                }
                // continue back loop until null
                root = q.peekLast();
            }
        }
    }
    public static void main(String args[]) {
        BinaryTree bt = new BinaryTree();
        Node root = null;
        root = bt.addNode(10, root);
        root = bt.addNode(30, root);
        root = bt.addNode(25, root);
        root = bt.addNode(35, root);
        root = bt.addNode(-10, root);
        root = bt.addNode(0, root);
        root = bt.addNode(-20, root);
        root = bt.addNode(-15, root);
        root = bt.addNode(45, root);

        TreeTraversalInSpiralOrder tt = new TreeTraversalInSpiralOrder();
        System.out.println("Two stack method");
        tt.spiralWithTwoStack(root);
        System.out.println("\nOne deque with count");
        tt.spiralWithOneDeque(root);
        System.out.println("\nOne deque with delimiter");
        tt.spiralWithOneDequeDelimiter(root);
    }
}
