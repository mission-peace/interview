package com.interview.dynamic;

/**
 * Given a preorder sequence how many unique trees can be created
 * Solution is catalan number. Number of tree is exactly same
 * as number of unique BST create with array of size n
 */
public class CountNumberOfTreePreorder {

    public int count(int num){
        int T[] = new int[num+1];
        T[0] = 1;
        T[1] = 1;
        for(int i=2; i <= num; i++){
            int sum = 0;
            for(int k=0; k < i; k++){
                sum += T[k]*T[i-k-1];
            }
            T[i] = sum;
        }
        return T[num];
    }
    
    public static void main(String args[]){
        CountNumberOfTreePreorder cn = new CountNumberOfTreePreorder();
        System.out.println(cn.count(3));
        System.out.println(cn.count(4));
        System.out.println(cn.count(5));
    }
}
