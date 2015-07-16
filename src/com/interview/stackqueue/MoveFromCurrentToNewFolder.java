package com.interview.stackqueue;

import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

/**
 * http://www.careercup.com/question?id=6209523802963968
 */
public class MoveFromCurrentToNewFolder {

    public String moveFolder(String absCurrentFolder, String relativeNewFolder){
        Deque<String> stack = new LinkedList<String>();
        StringTokenizer tokenizer = new StringTokenizer(absCurrentFolder, "/");
        while(tokenizer.hasMoreTokens()){
            stack.offerFirst(tokenizer.nextToken());
        }
        
        tokenizer = new StringTokenizer(relativeNewFolder,"/");
        while(tokenizer.hasMoreTokens()){
            String token = tokenizer.nextToken();
            if("..".equals(token)){
                stack.pollFirst();
            }else if(".".equals(token)){
            }
            else{
                stack.offerFirst(token);
            }
        }
        
        StringBuffer buffer = new StringBuffer();
        while(stack.size() > 0){
            buffer.append(stack.pollLast()).append("/");
        }
        return buffer.toString();
    }
    
    public static void main(String args[]){
        String absCurrentFolder = "/home/tusroy";
        String relativeNewFolder = "Desktop/.././Download/../../Tushar";
        MoveFromCurrentToNewFolder mfc = new MoveFromCurrentToNewFolder();
        System.out.println(mfc.moveFolder(absCurrentFolder, relativeNewFolder));
    }
}
