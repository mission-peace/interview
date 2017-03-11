package com.interview.tree;

/**
 * Date 03/08/2016
 * @author Tushar Roy
 *
 * Morris inorder/preorder traversals
 * A binary tree is threaded by making all right child pointers that would normally be null 
 * point to the inorder successor of the node (if it exists), 
 * and all left child pointers that would normally be null point to the inorder predecessor of the node.
 *
 * Time complexity O(n)
 * Space complexity O(1)
 */
public class MorrisTraversal {

    public void inorder(Node root) {
        Node current = root;
        while(current != null) {
            //left is null then print the node and go to right
            if (current.left == null) {
                System.out.print(current.data + " ");
                current = current.right;
            }
            else {
                //find the predecessor.
                Node predecessor = current.left;
                //To find predecessor keep going right till right node is not null or right node is not current.
                while(predecessor.right != current && predecessor.right != null){
                    predecessor = predecessor.right;
                }
                //if right node is null then go left after establishing link from predecessor to current.
                if(predecessor.right == null){
                    predecessor.right = current; //thread predecessor.right to next inorder node 
                    current = current.left;
                // reach this line only after threading predecessor.right to current
                }else{ //left is already visit. Go right after visiting current.
                    predecessor.right = null; // remove threaded pointer
                    System.out.print(current.data + " ");
                    current = current.right; 
                }
            }
        }
    }

    // only difference is node is visited before exploring left
    public void preorder(Node root) {
        Node current = root;
        while (current != null) {
            if(current.left == null) {
                System.out.print(current.data + " ");
                current = current.right;
            }
            else {
                Node predecessor = current.left;
                while(predecessor.right != current && predecessor.right != null) {
                    predecessor = predecessor.right;
                }
                if(predecessor.right == null){
                    predecessor.right = current;
                    System.out.print(current.data + " "); // visit node before exploring left
                    current = current.left;
                }else{
                    predecessor.right = null;
                    current = current.right;
                }
            }
        }
    }

    public static void main(String args[]) {
        BinaryTree bt = new BinaryTree();
        Node root = null;
        root = bt.addNode(10, root);
        root = bt.addNode(50, root);
        root = bt.addNode(-10, root);
        root = bt.addNode(7, root);
        root = bt.addNode(9, root);
        root = bt.addNode(-20, root);
        root = bt.addNode(30, root);
        MorrisTraversal mt = new MorrisTraversal();
        mt.inorder(root);
        System.out.println();
        mt.preorder(root);
    }
}
