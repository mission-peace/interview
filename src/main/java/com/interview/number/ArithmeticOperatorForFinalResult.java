package com.interview.number;

/**
 * Given a series of numbers as the input, the last one as the result. 
 * Use the rest numbers to calculate the result,only +, -, *, / are allowed. 
 * The order of the input cannot be changed. 
 * If there is an equation, print it; or print "no equation". 
 * If more than one solution, any working equation is fine.
 * 
 * Test cases:
 * 0 with / operator
 * Input array is less than size 1
 * Does not handle float/double, does division with integer results.
 * Total is negative number, zero or positive number
 */
public class ArithmeticOperatorForFinalResult {

    private static char operators[] = {'+','-','*','/'};
    
    public char[] matchesResult(int input[], int result){
        if(input.length < 1){
            throw new IllegalArgumentException();
        }
        char[] equation = new char[input.length-1];
        boolean flag =  getResult(input, 1, result, input[0],equation);
        if(flag){
            return equation;
        }else{
            return null;
        }
    }
    
    private boolean getResult(int input[], int pos, int finalResult, int currentResult,char[] equation){
    
        if(pos == input.length){
            if(currentResult == finalResult){
                return true;
            }
            else{
                return false;
            }
        }
        for(int i=0; i < operators.length ; i++){
            if(operators[i] == '/' && input[pos] == 0){
                continue;
            }
            equation[pos-1] = operators[i];
            int r = performOperation(operators[i], currentResult, input[pos]);
            boolean flag = getResult(input, pos+1, finalResult, r,equation);
            if(flag){
                return true;
            }
        }
        return false;
    }
    
    private int performOperation(char op, int a, int b){
        switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        }
        throw new IllegalArgumentException();
    }
    
    public static void main(String args[]){
        ArithmeticOperatorForFinalResult ao = new ArithmeticOperatorForFinalResult();
        int input[] = {6,4,3,8,11};
        char[] equation = ao.matchesResult(input, 66);
        if(equation != null){
            for(char c : equation){
                System.out.print(c + " ");
            }
        }else{
            System.out.println("No equation");
        }
    }
    
}
