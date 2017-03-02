package com.interview.dynamic;

/**
 * Date 05/07/2015
 * @author tusroy
 * 
 * Video link - https://youtu.be/RORuwHiblPc
 * 
 * Given a sequence of words, and a limit on the number of characters that can be put 
 * in one line (line width). Put line breaks in the given sequence such that the 
 * lines are printed neatly
 * 
 * Solution:
 * Badness - We define badness has square of empty spaces in every line. So 2 empty space
 * on one line gets penalized as 4 (2^2) while 1 each empty space on 2 lines gets
 * penalized as 2(1 + 1). So we prefer 1 empty space on different lines over 2 empty space on
 * one line.
 * 
 * For every range i,j(words from i to j) find the cost of putting them on one line. If words 
 * from i to j cannot fit in one line cost will be infinite. Cost is calculated as square of
 * empty space left in line after fitting words from i to j.
 * 
 * Then apply this formula to get places where words need to be going on new line.
 * minCost[i] = minCost[j] + cost[i][j-1]
 * Above formula will try every value of j from i to len and see which one gives minimum 
 * cost to split words from i to len.
 * 
 * Space complexity is O(n^2)
 * Time complexity is O(n^2)
 * 
 * References:
 * http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/
 */
public class TextJustification {

    // time complexity: O(n^2)
    // space complexity: O(n^2)
    public String justify(String words[], int width) {
        // cost refers to empty-space^2
        int cost[][] = new int[words.length][words.length];
        
        //next 2 for loop is used to calculate cost of putting words from
        //i to j in one line. If words don't fit in one line then we put
        //Integer.MAX_VALUE there.
        // O(n^2) for double loop
        for(int i=0 ; i < words.length; i++){
            //initialize \ diagonal with unused value
            cost[i][i] = width - words[i].length();
            for(int j=i+1; j < words.length; j++){
                // initialize matrix above \ diagonal (top-right)
                // subtract next word from remaining width, -1 for space
                // this yields negative values for lines that don't fit
                cost[i][j] = cost[i][j-1] - words[j].length() - 1; 
            }
        }
        
        for(int i=0; i < words.length; i++){
            for(int j=i; j < words.length; j++){
                if(cost[i][j] < 0){ 
                    // lines that don't fit are set to maxInt
                    cost[i][j] = Integer.MAX_VALUE;
                }else{
                    // cost is sum-of-square of char unused in width
                    cost[i][j] = (int)Math.pow(cost[i][j], 2); // square unused value
                }
            }
        }
        
        //minCost from i to len is found by trying
        //j between i to len and checking which
        //one has min value
        // stores minimumCost of index to result[sameIndex-1]
        int minCost[] = new int[words.length];
        // words[value] is 1st word of new line
        int result[] = new int[words.length];
        // S: start word, E-1: end word
        for(int S = words.length-1; S >= 0 ; S--){
            minCost[S] = cost[S][words.length-1];
            result[S] = words.length;
            for(int E=words.length-1; E > S; E--){
                if(cost[S][E-1] == Integer.MAX_VALUE){ // skip invalid line
                    continue;
                }
                //cost[S][E-1] is cost of current line
                //minCost[E] is cost of next line to end
                //minCost[0] is cost of all lines
                if(minCost[S] > minCost[E] + cost[S][E-1]){
                    minCost[S] = minCost[E] + cost[S][E-1];
                    result[S] = E;
                }
            }
        }
        int i = 0;
        int j;
        
        System.out.println("Minimum cost is " + minCost[0]);
        System.out.println("\n");
        //finally put all words with new line added in 
        //string buffer and print it.
        StringBuilder builder = new StringBuilder();
        do{
            j = result[i];
            for(int k=i; k < j; k++){
                builder.append(words[k] + " ");
            }
            builder.append("\n");
            i = j;
        }while(j < words.length);
        
        return builder.toString();
    }
    
    public static void main(String args[]){
        String words1[] = {"Tushar","likes","to","write","code","at", "free", "time"};
        TextJustification awl = new TextJustification();
        System.out.println(awl.justify(words1, 12));
    }
}
