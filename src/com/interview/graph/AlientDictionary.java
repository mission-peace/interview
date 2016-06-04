package com.interview.graph;

import java.util.*;

/**
 * There is a new alien language which uses the latin alphabet. However, the order among letters
 * are unknown to you. You receive a list of words from the dictionary, where words are sorted
 * lexicographically by the rules of this new language. Derive the order of letters in this language.
 * https://leetcode.com/problems/alien-dictionary/
 */
public class AlientDictionary {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> graph = buildGraph(words);
        Deque<Character> stack = new LinkedList<>();
        Set<Character> visited = new HashSet<>();
        Set<Character> dfs = new HashSet<>();

        for (char ch : getAllChars(words)) {
            if (topSortUtil(ch, stack, visited, dfs, graph)) {
                return "";
            }
        }

        StringBuffer buff = new StringBuffer();
        while (!stack.isEmpty()) {
            buff.append(stack.pollFirst());
        }
        return buff.toString();
    }

    private boolean topSortUtil(char vertex, Deque<Character> stack, Set<Character> visited, Set<Character> dfs, Map<Character, Set<Character>> graph) {
        if (visited.contains(vertex)) {
            return false;
        }
        visited.add(vertex);
        dfs.add(vertex);
        Set<Character> set = graph.get(vertex);
        if (set != null) {
            for (char neighbor : set) {
                if (dfs.contains(neighbor)) {
                    return true;
                }
                if (topSortUtil(neighbor, stack, visited, dfs, graph)) {
                    return true;
                }
            }
        }
        dfs.remove(vertex);
        stack.offerFirst(vertex);
        return false;
    }

    private Map<Character, Set<Character>> buildGraph(String words[]) {
        Set<Character> allCharacters = getAllChars(words);
        Map<Character, Set<Character>> graph = new HashMap<>();
        for (int i = 0; i < words.length - 1; i++) {
            String nextWord = words[i + 1];
            for (int k = 0; k < Math.min(words[i].length(), nextWord.length()); k++) {
                if (words[i].charAt(k) != nextWord.charAt((k))) {
                    allCharacters.remove(words[i].charAt(k));
                    Set<Character> set = graph.get(words[i].charAt(k));
                    if (set == null) {
                        set = new HashSet<>();
                        graph.put(words[i].charAt(k), set);
                    }
                    set.add(nextWord.charAt(k));
                    break;
                }
            }
        }
        for (char ch : allCharacters) {
            graph.put(ch, null);
        }
        return graph;
    }

    private Set<Character> getAllChars(String words[]) {
        Set<Character> set = new HashSet<>();
        for (String word : words) {
            for (char ch : word.toCharArray()) {
                set.add(ch);
            }
        }
        return set;
    }

    public static void main(String args[]) {
        AlientDictionary ad =  new AlientDictionary();
        String[] words1 = {"zy","zx"};
        String[] words = {"wrt", "wrf", "er", "ett", "rftt"};
        String result = ad.alienOrder(words);
        System.out.print(result);
    }
}
