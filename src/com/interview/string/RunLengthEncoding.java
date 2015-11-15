package com.interview.string;

public class RunLengthEncoding {
    public static void main(String[] args) {
        String input = "AAAAAAAAAAAAABBCDDEEEE";
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            int count = 1;
            while (i+1 < input.length() && input.charAt(i) == input.charAt(i+1)) {
                count++;
                i++;
            }
            result.append(input.charAt(i));
            result.append(count);
        }
        System.out.println(result.toString());
    }
}
