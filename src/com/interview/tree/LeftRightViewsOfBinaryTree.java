package com.interview.tree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 *
 * http://www.geeksforgeeks.org/print-right-view-binary-tree-2/
 * http://www.geeksforgeeks.org/print-left-view-binary-tree/
 *
 * Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.

 Right view of following tree is 1 3 7 8

        1
    /     \
    2       3
 /   \     /  \
 4     5   6    7
 \
 8


 Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from left side. Left view of following tree is 12, 10, 25.
            12
         /     \
       10       30
    /    \
 25      40

 * Created by saitejatokala on 19/01/16.
 */
public class LeftRightViewsOfBinaryTree {

    public List<List<Integer>> getLeftRightViews(Node root){

        List<Integer> rightView=new ArrayList<>();
        List<Integer> leftView=new ArrayList<>();
        LinkedList<Node> queue=new LinkedList<>();
        if(root!=null){
            queue.add(root);
        }
        while(queue.size()>0){
            int size=queue.size();
            for(int i=0;i<size;i++){
                Node top=queue.remove();
                if(i==0){
                    rightView.add(top.data);
                }
                if(i==(size-1)){
                    leftView.add(top.data);
                }
                if(top.right!=null){
                    queue.add(top.right);
                }
                if(top.left!=null){
                    queue.add(top.left);
                }
            }
        }
        List<List<Integer>> result=new ArrayList<>();
        result.add(leftView);
        result.add(rightView);
        return result;
    }

    public static void main(String[] args) {
        LeftRightViewsOfBinaryTree leftRightViewsOfBinaryTree =new LeftRightViewsOfBinaryTree();
        BinaryTree bt = new BinaryTree();
        Node head = null;
        head = bt.addNode(10, head);
        head = bt.addNode(15, head);
        head = bt.addNode(5, head);
        head = bt.addNode(7, head);
        head = bt.addNode(-1, head);
        head = bt.addNode(-4, head);
        head = bt.addNode(0, head);

        List<List<Integer>> leftRightViews = leftRightViewsOfBinaryTree.getLeftRightViews(head);

        System.out.println(leftRightViews.get(0));
        System.out.println(leftRightViews.get(1));
    }
}
