package com.interview.recursion;

public class PrintPermInSortedOrder {

    private void printArray(char arr[]){
        for(int i=0; i < arr.length; i++){
            System.out.print(arr[i]);
        }
        System.out.println();
    }
    
    public void printPerm(char arr[], int current, boolean used[],char []result){
        
        if(current == arr.length){
            printArray(result);
        }
        for(int i=0; i < arr.length; i++){
            if(!used[i]){
                used[i] = true;
                result[current] = arr[i];
                printPerm(arr, current+1, used,result);
                used[i] = false;
            }
        }
        
    }
    
    public static void main(String args[]){
        PrintPermInSortedOrder pat = new PrintPermInSortedOrder();
        char ch[] = {'A','B','C','D'};
        boolean[] used = new boolean[ch.length];
        char[] result = new char[ch.length];
        pat.printPerm(ch,0,used,result);
    }
}
