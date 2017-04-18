package com.interview.dynamic;

import java.util.Arrays;

/**
 * Date 05/09/2015
 * @author tusroy
 * 
 * Given different dimensions and unlimited supply of boxes for each dimension, stack boxes
 * on top of each other such that it has maximum height but with caveat that length and width
 * of box on top should be strictly less than length and width of box under it. You can
 * rotate boxes as you like.
 * 
 * 1) Create all rotations of boxes such that length is always greater or equal to width
 * 2) Sort boxes by base area in non increasing order (length * width). This is because box
 * with more area will never ever go on top of box with less area.
 * 3) Take T[] and result[] array of same size as total boxes after all rotations are done
 * 4) Apply longest increasing subsequence type of algorithm to get max height.
 * 
 * If n number of dimensions are given total boxes after rotation will be 3n.
 * So space complexity is O(n)
 * Time complexity - O(nlogn) to sort boxes. O(n^2) to apply DP on it So really O(n^2)
 *
 * References
 * http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem/
 * http://people.cs.clemson.edu/~bcdean/dp_practice/
 */
public class BoxStacking {
    // space complexity: O(n)
    // time complexity: O(n^2)
    public int maxHeight(Dimension[] input) {
        //get all rotations of box dimension.
        //e.g if dimension is 1,2,3 rotations will be 2,1,3  3,2,1  3,1,2. 
        //Here length is always greater or equal to width 
        //and we can do that without loss of generality.
        Dimension[] allRotationInput = new Dimension[input.length * 3];
        createAllRotation(input, allRotationInput);
        
        //sort these boxes in non increasing order by their base area.(length X width)
        Arrays.sort(allRotationInput);

        //apply longest increasing subsequence kind of algorithm on these sorted boxes.
        int H[] = new int[allRotationInput.length]; //stores max height of sequence
        //stores allRotationInput[index] where value at result[index] 
        //is index of box below. 
        int result[] = new int[allRotationInput.length]; 

        // initialize H[] with height of single box
        for (int i = 0; i < H.length; i++) {
            H[i] = allRotationInput[i].height;
            result[i] = i;
        }
        
        //t: top box, b: base box
        for (int t = 1; t < H.length; t++) {
            for (int b = 0; b < t; b++) {
                if (allRotationInput[t].length < allRotationInput[b].length
                        && allRotationInput[t].width < allRotationInput[b].width) {
                    // top box is strictly less than base box
                    if( H[b] + allRotationInput[t].height > H[t]){
                        // new height == base boxes + top box
                        H[t] = H[b] + allRotationInput[t].height;
                        // allRotationInput[H[index of max value]] will be top box
                        // next box down's index will be value at result[index]
                        result[t] = b;
                    }
                }
            }
        }
       
        //find max in H[] and that will be our max height.
        //Result can also be found using result[] array.
        int max = Integer.MIN_VALUE;
        for(int i=0; i < H.length; i++){
            if(H[i] > max){
                max = H[i];
            }
        }
        
        return max;
    }

    //create all rotations of boxes, always keeping length greater or equal to width
    private void createAllRotation(Dimension[] input, Dimension[] allRotationInput) {
        int index = 0;
        for (int i = 0; i < input.length; i++) {
            allRotationInput[index++] = Dimension.createDimension(
                    input[i].height, input[i].length, input[i].width);
            allRotationInput[index++] = Dimension.createDimension(
                    input[i].length, input[i].height, input[i].width);
            allRotationInput[index++] = Dimension.createDimension(
                    input[i].width, input[i].length, input[i].height);

        }
    }

    public static void main(String args[]) {
        BoxStacking bs = new BoxStacking();
        Dimension input[] = { new Dimension(3, 2, 5), new Dimension(1, 2, 4) };
        int maxHeight = bs.maxHeight(input);
        System.out.println("Max height is " + maxHeight);
        assert 11 == maxHeight;
    }
}

/**
 * Utility class to hold dimensions
 */
class Dimension implements Comparable<Dimension> {
    int height;
    int length;
    int width;

    Dimension(int height, int length, int width) {
        this.height = height;
        this.length = length;
        this.width = width;
    }

    Dimension() {
    }

    static Dimension createDimension(int height, int side1, int side2) {
        Dimension d = new Dimension();
        d.height = height;
        if (side1 >= side2) {
            d.length = side1;
            d.width = side2;
        } else {
            d.length = side2;
            d.width = side1;
        }
        return d;
    }

    /**
     * Sorts by base area(length X width)
     */
    @Override
    public int compareTo(Dimension d) {
        if (this.length * this.width >= d.length * d.width) {
            return -1;
        } else {
            return 1;
        }
    }

    @Override
    public String toString() {
        return "Dimension [height=" + height + ", length=" + length
                + ", width=" + width + "]";
    }
}
