package com.interview.recursion;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode.com/problems/n-queens/
 */
public class NQueenProblem {

    class Position {
        int x, y;
        Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        Position[] positions = new Position[n];
        solve(0, positions, result, n);
        return result;
    }

    public void solve(int current, Position[] positions, List<List<String>> result, int n) {
        if (n == current) {
            StringBuffer buff = new StringBuffer();
            List<String> oneResult = new ArrayList<>();
            for (Position p : positions) {
                for (int i = 0; i < n; i++) {
                    if (p.y == i) {
                        buff.append("Q");
                    } else {
                        buff.append(".");
                    }
                }
                oneResult.add(buff.toString());
                buff = new StringBuffer();

            }
            result.add(oneResult);
            return;
        }

        for (int i = 0; i < n; i++) {
            boolean foundSafe = true;
            for (int j = 0; j < current; j++) {
                if (positions[j].y == i || positions[j].y - positions[j].x == i - current || positions[j].x + positions[j].y == i + current) {
                    foundSafe = false;
                    break;
                }
            }
            if (foundSafe) {
                positions[current] = new Position(current, i);
                solve(current + 1, positions, result, n);
            }
        }
    }

    public static void main(String args[]) {
        NQueenProblem s = new NQueenProblem();
        List<List<String>> result = s.solveNQueens(4);
        result.forEach(r -> {
            r.forEach(r1 -> {
                System.out.print(r1 + " ");
                System.out.print("\n");
            });
            System.out.print("\n");
        });
    }
}