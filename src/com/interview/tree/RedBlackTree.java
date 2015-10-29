package com.interview.tree;

import java.util.Optional;

/**
 * Date 10/29/2015
 * @author Tushar Roy
 *
 * Red Black Tree
 *
 * Time complexity
 * Insert - O(logn)
 * Delete - O(logn)
 * Search - O(logn)
 *
 * References
 * http://pages.cs.wisc.edu/~skrentny/cs367-common/readings/Red-Black-Trees/
 * https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
 */
public class RedBlackTree {

    static enum Color {
        RED,
        BLACK;
    }

    static class Node {
        int data;
        Color color;
        Node left;
        Node right;
        Node parent;
    }

    private static Node createBlackNode(Node parent, int data) {
        Node node = new Node();
        node.data = data;
        node.color = Color.BLACK;
        node.parent = parent;
        return node;
    }

    private static Node createRedNode(Node parent, int data) {
        Node node = new Node();
        node.data = data;
        node.color = Color.RED;
        node.parent = parent;
        return node;
    }


    private void rightRotate(Node root, boolean changeColor) {
        Node parent = root.parent;
        root.parent = parent.parent;
        if(parent.parent != null) {
            if(parent.parent.right == parent) {
                parent.parent.right = root;
            } else {
                parent.parent.left = root;
            }
        }
        Node right = root.right;
        root.right = parent;
        parent.parent = root;
        parent.left = right;
        if(right != null) {
            right.parent = parent;
        }
        root.color = Color.BLACK;
        parent.color = Color.RED;
    }

    private void leftRotate(Node root, boolean changeColor) {
        Node parent = root.parent;
        root.parent = parent.parent;
        if(parent.parent != null) {
            if(parent.parent.right == parent) {
                parent.parent.right = root;
            } else {
                parent.parent.left = root;
            }
        }
        Node left = root.left;
        root.left = parent;
        parent.parent = root;
        parent.right = left;
        if(left != null) {
            left.parent = parent;
        }
        if(changeColor) {
            root.color = Color.BLACK;
            parent.color = Color.RED;
        }
    }

    private Optional<Node> findSiblingColor(Node root) {
        Node parent = root.parent;
        if(isLeftChild(root)) {
            return Optional.ofNullable(parent.right);
        } else {
            return Optional.ofNullable(parent.left);
        }
    }

    private boolean isLeftChild(Node root) {
        Node parent = root.parent;
        if(parent.left == root) {
            return true;
        } else {
            return false;
        }
    }

    public Node insert(Node root, int data) {
        return insert(null, root, data);
    }

    private Node insert(Node parent, Node root, int data) {
        if(root  == null) {
            if(parent != null) {
                return createRedNode(parent, data);
            } else {
                return createBlackNode(null, data);
            }
        }

        boolean isLeft;
        if(root.data >= data) {
            Node left = insert(root, root.left, data);
            if(left == root.parent) {
                return left;
            }
            root.left = left;
            isLeft = true;
        } else {
            Node right = insert(root, root.right, data);
            if(right == root.parent) {
                return right;
            }
            root.right = right;
            isLeft = false;
        }

        if(isLeft) {
            if(root.color == Color.RED && root.left.color == Color.RED) {
                Optional<Node> sibling = findSiblingColor(root);
                if(!sibling.isPresent() || sibling.get().color == Color.BLACK) {
                    if(isLeftChild(root)) {
                        rightRotate(root, true);
                    } else {
                        rightRotate(root.left, false);
                        root = root.parent;
                        leftRotate(root, true);
                    }

                } else {
                    root.color = Color.BLACK;
                    sibling.get().color = Color.BLACK;
                    if(root.parent.parent != null) {
                        root.parent.color = Color.RED;
                    }
                }
            }
        } else {
            if(root.color == Color.RED && root.right.color == Color.RED) {
                Optional<Node> sibling = findSiblingColor(root);
                if(!sibling.isPresent() || sibling.get().color == Color.BLACK) {
                    if(!isLeftChild(root)) {
                        leftRotate(root, true);
                    } else {
                        leftRotate(root.right, false);
                        root = root.parent;
                        rightRotate(root, true);
                    }
                } else {
                    root.color = Color.BLACK;
                    sibling.get().color = Color.BLACK;
                    if(root.parent.parent != null) {
                        root.parent.color = Color.RED;
                    }
                }
            }
        }
        return root;
  }

    public void printRedBlackTree(Node root, int space) {
        if(root == null) {
            return;
        }

        printRedBlackTree(root.right, space + 5);
        for(int i=0; i < space; i++) {
            System.out.print(" ");
        }
        System.out.println(root.data + " " + (root.color == Color.BLACK ? "B" : "R"));
        printRedBlackTree(root.left, space + 5);
    }

    public static void main(String args[]) {
        Node root = null;
        RedBlackTree redBlackTree = new RedBlackTree();
        root = redBlackTree.insert(root, 10);
        root = redBlackTree.insert(root, 20);
        root = redBlackTree.insert(root, 0);
        root = redBlackTree.insert(root, 25);
        root = redBlackTree.insert(root, -10);
        root = redBlackTree.insert(root, 35);
        root = redBlackTree.insert(root, 33);
        root = redBlackTree.insert(root, 34);
        root = redBlackTree.insert(root, 30);
        root = redBlackTree.insert(root, 23);
        root = redBlackTree.insert(root, 24);
        root = redBlackTree.insert(root, 5);
        root = redBlackTree.insert(root, 4);
        redBlackTree.printRedBlackTree(root, 0);
    }
}
