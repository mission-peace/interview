package com.interview.dynamic;

/**
 * Date 09/15/2014
 * @author tusroy
 * 
 * Find maximum subsquare in a matrix made up of Xs and Os such that all four sides of subsquare are Xs. It does not matter what is inside
 * the subsquare. All 4 sides should be made up entirely of Xs
 * 
 * e.g 
 * 0 0 0 0 0 X         0,0  0,0  0,0  0,0  0,0  1,1
 * 0 X 0 X X X         0,0  1,1  0,0  1,1  1,2  2,3 
 * 0 X 0 X 0 X         0,0  2,1  0,0  2,1  0,0  3,1
 * 0 X X X X X         0,0  3,1  1,2  3,3  1,4  4,5
 * 0 0 0 0 0 0         0,0  0,0  0,0  0,0  0,0  0,0   
 * 
 * Output of above program should be 3
 * 
 * Solution
 * Have another matrix which is capable of holding 2 values hori and ver. 
 * Ver stores how far vertically you can see Xs. Hori stores how far horizontally you can see Xs.
 * Once this matrix is build look for biggest subsquare by getting min of hori and ver at each point and checking
 * if subsquare can be formed from value min to 1.
 * 
 * Test cases:
 * Matrix entirely made up of Xs
 * Matrix entirely made up of Os
 * Matrix with Xs and Os but maximum subsquare is length 1
 */
public class SubsquareSurrounedByXs {

    class Cell{
        int ver;
        int hori;
    }
    public int findSubSquare(char input[][]){
        Cell T[][] = new Cell[input.length][input[0].length];
        for(int v=0; v < T.length; v++){
            for(int h=0; h < T[0].length; h++){
                T[v][h] = new Cell();
            }
        }
    
        for(int v=0; v < input.length; v++){
            for(int h=0; h < input[0].length; h++){
                if(input[v][h] == 'X'){
                    if(v == 0 && h == 0){
                        T[v][h].hori = 1;
                        T[v][h].ver = 1;
                    }
                    else if(v == 0){
                        T[v][h].hori = T[v][h-1].hori + 1;
                        T[v][h].ver = 1;
                    }else if(h == 0){
                        T[v][h].ver = T[v-1][h].ver +1;
                        T[v][h].hori = 1;
                    }else{
                        T[v][h].hori = T[v][h-1].hori +1;
                        T[v][h].ver = T[v-1][h].ver + 1;
                    }
                }
            }
        }
        for(int i=0; i < T.length; i++){
            for(int j=0; j < T[0].length; j++){
                System.out.print(T[i][j].ver + "," + T[i][j].hori+ "  ");
            }
            System.out.println();
        }
        
        //start iterating from bottom right corner and find min of hori or ver at every cell.
        //If this is greater than 1 then see if you can find a number between this min and 1
        //such that on left's ver and top's hori is greater greater than or equal to k.
        int max = 1;
        // iterate from bottomRight matrix
        // stopping at max since any solution inside max must be smaller
        for(int v=T.length -1; v >max ; v--){
            for(int h= T[0].length-1 ; h >max; h--){
                if(T[v][h].ver == 0 || T[v][h].ver == 1 || T[v][h].hori ==1 ){
                    continue;
                }
                // maximum square cannot exceed minimum(rightEdge, topEdge)
                int minEdge = Math.min(T[v][h].ver, T[v][h].hori);
                int k = 0;
                for(k=minEdge; k > 1; k--){
                    // check for valid leftEdge && topEdge 
                    if(T[v][h-k+1].ver >= k && T[v-k+1][h].hori >= k){
                        break;
                    }
                }
                if(max < k){
                    max = k;
                }
            }
        }
        
        return max;
    }
    
    public static void main(String args[]){
        char[][] input = {{'X','O','O','O','O','O'},
                          {'O','O','O','O','O','O'},
                          {'X','X','X','X','O','O'},
                          {'X','X','X','X','X','O'},
                          {'X','O','O','X','X','O'},
                          {'X','O','X','X','X','O'}};
        
        char [][] input1 = {{'O', 'O', 'O', 'O', 'O', 'X'},
                            {'O', 'X', 'O', 'X', 'X', 'X'},
                            {'O', 'X', 'O', 'X', 'O', 'X'},
                            {'O', 'X', 'X', 'X', 'X', 'X'},
                            {'O', 'O', 'O', 'O', 'O', 'O'},
        };
        
        char [][] input2 = {{'O', 'O', 'X', 'O', 'X'},
                            {'O', 'X', 'X', 'O', 'X'},
                            {'O', 'X', 'O', 'X', 'X'},
                            {'X', 'X', 'X', 'X', 'X'},
                            {'O', 'X', 'X', 'X', 'O'},
                           };

        SubsquareSurrounedByXs ss = new SubsquareSurrounedByXs();
        System.out.println(ss.findSubSquare(input));
        System.out.println(ss.findSubSquare(input1));
        System.out.println(ss.findSubSquare(input2));
    }
    
}
