package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/program-nth-catalan-number/
 * Count number of binary search tree created for array of size n
 * this counting problem follows Catalan numbers
 */
public class CountNumberOfTreesInBST {

    int countTreesRec(int numKeys) {
        // Base case
        if (numKeys <=1) {
            return(1);
        }
        else {
            int sum = 0;
            int left, right, root;
            for (root=1; root<=numKeys; root++) {
                left = countTreesRec(root - 1);
                right = countTreesRec(numKeys - root);
                sum += left*right;
            }
            return(sum);
        }
    }
    
    // A dynamic programming based function to find nth
    // Catalan number
    public int countTrees(int n){
        
        // Table to store results of subproblems
        int T[] = new int[n+1];
        
        // Initialize first two values in table
        T[0] = 1;
        T[1] = 1;
        
        // Fill entries in catalan[] using recursive formula
        for(int i=2; i <= n; i++){
            for(int j=0; j <i; j++){
                T[i] += T[j]*T[i-j-1];
            }
        }
        
        // Return last entry
        return T[n];
    }
    
    // Driver program to test above function
    public static void main(String args[]){
        CountNumberOfTreesInBST cnt = new CountNumberOfTreesInBST();
        System.out.println(cnt.countTrees(3));
        System.out.println(cnt.countTrees(4));
    }
}
