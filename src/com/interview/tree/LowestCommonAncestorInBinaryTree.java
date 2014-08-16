package com.interview.tree;

/**
 * http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
 * Test cases:
 * Both val1 and val2 exists in the tree
 * val1 is ancestor of val2
 * val2 is ancestor of val1
 * val1 and val2 have different ancestor
 * val1 and val2 are siblings
 */
public class LowestCommonAncestorInBinaryTree {

	public Node lowestCommonAncestor(int val1, int val2,Node root){
		if(root == null){
			return null;
		}
		if(root.data == val1 || root.data == val2){
			return root;
		}
		
		Node left = lowestCommonAncestor(val1, val2, root.left);
		Node right = lowestCommonAncestor(val1, val2, root.right);
		
		if(left != null && right != null){
			return root;
		}
		return left != null ? left : right;
	}
	
	public static void main(String args[]){
		BinaryTree bt = new BinaryTree();
		Node root = null;
		root = bt.addNode(10, root);
		root = bt.addNode(25, root);
		root = 	bt.addNode(-10, root);
		root = bt.addNode(0, root);
		root = bt.addNode(-20, root);
		root = bt.addNode(15, root);
		root = bt.addNode(18, root);
		root = bt.addNode(35, root);
		
		LowestCommonAncestorInBinaryTree lca = new LowestCommonAncestorInBinaryTree();
		Node result = lca.lowestCommonAncestor(0, -20, root);
		System.out.print(result.data);
	}
}
