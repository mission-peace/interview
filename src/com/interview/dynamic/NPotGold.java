package com.interview.dynamic;

/**
 * http://www.glassdoor.com/Interview/N-pots-each-with-some-number-of-gold-coins-are-arranged-in-a-line-You-are-playing-a-game-against-another-player-You-tak-QTN_350584.htm
 * @author tusroy
 * @author Z. Berkay Celik
 */
public class NPotGold {

    static class Pair{
        int first, second;
        int pick=0;
        public String toString(){
            return first + " " + second + " " + pick;
        }
    }
    /* bottom up dynamic programming
     * after picking, array shrinks into remaining subsequence
     * picking first means you are left with second option of subsequence*/
    public Pair[][] findMoves(int pots[]){
        
        Pair[][] moves = new Pair[pots.length][pots.length];
        
        for(int i=0; i < moves.length; i++){
            for(int j=0; j < moves[i].length; j++){
                moves[i][j] = new Pair();
            }
        }
        
        for(int i=0; i < pots.length; i++){
            moves[i][i].first = pots[i];
            //to track the sequence of moves
            moves[i][i].pick = i;
        }
        
        for(int L = 2; L <= pots.length; L++){ //L: Length of subsequence
            for(int s=0; s <= pots.length - L; s++){ //s: start index
                int e = s + L -1; //e: end index
                // if picking startIndex > picking endIndex
                if(pots[s] + moves[s+1][e].second > pots[e] + moves[s][e-1].second){
                    // startingPot + 2nd option of subsequence
                    moves[s][e].first = pots[s] + moves[s+1][e].second;
                    // starting pot gone, go to remaining subarray
                    // copy 1st (best) move of subsequence
                    moves[s][e].second = moves[s+1][e].first;
                    // save move
                    moves[s][e].pick = s;
                }else{
                    moves[s][e].first = pots[e] + moves[s][e-1].second;
                    moves[s][e].second = moves[s][e-1].first;
                    moves[s][e].pick =e;
                }
            }
        }
        
        return moves;
    }
    //prints the sequence of values and indexes
    public void printSequence(int pots[], Pair moves[][]){
        int i = 0;
        int j = pots.length - 1;
        int step;
        for (int k = 0; k < pots.length; k++) {
            step = moves[i][j].pick;
            //this is the value of pick and its index
            System.out.print("value: " + pots[step] + " " + "index: " + step + " ");
            if (step <= i) {
                i = i + 1;
            } else {
                j = j - 1;
            }
        }
    }
    public static void main(String args[]){
        NPotGold npg = new NPotGold();
        int pots[] = {3,1,5,6,2,9,3};
        Pair[][] moves = npg.findMoves(pots);
        for(int i=0; i < moves.length; i++){
            for(int j=0; j < moves[i].length; j++){
                System.out.print(moves[i][j] + "  ");
            }
            System.out.print("\n");
        }
        System.out.println("The moves by first player and second player:");
        npg.printSequence(pots, moves);
    }
}
