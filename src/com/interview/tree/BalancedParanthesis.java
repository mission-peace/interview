package com.interview.tree;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by saitejatokala on 17/01/16.
 * <p>
 * <p>
 * Print all combinations of balanced parentheses
 * Write a function to generate all possible n pairs of balanced parentheses.
 * <p>
 * For example, if n=1
 * {}
 * for n=2
 * {}{}
 * {{}}
 */
public class BalancedParanthesis {

    public static void main(String[] args) {
        BalancedParanthesis balancedParanthesis = new BalancedParanthesis();
        List<String> x = balancedParanthesis.generateParenthesis(3);
        for (String s : x) {
            System.out.println(s);
        }
    }

    public List<String> generateParenthesis(int n) {
        ArrayList<String> result = new ArrayList<>();
        dfs(result, "", n, n);
        return result;
    }

    
    public void dfs(ArrayList<String> result, String s, int left, int right) {
        if (left > right)
            return;

        if (left == 0 && right == 0) {
            result.add(s);
            return;
        }

        if (left > 0) {
            dfs(result, s + "(", left - 1, right);
        }

        if (right > 0) {
            dfs(result, s + ")", left, right - 1);
        }
    }
}
