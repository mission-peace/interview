package com.interview.tree;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

/**
 * Date 04/16/2015
 * @author tusroy
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
 * Solution 2 : Use one deque. Technique is like above but instead of
 * using two stack use deque. Also keep count till which point you read
 * in the dequeu.
 *         
 * Time complexity is O(n) 
 * Space complexity is O(n)
 */
public class TreeTraversalInSpiralOrder {

    /**
     * Two stack to print in spiral way
     */
    public void spiralWithTwoStack(Node root) {
        if (root == null) {
            return;
        }
        Stack<Node> s1 = new Stack<Node>();
        Stack<Node> s2 = new Stack<Node>();
        s1.push(root);

        while (!s1.isEmpty() || !s2.isEmpty()) {
            while (!s1.isEmpty()) {
                root = s1.pop();
                System.out.print(root.data + " ");
                if (root.left != null) {
                    s2.push(root.left);
                }
                if (root.right != null) {
                    s2.push(root.right);
                }
            }
            while (!s2.isEmpty()) {
                root = s2.pop();
                System.out.print(root.data + " ");
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
     * One deque method to print tree in spiral order
     */
    public void spiralWithOneDeque(Node root) {
        if (root == null) {
            return;
        }
        Deque<Node> deque = new LinkedList<Node>();
        deque.offerFirst(root);
        int count = 1;
        boolean flip = true;
        while (!deque.isEmpty()) {
            int currentCount = 0;
            while (count > 0) {
                if (flip) {
                    root = deque.pollFirst();
                    System.out.print(root.data + " ");
                    if (root.left != null) {
                        deque.offerLast(root.left);
                        currentCount++;
                    }
                    if (root.right != null) {
                        deque.offerLast(root.right);
                        currentCount++;
                    }
                } else {
                    root = deque.pollLast();
                    System.out.print(root.data + " ");
                    if (root.right != null) {
                        deque.offerFirst(root.right);
                        currentCount++;
                    }
                    if (root.left != null) {
                        deque.offerFirst(root.left);
                        currentCount++;
                    }
                }
                count--;
            }
            flip = !flip;
            count = currentCount;
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
        tt.spiralWithTwoStack(root);
        System.out.println();
        tt.spiralWithOneDeque(root);
    }
}
