package com.interview.misc;

/**
 * http://www.careercup.com/question?id=6139456847347712
 * Test case : 0 or negative number
 */
public class ConvertNumberIntoBase26 {

    /**
     * Here 1..26 is A...Z
     * 27...52 is AA...AZ. So we first try to divide num by 26 then find ceiling...so 27...52 returns 2. Then we subtract 1 from the number
     * @param num
     * @return
     */
    public String numberToBase26(int num){
        StringBuffer buff = new StringBuffer();
        while(num > 0){
            char r  = convert(num % 26);
            buff.append(r);
            num = (int)(Math.ceil(num*1.0/26));
            num--;
        }
        return buff.reverse().toString();
    }
    
    public int base26ToNumber(String str){
        int result = 0;
        int pow = 1;
        for(int i = str.length() -1; i>=0; i--){
            char s = str.charAt(i);
            s = (char)(s - 'A'+1);
            result += s*pow;
            pow *= 26;
        }
        return result;
    }
    
    private char convert(int r){
        if(r == 0){
            return 'Z';
        }else{
            return (char)(r + 'A'-1);
        }
    }
    
    public static void main(String args[]){
        ConvertNumberIntoBase26 cni = new ConvertNumberIntoBase26();
        System.out.println(cni.numberToBase26(704));
        System.out.println(cni.base26ToNumber("AAB"));

        System.out.println(cni.numberToBase26(52));
        System.out.println(cni.base26ToNumber("AZ"));

        System.out.println(cni.numberToBase26(13));
        System.out.println(cni.base26ToNumber("M"));

        System.out.println(cni.numberToBase26(126));
        System.out.println(cni.base26ToNumber("DV"));
    }
}
