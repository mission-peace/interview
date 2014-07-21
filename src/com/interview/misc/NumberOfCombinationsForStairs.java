package com.interview.misc;

import java.util.Iterator;
import java.util.LinkedList;


/**
 * A man is walking up a set of stairs. He can either take 1 or 2 steps at a time. 
 * Given n number of steps,
 * find out how many combinations of steps he can take to reach the top of the stairs.
 * Its like building a fibonaaci series but instead of looking back 2 you have to 
 * look back k elements
 */
public class NumberOfCombinationsForStairs {

	public int numberOfWays(int n,int k){
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(1);
		for(int i=1; i < k ; i++){
			Iterator<Integer> itr = queue.iterator();
			int count = 1;
			while(itr.hasNext()){
				count += itr.next();
			}
			queue.offerLast(count);
		}
		for(int i = k; i < n ; i++){
			Iterator<Integer> itr = queue.iterator();
			int count = 0;
			while(itr.hasNext()){
				count += itr.next();
			}
			queue.pollFirst();
			queue.offerLast(count);
		}
		return queue.pollLast();
	}
	
	public static void main(String args[]){
		NumberOfCombinationsForStairs noc = new NumberOfCombinationsForStairs();
		System.out.println(noc.numberOfWays(7, 4));
	}
}
