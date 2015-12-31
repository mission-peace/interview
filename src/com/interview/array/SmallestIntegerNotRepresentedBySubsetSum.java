package com.interview.array;

/**
 * Date 12/31/2015
 * @author Tushar Roy
 *
 * Given array in non decreasing order find smallest integer which cannot be represented by
 * subset sum of these integers.
 *
 * Time complexity is O(n)
 *
 * http://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
 */
public class SmallestIntegerNotRepresentedBySubsetSum {

    public int findSmallestInteger(int input[]) {
        int result = 1;
        for (int i = 0; i < input.length; i++) {
            if (input[i] <= result) {
                result += input[i];
            } else {
                break;
            }
        }
        return result;
    }

    public static void main(String args[]) {
        int input[] = {1, 2, 3, 8};
        SmallestIntegerNotRepresentedBySubsetSum ss = new SmallestIntegerNotRepresentedBySubsetSum();
        System.out.print(ss.findSmallestInteger(input));
    }
}
