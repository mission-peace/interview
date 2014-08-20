package com.interview.array;

import java.util.Arrays;

/**
 * http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
 */
public class TripletInArray {

    class Triplet {
        int a;
        int b;
        int c;

        public String toString() {
            return a + " " + b + " " + c;
        }
    }

    public Triplet findTriplet(int input[], int sum) {
        Arrays.sort(input);
        for (int i = 0; i < input.length - 2; i++) {

            int start = i + 1;
            int end = input.length - 1;
            int new_sum = sum - input[i];
            while (start < end) {
                if (new_sum == input[start] + input[end]) {
                    Triplet t = new Triplet();
                    t.a = input[i];
                    t.b = input[start];
                    t.c = input[end];
                    return t;
                }
                if (new_sum > input[start] + input[end]) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return null;
    }

    public static void main(String args[]){
        TripletInArray tip = new TripletInArray();
        int input[] = {1,2,6,9,11,18,26,28};
        int sum = 22;
        System.out.println(tip.findTriplet(input, sum));
    }
}
