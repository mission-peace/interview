package com.interview.string;

/**
 * Date 07/08/2015
 * @author tushar_v_roy
 * 
 * Given a string like heads print all combination of abbreviation
 * Output should be
 * h1ads
 * h2ds
 * h3s
 * he1ds
 * he2s
 * hea1s
 */
public class WordAbbreviationCombination {
    public void shorten(char input[]){
        for(int i = 1; i < input.length-1; i++){
            for(int j=i; j < input.length-1; j++){
                for(int k=0; k < i; k++){
                    System.out.print(input[k]);
                }
                System.out.print(j-i+1);
                for(int k=j+1; k < input.length; k++){
                    System.out.print(input[k]);
                }
                System.out.println();
            }
        }
    }

    public static void main(String args[]) {
        WordAbbreviationCombination ssc = new WordAbbreviationCombination();
        ssc.shorten("heading".toCharArray());
    }
}
