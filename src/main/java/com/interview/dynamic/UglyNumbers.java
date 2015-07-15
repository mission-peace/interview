package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/ugly-numbers/
 */
public class UglyNumbers {

    int ugly(int n){
        int arr[] = new int[n];
        int count = 1;
        arr[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while(count < n){
            int minNumber = min(arr[i2]*2, arr[i3]*3,arr[i5]*5);
            if(minNumber == arr[i2]*2){
                i2++;
            }
            if(minNumber == arr[i3]*3){
                i3++;
            }
            if(minNumber == arr[i5]*5){
                i5++;
            }
            arr[count++] = minNumber;
        }
        
        return arr[n-1];
    }
    
    private int min(int a,int b, int c){
        int l = Math.min(a, b);
        return Math.min(l, c);
    }
    
    public static void main(String args[]){
        UglyNumbers ugly = new UglyNumbers();
        int result = ugly.ugly(150);
        System.out.println(result);
    }
    
}
