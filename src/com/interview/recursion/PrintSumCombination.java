package com.interview.recursion;

import java.util.ArrayList;
import java.util.List;

/**
 * Date 07/10/2015
 * @author Tushar Roy
 * 
 * Given an input and total print all combinations with repetitions in this input
 * which sums to given total.
 * e.g
 * input - {2,3,5} 
 * total - 10
 * 
 * Output
 * {2,2,2,2,2}
 * {2,3,5}
 * {5,3,2}
 * {5,2,3}
 * {2,2,3,3}
 * {3,3,2,2}
 * and so on
 *
 */
public class PrintSumCombination {

    public void print(int input[], int sum) {
        List<Integer> result = new ArrayList<>();
        print(input, sum, result);
    }
    
    private void print(int input[], int sum, List<Integer >result) {     
        if(sum < 0) {
            return;
        }
        if(sum == 0) {
            result.stream().forEach(i -> System.out.print(i + " "));
            System.out.println();
            return;
        }
        
        
        for(int i=0; i < input.length; i++) {
            result.add(input[i]);
            print(input, sum - input[i], result);
            result.remove(result.size()-1);
        }
    }
    
    public static void main(String args[]) {
        int input[] = {2,3,5};
        PrintSumCombination psc = new PrintSumCombination();
        psc.print(input, 10);
    }
}
