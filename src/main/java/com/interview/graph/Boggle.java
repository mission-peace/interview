package com.interview.graph;

import java.util.HashSet;
import java.util.Set;

/**
 * http://www.careercup.com/question?id=14942063
 */
public class Boggle {

    public void game(Set<String> dictionary, char board[][]){
        
        boolean visited[][] = new boolean[board.length][board[0].length];
        for(int i=0; i < board.length; i++){
            for(int j=0; j <board[i].length; j++){
                StringBuffer buffer = new StringBuffer();
                DFS(dictionary,board,visited,i,j,buffer);
            }
        }
        
    }
    
    private void DFS(Set<String> dictionary,char[][] board,boolean [][]visited,int i,int j,StringBuffer buffer){
        if(i >= board.length || i <0 || j < 0 || j >= board[i].length){
            return;
        }
        
        if(visited[i][j] == true){
            return;
        }
        visited[i][j] = true;
        buffer.append(board[i][j]);
        if(dictionary.contains(buffer.toString())){
            System.out.println(buffer);
        }
        
        for(int k =i-1; k <= i+1; k++){
            for(int l = j-1;l<=j+1;l++){
                DFS(dictionary,board,visited,k,l,buffer);
            }
        }
        buffer.deleteCharAt(buffer.length()-1);
        visited[i][j] = false;
    }
    
    public static void main(String args[]){
        Boggle boggle = new Boggle();
        char board[][] = {{'t','a','s','g'},
                         {'l','u','n','h'},
                         {'t','e','i','a'},
                         {'a','w','s','r'}};
        Set<String> dictionary = new HashSet<String>();
        dictionary.add("tushar");
        dictionary.add("anisweta");
        boggle.game(dictionary, board);
        
    }
}
