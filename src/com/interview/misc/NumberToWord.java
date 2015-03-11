package com.interview.misc;

/**
 * Convert a number into words
 * Test cases
 * Negative number
 * Zero
 * Number in 100s
 * Number in 1000s
 * Number in millions
 */
public class NumberToWord {

    private static int MILLION = 1000000;
    private static int THOUSAND = 1000;
    
    public String toWord(int number){
        StringBuffer buffer = new StringBuffer();
        if(number ==0){
            return toString(number);
        }
        if(number < 0){
            buffer.append("minus ");
            number = number *-1;
        }
        if(number >= MILLION){
            int first = number /MILLION;
            number = number % MILLION;
            buffer.append(hundredsPart(first)).append(" million ");
        }
        if(number >= THOUSAND){
            int first = number /THOUSAND;
            number = number % THOUSAND;
            buffer.append(hundredsPart(first)).append(" thousand ");
        }
        buffer.append(hundredsPart(number));
        return buffer.toString();
    }
    
    private String hundredsPart(int number){
        StringBuffer buffer = new StringBuffer();
        if(number != 0){
            if(number <= 99){
                buffer.append(tenthPart(number));
            }else{
                int first = (number /100);
                int second = number % 100;
                buffer.append(toString(first) + " hundred");
                if(second != 0){
                    buffer.append(" ").append(tenthPart(second));
                }
            }
            return buffer.toString();
        }else{
            return "";
        }
    }
        
    private String tenthPart(int number){
        StringBuffer buffer = new StringBuffer();
        if(number != 0){
            if(number <= 19){
                buffer.append(toString(number));
            }else{
                int first = (number/10)*10;
                int second = number%10;
                buffer.append(toString(first));
                if(second != 0){
                    buffer.append(" ").append(toString(second));
                }
            }
            return buffer.toString();
        }else{
            return "";
        }
    }
    
    private String toString(int number){
        
        switch(number){
        case 0:
            return "Zero";
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";  
        case 10:
            return "Ten";
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thrirteen";
        case 14:
            return "Fourteen";
        case 15:
            return "Fifteen";
        case 16:
            return "Sixteen";
        case 17:
            return "Seventeen";
        case 18:
            return "Eighteen";
        case 19:
            return "Nineteen";  
        case 20:
            return "Twenty";    
        case 30:
            return "Thirty";    
        case 40:
            return "Forty"; 
        case 50:
            return "Fifty"; 
        case 60:
            return "Sixty"; 
        case 70:
            return "Seventy";   
        case 80:
            return "Eighty";    
        case 90:
            return "Ninety";    
        case 100:
            return "Hundred";   
        case 1000:
            return "Thousand";  
        case 1000000:
            return "Million";   
        default:
            throw new IllegalArgumentException();
        }
    }
    
    public static void main(String args[]){
        NumberToWord ntw = new NumberToWord();
        System.out.println(ntw.toWord(8000));
        System.out.println(ntw.toWord(8192));
        System.out.println(ntw.toWord(8112));
        System.out.println(ntw.toWord(504));
        System.out.println(ntw.toWord(565100));
        System.out.println(ntw.toWord(6721157));
        System.out.println(ntw.toWord(-106721157));
        System.out.println(ntw.toWord(106070571));
        System.out.println(ntw.toWord(-92));
        System.out.println(ntw.toWord(0));
    }
}
