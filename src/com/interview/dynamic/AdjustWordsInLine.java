package com.interview.dynamic;

/**
 * http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/
 */
public class AdjustWordsInLine {

    public String adjust(String words[],int width){
        int cost[][] = new int[words.length][words.length];
        int split[][] = new int[words.length][words.length];
        
        for(int i=0; i < words.length; i++){
            int diff = width - words[i].length();
            cost[i][i] = diff*diff;
            split[i][i] = i;
        }
        
        for(int l = 2; l <= words.length; l++){
            for(int i=0; i < words.length - l + 1; i++){
                int j = i + l -1;
                int diff = width - words[i].length();
                int k;
                for(k = i+1 ; k <= j; k++){
                    diff = diff - words[k].length()-1;
                    if(diff < 0){
                        break;
                    }
                }
                if(k == (j+1) && diff >=0){
                    cost[i][j] = diff*diff;
                    split[i][j] = j;
                    
                }else{
                    cost[i][j] = Integer.MAX_VALUE;
                    split[i][j] = -1;
                }
                for(k=i; k < j ; k++){
                    if(cost[i][k] + cost[k+1][j] < cost[i][j]){
                        cost[i][j] = cost[i][k] + cost[k+1][j];
                        split[i][j] = k;
                    }
                }
            }
        }
        StringBuffer buffer = new StringBuffer();
        int i = 0; 
        int j = words.length-1;
        while(i <= j){
            int k = split[i][j];
            for(int l = i; l <= k ; l++){
                buffer.append(words[l] + " ");
            }
            i = k+1;
            buffer.append("\n");
        }
        return buffer.toString();
    }
    
    public static void main(String args[]){
        String words[] = {"Tushar","Roy","Ani","Sinha"};
        AdjustWordsInLine awl = new AdjustWordsInLine();
        System.out.println(awl.adjust(words, 9));
    }
}
