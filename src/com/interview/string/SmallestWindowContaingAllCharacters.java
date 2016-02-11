package com.interview.string;

/**
 * References
 * https://leetcode.com/problems/minimum-window-substring/
 * http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
 */
import java.util.HashMap;
import java.util.Map;

public class SmallestWindowContaingAllCharacters {

    public String minWindow(String s, String t) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char s1 : t.toCharArray()) {
            countMap.compute(s1, (key, val) -> {
                if (val == null) {
                    return 1;
                }
                return val + 1;
            });
        }

        Map<Character, Integer> foundMap = new HashMap<>();
        for (char s1 : t.toCharArray()) {
            foundMap.put(s1, 0);
        }

        int startWindow;
        int charsFound = 0;
        for (startWindow = 0; startWindow < s.length(); startWindow++) {
            if (countMap.containsKey(s.charAt(startWindow))) {
                break;
            }
        }
        int minWindowStart = Integer.MIN_VALUE;
        int minWindowEnd = -1;
        int totalCharacters = t.length();
        for (int i = startWindow; i < s.length(); i++) {
            char ch = s.charAt(i);
            Integer count = countMap.get(ch);
            if (count != null) {
                Integer actualCount = foundMap.get(ch);
                foundMap.put(ch, actualCount + 1);
                if (actualCount < count) {
                    charsFound++;
                    if (charsFound == totalCharacters) {
                        if (i - startWindow < minWindowEnd - minWindowStart) {
                            minWindowStart = startWindow;
                            minWindowEnd = i;
                        }
                        ShrinkResult sr = shrinkWindow(countMap, foundMap, startWindow, s, i);
                        if (sr.fullStartWindow != -1) {
                            if (i - sr.fullStartWindow < minWindowEnd - minWindowStart) {
                                minWindowStart = sr.fullStartWindow;
                                minWindowEnd = i;
                            }
                        }
                        startWindow = sr.startWindow;
                        charsFound--;
                    }
                }
            }
        }
        if (minWindowEnd == -1) {
            return "";
        } else {
            return s.substring(minWindowStart, minWindowEnd + 1);
        }
    }

    class ShrinkResult {
        int startWindow;
        int fullStartWindow;
    }

    private ShrinkResult shrinkWindow(Map<Character, Integer> countMap, Map<Character, Integer> foundMap,
                                      int startWindow, String s, int end) {
        boolean firstViolation = false;
        int diff = -1;
        int i;
        for(i = startWindow; i <= end; i++) {
            if(!firstViolation) {
                diff = i;
            }
            char ch = s.charAt(i);
            Integer count = countMap.get(ch);
            if (count != null) {
                int actualCount = foundMap.get(ch);
                if (firstViolation) {
                    if (actualCount <= count) {
                        break;
                    }
                } else {
                    if (actualCount == count) {
                        firstViolation = true;
                    }
                }
                foundMap.compute(ch, (key, val) -> val - 1);
            }
        }
        ShrinkResult sr = new ShrinkResult();
        sr.fullStartWindow = diff;
        sr.startWindow = i;
        return sr;
    }

    public static void main(String args[]) {

        String str = "Tsuaosyogrlmnsluuorjkoruost";
        String subString = "soor";
        SmallestWindowContaingAllCharacters swcac = new SmallestWindowContaingAllCharacters();
        String result = swcac.minWindow(str, subString);
        System.out.println(result);
    }

}
