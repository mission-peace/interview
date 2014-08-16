package com.interview.multiarray;

import com.interview.stackqueue.MaximumHistogram;


/*
 * http://www.careercup.com/question?id=6299074475065344
 */
public class MaximumRectangularSubmatrixOf1s {

	public int maximum(int input[][]){
		int max = 1;
		for(int i=0; i < input.length ; i++){
			for(int j=0; j < input[i].length; j++){
				if(input[i][j] == 0){
					continue;
				}
				int maxLen = input[i].length;
				for(int k=i; k < input.length; k++){
					for(int l = j; l < maxLen; l++){
						if(input[k][l] != 1){
							maxLen = l;
							break;
						}
					}
					if((maxLen - j) == 0){
						break;
					}
					int r = (k-i+1)*(maxLen-j);
					max = Math.max(r, max);
				}
			}
		}
		return max;
	}
	
	public int maximumFast(int input[][]){
		int temp[] = new int[input[0].length];
		MaximumHistogram mh = new MaximumHistogram();
		int maxArea = 0;
		int area = 0;
		for(int i=0; i < input.length; i++){
			for(int j=0; j < temp.length; j++){
				if(input[i][j] == 0 || temp[j] == 0){
					temp[j] = input[i][j];
				}else{
					temp[j] += input[i][j];
				}
			}
			area = mh.maxHistogram(temp);
			if(area > maxArea){
				maxArea = area;
			}
		}
		return maxArea;
	}
	
	public static void main(String args[]){
		int input[][] = {{1,1,1,0},
						 {1,1,1,1},
						 {0,1,1,0},
						 {0,1,1,1},
						 {1,0,0,1},
						 {1,1,1,1}};
		MaximumRectangularSubmatrixOf1s mrs = new MaximumRectangularSubmatrixOf1s();
		System.out.println(mrs.maximumFast(input));
	}
}
