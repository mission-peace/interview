package com.interview.array;

import java.util.*;

/**
* Source: https://www.hackerrank.com/contests/101hack45/challenges/permutation-equation
*/
public class SequenceEquation {
    
	public static void main(String args[] ) throws Exception {
        
		Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int[] arr = new int[50];
        int[] res = new int[50];
        int y = 0;
        
        for (int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[j] == i+1) {
					for (int k = 0; k < n; k++) {
                        if (arr[k] == j+1) {
                            res[y] = k;
                            y++;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        for (int i = 0; i < y; i++) {
            System.out.println(res[i] + 1);
        }
    
        scan.close();
	}
	
}
