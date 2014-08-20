package com.interview.array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DivideNumbersInEqualGroupWithClosestSum {

    public void divide(int arr[],List<Integer> list1, List<Integer> list2){
        Arrays.sort(arr);
        int len = arr.length;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = len-1 ; i >=0; i--){
            if(sum1 < sum2 && list1.size() < len/2){
                list1.add(arr[i]);
                sum1 = sum1 + arr[i];
            }else{
                list2.add(arr[i]);
                sum2 = sum2 + arr[i];
            }
        }
    }
    
    public static void main(String args[]){
        List<Integer> list1 = new ArrayList<Integer>();
        List<Integer> list2 = new ArrayList<Integer>();
        int arr[] = {15,10,6,5,3,2,};
        DivideNumbersInEqualGroupWithClosestSum dn = new DivideNumbersInEqualGroupWithClosestSum();
        dn.divide(arr, list1, list2);
        System.out.println(list1);
        System.out.println(list2);
        
    }
}
