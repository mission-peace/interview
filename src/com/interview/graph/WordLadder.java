package com.interview.graph;

import java.util.*;

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

 Only one letter can be changed at a time
 Each intermediate word must exist in the word list
 * https://leetcode.com/problems/word-ladder-ii/
 */
public class WordLadder {
    public List<List<String>> findLadders(String beginWord, String endWord, Set<String> wordList) {
        wordList.add(endWord);
        Set<String> visited = new HashSet<>();
        Deque<String> queue = new LinkedList<>();
        Map<String, Set<String>> parent = new HashMap<>();
        List<List<String>> result = new ArrayList<>();
        queue.offerFirst(beginWord);
        queue.offerFirst(null);
        boolean foundEndWord = false;
        Set<String> levelVisited = new HashSet<>();
        visited.add(beginWord);
        while (!queue.isEmpty()) {
            String word = queue.pollLast();
            if (word == null) {
                visited.addAll(levelVisited);
                levelVisited.clear();
                if (foundEndWord) {
                    break;
                } else if (!queue.isEmpty()) {
                    queue.offerFirst(null);
                }
                continue;
            }
            List<String> neighbors = nextWord(visited, wordList, word);
            for (String neighbor : neighbors) {
                Set<String> set = parent.get(neighbor);
                if (set == null) {
                    set = new HashSet<>();
                }
                set.add(word);
                parent.put(neighbor, set);
                levelVisited.add(neighbor);
                if (endWord.equals(neighbor)) {
                    foundEndWord = true;
                }
                queue.offerFirst(neighbor);
            }
        }
        if (!foundEndWord) {
            return Collections.emptyList();
        }
        setResult(endWord, parent, new ArrayList<>(), beginWord, result);
        return result;
    }

    private void setResult(String word, Map<String, Set<String>> map, List<String> result, String beginWord, List<List<String>> finalResult) {
        result.add(word);
        if (beginWord.equals(word)) {
            List<String> r = new ArrayList<>();
            r.addAll(result);
            Collections.reverse(r);
            finalResult.add(r);
            result.remove(result.size() - 1);
            return;
        }
        Set<String> set = map.get(word);
        for (String parent : set) {
            setResult(parent, map, result, beginWord, finalResult);
        }
        result.remove(result.size() - 1);
    }

    private List<String> nextWord(Set<String> visited, Set<String> wordList, String word) {
        List<String> neighbors = new ArrayList<>();
        char[] input = word.toCharArray();
        for (int i = 0; i < input.length; i++) {
            char ch = input[i];
            for (char k = 'a'; k <= 'z'; k++) {
                if (k == ch) {
                    continue;
                }
                input[i] = k;
                String newString = new String(input);
                if (!visited.contains(newString) && wordList.contains(newString)) {
                    neighbors.add(newString);
                }
            }
            input[i] = ch;
        }
        return neighbors;
    }

    public static void main(String args[]) {
        String[] wordList = {"hot","dot","dog","lot","log"};
        Set<String> wordSet = new HashSet<>();
        wordSet.addAll(Arrays.asList(wordList));
        WordLadder wl = new WordLadder();
        List<List<String>> result = wl.findLadders("hit", "cog", wordSet);
        System.out.print(result);
    }
}
