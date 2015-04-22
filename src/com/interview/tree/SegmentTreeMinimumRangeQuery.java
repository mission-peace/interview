package com.interview.tree;

import com.interview.bits.NextPowerOf2;

/**
 * Date 08/22/2015
 * @author tusroy
 * 
 * A segment tree is a tree data structure for storing intervals, or segments. It allows 
 * for faster querying (e.g sum or min) in these intervals.

 * Write a program to support mininmum range query
 * createSegmentTree(int arr[]) - create segment tree
 * query(int segment[], int startRange, int endRange) - returns minimum between startRange and endRange
 * 
 * Time complexity to create segment tree is O(n) since new array will be at max 4n size
 * Space complexity to create segment tree is O(n) since new array will be at max 4n size
 * Time complexity to search in segment tree is O(logn) since you would at max travel 4 depths
 * 
 * References
 * http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
 * http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
 * https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
 */
public class SegmentTreeMinimumRangeQuery {

    public int[] createTree(int input[]){
        NextPowerOf2 np2 = new NextPowerOf2();
        //if input len is pow of then size of 
        //segment tree is 2*len -1 otherwisze
        //size of segment tree is next (pow of 2 for len) * 2 -1
        int nextPowOfTwo = np2.nextPowerOf2(input.length);
        int segmentTree[] = new int[nextPowOfTwo*2 -1];
        
        for(int i=0; i < segmentTree.length; i++){
            segmentTree[i] = Integer.MAX_VALUE;
        }
        constructMinSegmentTreeTree(segmentTree,input,0,input.length-1,0);
        return segmentTree;
        
    }
    
    private void constructMinSegmentTreeTree(int segmentTree[], int input[], int low, int high,int pos){
        if(low == high){
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        constructMinSegmentTreeTree(segmentTree,input,low,mid,2*pos+1);
        constructMinSegmentTreeTree(segmentTree,input,mid+1,high,2*pos+2);
        segmentTree[pos] = Math.min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
    }
    
    public int rangeMinimumQuery(int []segmentTree,int qlow,int qhigh,int len){
        return rangeMinimumQuery(segmentTree,0,len-1,qlow,qhigh,0);
    }
    
    private int rangeMinimumQuery(int segmentTree[],int low,int high,int qlow,int qhigh,int pos){
        if(qlow <= low && qhigh >= high){
            return segmentTree[pos];
        }
        if(qlow > high || qhigh < low){
            return Integer.MAX_VALUE;
        }
        int mid = (low+high)/2;
        return Math.min(rangeMinimumQuery(segmentTree,low,mid,qlow,qhigh,2*pos+1),
                rangeMinimumQuery(segmentTree,mid+1,high,qlow,qhigh,2*pos+2));
    }
    
    /**
     * Segment tree for given example
     *                         -1
     *                0                -1
     *            0       2         1         -1
     *         0    3   4   2     1   6    max   max 
     * 
     */
    
    public static void main(String args[]){
        SegmentTreeMinimumRangeQuery st = new SegmentTreeMinimumRangeQuery();
        int input[] = {0,3,4,2,1,6,-1};
        int segTree[] = st.createTree(input);
        
        assert 0 == st.rangeMinimumQuery(segTree, 0, 3, input.length);
        assert 1 == st.rangeMinimumQuery(segTree, 1, 5, input.length);
        assert -1 == st.rangeMinimumQuery(segTree, 1, 6, input.length);
        assert 2 == st.rangeMinimumQuery(segTree, 1, 3, input.length);
    }
}
