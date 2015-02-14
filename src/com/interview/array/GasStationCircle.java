package com.interview.array;

/**
 * http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
 * You can solve this one using kadane wrap since it finds max contiguous sum
 * for wrapped array. That start point is a best place to start a tour.
 * Test cases
 * Check if length of both input array is same
 * Check that there exists a path after kadane wrap responds
 * Check that there is at least one positive difference before you call kadane
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
    
    /**
     * This solution assumes that a tour does exists.
     * If it is not guaranteed that tour exists then once you get
     * result of kadanewrap make an actual trip to see if value is positive
     * @param gasAvailable
     * @param gasRequired
     * @return
     */
    public int startTour1(int gasAvailable[], int gasRequired[]){
        int diff[] = new int[gasAvailable.length];
        for(int i=0; i < diff.length; i++){
            diff[i] = gasAvailable[i] - gasRequired[i];
        }
        KadaneWrapArray kwa = new KadaneWrapArray();
        Triplet t = kwa.kadaneWrap(diff);
        return t.start;
    }
    
    public static void main(String args[]){
        GasStationCircle gsc = new GasStationCircle();
        int[] gasAvailable = {8,6,11,13,2,11};
        int[] gasRequired = {10,12,6,4,9,8};
        System.out.println(gsc.startTour(gasAvailable, gasRequired));
        System.out.println(gsc.startTour1(gasAvailable, gasRequired));
    }
}
