package com.interview.misc;

import java.util.List;

/**
 * Created by tushar_v_roy on 3/10/16.
 */
public class PalindromePair {
    public List<List<Integer>> palindromePairs(String[] words) {
        Trie trie = new Trie();
        for (String word: words) {
            trie.insert(reverse(word));
        }

        return null;
    }

    private String reverse(String word) {
        return word;
    }
}

class TrieNode {
    TrieNode[] child = new TrieNode[26];
    boolean isWord;
    public TrieNode() {

    }
}

class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = (char)(word.charAt(i) - 'a');

            if (current.child[ch] == null) {
                current.child[ch] = new TrieNode();
            }
            current = current.child[ch];
        }
        current.isWord = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = (char)(word.charAt(i) - 'a');
            if (current.child[ch] == null) {
                return false;
            }
            current = current.child[ch];
        }
        return current.isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = (char)(prefix.charAt(i) - 'a');
            if (current.child[ch] == null) {
                return false;
            }
            current = current.child[ch];
        }
        return true;
    }

    public static void main(String args[]) {
        Trie t = new Trie();
        t.insert("hello");
        System.out.println(t.startsWith("hell"));
    }
}
