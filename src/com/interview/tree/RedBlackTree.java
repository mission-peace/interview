package com.interview.tree;

import java.util.Optional;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

/**
 * Date 10/29/2015
 * @author Tushar Roy
 *
 * Red Black Tree
 * self balancing binary search tree (BST) 
 * with less restrictive balancing conditions than AVL
 * less restrictions means less rotation 
 * thus more preferred than AVL
 * 
 * Rules:
 * 1) Root is black
 * 2) No red-red parent-child
 * 3) Number of black nodes from root to node with less than 2 children is same
 *        meaning node has null child
 * This limits the longest height from being greater than twice the shortest height
 * Worst case: 
 *  longest height:  2 * k == (k * Black) + (k * Red), where Black:Red is 1:1
 *  shortest height: 1 * k == (k * Black), no Red
 * 
 * Time complexity because of rules,
 * Insert - O(logn)
 * Delete - O(logn)
 * Search - O(logn)
 * Rotation - O(1)
 * 
 * Java's TreeMap is a Red-Black tree based NavigableMap implementation.
 *
 * Does not work for duplicates.
 *
 * References
 * http://pages.cs.wisc.edu/~skrentny/cs367-common/readings/Red-Black-Trees/
 * https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
 */
public class RedBlackTree {

    public enum Color {
        RED,
        BLACK
    }

    public static class Node {
        int data;
        Color color;
        Node left;
        Node right;
        Node parent; // used to get sibling's color
        boolean isNullLeaf;
    }

    private static Node createBlackNode(int data) {
        Node node = new Node();
        node.data = data;
        node.color = Color.BLACK;
        node.left = createNullLeafNode(node);
        node.right = createNullLeafNode(node);
        return node;
    }

    // leaf nodes have black null-nodes as children instead of just null values
    private static Node createNullLeafNode(Node parent) {
        Node leaf = new Node();
        leaf.color = Color.BLACK; // null leafs are black
        leaf.isNullLeaf = true;
        leaf.parent = parent;
        return leaf;
    }

    private static Node createRedNode(Node parent, int data) {
        Node node = new Node();
        node.data = data;
        node.color = Color.RED;
        node.parent = parent;
        // null leaf nodes are black without value data
        node.left = createNullLeafNode(node);
        node.right = createNullLeafNode(node);
        return node;
    }

    /**
     * Main insert method of red black tree.
     */
    public Node insert(Node root, int data) {
        return insert(null, root, data);
    }

    /**
     * Main delete method of red black tree.
     */
    public Node delete(Node root, int data) {
        // pointer to root initially null
        AtomicReference<Node> rootReference = new AtomicReference<>();
        delete(root, data, rootReference);
        if(rootReference.get() == null) {
            // root pointer still null because root never changed
            return root;
        } else {
            // return dereferenced root
            return rootReference.get();
        }
    }

    /**
     * Main print method of red black tree.
     */
    public void printRedBlackTree(Node root) {
        printRedBlackTree(root, 0);
    }

    /**
     * Main validate method of red black tree.
     */
    public boolean validateRedBlackTree(Node root) {

        if(root == null) {
            return true;
        }
        //check if root is black
        if(root.color != Color.BLACK) {
            System.out.print("Root is not black");
            return false;
        }
        //Use of AtomicInteger solely because java does not provide any other mutable int wrapper.
        AtomicInteger blackCount = new AtomicInteger(0);
        //make sure black count is same on all path and there is no red red relationship
        return checkBlackNodesCount(root, blackCount, 0) 
                && noRedRedParentChild(root, Color.BLACK);
    }

    // last rotation changes color
    // if 2 rotations, 1st rotation doesn't change color
    private void rightRotate(Node pivot, boolean changeColor) {
        Node root = pivot.parent; // old root
        pivot.parent = root.parent; // update pivot's parent
        if(root.parent != null) {
            // determine if root is rightChild or leftChild of parent
            // so pivot can replace root on correct side of parent
            if(root.parent.right == root) {
                root.parent.right = pivot;
            } else {
                root.parent.left = pivot;
            }
        }
        Node pivotsRight = pivot.right;
        pivot.right = root; // root is now pivot's rightChild
        root.parent = pivot; // pivot is now root's parent
        root.left = pivotsRight; // root adopts child it replaced
        if(pivotsRight != null) {
            pivotsRight.parent = root;
        }
        if(changeColor) {
            pivot.color = Color.BLACK;
            root.color = Color.RED;
        }
    }
    
    // last rotation changes color
    // if 2 rotations, 1st rotation doesn't change color
    private void leftRotate(Node pivot, boolean changeColor) {
        Node root = pivot.parent; // old root
        pivot.parent = root.parent; // update pivot's parent
        if(root.parent != null) {
            // determine if root is rightChild or leftChild of parent
            // so pivot can replace root on correct side of parent
            if(root.parent.right == root) {
                root.parent.right = pivot;
            } else {
                root.parent.left = pivot;
            }
        }
        Node pivotsLeft = pivot.left;
        pivot.left = root; // root is now pivot's leftChild
        root.parent = pivot; // pivot is now root's parent
        root.right = pivotsLeft; // root adopts child it replaced
        if(pivotsLeft != null) {
            pivotsLeft.parent = root;
        }
        if(changeColor) {
            pivot.color = Color.BLACK;
            root.color = Color.RED;
        }
    }

    private Optional<Node> findSiblingNode(Node root) {
        Node parent = root.parent;
        if(isLeftChild(root)) {
            return Optional.ofNullable(parent.right.isNullLeaf ? null : parent.right);
        } else {
            return Optional.ofNullable(parent.left.isNullLeaf ? null : parent.left);
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

    /**
     * 1) If empty tree, create black root node
     * 2) Insert new leaf node as red, check for red-red conflict
     *   a. If its parent is black, then done (no conflict)
     *   b. If parent is red (conflict):
     *        if black or absent sibling: rotate, recolor, and done
     *        if red sibling: recolor (parent, parent's sibling, & next node up) 
     *                        and recursively check next node up. 
     *                        Do not recolor root to red.
     * Recoloring red siblings and their parent pushes the black down
     *  and the red up. This keeps black count the same. No rotation needed.
     * If red parent has no sibling or black sibling rotate like AVL. 
     * Use red-red relationship similar to AVL case. 
     * Final pivot swap colors with final root. All others remain the same.
     * New root is black, children are red so no need to check upwards
     *  since a black root can't have a red-red conflict.
     * RedBlack tree will do at most 2 rotations, 
     *  whereas AVL can do 2 * height rotations
     */
    private Node insert(Node parent, Node root, int data) {
    // parent is needed since relationship is not yet established
        if(root  == null || root.isNullLeaf) {
            //if parent is not null means tree is not empty
            //so create a red leaf node
            if(parent != null) {
                return createRedNode(parent, data);
            } else { //otherwise create a black root node if tree is empty
                return createBlackNode(data);
            }
        }

        //duplicate insertion is not allowed for this tree.
        if(root.data == data) {
            throw new IllegalArgumentException("Duplicate date " + data);
        }
        //if we go on left side then isLeft will be true
        //if we go on right side then isLeft will be false.
        boolean isLeft;
        // recursively traverse down tree
        if(root.data > data) {
            // left is result of recursion, could be:
            //     same, new node, or the resulting root after rotation
            // in recursion: root is now parent, left child is now subtree's root
            Node left = insert(root, root.left, data);
            //if left becomes root's parent, it means rotation happened
            //at left lower level. Root is no longer parent of left
            //So just return left so that nodes at upper level can set their
            //child correctly
            if(left == root.parent) {
                return left;
            }
            //else set the left child returned to be left of root node
            root.left = left;
            //set isLeft to be true
            isLeft = true;
        } else {
            // right is result of recursion, could be:
            //     same, new node, or the resulting root after rotation
            // in recursion: root is now parent, right child is now subtree's root
            Node right = insert(root, root.right, data);
            //if right becomes root's parent, it means rotation happened
            //at right lower level. Root is no longer parent of right
            //So just return right so that nodes at upper level can set their
            //child correctly
            if(right == root.parent) {
                return right;
            }
            // else set the right child returned to be right of root node
            root.right = right;
            //set isRight to be true
            isLeft = false;
        }

        if(isLeft) {
            //if we went to left side check to see Red-Red conflict
            //between root and its left child
            if(root.color == Color.RED 
                    && root.left.color == Color.RED) {
                //get the sibling of root. It is returning optional means
                //sibling could be empty
                Optional<Node> sibling = findSiblingNode(root);
                //if sibling is empty or of BLACK color
                // rotation scenario
                if(!sibling.isPresent() 
                        || sibling.get().color == Color.BLACK) {
                    //check if root is left child of its parent
                    if(isLeftChild(root)) {
                        //this creates left left situation. 
                        // So do one right rotate and change color of root
                        rightRotate(root, true);
                    } else {
                        //this creates left-right situation so do one right rotate followed
                        //by left rotate

                        //do right rotation without change in color. So pass false.
                        //when right rotation is done root becomes right child of its left
                        //child. So make root = root.parent because its left child before rotation
                        //is new root of this subtree.
                        rightRotate(root.left, false); //pivot child
                        //after rotation root should be root's parent
                        root = root.parent;
                        //then do left rotate with change of color
                        leftRotate(root, true);
                    }

                } else {
                    //we have sibling color as RED. So change color of root
                    //and its sibling to Black. And then change color of their
                    //parent to red if their parent is not a root.
                    root.color = Color.BLACK;
                    sibling.get().color = Color.BLACK;
                    //if parent's parent is not null means parent is not root.
                    //so change its color to RED.
                    if(root.parent.parent != null) {
                        root.parent.color = Color.RED;
                    }// else leave parent as black (since it is root)
                }
            }
        } else {
            //this is mirror case of above. So same comments as above.
            if(root.color == Color.RED 
                    && root.right.color == Color.RED) {
                Optional<Node> sibling = findSiblingNode(root);
                if(!sibling.isPresent() 
                        || sibling.get().color == Color.BLACK) {
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
        return root; // return root so calling method can set its child properly
    }

    /**
     * 1) If both children aren't null-nodes, Convert to 0 or 1 child case
     *     by replacing with in-order successor node. 
     *     Now delete copied node properly through recursion
     * 2) If red node, delete it
     * 3) If black node with red child, delete black, turn red child black.
     * Using atomicReference because java does not provide mutable wrapper. Its like
     * double pointer in C. rootReference is the pointer that gets passed to methods.
     * rootReference points to root & will update its pointer if root changes.
     * This prevents nullPointerException during recursions.
     */
    private void delete(Node root, int data, AtomicReference<Node> rootReference) {
        if(root == null || root.isNullLeaf) {
            return;
        }
        if(root.data == data) {
            //if node to be deleted has 1+ nullNode child then we have
            //deleteOneChild use case as discussed in video.
            if(root.right.isNullLeaf || root.left.isNullLeaf) {
                deleteOneChild(root, rootReference);
            } else { // both children aren't null-nodes
                //otherwise look for the inorder successor in right subtree.
                //replace root data with inorder successor data.
                //then delete copied node recursively
                // it should enter 1+ nullNode child algorithm.
                Node inorderSuccessor = findSmallest(root.right);
                root.data = inorderSuccessor.data;
                delete(root.right, inorderSuccessor.data, rootReference);
            }
        }
        //search for the node to be deleted.
        if(root.data < data) {
            delete(root.right, data, rootReference);
        } else {
            delete(root.left, data, rootReference);
        }
    }

    // given right child, inOrderSuccessor will be left-most (smallest) child
    private Node findSmallest(Node rightChild) {
        Node prev = null;
        while(rightChild != null 
                && !rightChild.isNullLeaf) {
            prev = rightChild;
            rightChild = rightChild.left;
        }
        return prev != null ? prev : rightChild;
    }

    /**
     * Assumption that node to be deleted has either 0 or 1 non leaf child
     */
    private void deleteOneChild(Node nodeToDelete, AtomicReference<Node> rootReference) {
        Node child = nodeToDelete.right.isNullLeaf ? nodeToDelete.left : nodeToDelete.right;
        //replace node with either one not-null child if it exists or null child.
        replaceNode(nodeToDelete, child, rootReference);
        //if the node to be deleted is BLACK. See if it has one red child.
        if(nodeToDelete.color == Color.BLACK) {
            //if it has one red child then change color of that child to be Black.
            // child will replace nodeToBeDelete without changing black count
            if(child.color == Color.RED) {
                child.color = Color.BLACK;
            } else {
                //otherwise we have double black situation.
                deleteCase1(child, rootReference);
            }
        }
    }


    /** 
     * If double black node becomes root then we are done. Turning it into
     * single black node just reduces one black in every path.
     */
    private void deleteCase1(Node doubleBlackNode, AtomicReference<Node> rootReference) {
        if(doubleBlackNode.parent == null) {
            rootReference.set(doubleBlackNode);
            return; //Terminal case
        }
        deleteCase2(doubleBlackNode, rootReference);
    }

    /**
     * If sibling is red and parent and sibling's children are black then rotate it
     * so that sibling becomes black. Double black node is still double black so we need
     * further processing.
     */
    private void deleteCase2(Node doubleBlackNode, AtomicReference<Node> rootReference) {
        Node siblingNode = findSiblingNode(doubleBlackNode).get();
        if(siblingNode.color == Color.RED) {
            if(isLeftChild(siblingNode)) {
                rightRotate(siblingNode, true);
            } else {
                leftRotate(siblingNode, true);
            }
            if(siblingNode.parent == null) {
                rootReference.set(siblingNode);
            }
        }
        deleteCase3(doubleBlackNode, rootReference);
    }

    /** 
     * If sibling, sibling's children and parent are all black then turn sibling into red.
     * This reduces and balances black node for both the paths from parent. 
     * Now parent is new double black node which needs further processing by going back to case1.
     */
    private void deleteCase3(Node doubleBlackNode, AtomicReference<Node> rootReference) {

        Node siblingNode = findSiblingNode(doubleBlackNode).get();

        if(doubleBlackNode.parent.color == Color.BLACK 
                && siblingNode.color == Color.BLACK 
                && siblingNode.left.color == Color.BLACK
                && siblingNode.right.color == Color.BLACK) {
            siblingNode.color = Color.RED;
            // push problem upward
            // double black node will bubble up to parent
            deleteCase1(doubleBlackNode.parent, rootReference);
        } else {
            deleteCase4(doubleBlackNode, rootReference);
        }
    }

    /**
     * If sibling color is black, parent color is red and sibling's children color is black then swap color b/w sibling
     * and parent. This increases one black node on double black node path but does not affect black node count on
     * sibling path. We are done if we hit this situation.
     */
    private void deleteCase4(Node doubleBlackNode, AtomicReference<Node> rootReference) {
        Node siblingNode = findSiblingNode(doubleBlackNode).get();
        if(doubleBlackNode.parent.color == Color.RED 
                && siblingNode.color == Color.BLACK 
                && siblingNode.left.color == Color.BLACK
                && siblingNode.right.color == Color.BLACK) {
            siblingNode.color = Color.RED;
            doubleBlackNode.parent.color = Color.BLACK;
            return; // terminal case
        } else {
            deleteCase5(doubleBlackNode, rootReference);
        }
    }

    /** Results from case3
     * If sibling is black, double black node is left child of its parent, siblings right child is black
     * and sibling's left child is red then do a right rotation at siblings left child and swap colors.
     * This converts it to delete case6. It will also have a mirror case.
     */
    private void deleteCase5(Node doubleBlackNode, AtomicReference<Node> rootReference) {
        Node siblingNode = findSiblingNode(doubleBlackNode).get();
        if(siblingNode.color == Color.BLACK) {
            if (isLeftChild(doubleBlackNode) 
                    && siblingNode.right.color == Color.BLACK 
                    && siblingNode.left.color == Color.RED) {
                rightRotate(siblingNode.left, true);
            } else if (!isLeftChild(doubleBlackNode) 
                    && siblingNode.left.color == Color.BLACK 
                    && siblingNode.right.color == Color.RED) {
                leftRotate(siblingNode.right, true);
            }
        }
        deleteCase6(doubleBlackNode, rootReference);
    }

    /** Terminal case
     * If sibling is black, double black node is left child of its parent, sibling left child is black and sibling's right child is
     * red, sibling takes its parent color, parent color becomes black, sibling's right child becomes black and then do
     * left rotation at sibling without any further change in color. This removes double black and we are done. This
     * also has a mirror condition.
     */
    private void deleteCase6(Node doubleBlackNode, AtomicReference<Node> rootReference) {
        Node siblingNode = findSiblingNode(doubleBlackNode).get();
        siblingNode.color = siblingNode.parent.color;
        siblingNode.parent.color = Color.BLACK;
        if(isLeftChild(doubleBlackNode)) {
            siblingNode.right.color = Color.BLACK;
            leftRotate(siblingNode, false);
        } else { // right child double black
            siblingNode.left.color = Color.BLACK;
            rightRotate(siblingNode, false);
        }
        if(siblingNode.parent == null) { // point to new root
            rootReference.set(siblingNode);
        }
    }

    // replace parent with child. 
    // Parent will be at mercy of garbage collector after recursion completes
    private void replaceNode(Node root, Node child, AtomicReference<Node> rootReference) {
        child.parent = root.parent;
        if(root.parent == null) { // point to new root
            rootReference.set(child);
        }
        else {
            if(isLeftChild(root)) {
                root.parent.left = child;
            } else {
                root.parent.right = child;
            }
        }
    }

    private void printRedBlackTree(Node root, int space) {
        if(root == null || root.isNullLeaf) {
            return;
        }
        printRedBlackTree(root.right, space + 5);
        for(int i=0; i < space; i++) {
            System.out.print(" ");
        }
        System.out.println(root.data + " " + (root.color == Color.BLACK ? "B" : "R"));
        printRedBlackTree(root.left, space + 5);
    }

    private boolean noRedRedParentChild(Node root, Color parentColor) {
        if(root == null) {
            return true;
        }
        if(root.color == Color.RED && parentColor == Color.RED) {
            return false;
        }

        return noRedRedParentChild(root.left, root.color) 
                && noRedRedParentChild(root.right, root.color);
    }

    private boolean checkBlackNodesCount(Node root, AtomicInteger blackCount, int currentCount) {

        if(root.color == Color.BLACK) {
            currentCount++;
        }

        if(root.left == null && root.right == null) {
            if(blackCount.get() == 0) {
                blackCount.set(currentCount);
                return true;
            } else {
                return currentCount == blackCount.get();
            }
        }
        return checkBlackNodesCount(root.left, blackCount, currentCount) 
                && checkBlackNodesCount(root.right, blackCount, currentCount);
    }

    public static void main(String args[]) {
        Node root = null;
        RedBlackTree redBlackTree = new RedBlackTree();

        root = redBlackTree.insert(root, 10);
        root = redBlackTree.insert(root, 15);
        root = redBlackTree.insert(root, -10);
        root = redBlackTree.insert(root, 20);
        root = redBlackTree.insert(root, 30);
        root = redBlackTree.insert(root, 40);
        root = redBlackTree.insert(root, 50);
        root = redBlackTree.insert(root, -15);
        root = redBlackTree.insert(root, 25);
        root = redBlackTree.insert(root, 17);
        root = redBlackTree.insert(root, 21);
        root = redBlackTree.insert(root, 24);
        root = redBlackTree.insert(root, 28);
        root = redBlackTree.insert(root, 34);
        root = redBlackTree.insert(root, 32);
        root = redBlackTree.insert(root, 26);
        root = redBlackTree.insert(root, 35);
        root = redBlackTree.insert(root, 19);
        redBlackTree.printRedBlackTree(root);

        root = redBlackTree.delete(root, 50);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 40);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, -10);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 15);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 17);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 24);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 21);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 32);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 26);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 19);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 25);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 17);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, -15);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 20);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 35);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 34);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 30);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 28);
        System.out.println(redBlackTree.validateRedBlackTree(root));
        root = redBlackTree.delete(root, 10);
        System.out.println(redBlackTree.validateRedBlackTree(root));
    }
}
