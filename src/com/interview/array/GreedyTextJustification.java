package com.interview.array;

import java.util.ArrayList;
import java.util.List;

/**
 * Date 03/12/2016
 * @author Tushar Roy
 *
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully
 * (left and right) justified.
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 *
 * Time complexity - O(n) where n is the number of words
 * Space complexity - O(1)
 *
 * https://leetcode.com/problems/text-justification/
 */
public class GreedyTextJustification {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < words.length; ) {
            int total = words[i].length();
            int j = i + 1;
            StringBuffer buff = new StringBuffer();
            buff.append(words[i]);
            while(j < words.length && total + words[j].length() + 1 <= maxWidth) {
                total += words[j].length() + 1;
                j++;
            }
            int remaining = maxWidth - total;
            //since j is not word length means its not a last line. So pad accordingly.
            if (j != words.length) {
                int count = j - i - 1;
                if (count == 0) {
                    padSpace(buff, remaining);
                } else {
                    int q = remaining/count;
                    int r = remaining % count;
                    for (int k = i + 1; k < j; k++) {
                        padSpace(buff, q);
                        if (r > 0) {
                            buff.append(" ");
                            r--;
                        }
                        buff.append(" ").append(words[k]);
                    }
                }
            } else { //if it is last line then left justify all the words.
                for (int k = i + 1; k < j; k++) {
                    buff.append(" ").append(words[k]);
                }
                padSpace(buff, remaining);
            }
            result.add(buff.toString());
            i = j;
        }
        return result;
    }

    private void padSpace(StringBuffer buff, int count) {
        for (int i = 0; i < count; i++) {
            buff.append(" ");
        }
    }

    public static void main(String args[]) {
        String[] input = {"What","must","be","shall","be."};
        GreedyTextJustification gtj = new GreedyTextJustification();
        List<String> result = gtj.fullJustify(input, 12);
        System.out.print(result);
    }
}
