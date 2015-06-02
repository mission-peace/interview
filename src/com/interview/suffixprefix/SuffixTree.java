package com.interview.suffixprefix;

import java.util.ArrayList;
import java.util.List;

/**
 * Date 06/01/2015
 * @author tusroy
 * 
 * Construct suffix tree using Ukkonen's algorithm
 * 
 * Solution
 * Rule 1: For phase i+1 if S[j..i] ends at last character of leaf edge then add S[i+1] at 
 * the end.
 * Rule 2: For phase i+1 if S[j..i] ends somewhere in middle of edge and next character is
 * not S[i+1] then a new leaf edge with label S[i+1] should be created
 * Rule 3: For phase i+1 if S[j..i] ends somewhere in middle of edge and next character is
 * S[i+1] then do nothing(resulting in implicit tree)
 * 
 * Suffix Link:
 * For every node with label x@ where x is a single character and @ is possibly empty substring
 * there is another node with label x. This node is suffix link of first node. If @ is
 * empty then suffix link is root.
 * 
 * Trick1
 * Skip/Count trick
 * While traveling down if number of characters on edge is less than number of characters
 * to traverse then skip directly to the end of the edge. If number of characters on label
 * is more than number of characters to traverse then go directly to that character
 * we care about.
 * 
 * Edge-label compression
 * Instead of storing actual characters on the path store start and end indices on the 
 * path.
 * 
 * Trick2 - Stop process as soon as you hit rule 3. Rule 3 is show stopper
 * 
 * Trick3 - Keep a global end on leaf to do rule 1 extension.
 * 
 * Test cases 
 * adeacdade
 * abcabxabcd
 * abcdefabxybcdmnabcdex
 * abcadak
 * dedododeodo
 * abcabxabcd
 * mississippi
 * banana
 * 
 * References
 * http://web.stanford.edu/~mjkay/gusfield.pdf
 * http://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-6/
 * https://www.cs.helsinki.fi/u/ukkonen/SuffixT1withFigs.pdf
 * https://gist.github.com/axefrog/2373868
 */
public class SuffixTree {

    public static void main(String args[]){
        SuffixTree st = new SuffixTree("mississippi".toCharArray());
        
        st.build();
        st.dfsTraversal();
        System.out.println(st.validate());
        
    }
    
    private SuffixNode root;
    private Active active;
    private int remainingSuffixCount;
    private End end;
    private char input[];
    private static char UNIQUE_CHAR = '$';
    
    public SuffixTree(char input[]){
        this.input = new char[input.length+1];
        for(int i=0; i < input.length; i++){
            this.input[i] = input[i];
        }
        this.input[input.length] = UNIQUE_CHAR;
    }
    
    public void build(){
        root = SuffixNode.createNode(1, new End(0));
        root.index = -1;
        active = new Active(root);
        this.end = new End(-1);
        for(int i=0; i < input.length; i++){
            startPhase(i);
        }
        setIndexUsingDfs(root, 0, input.length);
    }
    
    private void startPhase(int i){
        SuffixNode lastCreatedInternalNode = null;
        end.end++;
        remainingSuffixCount++;
        while(remainingSuffixCount > 0){
            if(active.activeLength == 0){
                if(selectNode(i) != null){
                    active.activeIndex = selectNode(i).start;
                    active.activeLength++;
                    break;
                } else {
                    root.child[input[i]] = SuffixNode.createNode(i, end);
                    remainingSuffixCount--;
                }
            } else{
                try {
                    char ch = nextChar(i);
                    if(ch == input[i]){
                        walkDown(i, lastCreatedInternalNode);
                        break;
                    }
                    else{
                        SuffixNode node = selectNode();
                        int oldStart = node.start;
                        node.start = node.start + active.activeLength;
                        SuffixNode newInternalNode = SuffixNode.createNode(oldStart, new End(oldStart + active.activeLength - 1));
                        
                        SuffixNode newNode2 = SuffixNode.createNode(i, this.end);
                        newInternalNode.child[input[newInternalNode.start + active.activeLength]] = node;
                        newInternalNode.child[input[i]] = newNode2;
                        newInternalNode.index = -1;
                        active.activeNode.child[input[newInternalNode.start]] = newInternalNode;
                        if(lastCreatedInternalNode != null){
                            lastCreatedInternalNode.suffixLink = newInternalNode;
                        }
                        lastCreatedInternalNode = newInternalNode;
                        newInternalNode.suffixLink = root;
                        if(active.activeNode != root){
                            active.activeNode = active.activeNode.suffixLink;
                        }
                        else{
                            active.activeIndex = active.activeIndex  + 1;
                            active.activeLength--;
                        }
                        remainingSuffixCount--;
                    }
           
                } catch (EndOfPathException e) {
                    SuffixNode node = selectNode();
                        node.child[input[i]] = SuffixNode.createNode(i, end);
                        if(lastCreatedInternalNode != null){
                            lastCreatedInternalNode.suffixLink = node;
                        }
                        lastCreatedInternalNode = node;
                        node.suffixLink = root;
                        if(active.activeNode != root){
                            active.activeNode = active.activeNode.suffixLink;
                        }
                        else{
                            active.activeIndex = active.activeIndex + 1;
                            active.activeLength--;
                        }
                        remainingSuffixCount--;
                }
            }
        }
    }
    
    private void walkDown(int index, SuffixNode lastCreatedInternalNode){
        SuffixNode node = selectNode();
        if(lastCreatedInternalNode != null){
            lastCreatedInternalNode.suffixLink = node;
        }
        if(diff(node) < active.activeLength){
            active.activeNode = node;
            active.activeLength = active.activeLength - diff(node);
            active.activeIndex = node.child[input[index]].start;
        }else{
            active.activeLength++;
        }
    }
    
    private char nextChar(int i) throws EndOfPathException{
        SuffixNode node = selectNode();
        if(diff(node) >= active.activeLength){
            return input[active.activeNode.child[input[active.activeIndex]].start + active.activeLength];
        }
        if(diff(node) + 1 == active.activeLength ){
            if(node.child[input[i]] != null){
                return input[i];
            }
        }
        else{
            active.activeNode = node;
            active.activeLength = active.activeLength - diff(node) -1;
            active.activeIndex = active.activeIndex + diff(node)  +1;
            return input[active.activeNode.child[input[active.activeIndex]].start + active.activeLength];
        }
        
        throw new EndOfPathException();
    }
    
    private static class EndOfPathException extends Exception{
        
    }
    
    private SuffixNode selectNode(){
        return active.activeNode.child[input[active.activeIndex]];
    }
    
    private SuffixNode selectNode(int index){
        return active.activeNode.child[input[index]];
    }
    
    
    private int diff(SuffixNode node){
        return node.end.end - node.start;
    }
  
    private void setIndexUsingDfs(SuffixNode root,int val, int size){
        if(root == null){
            return;
        }
        
        val += root.end.end - root.start + 1;
        if(root.index != -1){
            root.index = size - val;
            return;
        }
        
        for(SuffixNode node : root.child){
            setIndexUsingDfs(node, val, size);
        }
    }
    
    public void dfsTraversal(){
        List<Character> result = new ArrayList<>();
        for(SuffixNode node : root.child){
            dfsTraversal(node, result);
        }
    }
    
    private void dfsTraversal(SuffixNode root, List<Character> result){
        if(root == null){
            return;
        }
        if(root.index != -1){
            for(int i=root.start; i <= root.end.end; i++){
                result.add(input[i]);
            }
            result.stream().forEach(System.out::print);
            System.out.println(" " + root.index);
            for(int i=root.start; i <= root.end.end; i++){
                result.remove(result.size()-1);
            }
            return;
        }
        
        for(int i=root.start; i <= root.end.end; i++){
            result.add(input[i]);
        }
        
        for(SuffixNode node : root.child){
            dfsTraversal(node, result);
        }
        
        for(int i=root.start; i <= root.end.end; i++){
            result.remove(result.size()-1);
        }
       
    }
    
    private boolean validate(SuffixNode root, char[] input, int index, int curr){
        if(root == null){
            System.out.println("Failed at " + curr + " for index " + index);
            return false;
        }
        
        if(root.index != -1){
            if(root.index != index){
                System.out.println("Index not same. Failed at " + curr + " for index " + index);
                return false;        
            }else{
                return true;
            }
        }
        if(curr >= input.length){
            System.out.println("Index not same. Failed at " + curr + " for index " + index);
            return false;        
        }
        
        SuffixNode node = root.child[input[curr]];
        if(node == null){
            System.out.println("Failed at " + curr + " for index " + index);
            return false;
        }
        int j = 0;
        for(int i=node.start ; i <= node.end.end; i++){
            if(input[curr+j] != input[i] ){
                System.out.println("Mismatch found " + input[curr+j] + " " + input[i]);
                return false;
            }
            j++;
        }
        curr += node.end.end - node.start + 1;
        return validate(node, input, index, curr);
    }
    
    public boolean validate(){
        for(int i=0; i < this.input.length; i++){
            if(!validate(this.root, this.input, i, i)){
                System.out.println("Failed validation");
                return false;
            }
        }
        return true;
    }
}

class SuffixNode{
    
    private SuffixNode(){
    }
    
    private static final int TOTAL = 256;
    SuffixNode[] child = new SuffixNode[TOTAL];
    
    int start;
    End end;
    int index;
    
    SuffixNode suffixLink;
    
    public static SuffixNode createNode(int start, End end){
        SuffixNode node = new SuffixNode();
        node.start = start;
        node.end = end;
        return node;
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        int i=0;
        for(SuffixNode node : child){
            if(node != null){
                buffer.append((char)i + " ");
            }
            i++;
        }
        return "SuffixNode [start=" + start + "]" + " " + buffer.toString();
    }
 }

class End{
    public End(int end){
        this.end = end;
    }
    int end;
}

class Active{
    Active(SuffixNode node){
        activeLength = 0;
        activeNode = node;
        activeIndex = -1;
    }
    
    @Override
    public String toString() {
        
        return "Active [activeNode=" + activeNode + ", activeIndex="
                + activeIndex + ", activeLength=" + activeLength + "]";
    }

    SuffixNode activeNode;
    int activeIndex;
    int activeLength;
}