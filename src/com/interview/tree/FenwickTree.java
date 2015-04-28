package com.interview.tree;

/**
 * Date 04/27/2015
 * @author tusroy
 * 
 * Write a program to implement fenwick or binary indexed tree
 * 
 * A Fenwick tree or binary indexed tree is a data structure providing efficient methods
 * for calculation and manipulation of the prefix sums of a table of values.
 * 
 * Space complexity for fenwick tree is O(n)
 * Time complexity to create fenwick tree is O(nlogn)
 * Time complexity to update value is O(logn)
 * Time complexity to get prefix sum is O(logn)
 * 
 * References
 * http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
 * https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
 * http://en.wikipedia.org/wiki/Fenwick_tree
 */
public class FenwickTree {

    public void updateBinaryIndexedTree(int binaryIndexedTree[], int val, int index){
        while(index < binaryIndexedTree.length){
            binaryIndexedTree[index] += val;
            index += (index & -index);
        }
    }
    
    public int getSum(int binaryIndexedTree[], int index){
        index = index + 1;
        int sum = 0;
        while(index > 0){
            sum += binaryIndexedTree[index];
            index -= (index & -index);
        }
        return sum;
    }
    
    public int[] createTree(int input[]){
        int binaryIndexedTree[] = new int[input.length+1];
        for(int i=1; i <= input.length; i++){
            updateBinaryIndexedTree(binaryIndexedTree, input[i-1], i);
        }
        return binaryIndexedTree;
    }
    
    public static void main(String args[]){
        int input[] = {1,2,3,4,5,6,7};
        FenwickTree ft = new FenwickTree();
        int binaryIndexedTree[] = ft.createTree(input);
        assert 1 == ft.getSum(binaryIndexedTree, 0);
        assert 3 == ft.getSum(binaryIndexedTree, 1);
        assert 6 == ft.getSum(binaryIndexedTree, 2);
        assert 10 == ft.getSum(binaryIndexedTree, 3);
        assert 15 == ft.getSum(binaryIndexedTree, 4);
        assert 21 == ft.getSum(binaryIndexedTree, 5);
        assert 28 == ft.getSum(binaryIndexedTree, 6);
    }
}
