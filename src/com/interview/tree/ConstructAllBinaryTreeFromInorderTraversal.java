package com.interview.tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Date 11/07/2015
 * @author Tushar Roy
 *
 * Given an inorder traversal construct all binary search trees possible.
 * Total number of binary search tree possible is Catalan number.
 */
public class ConstructAllBinaryTreeFromInorderTraversal {

    public List<Node> construct(int inorder[]) {
        return construct(inorder, 0, inorder.length - 1);
    }

    private List<Node> construct(int inorder[], int start, int end) {
        if (start > end) {
            return Collections.singletonList(null);
        }
        List<Node> allTrees = new ArrayList<>();
        for (int root = start; root <= end; root++) {
            //get all subtrees from left and right side.
            List<Node> allLeftSubstrees = construct(inorder, start, root - 1);
            List<Node> allRightSubstrees = construct(inorder, root + 1, end);
            //iterate through them in all combination and them connect them to root
            //and add to allTrees.
            for (Node left : allLeftSubstrees) {
                for (Node right : allRightSubstrees) {
                    Node node = Node.newNode(inorder[root]);
                    node.left = left;
                    node.right = right;
                    allTrees.add(node);
                }
            }
        }
        return allTrees;
    }

    public void printAllTrees(List<Node> allTrees) {
        TreeTraversals tt = new TreeTraversals();
        System.out.println("Total number of trees " + allTrees.size());
        for(Node node : allTrees) {
            tt.inOrder(node);
            System.out.println();
            tt.preOrder(node);
            System.out.print("\n\n");
        }
    }

    public static void main(String args[]) {
        int inorder[] = {1, 2, 3, 4, 5};
        ConstructAllBinaryTreeFromInorderTraversal ct = new ConstructAllBinaryTreeFromInorderTraversal();
        List<Node> allTrees = ct.construct(inorder);
        ct.printAllTrees(allTrees);
    }
}
