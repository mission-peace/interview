package com.interview.tree;

/**
 * http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
 * http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
 */
public class SegmentTree {

	public int[] createTree(int input[]){
		int height = (int)Math.ceil(Math.log(input.length)/Math.log(2));
		int segmentTree[] = new int[(int)(2*Math.pow(2, height)-1)];
		constructTree(segmentTree,input,0,input.length-1,0);
		return segmentTree;
	}
	
	private void constructTree(int segmentTree[], int input[], int low, int high,int pos){
		if(low == high){
			segmentTree[pos] = input[low];
			return;
		}
		int mid = (low + high)/2;
		constructTree(segmentTree,input,low,mid,2*pos+1);
		constructTree(segmentTree,input,mid+1,high,2*pos+2);
		segmentTree[pos] = segmentTree[2*pos+1] + segmentTree[2*pos+2];
	}
	
	public int getSum(int []segmentTree,int qlow,int qhigh,int len){
		return getSum(segmentTree,0,len-1,qlow,qhigh,0);
	}
	
	private int getSum(int segmentTree[],int low,int high,int qlow,int qhigh,int pos){
		if(qlow <= low && qhigh >= high){
			return segmentTree[pos];
		}
		if(qlow > high || qhigh < low){
			return 0;
		}
		int mid = (low+high)/2;
		return getSum(segmentTree,low,mid,qlow,qhigh,2*pos+1) + 
				getSum(segmentTree,mid+1,high,qlow,qhigh,2*pos+2);
	}
	
	public void updateValue(int input[],int segmentTree[],int newVal,int index){
		int diff = newVal - input[index];
		input[index] = newVal;
		updateVal(segmentTree,0,input.length-1,diff,index,0);
	}
	
	private void updateVal(int segmentTree[],int low,int high,int diff,int index, int pos){
		if(index < low || index > high){
			return;
		}
		segmentTree[pos] += diff;
		if(low >= high){
			return;
		}
		int mid = (low + high)/2;
		updateVal(segmentTree,low,mid,diff,index,2*pos+1);
		updateVal(segmentTree,mid+1,high,diff,index,2*pos+2);
	}
	
	public static void main(String args[]){
		int input[] = {1,3,5,7,9,11};
		SegmentTree st = new SegmentTree();
		int result [] = st.createTree(input);
		for(int i=0; i < result.length; i++){
			System.out.print(result[i] + " ");
		}
		st.updateValue(input, result,0 , 0);
		System.out.println();
		for(int i=0; i < result.length; i++){
			System.out.print(result[i] + " ");
		}
		
	}
}

