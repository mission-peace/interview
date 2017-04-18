package com.interview.tree;

/**
 * Date 07/04/2014
 * @author tusroy
 *
 * Video link - https://youtu.be/rbg7Qf8GkQ4
 *
 * Write a program to insert into an AVL tree.
 * 
 * AVL tree is self balancing binary tree. Difference of height of left or right subtree
 * cannot be greater than one. A search will therefore be O(logN)
 * 
 * There are four different use cases to insert into AVL tree
 * left left - needs ones right rotation
 * left right - needs one (root.left) left and one (root) right rotation
 * right left - needs one (root.right) right and one (root) left rotation
 * right right - needs one left rotation
 * Worst case: 2 rotations throughout height of tree during insertion
 *             2*logN work, which is O(logN) time complexity
 * 
 * Follow rotation rules to keep tree balanced.
 * 
 * At every node we will also keep height of the tree so that we don't
 * have to recalculate values again.
 * 
 * Runtime complexity to insert, delete, or search AVL tree is O(logN).
 * 
 * References 
 * http://en.wikipedia.org/wiki/AVL_tree
 * http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 * 
 */
public class AVLTree {

    private Node leftRotate(Node root){
        // rotation
        Node pivot = root.right; // pivot will become new root
        // pivot is no longer root's child
        root.right = root.right.left; // root adopts child it will be replacing
        pivot.left = root; // root replaces pivot's child
        
        // update node variables
        root.height = incrementHeight(root);
        root.size = incrementSize(root);
        pivot.height = incrementHeight(pivot);
        pivot.size = incrementSize(pivot);
        return pivot; // pivot is now root
    }
    
    private Node rightRotate(Node root){
        // rotation
        Node pivot = root.left; // pivot will become new root
        // pivot is no longer root's child
        root.left = root.left.right; // root adopts child it will be replacing
        pivot.right = root; // root replaces pivot's child
        
        // update node variables
        root.height = incrementHeight(root);
        root.size = incrementSize(root);
        pivot.height = incrementHeight(pivot);
        pivot.size = incrementSize(pivot);
        return pivot; // pivot is now root
    }

    private int incrementHeight(Node root){
        if(root == null){
            return 0;
        }
        // increment height of longest branch by one
        return 1 + Math.max((root.left != null ? root.left.height : 0), 
                (root.right != null ? root.right.height : 0));
    }
    
    private int getHeight(Node root){
        if(root == null){
            return 0;
        }else {
            return root.height;
        }
    }
    
    private int incrementSize(Node root){
        if(root == null){
            return 0;
        }
        return 1 + Math.max((root.left != null ? root.left.size : 0), 
                (root.right != null ? root.right.size : 0));
    }
    
    public Node insert(Node root, int data){
        // regular binary search tree (BST) node insertion
        if(root == null){ // leaf node's child is null
            return Node.newNode(data); // insert data into leaf node's child
        }
        // recursion to find point of insertion
        if(root.data <= data){
            root.right = insert(root.right,data);
        }
        else{
            root.left = insert(root.left,data);
        }
        
        /* AVL balance in reverse recursion*/
        int balance = balance(root.left, root.right); // leftHeight - rightHeight
        if(balance > 1){ // leftHeight > rightHeight by more than 1, left case
            if(getHeight(root.left.left) >= getHeight(root.left.right)){
                // left's left > left's right = left left case, rightRotate root
                root = rightRotate(root);
            }else{
                // left case + right case = left right case
                // leftRotate leftChild, rightRotate root
                root.left = leftRotate(root.left); // leftRotate into leftLeft case
                root = rightRotate(root); //rightRotate left left case
            }
        }else if(balance < -1){ // rightHeight > leftHeight by more than 1, right case
            if(getHeight(root.right.right) >= getHeight(root.right.left)){
                // right's right > right's left = right right case, leftRotate root
                root = leftRotate(root);
            }else{
                // right's left > right's left = right left case
                // rightRotate rightChild, leftRotate root
                root.right = rightRotate(root.right); // rightRotate into rightRight case
                root = leftRotate(root); // leftRotate right right case
            }
        }
        else{ // no balance needed, update node variables
            root.height = incrementHeight(root); // 1 + max(leftBranch, rightBranch)
            root.size = incrementSize(root);
        }
        // if rotation occured, pivot is now root; else root stays as is
        return root; // return root as calling method's child
    }
    
    private int balance(Node rootLeft, Node rootRight){
        return getHeight(rootLeft) - getHeight(rootRight);
    }
    
    public static void main(String args[]){
        AVLTree avlTree = new AVLTree();
        Node root = null;
        root = avlTree.insert(root, -10);
        root = avlTree.insert(root, 2);
        root = avlTree.insert(root, 13);
        root = avlTree.insert(root, -13);
        root = avlTree.insert(root, -15);
        root = avlTree.insert(root, 15);
        root = avlTree.insert(root, 17);
        root = avlTree.insert(root, 20);
        
        TreeTraversals tt = new TreeTraversals();
        tt.inOrder(root);
        System.out.println();
        tt.preOrder(root);
    }
}
