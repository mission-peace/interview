package com.interview.string;

/**
 * http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
 */
import java.util.HashMap;
import java.util.Map;

public class SmallestWindowContaingAllCharacters {

    private void updateMap(Map<Character, Integer> map, Character ch) {
        int count = 1;
        if (map.containsKey(ch)) {
            count = map.get(ch);
            count++;
        }
        map.put(ch, count);
    }

    private void updateMapDecreaseCount(Map<Character, Integer> map, Character ch) {
        int count = map.get(ch);
        count--;
        map.put(ch, count);
    }

    public int smallestWindow(char[] str, char[] subString) {

        Map<Character, Integer> subStringVisited = new HashMap<Character, Integer>();
        Map<Character, Integer> mainStringVisited = new HashMap<Character, Integer>();
        for (int i = 0; i < subString.length; i++) {
            updateMap(subStringVisited, subString[i]);
        }
        int i = 0;
        int startIndex = -1;
        int count = 0;
        // initial big window
        for (; i < str.length; i++) {
            if (subStringVisited.containsKey(str[i])) {
                if (startIndex == -1) {
                    startIndex = i;
                }
                updateMap(mainStringVisited, str[i]);
                if (mainStringVisited.get(str[i]) == subStringVisited
                        .get(str[i])) {
                    count += mainStringVisited.get(str[i]);
                }
                if (count == subString.length) {
                    break;
                }
            }
        }
        int endIndex = i;
        System.out.println(startIndex + " " + i);

        i = trimWindow(startIndex,str,endIndex,mainStringVisited,subStringVisited);
            
        System.out.print(i + " " + endIndex);
        int minWindow = endIndex - i +1;
        startIndex =i;
        for(i = endIndex+1 ; i < str.length; i++){
            if(subStringVisited.containsKey(str[i])){
                updateMap(mainStringVisited,str[i]);
            }
            if(str[startIndex] == str[i]){
                startIndex =trimWindow(startIndex,str,i,mainStringVisited,subStringVisited);
                if(minWindow > i - startIndex + 1){
                    minWindow = i-startIndex +1;
                }
            }
        }
        return minWindow;
    }
    
    private int trimWindow(int startIndex, char[] str, int endIndex,Map<Character,Integer> mainStringVisited, Map<Character,Integer> subStringVisited){
        int i=0;
        for (i = startIndex; i <= endIndex; i++) {

            if (mainStringVisited.containsKey(str[i])){
                if(mainStringVisited.get(str[i]) > subStringVisited
                            .get(str[i])) {
                    updateMapDecreaseCount(mainStringVisited, str[i]);
                }else{
                    break;
                }
            }
        }
        return i;
    }

    public static void main(String args[]) {

        String str = "Tsuaosyogrlmnsluuorjkoruost";
        String subString = "soor";
        SmallestWindowContaingAllCharacters swcac = new SmallestWindowContaingAllCharacters();
        int minWindow = swcac.smallestWindow(str.toCharArray(), subString.toCharArray());
        System.out.println(minWindow);
    }

}
