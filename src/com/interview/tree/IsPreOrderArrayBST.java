package com.interview.tree;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Check if given pre array sequence will create a binary search tree or not.
 *
 * Idea is to keep minimal acceptable value. Any element in pre array should never be less
 * than minimal acceptable value. Values are popped from stack till they are less than pre[i]
 * Last popped value becomes new minimally acceptable vaue.
 *
 * It does not work for duplicates
 *
 * Time complexity - O(n)
 * Space complexity - O(n)
 * Reference - http://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
 */
public class IsPreOrderArrayBST {

    public boolean isCorrect(int pre[]) {
        Deque<Integer> deque = new LinkedList<>();
        int minAcceptable = Integer.MIN_VALUE;
        deque.addFirst(pre[0]);
        for(int i = 1; i < pre.length; i++) {
            if(pre[i] < minAcceptable) {
                return false;
            }
            while(!deque.isEmpty() && deque.peekFirst() < pre[i]) {
                minAcceptable = deque.pollFirst();
            }
            deque.addFirst(pre[i]);
        }
        return true;
    }

    public static void main(String args[]) {
        IsPreOrderArrayBST isb = new IsPreOrderArrayBST();
        int pre1[] = {10, -5, -20};
        System.out.println(isb.isCorrect(pre1));
        int pre2[] = {10, -5, -20, -10, 7, -6};
        System.out.println(isb.isCorrect(pre2));
        int pre3[] = {40, 30, 35, 80, 100};
        System.out.println(isb.isCorrect(pre3));
        int pre4[] = {40, 30, 35, 20, 80, 100};
        System.out.println(isb.isCorrect(pre4));
    }
}
