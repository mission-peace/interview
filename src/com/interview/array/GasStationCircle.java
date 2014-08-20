package com.interview.array;

/**
 * http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
 */
public class GasStationCircle {

    public int startTour(int gasAvailable[],int gasRequired[]){
        int start = -1;
        int end = 0;
        int currentGas = 0;
        boolean visitedOnce = false;
        while(start != end){
            currentGas += gasAvailable[end] - gasRequired[end];
            if(start == -1){
                start = end;
            }
            if(end == gasAvailable.length-1 && visitedOnce == false){
                visitedOnce = true;
            }else if(end == gasAvailable.length-1 && visitedOnce == true){
                return -1;
            }
            if(currentGas < 0){
                start = -1;
                currentGas = 0;
            }
            end = (end + 1)%gasAvailable.length;
        }
        
        return end;
    }
    
    public static void main(String args[]){
        GasStationCircle gsc = new GasStationCircle();
        int[] gasAvailable = {3,4,5,8,9};
        int[] gasRequired = {4,1,8,4,6};
        System.out.println(gsc.startTour(gasAvailable, gasRequired));
    }
}
