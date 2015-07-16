package com.interview.suffixprefix;

public class Trie {

    private Node root = new Node();
    private static int NUM_OF_CHAR = 256;
    static class Node{
        Node[] child = new Node[NUM_OF_CHAR];
        boolean isWord;
    }
    
    public void insert(char[] str){
        
        Node start = root;
        for(char ch : str){
            if(start.child[ch] != null){
                start = start.child[ch];
            }else{
                start.child[ch] = new Node();
                start = start.child[ch];
            }
        }
        start.isWord = true;
    }
    
    public void delete(char[] str){
        
        deleteRecursively(root, str, 0);
    }
    
    public boolean deleteRecursively(Node root,char[] str,int pos){
        
        if(pos == str.length){
            if(root.isWord){
                root.isWord = false;
                boolean hasChild = hasAnyOtherChild(root);
                if(!hasChild){
                    return true;
                }
            }
            return false;
        }
        
        if(root == null){
            return false;
        }
        
        boolean r = deleteRecursively(root.child[str[pos]], str, pos+1);
        if(r == false){
            return false;
        }
        root.child[str[pos]] = null;
        
        boolean hasChild = hasAnyOtherChild(root);
        return !hasChild && !root.isWord;
    }
    
    public boolean hasAnyOtherChild(Node root){
        for(int i=0; i < NUM_OF_CHAR; i++){
            if(root.child[i] != null){
                return true;
            }
        }
        return false;
    }
    
    public boolean search(char[] key){
        
        Node start = root;
        for(char ch : key){
            if(start.child[ch] == null){
                return false;
            }
            start = start.child[ch];
        }
        
        return true;
    }
    
    private void displayTrie(Node root){
        Node start = root;
        System.out.println(root.isWord);
        for(int i=0; i < NUM_OF_CHAR ; i++){
            if(start.child[i] != null){
                System.out.println((char)i);
                displayTrie(start.child[i]);
            }
        }
    }
    
    public static void main(String args[]){
        Trie t = new Trie();
        t.insert("A".toCharArray());
        t.insert("Tushar".toCharArray());
        t.insert("TusharRoy".toCharArray());
        t.insert("Anisweta".toCharArray());
        t.insert("AniswetaS".toCharArray());
        t.displayTrie(t.root);
        t.delete("TusharRoy".toCharArray());
        t.displayTrie(t.root);
    }
    
}
