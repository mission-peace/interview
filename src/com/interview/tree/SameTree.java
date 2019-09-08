package com.interview.tree;

/**
 * Date 04/11/2015
 * @author tusroy
 * 
 * Youtube link - https://youtu.be/ySDDslG8wws
 * 
 * Given roots of two tree, return true if they have same data and same structure
 * or return false.
 * 
 * Solution
 * Keep comparing root of both data and then recursively check left and right.
 * 
 * Time complexity is O(n)
 */
class Node
{
    int key;
    Node left,right;
    Node(int key)
    {
        this.key=key;
        left=right=null;
    }
}

class Main
{
   static  Node insert(Node temp,int data)
    {
        Node tnode=new Node(data);
        if(temp==null)
        {
            temp=tnode;
            return temp;
        }
        Node current=temp;
        Node parent=null;
        while(current!=null)
        {
          parent=current;
          if(current.key<data)
          current=current.right;
          else if(current.key>data)
          current=current.left;
        }
        if(parent.key<data)
        parent.right=tnode;
        else
        parent.left=tnode;
        return temp;
    }
    
    static void inorder(Node temp)
    {
    if(temp==null)
    return;
    inorder(temp.left);
    System.out.print(temp.key+" ");
    inorder(temp.right);
    }
    
    static boolean sametree(Node temp1,Node temp2)
    {
    if(temp1==null&&temp2==null)
    return true;
    if(temp1==null||temp2==null)
    return false;
    return temp2.key==temp1.key&&sametree(temp1.left,temp2.left)&&sametree(temp1.right,temp2.right);
    }
    public static void main(String[]args)
    {
        
        
        Node root1=null;
        root1=insert(root1,10);
        root1=insert(root1,-5);
        root1=insert(root1,16);
        root1=insert(root1,-8);
        root1=insert(root1,7);
        root1=insert(root1,18);
        System.out.print("The inorder before new insertion in the binary tree is ");
        inorder(root1);
        root1=insert(root1,6);
        System.out.print("\nThe inorder after new insertion in the binary tree is ");
        inorder(root1);
          Node root2=null;
        root2=insert(root2,10);
        root2=insert(root2,-5);
        root2=insert(root2,16);
        root2=insert(root2,-8);
        root2=insert(root2,7);
        root2=insert(root2,18);
        System.out.print("\nThe inorder before new insertion in the binary tree is ");
        inorder(root2);
        root2=insert(root2,6);
         root2=insert(root2,11);
        System.out.print("\nThe inorder after new insertion in the binary tree is ");
        inorder(root2);
        boolean a=sametree(root1,root2);
         System.out.println("\nThe ans is "+a);
    }
}
