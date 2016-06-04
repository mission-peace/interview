package com.interview.string;

import java.util.*;

/**
 * https://leetcode.com/problems/anagrams/
 */
public class GroupAnagramsTogether {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs == null || strs.length == 0) return new ArrayList<List<String>>();
        Map<String, Map<String, Integer>> anagramGroup = new HashMap<>();
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            if (anagramGroup.containsKey(sorted)) {
                Map<String, Integer> r = anagramGroup.get(sorted);
                if (r.containsKey(str)) {
                    r.put(str, r.get(str) + 1);
                } else {
                    r.put(str, 1);
                }
            } else {
                Map<String, Integer> r = new TreeMap<>();
                r.put(str, 1);
                anagramGroup.put(sorted, r);
            }
        }
        List<List<String>> result = new ArrayList<>();
        for (Map<String, Integer> value : anagramGroup.values()) {
            List<String> r = new ArrayList<>();
            for (String k : value.keySet()) {
                for (int i = 0; i < value.get(k) ; i++) {
                    r.add(k);
                }
            }
            result.add(r);
        }
        return result;
    }
}
