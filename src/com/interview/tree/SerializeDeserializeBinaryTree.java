package com.interview.tree;

/**
 * Date 03/12/2016
 * @author Tushar Roy
 *
 * Serialize/Deserialize a binary tree whose data is a number.
 *
 *  Time complexity O(n)
 *  Space complexity O(n)
 *
 * Reference
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 */
public class SerializeDeserializeBinaryTree {

    // Encodes a tree to a single string.
    public String serialize(Node root) {
        StringBuffer buff = new StringBuffer();
        serializeUtil(root, buff);
        return buff.toString();
    }

    private void serializeUtil(Node root, StringBuffer buff) {
        if (root == null) {
            buff.append("%,");
            return;
        }

        buff.append(root.data).append(",");
        if (root.left != null || root.right != null) {
            buff.append("$,");
            serializeUtil(root.left, buff);
            serializeUtil(root.right, buff);
        } else {
            return;
        }

    }
    int index = 0;

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        String[] input = data.split(",");
        index = 0;
        return deserializeUtil(input);
    }

    public Node deserializeUtil(String input[]) {
        if (index == input.length) {
            return null;
        }

        if (input[index].equals("%")) {
            index++;
            return null;
        }
        Node n = new Node();
        n.data = Integer.parseInt(input[index]);
        if (index < input.length - 1) {
            if (input[index + 1].equals("$")) {
                index += 2;
                n.left = deserializeUtil(input);
                n.right = deserializeUtil(input);
            } else {
                index++;
            }
        }
        return n;
    }
}


