package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/
 * Test cases
 * Negative number
 * Number less than 7
 * Number greater than equal to 7
 */
public class CountAs {

    public int countAs(int n){
        if(n < 7){
            return n;
        }
        
        int T[] = new int[n+1];
        for(int i=1; i < 7 ; i++){
            T[i] = i;
        }

        //We only have to consider up to 4 consecutive pastes, since select, copy, paste x 5 is equivalent to 
        // select, copy, paste, select, copy, paste and the latter is better since it leaves us with more in the clipboard.
        int mark = 5;
        for (int i=8; i<=n; i++) {
            for (int k=i-mark; k<=i; k++) {
                T[i] = Math.max(T[i], (k-3)*(i-k+1));
            }
            int p = 6; //since after 4 pastes you can do better by increasing buffer.
            for (int k=i-p; k<=i && p>2; k++, --p) {
                T[i] = Math.max(T[i], T[k]*(p-2));
            }
        }
        
        return T[n];
    }
    
    public static void main(String args[]){
        CountAs ca =new CountAs();
        //System.out.println(ca.countAsRec(25));
        System.out.println(ca.countAs(25));
              
    }
}
