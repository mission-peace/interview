package com.interview.tree;

class MinMax{
	int min;
	int max;
	boolean isBST;
	int size ;
	
	MinMax(){
		min = Integer.MAX_VALUE;
		max = Integer.MIN_VALUE;
		isBST = true;
		size = 0;
	}
}

/**
 * http://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
 * Test cases
 * Entire tree is BST
 * Only leaf node is BST
 * Mix of BST and non BST nodes
 */
public class LargestBSTInBinaryTree {

	public int largestBST(Node root){
		MinMax m = largest(root);
		return m.size;
	}
	
	private MinMax largest(Node root){
		if(root == null){
			return new MinMax();
		}
		
		if(root.left == null && root.right == null){
			MinMax m = new MinMax();
			m.isBST = true;
			m.max = root.data;
			m.min = root.data;
			m.size = 1;
		}
		
		MinMax leftMinMax = largest(root.left);
		MinMax rightMinMax =largest(root.right);
		MinMax m = new MinMax();
		if(leftMinMax.isBST == false || rightMinMax.isBST == false || (leftMinMax.max > root.data || rightMinMax.min <= root.data)){
			m.isBST = false;
			m.size = Math.max(leftMinMax.size, rightMinMax.size);
			return m;
		}
		m.isBST = true;
		m.size = leftMinMax.size + rightMinMax.size + 1;
		if(rightMinMax.max == Integer.MIN_VALUE){
			m.max = root.data;
		}else{
			m.max = rightMinMax.max;
		}
		if(leftMinMax.min == Integer.MAX_VALUE){
			m.min = root.data;
		}else{
			m.min = leftMinMax.min;
		}
		return m;
	}
	
	public static void main(String args[]){
		LargestBSTInBinaryTree lbi = new LargestBSTInBinaryTree();
		ConstructTreeFromInOrderPreOrder ctf = new ConstructTreeFromInOrderPreOrder();
		int inorder[]  = {-7,-6,-5,-4,-3,-2,1,2,3,16,6,10,11,12,14};
		int preorder[] = {3,-2,-3,-4,-5,-6,-7,1,2,16,10,6,12,11,14};
		Node root = ctf.createTree(inorder, preorder);
		System.out.println(lbi.largestBST(root));
	}
}
