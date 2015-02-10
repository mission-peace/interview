package com.interview.tree;

/**
 * http://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/
 * Test cases
 * Empty tree
 * tree with only right childs
 * tree with only left child
 * Tree with short left and long right side
 * Tree with long left and short right side
 */
public class ConnectNodesAtSameLevel {

    public void connect(Node root){
        if(root == null){
            return;
        }
        
        if(root.left != null && root.right != null){
            root.left.next = root.right;
        }
        
        if(root.right != null){
            root.right.next = findRightSibling(root.next);
        }
        else if(root.left != null){
            root.left.next = findRightSibling(root.next);
        }
        connect(root.left);
        connect(root.right);
    }
    
    public void print(Node root){
        if(root == null){
            return;
        }
        Node temp = root;
        while(temp != null){
            System.out.println(temp.data);
            temp = temp.next;
        }
        while(root != null){
            if(root.left != null){
                print(root.left);
                break;
            }
            else if(root.right != null){
                print(root.right);
                break;
            }else{
                root = root.next;
            }
        }
    }
    
    private Node findRightSibling(Node root){
        if(root == null){
            return null;
        }
        if(root.left != null){
            return root.left;
        }
        else if(root.right != null){
            return root.right;
        }
        return findRightSibling(root.next);
    }
    
    public static void main(String args[]){
        BinaryTree bt = new BinaryTree();
        Node head = null;
        head = bt.addNode(10, head);
        head = bt.addNode(15, head);
        head = bt.addNode(5, head);
        head = bt.addNode(7, head);
        head = bt.addNode(19, head);
        head = bt.addNode(20, head);
        head = bt.addNode(-1, head);
        head = bt.addNode(21, head);
        ConnectNodesAtSameLevel cns = new ConnectNodesAtSameLevel();
        cns.connect(head);
        cns.print(head);
    }
}
