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
     * A much simpler solution - 
     * If total gas available < total gas required then we return -1
     * Otherwise we just track the current remaining distance and if
     * that's negative, increment start index
     * @param  gasAvailable [Gas available at each station]
     * @param  gasRequired [required amount of gas to go from one station to next]
     * @return  start [index of starting point]
     */
    public int startTour1(int gasAvailable[], int gasRequired[]){
        int totalDistance = 0;
        int totalGas = 0;
        int start = 0;
        int remainingDistance = 0;
        for(int i=0; i<gasAvailable.length; i++) {
        	totalDistance += gasRequired[i];
        	totalGas += gasAvailable[i];
        	remainingDistance += gasAvailable[i] - gasRequired[i];
        	if(remainingDistance < 0) {
        		remainingDistance = 0;
        		start = i+1;
        	}
        }
        return totalGas < totalDistance ? -1 : start;
    }

    public static void main(String args[]){
        GasStationCircle gsc = new GasStationCircle();
        int[] gasAvailable = {4, 4, 6};
        int[] gasRequired = {5, 6, 1};
        System.out.println(gsc.startTour(gasAvailable, gasRequired));
        System.out.println(gsc.startTour1(gasAvailable, gasRequired));
    }
}
