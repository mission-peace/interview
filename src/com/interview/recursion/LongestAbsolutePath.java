package com.interview.recursion;

import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * Find longest absolute path in file system indicated by \n and \t.
 *
 * Solution:
 * Create queue of file and its level. Then recurse from root towards file. Use level
 * to decide if next word in queue is in same level (so no more recursion) or next level so
 * going deep in recursion.
 *
 * Time complexity O(n)
 * Space complexity O(n)
 *
 * https://leetcode.com/problems/longest-absolute-file-path/
 */
public class LongestAbsolutePath {
    public int lengthLongestPath(String input) {
        if (input.length() == 0) {
            return 0;
        }
        StringTokenizer tokenizer = new StringTokenizer(input, "\n");
        Queue<Node> queue = new LinkedList<>();
        while (tokenizer.hasMoreTokens()) {
            queue.offer(new Node(tokenizer.nextToken()));
        }
        Node root = new Node("", -1);
        return lengthLongestPath(queue, root, 0);
    }

    public int lengthLongestPath(Queue<Node> queue, Node root, int currentLength) {
        if (root.isFile) {
            return currentLength + root.level;
        }
        if (queue.isEmpty()) {
            return 0;
        }
        int max = 0;
        while (!queue.isEmpty()) {
            Node n = queue.peek();
            if (root.level < n.level) {
                queue.poll();
                max = Math.max(max, lengthLongestPath(queue, n, n.file.length() + currentLength));
            } else {
                break;
            }
        }
        return max;
    }

    class Node {
        String file;
        int level;
        boolean isFile;
        Node(String file, int level) {
            this.file = file;
            this.level = level;
        }
        Node(String file) {
            int numberOfTabs = 0;
            int i;
            for (i = 0; i < file.length(); i++) {
                if (file.charAt(i) == '\t') {
                    numberOfTabs++;
                } else {
                    break;
                }
            }
            this.file = file.substring(i);
            this.level = numberOfTabs;
            this.isFile = file.contains(".");
        }
    }
}
