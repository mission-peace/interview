package com.interview.tree;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Date 04/11/2015
 * @author tusroy
 * 
 * Youtube link - https://youtu.be/MILxfAbIhrE
 * 
 * Given a binary tree, return true if it is binary search tree else return false.
 * 
 * Solution
 * Keep min, max for every recursion. Initial min and max is very small and very larger
 * number. Check if root.data is in this range. When you go left pass min and root.data and 
 * for right pass root.data and max.
 * 
 * Time complexity is O(n) since we are looking at all nodes.
 * 
 * Test cases:
 * Null tree
 * 1 or 2 nodes tree
 * Binary tree which is actually BST
 * Binary tree which is not a BST
 */
public class IsBST {

    public boolean isBST(Node root){
        return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    private boolean isBST(Node root, int min, int max){
        if(root == null){
            return true;
        }
        // if node fails to fall in expected range, return false
        if(root.data <= min || root.data > max){
            return false;
        }
        // when traversing tree, reduce expected range of node based on previously traversed nodes
        return isBST(root.left, min, root.data) && isBST(root.right, root.data, max);
    }

    // inOrder traversal of BST is sorted
    // left->root->right
    public boolean isBSTIterative(Node root) {
        if (root == null) {
            return true;
        }

        // double ended queue, supports insertion & removals from both ends
        Deque<Node> stack = new LinkedList<>();
        Node node = root;
        int prev = Integer.MIN_VALUE;
        int current;
        while ( true ) {
            // traverse down left side of tree
            if (node != null) {
                // add left node in front of queue
                stack.addFirst(node);
                node = node.left;
            } else {
                // exit condition
                if (stack.isEmpty()) {
                    break;
                }
                // since every left node is added to front of queue,
                // nodes in queue should be in increasing order
                node = stack.pollFirst();
                current = node.data;
                if (current < prev) {
                    return false;
                }
                prev = current;
                // traverse right after left is exhausted
                node = node.right;
                // after right node is queued,
                // loop traverses down left nodes
                // adding each left node to front of queue
                // pushing back greater values
            }
        }
        return true;
    }
    
    public static void main(String args[]){
        BinaryTree bt = new BinaryTree();
        Node root = null;
        root = bt.addNode(10, root);
        root = bt.addNode(15, root);
        root = bt.addNode(-10, root);
        root = bt.addNode(17, root);
        root = bt.addNode(20, root);
        root = bt.addNode(0, root);
        
        IsBST isBST = new IsBST();
        assert isBST.isBST(root);
        assert isBST.isBSTIterative(root);
    }
}
