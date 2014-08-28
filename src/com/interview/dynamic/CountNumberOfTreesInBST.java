package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/program-nth-catalan-number/
 * Count number of binary search tree created for array of size n
 */
public class CountNumberOfTreesInBST {

    int countTrees(int numKeys) {
        if (numKeys <=1) {
            return(1);
        }
        else {
            int sum = 0;
            int left, right, root;
            for (root=1; root<=numKeys; root++) {
                left = countTrees(root - 1);
                right = countTrees(numKeys - root);
                sum += left*right;
            }
            return(sum);
        }
    }
    
    public int countTreesDynamic(int n){
        int T[] = new int[n+1];
        T[0] = 1;
        T[1] = 1;
        for(int i=2; i <= n; i++){
            for(int j=0; j <i; j++){
                T[i] += T[j]*T[i-j-1];
            }
        }
        return T[n];
    }
    public static void main(String args[]){
        CountNumberOfTreesInBST cnt = new CountNumberOfTreesInBST();
        System.out.println(cnt.countTreesDynamic(3));
        System.out.println(cnt.countTreesDynamic(4));
    }
}
