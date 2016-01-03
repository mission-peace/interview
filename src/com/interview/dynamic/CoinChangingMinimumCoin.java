package com.interview.dynamic;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.MultiHashtable;

import java.util.HashMap;
import java.util.Map;

/**
 * Date 08/12/2013
 * @author Tushar Roy
 *
 * Given a total and coins of certain denomination with infinite supply, what is the minimum number
 * of coins it takes to form this total.
 *
 * Time complexity - O(coins.size * total)
 * Space complexity - O(coins.size * total)
 *
 * Youtube video -
 * Topdown DP - https://youtu.be/Kf_M7RdHr1M
 * Bottom up DP - https://youtu.be/Y0ZqKpToTic
 */
public class CoinChangingMinimumCoin {

    /**
     * Top down dynamic programing. Using map to store intermediate results.
     * Returns Integer.MAX_VALUE if total cannot be formed with given coins
     */
    public int minimumCoinTopDown(int total, int coins[], Map<Integer, Integer> map) {

        //if total is 0 then there is nothing to do. return 0.
        if ( total == 0 ) {
            return 0;
        }

        //if map contains the result means we calculated it before. Lets return that value.
        if ( map.containsKey(total) ) {
            return map.get(total);
        }

        //iterate through all coins and see which one gives best result.
        int min = Integer.MAX_VALUE;
        for ( int i=0; i < coins.length; i++ ) {
            //if value of coin is greater than total we are looking for just continue.
            if( coins[i] > total ) {
                continue;
            }
            //recurse with total - coins[i] as new total
            int val = minimumCoinTopDown(total - coins[i], coins, map);

            //if val we get from picking coins[i] as first coin for current total is less
            // than value found so far make it minimum.
            if( val < min ) {
                min = val;
            }
        }

        //if min is MAX_VAL dont change it. Just result it as is. Otherwise add 1 to it.
        min =  (min == Integer.MAX_VALUE ? min : min + 1);

        //memoize the minimum for current total.
        map.put(total, min);
        return min;
    }

    /**
     * Bottom up way of solving this problem.
     * Keep input sorted. Otherwise temp[j-arr[i]) + 1 can become Integer.Max_value + 1 which
     * can be very low negative number
     * Returns Integer.MAX_VALUE if solution is not possible.
     */
    public int minimumCoinBottomUp(int total, int arr[]){
        int temp[] = new int[total+1];
        temp[0] = 0;
        for(int i=1; i <= total; i++){
            temp[i] = Integer.MAX_VALUE-1;
        }
        for(int i=0; i < arr.length; i++){
            for(int j=1; j <= total; j++){
                if(j >= arr[i]){
                    //be careful here. Max_val + 1 can result in very small negative number.
                    temp[j] = Math.min(temp[j], temp[j-arr[i]] +1);
                }
            }
        }
        return temp[total];
    }

    public static void main ( String args[] ) {
        int total = 39;
        int coins[] = {1, 7, 9, 17};
        CoinChangingMinimumCoin cc = new CoinChangingMinimumCoin();
        Map<Integer, Integer> map = new HashMap<>();
        int topDownValue = cc.minimumCoinTopDown(total, coins, map);
        int bottomUpValue = cc.minimumCoinBottomUp(total, coins);

        System.out.print(topDownValue + " " + bottomUpValue);

    }
}
