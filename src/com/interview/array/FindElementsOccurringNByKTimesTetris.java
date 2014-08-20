package com.interview.array;

/**
 * http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
 */
public class FindElementsOccurringNByKTimesTetris {

    public static class Pair{
        public int element;
        public int count;
    }
    
    public void printElementsOccurringKTimes(int arr[],int k){
        Pair[] p = new Pair[k];
        for(int i=0; i < k; i++){
            p[i] = new Pair();
        }
        for(int i=0; i < arr.length; i++){
            
            int j=0;
            for(j=0; j < k; j++){
                if(p[j].element == arr[i]){
                    p[j].count++;
                    break;
                }
            }
            
            if(j == k){
                int l=0;
                for(l =0; l < k ; l++){
                    if(p[l].count == 0){
                        p[l].element = arr[i];
                        p[l].count = 1;
                        break;
                    }
                }
                if(l == k){
                    for(int t =0; t < k ; t++){
                        p[t].count--;
                    }
                }
            }
        }
        
        for(int i=0; i < k ; i++){
            if(p[i].count > 0){
                int count =0;
                for(int j=0; j < arr.length; j++){
                    if(arr[j] == p[i].element){
                        count++;
                    }
                }
                if(count >= arr.length/k){
                    System.out.println(p[i].element);
                }
            }
        }
    }
    
    public static void main(String args[]){
        int arr[] = {3,2,2,1,1,2,3,3,4,5,3,1};
        FindElementsOccurringNByKTimesTetris fe = new FindElementsOccurringNByKTimesTetris();
        fe.printElementsOccurringKTimes(arr, 3);
    }

    
}
