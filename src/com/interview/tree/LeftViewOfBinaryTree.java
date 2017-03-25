package com.interview.tree;

/**
 * Created by saitejatokala on 03/12/15.
 *
 * Print Left View of a Binary Tree
 Given a Binary Tree, print left view of it. Left view of a Binary Tree
 is set of nodes visible when tree is visited from left side.
 Left view of following tree is 12, 10, 25.

          12
        /   \
      10    30
           /  \
          25  40

 Solution:
 The problem can also be solved using
 simple recursive traversal. We can keep track of level
 of a node by passing a parameter to all recursive calls.
 The idea is to keep track of maximum level also.
 Whenever we see a node whose level is more than
 maximum level so far, we print the node because
 this is the first node in its level
 (Note that we traverse the left subtree before
 right subtree).

 References : http://www.geeksforgeeks.org/print-left-view-binary-tree/


 */

class BNode{


    int data;
    BNode left;
    BNode right;
    public static BNode newNode(int data) {
        BNode n = new BNode();
        n.left = null;
        n.right = null;
        n.data = data;
        //s
        return n;
    }

}
public class LeftViewOfBinaryTree {

    class Maxlevel {
        int maxLevel;

    }
    //First Type of Implementation
    public void leftView1(BNode root){
        Maxlevel maxlevel=new Maxlevel();
        maxlevel.maxLevel=Integer.MIN_VALUE;
        leftView1(root,0,maxlevel);
    }
    private void leftView1(BNode root,int level,Maxlevel maxLevel){
        if(root==null){
            return ;
        }
        if(level>maxLevel.maxLevel){
            System.out.println(root.data);
            maxLevel.maxLevel=level;
        }
        leftView1(root.left,level+1,maxLevel);
        leftView1(root.right,level+1,maxLevel);
    }

    //2nd Type of Implementation
    public void leftView(BNode root){
        leftView(root,0,Integer.MIN_VALUE);
    }

    private int leftView(BNode root,int level,int maxLevel){
        if(root==null){
            return maxLevel;
        }
        if(level>maxLevel){
            System.out.println(root.data);
            maxLevel=level;
        }
        int lm=leftView(root.left,level+1,maxLevel);
        int rm=leftView(root.right,level+1,lm);
        return Math.max(lm,rm);
    }
    public static void main(String[] args){
        BNode root=BNode.newNode(12);
        root.left=BNode.newNode(10);
        root.right=BNode.newNode(30);
        root.right.left=BNode.newNode(25);
        root.right.right=BNode.newNode(40);

        LeftViewOfBinaryTree leftViewOfBinaryTree=new LeftViewOfBinaryTree();
        leftViewOfBinaryTree.leftView(root);
        System.out.println("-------");
        leftViewOfBinaryTree.leftView1(root);

    }
}
