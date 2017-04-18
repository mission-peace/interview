package com.interview.ds;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by koray2 on 7/1/16.
 */
public class StringTrie {
    
    
    
    
    private static final class TrieNode{
        Map<Character , TrieNode> child = new HashMap<>();
        boolean isEndNode = false;
    }
    
    private TrieNode root = new TrieNode();
    
    public void insert(String s){
        
        insert(s,root);
        return;
        
    }
    
    private void insert(String s, TrieNode root) {
        for(int i = 0 ; i < s.length() ; i++){
            char c = s.charAt(i);
            TrieNode node = root.child.get(c);
            if(node == null){
                node = new TrieNode();
                root.child.put(c , node);
            }
            node.isEndNode |= i==s.length() - 1;
            root = node;
        } 
    }
    
    public boolean searchPrefix(String prefix){
        TrieNode current = root;
        for(int i = 0; i < prefix.length() ; i++){
            current = current.child.get(prefix.charAt(i));
            if(current == null)
                return false;
        }
        return true;
    }
    
    
    
    public boolean searchWord(String prefix){
        TrieNode current = root;
        for(int i = 0; i < prefix.length() ; i++){
            current = current.child.get(prefix.charAt(i));
            if(current == null)
                return false;
        }
        return current.isEndNode;
    }
    
    
    public static  void main(String... args){
        StringTrie trie  =  new StringTrie();
        trie.insert("abc");
        trie.insert("abgl");
        trie.insert("cdf");
        trie.insert("abcd");
        trie.insert("lmn");
        assert trie.searchPrefix("abcd");
        assert trie.searchPrefix("a");
        assert !trie.searchPrefix("lmng");
        assert trie.searchPrefix("ab");
        assert trie.searchWord("abcd");
        assert trie.searchWord("abc");
        assert !trie.searchWord("ab");
        assert !trie.searchWord("ff");
        System.out.println();
    }
    
    
}
